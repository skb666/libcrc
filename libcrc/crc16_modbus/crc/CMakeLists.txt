# crc16_modbus
file(GLOB crc16_modbus_srcs "*.c")
add_library(crc16_modbus STATIC ${crc16_modbus_srcs})
target_include_directories(crc16_modbus PUBLIC .)
