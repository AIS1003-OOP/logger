#ifndef LOGGER_LOGGERLISTENER_HPP
#define LOGGER_LOGGERLISTENER_HPP

#include "SimulationListener.hpp"
#include "Simulation.hpp"
#include "Logger.hpp"

#include <memory>

class LoggerListener : public SimulationListener {
public:
    explicit LoggerListener(std::unique_ptr<Logger> logger)
        : logger_(std::move(logger)) {
    }

    void onStep(const Simulation &sim) override {
        if (logger_) {
            logger_->log("Simulation time: " + std::to_string(sim.getTime()) + "\n");
        }
    }

private:
    std::unique_ptr<Logger> logger_;
};

#endif //LOGGER_LOGGERLISTENER_HPP
