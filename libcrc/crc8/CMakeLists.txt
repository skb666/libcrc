# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_srcs "*.c")
add_executable(test_crc8 ${test_crc8_srcs})
target_link_libraries(test_crc8 PRIVATE crc8)
add_dependencies(test_crc8 crc8)

# 单元测试
add_test(
    NAME test_crc8
    COMMAND ./test_crc8
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
