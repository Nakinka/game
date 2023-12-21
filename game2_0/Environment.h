#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <string>

using namespace std;

class Environment {
private:
    string m_weather;
    string m_timeOfDay;

public:
    Environment(const string&, const string&);
    virtual ~Environment();

    string getWeather() const;
    string getTimeOfDay() const;

    void changeWeather(const string&);
    void changeTimeOfDay(const string&);

};

#endif
