cmake_minimum_required(VERSION 3.21)
project(BST)

set(CMAKE_CXX_STANDARD 14)

add_executable(BST main.cpp BSTNode.cpp BSTNode.h BST.cpp BST.h)
