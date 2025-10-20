
#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include <string>

class Logger {
public:
    virtual void log(const std::string &msg) = 0;

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Logger() = default;
};


#endif //LOGGER_LOGGER_HPP