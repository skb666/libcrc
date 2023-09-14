# crc64_xz
file(GLOB crc64_xz_srcs "*.c")
add_library(crc64_xz STATIC ${crc64_xz_srcs})
target_include_directories(crc64_xz PUBLIC .)
