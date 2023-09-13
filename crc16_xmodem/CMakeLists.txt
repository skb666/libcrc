# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_xmodem_srcs "*.c")
add_executable(test_crc16_xmodem ${test_crc16_xmodem_srcs})
target_link_libraries(test_crc16_xmodem crc16_xmodem)

# 单元测试
add_test(
    NAME test_crc16_xmodem
    COMMAND ./test_crc16_xmodem
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
