# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_jamcrc_srcs "*.c")
add_executable(test_crc32_jamcrc ${test_crc32_jamcrc_srcs})
target_link_libraries(test_crc32_jamcrc PRIVATE crc32_jamcrc)
add_dependencies(test_crc32_jamcrc crc32_jamcrc)

# 单元测试
add_test(
    NAME test_crc32_jamcrc
    COMMAND ./test_crc32_jamcrc
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
