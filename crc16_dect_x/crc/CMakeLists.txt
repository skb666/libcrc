# crc16_dect_x
file(GLOB crc16_dect_x_srcs "*.c")
add_library(crc16_dect_x STATIC ${crc16_dect_x_srcs})
target_include_directories(crc16_dect_x PUBLIC .)
