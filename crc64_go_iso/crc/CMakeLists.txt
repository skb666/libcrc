# crc64_go_iso
file(GLOB crc64_go_iso_srcs "*.c")
add_library(crc64_go_iso STATIC ${crc64_go_iso_srcs})
target_include_directories(crc64_go_iso PUBLIC .)
