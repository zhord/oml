#include "stdafx.h"
#include "config/base_config.h"


int main(int argc, char** argv)
{
    base_config& config = base_config::get_instance();
    config.load_from_file(L"oml.cfg");

    return 0;
}
