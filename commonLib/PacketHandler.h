#ifndef __PACKETHANDLER_H__
#define __PACKETHANDLER_H__

#include <iostream>
#include <queue>
#include <TypeDef.h>
#include <algorithm>

namespace application
{

enum class enumTask
{
    start = 0, begin, cmd1, cmd2, length1, length2, data, end
};

class PacketHandler
{
private:
    std::queue<qData> dataQueue_; 
    std::queue<MotorTask> taskQueue_;
    enumTask state_ = enumTask::start;
public:
    PacketHandler(/* args */);
    ~PacketHandler();

    void writeByte(qData data);
    bool readByte(qData &data);

    bool taskMachine();
};
}

#endif // __PACKETHANDLER_H__