# crc24_flexray_a
file(GLOB crc24_flexray_a_srcs "*.c")
add_library(crc24_flexray_a STATIC ${crc24_flexray_a_srcs})
target_include_directories(crc24_flexray_a PUBLIC .)
