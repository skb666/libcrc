# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_ibm_srcs "*.c")
add_executable(test_crc16_ibm ${test_crc16_ibm_srcs})
target_link_libraries(test_crc16_ibm PRIVATE crc16_ibm)
add_dependencies(test_crc16_ibm crc16_ibm)

# 单元测试
add_test(
    NAME test_crc16_ibm
    COMMAND ./test_crc16_ibm
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
