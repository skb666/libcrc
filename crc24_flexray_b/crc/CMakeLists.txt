# crc24_flexray_b
file(GLOB crc24_flexray_b_srcs "*.c")
add_library(crc24_flexray_b STATIC ${crc24_flexray_b_srcs})
target_include_directories(crc24_flexray_b PUBLIC .)
