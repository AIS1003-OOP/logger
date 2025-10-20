
#include "Simulation.hpp"
#include "LoggerListener.hpp"

#include "FileLogger.hpp"
#include "ConsoleLogger.hpp"


int main() {

    Simulation sim;

    auto logger = std::make_unique<ConsoleLogger>();
    auto listener = std::make_unique<LoggerListener>(std::move(logger));
    sim.add_listener(std::move(listener));

    double delta = 0.1;
    for (int i = 0; i < 10; ++i) {

        sim.step(delta);
    }
}
