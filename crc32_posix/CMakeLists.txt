# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_posix_srcs "*.c")
add_executable(test_crc32_posix ${test_crc32_posix_srcs})
target_link_libraries(test_crc32_posix crc32_posix)

# 单元测试
add_test(
    NAME test_crc32_posix
    COMMAND ./test_crc32_posix
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
