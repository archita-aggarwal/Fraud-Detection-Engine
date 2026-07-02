#include "D:/archita/CODES/FraudDetectionEngine/include/UserProfile.h"

using namespace std;

void UserProfile::updateProfile(string user,double amount)
{
    averageAmount[user] =
        (averageAmount[user] *
        transactionCount[user] + amount)
        /(transactionCount[user]+1);

    transactionCount[user]++;
}

double UserProfile::getAverageAmount(string user)
{
    return averageAmount[user];
}

bool UserProfile::isUnusualTransaction(
        string user,double amount)
{
    if(transactionCount[user]<5)
        return false;

    return amount > averageAmount[user]*3;
}