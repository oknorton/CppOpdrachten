#include "StopWatch.h"

StopWatch::StopWatch() {
    startTime = std::chrono::steady_clock::now();
    endTime = startTime;
}

void StopWatch::start() {
    startTime = std::chrono::steady_clock::now();
}

void StopWatch::stop() {
    endTime = std::chrono::steady_clock::now();
}

long long StopWatch::getElapsedTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}
