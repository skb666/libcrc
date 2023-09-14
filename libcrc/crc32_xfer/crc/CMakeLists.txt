# crc32_xfer
file(GLOB crc32_xfer_srcs "*.c")
add_library(crc32_xfer STATIC ${crc32_xfer_srcs})
target_include_directories(crc32_xfer PUBLIC .)
