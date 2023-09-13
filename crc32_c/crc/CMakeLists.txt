# crc32_c
file(GLOB crc32_c_srcs "*.c")
add_library(crc32_c STATIC ${crc32_c_srcs})
target_include_directories(crc32_c PUBLIC .)
