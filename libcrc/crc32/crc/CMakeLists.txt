# crc32
file(GLOB crc32_srcs "*.c")
add_library(crc32 STATIC ${crc32_srcs})
target_include_directories(crc32 PUBLIC .)
