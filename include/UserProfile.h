#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <unordered_map>
#include <string>

class UserProfile
{
private:
    std::unordered_map<std::string,double> averageAmount;
    std::unordered_map<std::string,int> transactionCount;

public:

    void updateProfile(std::string user,double amount);

    double getAverageAmount(std::string user);

    bool isUnusualTransaction(std::string user,double amount);
};

#endif