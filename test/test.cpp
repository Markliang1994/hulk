//
// Created by mark on 11/16/16.
//

#include "schedule.h"

#include <functional>
#include <stdio.h>
#include <iostream>

using namespace coroutine;

void func(Schedule* schedule, int base) {
    for (int i = 0; i < 5; ++i) {
        printf("running id = %d, num = %d\n", schedule->getRunningCoroutineId(), base + i);
        schedule->suspendCurrentCoroutine();
    }
}

int main(int argc, char* argv[]) {
    Schedule schedule;
    int coroutine1 = schedule.createCoroutine(std::bind(func, std::placeholders::_1, 1));
    int coroutine2 = schedule.createCoroutine(std::bind(func, std::placeholders::_1, 1000));
    for(int i=0; i<5; i++) {
        schedule.runCoroutineById(coroutine1);
        std::cout << "coroutine1 status: " << schedule.getCoroutineStateById(coroutine1) << std::endl;
        schedule.runCoroutineById(coroutine2);
        std::cout << "coroutine2 status: " << schedule.getCoroutineStateById(coroutine2) << std::endl;
    }
    return 0;
}
