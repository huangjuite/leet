cmake_minimum_required(VERSION 3.0.0)
project(leet VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(reverse_interger algorithm/reverse_integer.cpp)
add_executable(two_sum algorithm/two_sum.cpp)
add_executable(add_two_numbers algorithm/add_two_numbers.cpp)
add_executable(longestSubstringWithoutRepeatingCharacters algorithm/longestSubstringWithoutRepeatingCharacters.cpp)
add_executable(MedianofTwoSortedArrays algorithm/MedianofTwoSortedArrays.cpp)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
