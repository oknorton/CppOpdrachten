#include <iostream>
#include <algorithm>
#include <vector>

#include "StopWatch.h"

int main() {
    std::vector<int> numbers(100000);
    for (int i = 0; i < 100000; ++i) {
        numbers[i] = rand();
    }

    StopWatch stopwatch;

    stopwatch.start();

    std::sort(numbers.begin(), numbers.end());

    stopwatch.stop();

    long long elapsedTime = stopwatch.getElapsedTime();

    std::cout << "Sorting time: " << elapsedTime << " milliseconds." << std::endl;

    return 0;
}
