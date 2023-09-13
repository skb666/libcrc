# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_srcs "*.c")
add_executable(test_crc32 ${test_crc32_srcs})
target_link_libraries(test_crc32 crc32)

# 单元测试
add_test(
    NAME test_crc32
    COMMAND ./test_crc32
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
