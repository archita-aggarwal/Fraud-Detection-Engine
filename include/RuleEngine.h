#ifndef RULEENGINE_H
#define RULEENGINE_H

#include <vector>
#include <string>
#include <unordered_set>

#include "Transaction.h"
#include "UserProfile.h"

class RuleEngine
{
private:
    std::unordered_set<std::string> blacklistedMerchants;

public:

    RuleEngine();

    bool highAmountRule(const Transaction& t);

    bool blacklistedMerchantRule(const Transaction& t);

    bool nightTransactionRule(const Transaction& t);

    bool velocityRule(
        const Transaction& current,
        const std::vector<Transaction>& history);

    bool impossibleTravelRule(
        const Transaction& current,
        const std::vector<Transaction>& history);

    bool unusualSpendingRule(
        const Transaction& t,
        UserProfile& profile);

    std::vector<std::string> evaluateRules(
        const Transaction& current,
        const std::vector<Transaction>& history,
        UserProfile& profile);
};

#endif