#include <vector>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <thread>

#include <MotorHandler.h>

uint64_t getTick(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)(ts.tv_nsec / 1000000) + ((uint64_t)ts.tv_sec * 1000ull);
}

// 싱글톤 디자인
// Motor.h: 메인 알고리즘
// Hardware.h: 하드웨어 구현체 (통신, IO)

application::MotorHandle handler;

void th();

int main()
{
    uint64_t nowTick = getTick();
    uint64_t pastTick = nowTick;

    std::thread _th(th);

    while(1)
    {
        nowTick = getTick();
        if(nowTick - pastTick > 1000)
        {
            handler.spinOnce();
            handler.getHardware()->printHello();
            pastTick = nowTick;
        }
    }
}  

void th()
{
    uint64_t nowTick = getTick();
    uint64_t pastTick = nowTick;
    
    while(1){
        nowTick = getTick();
        
        if(nowTick - pastTick > 100)
        {
            std::array<uint8_t, 8> sendData;
            sendData.at(0) = 0xFF;
            sendData.at(1) = 0xFF;
            sendData.at(2) = 0x00;
            sendData.at(3) = 0x01;
            sendData.at(4) = 0x0F;
            sendData.at(5) = 0x0F;
            
            for(int i = 0; i < sendData.size(); i++)
                handler.getHardware()->readByte(sendData[i]);

            pastTick = nowTick;
        }
    }
}