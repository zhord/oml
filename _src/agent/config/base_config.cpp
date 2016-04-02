#include "stdafx.h"
#include "base_config.h"


base_config& base_config::get_instance()
{
    static base_config instance;
    return instance;
}


base_config::base_config()
    : is_loaded_(false)
{}

base_config::~base_config()
{}


bool base_config::load_from_file(const std::wstring& path)
{
    // TODO(zhord):
    // 1. check if file exists or not
    // 2. 

    return is_loaded_;
}
