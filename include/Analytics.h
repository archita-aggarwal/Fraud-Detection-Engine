#ifndef ANALYTICS_H
#define ANALYTICS_H

#include<vector>
#include<string>
#include "Transaction.h"

class Analytics
{
public:

    void generateSummary(
        const std::vector<Transaction>& txns,
        const std::vector<int>& scores,
        const std::vector<std::string>& decisions);

};

#endif