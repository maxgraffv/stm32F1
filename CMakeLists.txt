cmake_minimum_required(VERSION 3.16)

# ---- Projekt ----
project(stm32f103rb-min C ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# (opcjonalnie) wyłącz testy linkera w try_compile, bo i tak linkujemy "po swojemu"
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# ---- Toolchain ARM GCC ----
# Jeśli masz toolchain w PATH, wystarczy tak; inaczej podaj pełne ścieżki.
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy CACHE STRING "" FORCE)
set(CMAKE_SIZE    arm-none-eabi-size    CACHE STRING "" FORCE)
set(CMAKE_GDB     arm-none-eabi-gdb     CACHE STRING "" FORCE)

# ---- Pliki ----
set(SRCS
  startup_stm32.c
  src/uart.c
)
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/linker.ld)

# ---- Flagi kompilacji/linkowania ----
set(MCU_FLAGS -mcpu=cortex-m3 -mthumb)
set(COMMON_WARN -Wall -Wextra -Wundef -Wno-unused-parameter)

add_executable(firmware.elf ${SRCS})

target_compile_definitions(firmware.elf PRIVATE STM32F103xB)
target_compile_options(firmware.elf PRIVATE
  ${MCU_FLAGS} -Os -g3 -ffunction-sections -fdata-sections ${COMMON_WARN}
)
# Uwaga: -nostartfiles bo mamy własny startup i wektor przerwań
target_link_options(firmware.elf PRIVATE
  ${MCU_FLAGS}
  -T ${LINKER_SCRIPT}
  -Wl,--gc-sections
  -Wl,-Map=${CMAKE_BINARY_DIR}/firmware.map
  -nostartfiles -static
)

# ---- Tworzenie .bin i size po buildzie ----
add_custom_command(TARGET firmware.elf POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O binary firmware.elf firmware.bin
  COMMAND ${CMAKE_SIZE} firmware.elf
  BYPRODUCTS firmware.bin
  COMMENT "Objcopy -> firmware.bin && size"
)

# ---- Cele flashowania ----
# Ustaw zmienne przez -D przy wywołaniu cmake, jeśli masz inny interfejs/target
set(OPENOCD_IF "interface/stlink.cfg" CACHE STRING "OpenOCD interface cfg")
set(OPENOCD_TGT "target/stm32f1x.cfg" CACHE STRING "OpenOCD target cfg")

add_custom_target(flash-stlink
  COMMAND st-flash --reset write ${CMAKE_BINARY_DIR}/firmware.bin 0x08000000
  DEPENDS firmware.elf
  COMMENT "Flashing via ST-Link (st-flash)"
)

add_custom_target(flash-openocd
  COMMAND openocd -f ${OPENOCD_IF} -f ${OPENOCD_TGT}
          -c "init; halt; program ${CMAKE_BINARY_DIR}/firmware.elf verify reset exit"
  DEPENDS firmware.elf
  COMMENT "Flashing via OpenOCD"
)

add_custom_target(flash-dfu
  COMMAND dfu-util -a 0 -s 0x08000000:leave -D ${CMAKE_BINARY_DIR}/firmware.bin
  DEPENDS firmware.elf
  COMMENT "Flashing via DFU (ROM bootloader)"
)

# ---- Debug (opcjonalnie) ----
add_custom_target(ocd
  COMMAND openocd -f ${OPENOCD_IF} -f ${OPENOCD_TGT}
  COMMENT "Start OpenOCD server (Ctrl+C to stop)"
)

add_custom_target(gdb
  COMMAND ${CMAKE_GDB} ${CMAKE_BINARY_DIR}/firmware.elf
  COMMENT "Launch arm-none-eabi-gdb"
)