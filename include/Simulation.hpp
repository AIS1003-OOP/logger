#ifndef LOGGER_SIMULATION_HPP
#define LOGGER_SIMULATION_HPP

#include <memory>
#include <vector>

#include "SimulationListener.hpp"


class Simulation {
public:
    void step(double dt) {
        for (const auto &listener: listeners_) {
            listener->onStep(*this);
        }

        time_ += dt;
    }

    void add_listener(std::unique_ptr<SimulationListener> listener) {
        listeners_.emplace_back(std::move(listener));
    }

    double getTime() const {
        return time_;
    }

private:
    double time_{0};
    std::vector<std::unique_ptr<SimulationListener> > listeners_;
};


#endif //LOGGER_SIMULATION_HPP
