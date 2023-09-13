# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_xfer_srcs "*.c")
add_executable(test_crc32_xfer ${test_crc32_xfer_srcs})
target_link_libraries(test_crc32_xfer crc32_xfer)

# 单元测试
add_test(
    NAME test_crc32_xfer
    COMMAND ./test_crc32_xfer
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
