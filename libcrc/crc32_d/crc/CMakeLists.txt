# crc32_d
file(GLOB crc32_d_srcs "*.c")
add_library(crc32_d STATIC ${crc32_d_srcs})
target_include_directories(crc32_d PUBLIC .)
