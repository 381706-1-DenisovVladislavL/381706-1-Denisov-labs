file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolynomTest} ${srcs} ${hdrs})
target_link_libraries(${PolynomTest} ${PolynomLib} gtest)
