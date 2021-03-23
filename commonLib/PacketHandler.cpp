#include <PacketHandler.h>
namespace application
{
    PacketHandler::PacketHandler(/* args */) 
    {
        std::cout << __func__ << std::endl;
    }
    
    
    PacketHandler::~PacketHandler() 
    {
        std::cout << __func__ << std::endl;
    }
    
    void PacketHandler::writeByte(qData data) 
    {
        dataQueue_.push(data);
    }
    
    bool PacketHandler::readByte(qData &data) 
    {
        if(dataQueue_.empty())
            return false;
        data = dataQueue_.front();
        return true;
    }
    
    bool PacketHandler::taskMachine() 
    {
        uint8_t data;
        if(readByte(data))
        {
            switch(state_)
            {
                case enumTask::start:
                    break;
                case enumTask::begin:
                    break;
                case enumTask::cmd1:
                    break;
                case enumTask::cmd2:
                    break;
                case enumTask::length1:
                    break;
                case enumTask::length2:
                    break;
                case enumTask::data:
                    break;
                case enumTask::end:
                    break;
            }   
        }
    }
}