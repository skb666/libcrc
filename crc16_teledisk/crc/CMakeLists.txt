# crc16_teledisk
file(GLOB crc16_teledisk_srcs "*.c")
add_library(crc16_teledisk STATIC ${crc16_teledisk_srcs})
target_include_directories(crc16_teledisk PUBLIC .)
