#include "stdafx.h"
#include "file_utils.h"


std::string LoadWholeFile(const std::string& path)
{
    std::string file_content;

    std::ifstream in_file(path, std::ios::in|std::ios::binary);
    if (in_file)
    {
        in_file.seekg(0, std::ios::end);
        file_content.resize(static_cast<size_t>(in_file.tellg()));
        in_file.seekg(0, std::ios::beg);
        in_file.read(&file_content[0], file_content.size());
        in_file.close();
    }

    return file_content;
}