#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    virtual void log(const std::string &msg) = 0;

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string &msg) override {
        std::cout << msg;
    }
};

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

class Simulation {
public:
    void step(double dt) {
        if (logger_) {
            logger_->log("Simulation time: " + std::to_string(time_) + "\n");
        }

        time_ += dt;
    }

    void setLogger(std::unique_ptr<Logger> logger) {
        logger_ = std::move(logger);
    }

private:
    double time_{0};
    std::unique_ptr<Logger> logger_;
};

int main() {
    FileLogger fileLogger("log.txt");
    ConsoleLogger consoleLogger;

    Logger *logger = &fileLogger;
    FileLogger *file = dynamic_cast<FileLogger *>(logger);

    log(&fileLogger, "Logging to file\n");
    log(&consoleLogger, "Logging to console\n");

    Simulation sim;
    sim.setLogger(std::make_unique<FileLogger>("sim_log.txt"));

    double delta = 0.1;
    bool changedLogger = false;
    for (int i = 0; i < 10; ++i) {

        sim.step(delta);

        if (i > 5 && !changedLogger) {
            sim.setLogger(std::make_unique<ConsoleLogger>());
            changedLogger = true;
        }
    }
}
