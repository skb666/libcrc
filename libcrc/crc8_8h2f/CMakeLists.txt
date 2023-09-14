# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_8h2f_srcs "*.c")
add_executable(test_crc8_8h2f ${test_crc8_8h2f_srcs})
target_link_libraries(test_crc8_8h2f PRIVATE crc8_8h2f)
add_dependencies(test_crc8_8h2f crc8_8h2f)

# 单元测试
add_test(
    NAME test_crc8_8h2f
    COMMAND ./test_crc8_8h2f
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
