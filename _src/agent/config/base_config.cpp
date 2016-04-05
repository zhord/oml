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
#ifdef OML_LOG
    std::cout << "base_config::load_from_raw_buffer( " << buffer.c_str() << " )" << std::endl;
#endif

    return true;
}
