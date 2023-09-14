# crc32_jamcrc
file(GLOB crc32_jamcrc_srcs "*.c")
add_library(crc32_jamcrc STATIC ${crc32_jamcrc_srcs})
target_include_directories(crc32_jamcrc PUBLIC .)
