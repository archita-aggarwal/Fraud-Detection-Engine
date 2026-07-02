#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include<vector>
#include<string>
#include "Transaction.h"

class ReportGenerator
{
public:

    void generateReport(
        const std::vector<Transaction>& txns,
        const std::vector<int>& scores,
        const std::vector<std::string>& decisions);

};

#endif