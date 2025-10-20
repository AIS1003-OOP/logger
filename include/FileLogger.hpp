
#ifndef LOGGER_FILELOGGER_HPP
#define LOGGER_FILELOGGER_HPP

#include <fstream>

#include "Logger.hpp"

class FileLogger : public Logger {
public:
    explicit FileLogger(const std::string &fileName)
        : file(fileName) {
    }

    void log(const std::string &msg) override {
        file << msg;
    }

private:
    std::ofstream file;
};

void log(Logger *logger, const std::string &msg) {
    logger->log(msg);
}

#endif //LOGGER_FILELOGGER_HPP