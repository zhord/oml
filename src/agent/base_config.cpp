#include "agent.h"
#include "base_config.h"


BaseConfig& BaseConfig::GetInstance()
{
    static BaseConfig instance;
    return instance;
}


BaseConfig::BaseConfig()
{}

BaseConfig::~BaseConfig()
{}


bool BaseConfig::LoadFromFile(const std::string& path)
{
    std::string buffer = utils::load_whole_file(path);
    return LoadFromRawBuffer(buffer);
}

bool BaseConfig::LoadFromRawBuffer(const std::string& buffer)
{
    auto buffer_tokens = utils::get_string_tokens(buffer, " ,\r\n");
    for (auto url : buffer_tokens)
    {
        bool is_http  = (url.find("http://")  != std::string::npos);
        bool is_https = (url.find("https://") != std::string::npos);

        if (!is_http && !is_https)
        {
            url.insert(0, "http://");
            is_http = true;
        }

        mSourceSites.insert({ url, is_https, true });
    }

    return true;
}
