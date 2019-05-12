file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${TextTest} ${srcs} ${hdrs})
target_link_libraries(${TextTest} ${TextLib} gtest)
