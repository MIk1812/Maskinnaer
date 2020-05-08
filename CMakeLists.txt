cmake_minimum_required(VERSION 3.15)
project(projekt2 C)

set(CMAKE_C_STANDARD 99)

add_executable(projekt2 main.c Opcodes/STI.h Pseudo-Ops/FILL.h Pseudo-Ops/BLKW.h)