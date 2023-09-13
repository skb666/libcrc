# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_mpeg2_srcs "*.c")
add_executable(test_crc32_mpeg2 ${test_crc32_mpeg2_srcs})
target_link_libraries(test_crc32_mpeg2 crc32_mpeg2)

# 单元测试
add_test(
    NAME test_crc32_mpeg2
    COMMAND ./test_crc32_mpeg2
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
