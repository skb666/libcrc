# crc8_sae_j1850_zero
file(GLOB crc8_sae_j1850_zero_srcs "*.c")
add_library(crc8_sae_j1850_zero STATIC ${crc8_sae_j1850_zero_srcs})
target_include_directories(crc8_sae_j1850_zero PUBLIC .)
