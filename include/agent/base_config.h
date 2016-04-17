#pragma once

// NOTE(zhord): for now config file consists of site's urls only.
// Each line of file equals to a single site.

struct SourceSite
{
    std::string Url;
    bool        IsHttps;
    bool        IsValid;
};

struct SourceSiteCompLess
{
    bool operator() (const SourceSite& s1, const SourceSite& s2) const { return (s1.Url.compare(s2.Url) < 0); }
};

typedef std::set<SourceSite, SourceSiteCompLess> config_source_sites_t;


class BaseConfig
{
public:
    static BaseConfig& GetInstance();
    
    bool LoadFromFile(const std::string& path);
    bool LoadFromRawBuffer(const std::string& buffer);

private:
    BaseConfig();
    ~BaseConfig();

    // not copyable
    BaseConfig(const BaseConfig&) = delete;
    BaseConfig& operator= (const BaseConfig&) = delete;

private:
    config_source_sites_t mSourceSites;
};
