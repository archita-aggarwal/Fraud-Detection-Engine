#include <iostream>
#include "D:/archita/CODES/FraudDetectionEngine/include/CSVReader.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/RuleEngine.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/RiskCalculator.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/DecisionEngine.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/TimeUtils.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/BlacklistLoader.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/ReportGenerator.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/UserProfile.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/Analytics.h"
#include "D:/archita/CODES/FraudDetectionEngine/include/Logger.h"
#include <string>
using namespace std;

int main()
{
    CSVReader reader;
    vector<Transaction> transactions =
        reader.readTransactions("D:/archita/CODES/FraudDetectionEngine/data/transactions.csv");
    // for(auto &t : transactions)
    // {
    //     cout << t.txnID << " "
    //          << t.userID << " "
    //          << t.amount << " "
    //          << t.merchant << endl;
    // }


    RuleEngine engine;
    // vector<Transaction> history;
    // for(auto &t:transactions)
    // {
    //     auto reasons = engine.evaluateRules(t,history);
    //     cout<<"Transaction "<<t.txnID<<endl;
    //     if(reasons.empty())
    //     {
    //         cout<<"Safe"<<endl;
    //     }
    //     else
    //     {
    //         cout<<"Suspicious"<<endl;
    //         for(auto &r:reasons)
    //             cout<<"  -> "<<r<<endl;
    //     }
    //     history.push_back(t);
    //     cout<<endl;
    // }

    RiskCalculator calculator;
    DecisionEngine decision;
    vector<Transaction> history;
    vector<int> scores;
    vector<string> decisions;
    UserProfile profile;
    Analytics dashboard;
    for(auto &t : transactions)
    {
        auto reasons =
            engine.evaluateRules(t,history, profile);
        profile.updateProfile(
    t.userID,
    t.amount);

        int score =
            calculator.calculateRiskScore(reasons);
        string result =
            decision.getDecision(score);
        scores.push_back(score);

        decisions.push_back(result);
        if(result=="REJECTED")
        {
            Logger::log(
    std::string("Txn ") +
    std::to_string(t.txnID) +
    " rejected. User : " +
    t.userID
);
        }
        cout<<"--------------------------------\n";
        cout<<"Txn ID : "<<t.txnID<<endl;
        cout<<"Amount : "<<t.amount<<endl;
        cout<<"Merchant : "<<t.merchant<<endl;
        cout<<"Risk Score : "<<score<<endl;
        cout<<"Decision : "<<result<<endl;
        cout<<"Reasons"<<endl;
        if(reasons.empty())
        {
            cout<<"None"<<endl;
        }
        else
        {
            for(auto &r:reasons)
                cout<<"- "<<r<<endl;
        }
        history.push_back(t);


    }
ReportGenerator report;

report.generateReport(
    transactions,
    scores,
    decisions);

dashboard.generateSummary(
    transactions,
    scores,
    decisions);


    return 0;
}