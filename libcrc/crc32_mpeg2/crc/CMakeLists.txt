# crc32_mpeg2
file(GLOB crc32_mpeg2_srcs "*.c")
add_library(crc32_mpeg2 STATIC ${crc32_mpeg2_srcs})
target_include_directories(crc32_mpeg2 PUBLIC .)
