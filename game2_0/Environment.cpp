#include "pch.h"
#include "Environment.h"

Environment::Environment(const string& weather, const string& timeOfDay) :
	m_weather(weather), m_timeOfDay(timeOfDay) {}

Environment::~Environment() {}

string Environment::getWeather() const {
	return m_weather;
}

string Environment::getTimeOfDay() const {
	return m_timeOfDay;
}

void Environment::changeWeather(const string& newWeather) {
	m_weather = newWeather;
}

void Environment::changeTimeOfDay(const string& newTimeOfDay) {
	m_timeOfDay = newTimeOfDay;
}
