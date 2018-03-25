cmake_minimum_required(VERSION 2.8.4)

project(RayTracer)

set(CMAKE_CXX_STANDARD 11)

add_executable(RayTracer main.cpp vec3.h ray.h hitable.h sphere.h hitable_list.h camera.h material.h lambertian.h metal.h)