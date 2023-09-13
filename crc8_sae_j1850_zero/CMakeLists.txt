# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_sae_j1850_zero_srcs "*.c")
add_executable(test_crc8_sae_j1850_zero ${test_crc8_sae_j1850_zero_srcs})
target_link_libraries(test_crc8_sae_j1850_zero crc8_sae_j1850_zero)

# 单元测试
add_test(
    NAME test_crc8_sae_j1850_zero
    COMMAND ./test_crc8_sae_j1850_zero
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
