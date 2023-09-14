# crc32_bzip2
file(GLOB crc32_bzip2_srcs "*.c")
add_library(crc32_bzip2 STATIC ${crc32_bzip2_srcs})
target_include_directories(crc32_bzip2 PUBLIC .)
