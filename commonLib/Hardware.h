#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <iostream>
#include <memory>
#include <queue>

#include <TypeDef.h>

namespace application
{
    enum class enumTask
    {
        start = 0, begin, cmd1, cmd2, length1, length2, data, end
    };

    class Hardware
    {
    public:
        Hardware(/* args */){}
        ~Hardware(){}
        void printHello()
        {
            std::cout << "Hello" << std::endl;
        }
        
    private:
        MotorTask taskOne_;
        uint16_t dataCount_;
        enumTask state_ = enumTask::start;

    public:
        std::queue<qData> dataQueue_; 
        std::queue<MotorTask> taskQueue_;
        void writeByte(qData data);
        bool readByte(qData &data);

        bool taskMachine();
    };
}
#endif // __HARDWARE_H__