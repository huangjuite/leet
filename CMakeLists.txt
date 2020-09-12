cmake_minimum_required(VERSION 3.0.0)
project(leet VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

add_executable(reverse_interger algorithm/reverse_integer.cpp)
add_executable(two_sum algorithm/two_sum.cpp)
add_executable(add_two_numbers algorithm/add_two_numbers.cpp)
add_executable(longestSubstringWithoutRepeatingCharacters algorithm/longestSubstringWithoutRepeatingCharacters.cpp)
add_executable(MedianofTwoSortedArrays algorithm/MedianofTwoSortedArrays.cpp)
add_executable(LongestPalindromicSubstring algorithm/LongestPalindromicSubstring.cpp)
add_executable(ZigZagConversion algorithm/ZigZagConversion.cpp)
add_executable(935_knight_dialer algorithm/935_knight_dialer.cpp)
add_executable(821 algorithm/821.cpp)
add_executable(1510 algorithm/1510.cpp)
add_executable(1417 algorithm/1417.cpp)
add_executable(433 algorithm/433.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
