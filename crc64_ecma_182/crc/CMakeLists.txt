# crc64_ecma_182
file(GLOB crc64_ecma_182_srcs "*.c")
add_library(crc64_ecma_182 STATIC ${crc64_ecma_182_srcs})
target_include_directories(crc64_ecma_182 PUBLIC .)
