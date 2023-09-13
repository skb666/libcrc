# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_modbus_srcs "*.c")
add_executable(test_crc16_modbus ${test_crc16_modbus_srcs})
target_link_libraries(test_crc16_modbus crc16_modbus)

# 单元测试
add_test(
    NAME test_crc16_modbus
    COMMAND ./test_crc16_modbus
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
