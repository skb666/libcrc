# crc16_x25
file(GLOB crc16_x25_srcs "*.c")
add_library(crc16_x25 STATIC ${crc16_x25_srcs})
target_include_directories(crc16_x25 PUBLIC .)
