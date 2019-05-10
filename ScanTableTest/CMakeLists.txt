file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ScanTableTest} ${srcs} ${hdrs})
target_link_libraries(${ScanTableTest} ${ScanTableLib} gtest)
