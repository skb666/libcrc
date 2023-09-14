# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_usb_srcs "*.c")
add_executable(test_crc16_usb ${test_crc16_usb_srcs})
target_link_libraries(test_crc16_usb PRIVATE crc16_usb)
add_dependencies(test_crc16_usb crc16_usb)

# 单元测试
add_test(
    NAME test_crc16_usb
    COMMAND ./test_crc16_usb
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
