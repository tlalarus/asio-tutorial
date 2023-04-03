set(BIN_NAME ${PROJECT_NAME}-timer2)

message("${BIN_NAME} configuration...")
add_executable(${BIN_NAME} main.cpp)
target_link_libraries(${BIN_NAME} ${Boost_LIBRARIES} pthread)
target_include_directories(${BIN_NAME} PUBLIC ${Boost_INCLUDE_DIR})