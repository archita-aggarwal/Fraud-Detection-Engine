#include "D:/archita/CODES/FraudDetectionEngine/include/ReportGenerator.h"

#include <fstream>

using namespace std;

void ReportGenerator::generateReport(

    const vector<Transaction>& txns,

    const vector<int>& scores,

    const vector<string>& decisions)
{
    ofstream file("D:/archita/CODES/FraudDetectionEngine/output/fraud_report.csv");

    file<<"TxnID,RiskScore,Decision\n";

    for(size_t i=0;i<txns.size();i++)
    {
        file<<txns[i].txnID<<","
            <<scores[i]<<","
            <<decisions[i]<<endl;
    }

    file.close();
}