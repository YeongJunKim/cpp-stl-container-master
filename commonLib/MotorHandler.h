#ifndef __MOTORHANDLER_H__
#define __MOTORHANDLER_H__

#include <Motor.h>
#include <Hardware.h>

namespace application
{
    typedef Motor<Hardware> MotorHandle;
}

#endif // __MOTORHANDLER_H__