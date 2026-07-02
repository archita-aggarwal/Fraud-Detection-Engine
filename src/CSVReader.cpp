#include "D:/archita/CODES/FraudDetectionEngine/include/CSVReader.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Transaction> CSVReader::readTransactions(string filename)
{
    vector<Transaction> transactions;

    ifstream file(filename);

    string line;

    getline(file, line);   // Skip Header

    while(getline(file,line))
    {
        stringstream ss(line);

        string txnID,userID,time,amount,merchant,city,country,cardType;

        getline(ss,txnID,',');
        getline(ss,userID,',');
        getline(ss,time,',');
        getline(ss,amount,',');
        getline(ss,merchant,',');
        getline(ss,city,',');
        getline(ss,country,',');
        getline(ss,cardType,',');

        Transaction t(
            stoi(txnID),
            userID,
            time,
            stod(amount),
            merchant,
            city,
            country,
            cardType
        );

        transactions.push_back(t);
    }

    return transactions;
}