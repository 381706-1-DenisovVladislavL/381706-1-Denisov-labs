file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${HashTableTest} ${srcs} ${hdrs})
target_link_libraries(${HashTableTest} ${HashTableLib} gtest)
