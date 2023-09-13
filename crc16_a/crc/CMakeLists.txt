# crc16_a
file(GLOB crc16_a_srcs "*.c")
add_library(crc16_a STATIC ${crc16_a_srcs})
target_include_directories(crc16_a PUBLIC .)
