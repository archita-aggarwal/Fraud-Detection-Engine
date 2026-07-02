#ifndef RISKCALCULATOR_H
#define RISKCALCULATOR_H

#include<vector>
#include<string>

class RiskCalculator
{
public:

    int calculateRiskScore(
        const std::vector<std::string>& reasons);

};

#endif