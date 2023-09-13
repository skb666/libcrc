# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_maxim_srcs "*.c")
add_executable(test_crc8_maxim ${test_crc8_maxim_srcs})
target_link_libraries(test_crc8_maxim crc8_maxim)

# 单元测试
add_test(
    NAME test_crc8_maxim
    COMMAND ./test_crc8_maxim
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
