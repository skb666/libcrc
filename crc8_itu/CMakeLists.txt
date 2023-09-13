# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_itu_srcs "*.c")
add_executable(test_crc8_itu ${test_crc8_itu_srcs})
target_link_libraries(test_crc8_itu crc8_itu)

# 单元测试
add_test(
    NAME test_crc8_itu
    COMMAND ./test_crc8_itu
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
