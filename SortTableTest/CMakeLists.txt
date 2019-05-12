file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${SortTableTest} ${srcs} ${hdrs})
target_link_libraries(${SortTableTest} ${SortTableLib} gtest)
