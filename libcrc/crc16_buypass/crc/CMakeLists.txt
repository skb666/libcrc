# crc16_buypass
file(GLOB crc16_buypass_srcs "*.c")
add_library(crc16_buypass STATIC ${crc16_buypass_srcs})
target_include_directories(crc16_buypass PUBLIC .)
