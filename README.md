# What is kdb?
"Kdb" stands for Kassi-DeBugger. It aims to be a beginner-friendly memory debugger written in C++, for Linux Systems.

# Why Am I doing this? 💡

1. I want the debugger to be my "friend;" **understand** how it works, and integrate it in my workflow. I believe the
best way to understand how a debugger work is to _go through the process of building one_.

2. I no longer want to look at my code and think really hard about how variables are changing over time. It gets
difficult for me when the codebase grows and things becomes too hard to have a bird view of, while making sure
everything has the right values.

3. Print debugging does not scale well. The process of adding log statements, recompiling, and re-running the program
everytime I want to make an experiment is **inefficient**.

4. Provide a better debugging experience. I'd like to build a tool that will **educate** beginners, but will **inform**
more advanced users. This project is just me learning, and if you're skilled, you probably don't need this.

# Dependencies, Tools, or Frameworks 🛠️

- [CMake](https://cmake.org/): To compile the project
- [Linenoise](https://github.com/antirez/linenoise): To handle command line inputs
- [Libelfin](https://github.com/TartanLlama/libelfin/tree/fbreg): To parse debug information

# Goals 🎯

I would like kdb to have the following features:

- Launch, halt, and continue program execution
- Set breakpoints on memory addresses, source code lines, and function entry
- Stepping through the program
- Read and write registers and memory
- Print the current source location
- Print backtrace
- Print values of simple variables
- A TUI

# How to run the project?

1. Clone this repo:
```shell
git clone --recusive https://github.com/kassi-bertrand/kdb
```
2. Get into the project folder
```shell
cd test
```
3. Create a `test` folder and `cd` into it:
```shell
mkdir test && cd test
```
4. Build and compile the project from the `test` folder
```shell
cmake .. && make
```
5. Run the program executable:
```shell
./kdb your_executable
```

# Special thanks 🤝

- ![Sy Brand](https://github.com/TartanLlama) for sharing their knowledge on debugger construction.
