#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <iostream>
#include <memory>
#include <vector>
#include <TypeDef.h>
#include <algorithm>

namespace application
{
template <class Hardware>
class Motor
{
public:
    Motor() {}
    ~Motor() {}

private:
    Hardware hardware_;
    std::vector<MotorComponent> motorComponents_;
    
public:
    std::shared_ptr<Hardware> getHardware() { return std::make_shared<Hardware>(hardware_); }

    void spinOnce()
    {
        if(hardware_.taskMachine())
        {
            auto task = hardware_.taskQueue_.front();
            
            if(task.cmd == 0x01)
            {
                // add motor
                MotorComponent temp;
                motorComponents_.push_back(temp);
            }
            else if(task.cmd == 0x02)
            {
                // delete motor
                std::for_each(motorComponents_.begin(), motorComponents_.end(), [&](const auto n){
                    // find motor (task.data[?])
                    // delete motor
                    // 
                    if(n.id == task.data[0])
                    {
                        // motorComponents_.erase(n);
                    }
                });
                
            }
            else if(task.cmd == 0x03)
            {
                // 
            }
            // ...
            // ...
            
        }
    }
};
}
#endif // __MOTOR_H__