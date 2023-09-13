# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_sae_j1850_srcs "*.c")
add_executable(test_crc8_sae_j1850 ${test_crc8_sae_j1850_srcs})
target_link_libraries(test_crc8_sae_j1850 crc8_sae_j1850)

# 单元测试
add_test(
    NAME test_crc8_sae_j1850
    COMMAND ./test_crc8_sae_j1850
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
