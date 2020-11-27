# Convolution Operation

A comparison of performance of GPU and CPU using the convolution operation

## CPU

Install `g++` and run

`g++ -o kernel.o kernel.cpp`

`./kernel.o`

# GPU

Make sure you have CuDA computation toolkit installed. If you don't have an Nvidia GPU, this code will not run on your system, so don't bother and look for an OpenCL implementation of this version.

Run `nvcc --version` from the command line to check if you have `nvcc` installed which is the Nvidia CuDA Compiler

Run the code using the following

`nvcc -o kernel.o kernel.cu`

`./kernel.o`
