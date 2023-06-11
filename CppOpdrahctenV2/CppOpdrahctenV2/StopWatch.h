#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class StopWatch {
private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;

public:
    StopWatch();
    void start();
    void stop();
    long long getElapsedTime();
};

#endif  // STOPWATCH_H
