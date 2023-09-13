# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_t10_dif_srcs "*.c")
add_executable(test_crc16_t10_dif ${test_crc16_t10_dif_srcs})
target_link_libraries(test_crc16_t10_dif crc16_t10_dif)

# 单元测试
add_test(
    NAME test_crc16_t10_dif
    COMMAND ./test_crc16_t10_dif
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
