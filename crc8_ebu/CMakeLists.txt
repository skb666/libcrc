# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_ebu_srcs "*.c")
add_executable(test_crc8_ebu ${test_crc8_ebu_srcs})
target_link_libraries(test_crc8_ebu crc8_ebu)

# 单元测试
add_test(
    NAME test_crc8_ebu
    COMMAND ./test_crc8_ebu
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
