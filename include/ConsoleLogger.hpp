
#ifndef LOGGER_CONSOLELOGGER_HPP
#define LOGGER_CONSOLELOGGER_HPP

#include <iostream>

#include "Logger.hpp"

class ConsoleLogger : public Logger {
public:
    void log(const std::string &msg) override {
        std::cout << msg;
    }
};


#endif //LOGGER_CONSOLELOGGER_HPP