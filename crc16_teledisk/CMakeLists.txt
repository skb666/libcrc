# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_teledisk_srcs "*.c")
add_executable(test_crc16_teledisk ${test_crc16_teledisk_srcs})
target_link_libraries(test_crc16_teledisk crc16_teledisk)

# 单元测试
add_test(
    NAME test_crc16_teledisk
    COMMAND ./test_crc16_teledisk
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
