#include "agent.h"
#include "base_config.h"


int main(int argc, char** argv)
{
    BaseConfig& config = BaseConfig::GetInstance();
    config.LoadFromFile("R:\\oml.cfg");
    
    return 0;
}
