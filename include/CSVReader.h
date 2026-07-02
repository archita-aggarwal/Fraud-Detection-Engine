#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>
#include "Transaction.h"

class CSVReader
{
public:
    std::vector<Transaction> readTransactions(std::string filename);
};

#endif