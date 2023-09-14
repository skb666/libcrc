# crc16_ccitt_false
file(GLOB crc16_ccitt_false_srcs "*.c")
add_library(crc16_ccitt_false STATIC ${crc16_ccitt_false_srcs})
target_include_directories(crc16_ccitt_false PUBLIC .)
