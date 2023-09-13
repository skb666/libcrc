# crc16_dect_r
file(GLOB crc16_dect_r_srcs "*.c")
add_library(crc16_dect_r STATIC ${crc16_dect_r_srcs})
target_include_directories(crc16_dect_r PUBLIC .)
