# crc16_riello
file(GLOB crc16_riello_srcs "*.c")
add_library(crc16_riello STATIC ${crc16_riello_srcs})
target_include_directories(crc16_riello PUBLIC .)
