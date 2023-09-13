# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_dnp_srcs "*.c")
add_executable(test_crc16_dnp ${test_crc16_dnp_srcs})
target_link_libraries(test_crc16_dnp crc16_dnp)

# 单元测试
add_test(
    NAME test_crc16_dnp
    COMMAND ./test_crc16_dnp
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
