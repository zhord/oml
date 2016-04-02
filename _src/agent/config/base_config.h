#pragma once


class base_config
{
public:
    static base_config& get_instance();

    bool load_from_file(const std::wstring& path);

private:
    base_config();
    ~base_config();

    // not copyable
    base_config(const base_config&) = delete;
    base_config& operator= (const base_config&) = delete;

private:
    bool is_loaded_;

};
