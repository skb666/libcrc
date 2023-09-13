# crc32_q
file(GLOB crc32_q_srcs "*.c")
add_library(crc32_q STATIC ${crc32_q_srcs})
target_include_directories(crc32_q PUBLIC .)
