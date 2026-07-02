#ifndef BLACKLISTLOADER_H
#define BLACKLISTLOADER_H

#include <unordered_set>
#include <string>

class BlacklistLoader
{
public:
    static std::unordered_set<std::string>
    loadMerchants(std::string filename);
};

#endif