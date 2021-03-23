#include <vector>
#include <iostream>

#include <MotorHandler.h>

#include <time.h>
#include <unistd.h>

    uint64_t getTick(void)
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (uint64_t)(ts.tv_nsec / 1000000) + ((uint64_t)ts.tv_sec * 1000ull);
    }

// 싱글톤 디자인
// Motor.h: 메인 알고리즘
// Hardware.h: 하드웨어 구현체

application::MotorHandle handler;

int main()
{
    handler.spinOnce();
}  