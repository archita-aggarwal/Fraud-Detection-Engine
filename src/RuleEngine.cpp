#include <iostream>
#include "D:/archita/CODES/FraudDetectionEngine/include/CSVReader.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/RuleEngine.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/RiskCalculator.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/DecisionEngine.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/TimeUtils.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/BlacklistLoader.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/ReportGenerator.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/UserProfile.h"

#include <sstream>

using namespace std;


// RuleEngine::RuleEngine()
// {
//     blacklistedMerchants.insert("Crypto Exchange");
//     blacklistedMerchants.insert("DarkMarket");
//     blacklistedMerchants.insert("Fake Store");
// }

bool RuleEngine::highAmountRule(const Transaction& t)
{
    return t.amount > 100000;
}

bool RuleEngine::blacklistedMerchantRule(const Transaction& t)
{
    return blacklistedMerchants.count(t.merchant);
}

bool RuleEngine::nightTransactionRule(const Transaction& t)
{
    int hour = stoi(t.time.substr(0,2));

    return (hour>=0 && hour<=5);
}

bool RuleEngine::velocityRule(
    const Transaction& current,
    const vector<Transaction>& history)
{
    int count = 0;

    int currentTime =
        TimeUtils::toMinutes(current.time);

    for(const auto &t : history)
    {
        if(t.userID != current.userID)
            continue;

        int oldTime =
            TimeUtils::toMinutes(t.time);

        if(currentTime - oldTime <= 1 &&
           currentTime - oldTime >= 0)
        {
            count++;
        }
    }

    return count >= 4;
}

vector<string> RuleEngine::evaluateRules(
    const Transaction& current,
    const vector<Transaction>& history,
UserProfile& profile)
{
    vector<string> reasons;

    if(highAmountRule(current))
        reasons.push_back("High Amount");

    if(blacklistedMerchantRule(current))
        reasons.push_back("Blacklisted Merchant");

    if(nightTransactionRule(current))
        reasons.push_back("Night Transaction");

    if(velocityRule(current,history))
        reasons.push_back("Too Many Transactions");

    if(impossibleTravelRule(current,history))
        reasons.push_back("Impossible Travel");

    if(unusualSpendingRule(current,profile))
    reasons.push_back("Unusual Spending");
    
    return reasons;
}

RuleEngine::RuleEngine()
{
    blacklistedMerchants =
        BlacklistLoader::loadMerchants(
            "D:/archita/CODES/FraudDetectionEngine/data/blacklist.csv");
}

bool RuleEngine::impossibleTravelRule(
        const Transaction& current,
        const vector<Transaction>& history)
{
    int currentTime =
        TimeUtils::toMinutes(current.time);

    for(const auto &t : history)
    {
        if(t.userID!=current.userID)
            continue;

        int oldTime =
            TimeUtils::toMinutes(t.time);

        if(current.country!=t.country &&
            currentTime-oldTime<=30 &&
            currentTime-oldTime>=0)
        {
            return true;
        }
    }

    return false;
}

bool RuleEngine::unusualSpendingRule(
        const Transaction& t,
        UserProfile& profile)
{   
    return profile.isUnusualTransaction(
            t.userID,
            t.amount);
}