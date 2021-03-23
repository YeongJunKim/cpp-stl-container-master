#include <Hardware.h>

namespace application
{
    
    void Hardware::writeByte(qData data) 
    {
        dataQueue_.push(data);
    }
    
    bool Hardware::readByte(qData &data) 
    {
        if(dataQueue_.empty())
            return false;
        data = dataQueue_.front();
        return true;
    }
    
    bool Hardware::taskMachine() 
    {
        uint8_t data;
        if(readByte(data))
        {
            switch(state_)
            {
                case enumTask::start:
                    dataCount_ = 0;
                    taskOne_.checkSum = 0;

                    if(data == 0xFF)
                        state_ = enumTask::begin;
                    else
                        state_ = enumTask::start;
                    break;
                case enumTask::begin:
                    if(data == 0xFF)
                        state_ = enumTask::cmd1;
                    else
                        state_ = enumTask::start;
                    break;
                case enumTask::cmd1:
                    taskOne_.cmd = data;
                    state_ = enumTask::cmd2;
                    break;
                case enumTask::cmd2:
                    taskOne_.cmd &= static_cast<uint16_t>(data) << 8;
                    state_ = enumTask::length1;
                    break;
                case enumTask::length1:
                    taskOne_.length = data;
                    state_ = enumTask::length2;
                    break;
                case enumTask::length2:
                    taskOne_.length &= static_cast<uint16_t>(data) << 8;
                    state_ = enumTask::data;
                    taskOne_.data = new uint8_t[taskOne_.length];
                    // taskOne_.sptr = std::make_shared<uint8_t>(taskOne_.data);
                    // taskOne_.sptr = std::make_shared<uint8_t>(new uint8_t[taskOne_.length],[](uint8_t *p){delete[] p;});
                    break;
                case enumTask::data:
                    if(taskOne_.length == dataCount_++)
                        state_ = enumTask::end;
                    taskOne_.data[dataCount_] = data;
                    taskOne_.checkSum += data;
                    break;
                case enumTask::end:
                    if(taskOne_.checkSum == data){
                        taskQueue_.push(taskOne_);
                        return true;
                    }
                    delete(taskOne_.data);
                    break;
            }   
        }
        return false;
    }
}