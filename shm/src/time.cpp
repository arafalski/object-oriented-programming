#include "time.hpp"

#include <algorithm>

constexpr size_t time = 0;

Time::Time()
    : timeElapsed_(time) {
}

void Time::addObserver(Observer* obs) {
    observers_.push_back(obs);
}

void Time::removeObserver(Observer* obs) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), vec.end());
}

size_t Time::getElapsedTime() const {
    return timeElapsed_;
}

Time& Time::operator++() {
    timeElapsed_++;
    return *this;
}