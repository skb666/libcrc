# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc24_openpgp_srcs "*.c")
add_executable(test_crc24_openpgp ${test_crc24_openpgp_srcs})
target_link_libraries(test_crc24_openpgp PRIVATE crc24_openpgp)
add_dependencies(test_crc24_openpgp crc24_openpgp)

# 单元测试
add_test(
    NAME test_crc24_openpgp
    COMMAND ./test_crc24_openpgp
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
