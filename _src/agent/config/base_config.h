#pragma once

// NOTE(zhaa): for now config file consists of site's urls only.
// Each line of file equals to a single site.

struct source_site
{
    std::string url_;
    bool        is_https_;
    bool        is_valid_;
};

struct source_site_comp_less
{
    bool operator() (const source_site& s1, const source_site& s2) const { return (s1.url_.compare(s2.url_) < 0); }
};

typedef std::set<source_site, source_site_comp_less> config_source_sites_t;


class base_config
{
public:
    static base_config& get_instance();

    bool load_from_file(const std::string& path);
    bool load_from_raw_buffer(const std::string& buffer);

private:
    base_config();
    ~base_config();

    // not copyable
    base_config(const base_config&) = delete;
    base_config& operator= (const base_config&) = delete;

private:
    config_source_sites_t source_sites_;
};
