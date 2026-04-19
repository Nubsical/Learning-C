# Learning-C
Working through K&amp;R The C Programming Language as foundation for embedded systems (drone) and GPU programming (CUDA) work.

## Why C
C is the core of almost everything I'm building. This repo is my work through Kernighan & Ritchie's The C Programming Language (2nd edition), the entire book including the exercises, as the main foundation for two larger projects:
that being the drone/autonomous systems work. My autonomous quad runs ArduPilot, which is written in C and C++. The flight controller firmware, implementations of MAVLink protocol, and any low-level sensor or actuator code I'll write or modify for autonomous landing and target tracking sit in the C/C++ layer. Embedded work broadly — microcontrollers, RTOS code, driver interfaces — is C-first.
GPU programming/CUDA. CUDA is essentially a C/C++ model with parallel execution extensions. Before I can really write efficient GPU kernels for drone perception (AprilTag detection, image preprocessing, eventually neural network inference on Jetson Orin Nano), I need fluency in the memory model, pointer arithmetic, and manual memory management that C forces an understanding of. CUDA's performance is, from what I understand, entirely about memory hierarchy. Thus, learning this in C first is the right order.
Systems and architecture foundations. ECE 220 (Computer Systems & Programming) at UIUC is taught in C. ECE 391 (Computer Systems Engineering — kernel writing), ECE 411 (Computer Organization & Design), and embedded systems courses all assume C fluency. Getting ahead of this over the summer reduces the load during the academic year and hopefully enhances my understanding of future concepts.

## What's in this repo

chapter-X/examples/ — code typed from the book, compiled and run
chapter-X/exercises/ — my solutions to exercises
notes.md — running log of concepts that clicked, things that messed me up, and connections to the drone/CUDA work

## Build
All exercises are single-file C programs. Compile with:
bashgcc -Wall -Wextra -g -std=c99 filename.c -o out && ./out
Progress

