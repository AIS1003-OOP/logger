
#ifndef LOGGER_SIMULATIONLISTENER_HPP
#define LOGGER_SIMULATIONLISTENER_HPP

class Simulation;

class SimulationListener {

public:
    virtual void onStep(const Simulation& sim) = 0;

    virtual ~SimulationListener() = default;
};


#endif //LOGGER_SIMULATIONLISTENER_HPP