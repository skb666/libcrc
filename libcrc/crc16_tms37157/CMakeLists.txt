# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_tms37157_srcs "*.c")
add_executable(test_crc16_tms37157 ${test_crc16_tms37157_srcs})
target_link_libraries(test_crc16_tms37157 PRIVATE crc16_tms37157)
add_dependencies(test_crc16_tms37157 crc16_tms37157)

# 单元测试
add_test(
    NAME test_crc16_tms37157
    COMMAND ./test_crc16_tms37157
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
