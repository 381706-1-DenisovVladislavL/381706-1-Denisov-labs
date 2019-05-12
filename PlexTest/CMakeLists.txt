file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PlexTest} ${srcs} ${hdrs})
target_link_libraries(${PlexTest} ${PlexLib} gtest)
