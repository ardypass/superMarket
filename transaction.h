#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
private:
    int id;
    int number;
    string date, itemsId;
    double price;
    bool deleted;
public:
    int getId() const {
        return id;
    }

    void setId(int id) {
        Transaction::id = id;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        Transaction::number = number;
    }

    string getDate() const {
        return date;
    }

    void setDate(string date) {
        Transaction::date = date;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Transaction::price = price;
    }

    const string &getItemsId() const {
        return itemsId;
    }

    void setItemsId(const string &itemsId) {
        Transaction::itemsId = itemsId;
    }

    bool isDeleted() const {
        return deleted;
    }

    void setDeleted(bool deleted) {
        Transaction::deleted = deleted;
    }
};

#endif