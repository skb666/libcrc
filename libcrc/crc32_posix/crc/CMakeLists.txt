# crc32_posix
file(GLOB crc32_posix_srcs "*.c")
add_library(crc32_posix STATIC ${crc32_posix_srcs})
target_include_directories(crc32_posix PUBLIC .)
