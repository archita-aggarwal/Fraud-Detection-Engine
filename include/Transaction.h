#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
public:
    int txnID;
    std::string userID;
    std::string time;
    double amount;
    std::string merchant;
    std::string city;
    std::string country;
    std::string cardType;

    Transaction(
        int txnID,
        std::string userID,
        std::string time,
        double amount,
        std::string merchant,
        std::string city,
        std::string country,
        std::string cardType)
    {
        this->txnID = txnID;
        this->userID = userID;
        this->time = time;
        this->amount = amount;
        this->merchant = merchant;
        this->city = city;
        this->country = country;
        this->cardType = cardType;
    }
};

#endif