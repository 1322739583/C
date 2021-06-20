cmake_minimum_required(VERSION 3.17)
project(C)

set(CMAKE_CXX_STANDARD 14)



add_executable(time basic/time/time.c)
add_executable(signal basic/signal/signal.c)
add_executable(typedef basic/def/typedef.c)
 add_executable(define_1 basic/def/define_1.c)
 
 
add_executable(define_placeholder basic/def/define_placeholder.c)
add_executable(define_value_name basic/def/define_value_name.c)
add_executable(define_mutil_type basic/def/define_mutil_type.cpp)
add_executable(undef basic/def/undef.c)
add_executable(condition_def basic/def/condition_def.c)
add_executable(point_expr basic/point/point_expr.c)
add_executable(point_border basic/point/point_border.c)
 
add_executable(string_test basic/char/ch_and_string.c)
add_executable(test_char basic/char/test_char.c)
add_executable(printf_scanf basic/io/printf_scanf.cpp)