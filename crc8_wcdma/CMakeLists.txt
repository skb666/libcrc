# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_wcdma_srcs "*.c")
add_executable(test_crc8_wcdma ${test_crc8_wcdma_srcs})
target_link_libraries(test_crc8_wcdma crc8_wcdma)

# 单元测试
add_test(
    NAME test_crc8_wcdma
    COMMAND ./test_crc8_wcdma
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
