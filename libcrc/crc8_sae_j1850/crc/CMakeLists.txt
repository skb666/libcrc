# crc8_sae_j1850
file(GLOB crc8_sae_j1850_srcs "*.c")
add_library(crc8_sae_j1850 STATIC ${crc8_sae_j1850_srcs})
target_include_directories(crc8_sae_j1850 PUBLIC .)
