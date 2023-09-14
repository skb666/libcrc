# crc24_openpgp
file(GLOB crc24_openpgp_srcs "*.c")
add_library(crc24_openpgp STATIC ${crc24_openpgp_srcs})
target_include_directories(crc24_openpgp PUBLIC .)
