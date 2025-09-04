cmake_minimum_required(VERSION 3.15)
project(raytracer4d VERSION 0.1)

add_executable(raytracer4d main.cc src/vec3.cc src/vec4.cc src/ObjectWorld.cc src/Object4D.cc src/Hypersphere.cc)
