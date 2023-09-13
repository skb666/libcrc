# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_ccitt_false_srcs "*.c")
add_executable(test_crc16_ccitt_false ${test_crc16_ccitt_false_srcs})
target_link_libraries(test_crc16_ccitt_false crc16_ccitt_false)

# 单元测试
add_test(
    NAME test_crc16_ccitt_false
    COMMAND ./test_crc16_ccitt_false
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
