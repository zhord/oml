#include "stdafx.h"
#include "base_config.h"
#include "common/file_utils.h"


base_config& base_config::get_instance()
{
    static base_config instance;
    return instance;
}


base_config::base_config()
{}

base_config::~base_config()
{}


bool base_config::load_from_file(const std::string& path)
{
    std::string raw_buffer = LoadWholeFile(path);
    return load_from_raw_buffer(raw_buffer);
}

bool base_config::load_from_raw_buffer(const std::string& buffer)
{
    auto buffer_tokens = GetStringTokens(buffer, " ,\r\n");
    for (auto url : buffer_tokens)
    {
        bool is_http  = (url.find("http://")  != std::string::npos);
        bool is_https = (url.find("https://") != std::string::npos);

        if (!is_http && !is_https)
        {
            url.insert(0, "http://");
            is_http = true;
        }

        source_sites_.insert({ url, is_https, true });
    }

    return true;
}
