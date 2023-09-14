# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_kermit_srcs "*.c")
add_executable(test_crc16_kermit ${test_crc16_kermit_srcs})
target_link_libraries(test_crc16_kermit PRIVATE crc16_kermit)
add_dependencies(test_crc16_kermit crc16_kermit)

# 单元测试
add_test(
    NAME test_crc16_kermit
    COMMAND ./test_crc16_kermit
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
