# crc16_kermit
file(GLOB crc16_kermit_srcs "*.c")
add_library(crc16_kermit STATIC ${crc16_kermit_srcs})
target_include_directories(crc16_kermit PUBLIC .)
