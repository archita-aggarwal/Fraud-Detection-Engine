#include "D:/archita/CODES/FraudDetectionEngine./include/RiskCalculator.h"

using namespace std;

int RiskCalculator::calculateRiskScore(
        const vector<string>& reasons)
{

    int score = 0;

    for(auto &r : reasons)
    {
        // if(unusualSpendingRule(current,profile))
        //     reasons.push_back("Unusual Spending");
        
        if(r=="High Amount")
            score+=30;

        else if(r=="Blacklisted Merchant")
            score+=40;

        else if(r=="Night Transaction")
            score+=15;

        else if(r=="Too Many Transactions")
            score+=25;
        
        else if(r=="Unusual Spending")
            score+=20;
    }

    if(score>100)
        score=100;

    return score;
}