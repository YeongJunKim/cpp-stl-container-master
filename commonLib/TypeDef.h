#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

#include <iostream>
#include <memory>
#include <array>
#include <Pid.h>

namespace application
{
struct MotorComponent
{
    uint32_t id;
    Pid<long> pid;
};

struct MotorTask
{
    uint16_t cmd;
    uint16_t length;
    uint8_t *data;
    uint8_t checkSum;
    std::shared_ptr<uint8_t> sptr;
};

using qData = uint8_t;
}



#endif // __TYPEDEF_H__