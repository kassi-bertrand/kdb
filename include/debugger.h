/*
 * @Author(s):      Kassi Bertrand
 * @filename:       debugger.h
 * @date:           08-21-2022
 * @description:    Declaration of the debugger class within the kdb namespace
 */

#ifndef KASSIDEBUGGER_DEBUGGER_H
#define KASSIDEBUGGER_DEBUGGER_H

#include <utility>
#include <string>
#include <linux/types.h>
#include <sstream>
#include <vector>

namespace kdb{
    class Debugger{
    private:
        void handle_command(const std::string& line);
        void continue_execution();

        /// \param sub              -> Substring
        /// \param str              -> String to match "sub" against
        /// \return boolean         -> True/False
        /// \description            -> Determines whether "str" starts with "sub"
        bool is_prefix(const std::string& sub, const std::string& str);

        /// \param  s               -> String to split
        /// \param  delimiter       -> Delimitation character
        /// \return vector          -> List of tokens extracted from param "s"
        /// \description            -> Splits "s" into a series of tokens based on "delimiter"
        std::vector<std::string> split(const std::string &s, char delimiter);

        //Target program name, and PID
        std::string m_prog_name;
        pid_t m_pid;

    public:
        Debugger(std::string prog_name, pid_t pid) :m_prog_name{std::move(prog_name)}, m_pid{pid} {}
        void run();
    };
}

#endif //KASSIDEBUGGER_DEBUGGER_H
