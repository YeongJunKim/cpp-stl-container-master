#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <iostream>
#include <memory>

template <class hardware_>
class Motor
{
public:
    Motor();
    ~Motor();

private:
    std::shared_ptr<hardware_> hardware;

public:
    hardware_ getHardware() { return hardware; }
};

#endif // __MOTOR_H__