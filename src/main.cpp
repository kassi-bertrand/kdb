/*
 * @Author(s):      Kassi Bertrand
 * @filename:       main.cpp
 * @date:           08-21-2022
 * @description:    The program entry point
 */

#include <iostream>
#include <unistd.h>
#include <sys/ptrace.h>
#include <string>

#include "debugger.h"


void execute_target(const std::string& prog_name){
    if(ptrace(PTRACE_TRACEME, 0, 0, 0) < 0){
        std::cerr << "Error in ptrace\n";
        return;
    }
    execl(prog_name.c_str(), prog_name.c_str(), nullptr);
}

int main(int argc, char* argv[]){
    if(argc < 2){
        std::cerr << "Program name not specified";
        return -1;
    }
    auto program = argv[1];

    auto pid = fork();
    if(pid == 0){
        //child process
        //run target program
        execute_target(program);
    }
    else if(pid >= 1){
        //parent process
        std::cout << "Started debugging process" << pid << '\n';
        kdb::Debugger dbg {program, pid};
        dbg.run();
    }
}