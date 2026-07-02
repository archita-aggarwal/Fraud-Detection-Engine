#include "D:/archita/CODES/FraudDetectionEngine/include/Analytics.h"

#include <iostream>
#include <unordered_map>

using namespace std;

void Analytics::generateSummary(

        const vector<Transaction>& txns,

        const vector<int>& scores,

        const vector<string>& decisions)
{
    int fraud=0;

    unordered_map<string,int> userFraud;

    unordered_map<string,int> merchantFraud;

    for(size_t i=0;i<txns.size();i++)
    {
        if(decisions[i]=="REJECTED")
        {
            fraud++;

            userFraud[txns[i].userID]++;

            merchantFraud[txns[i].merchant]++;
        }
    }

    cout<<"============================\n";

    cout<<"Fraud Dashboard\n";

    cout<<"============================\n";

    cout<<"Total Transactions : "
        <<txns.size()<<endl;

    cout<<"Fraud Detected : "
        <<fraud<<endl;

    cout<<"Fraud Rate : "
        <<(100.0*fraud/txns.size())
        <<" %"<<endl;

    cout<<"\nTop Risky Users\n";

    for(auto &x:userFraud)
        cout<<x.first<<" -> "<<x.second<<endl;

    cout<<"\nTop Risky Merchants\n";

    for(auto &x:merchantFraud)
        cout<<x.first<<" -> "<<x.second<<endl;
}