# crc64_we
file(GLOB crc64_we_srcs "*.c")
add_library(crc64_we STATIC ${crc64_we_srcs})
target_include_directories(crc64_we PUBLIC .)
