# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_darc_srcs "*.c")
add_executable(test_crc8_darc ${test_crc8_darc_srcs})
target_link_libraries(test_crc8_darc PRIVATE crc8_darc)
add_dependencies(test_crc8_darc crc8_darc)

# 单元测试
add_test(
    NAME test_crc8_darc
    COMMAND ./test_crc8_darc
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
