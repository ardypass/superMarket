#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

using namespace std;

class Transaction {
private:
    int id;
    int date;
    vector<Item *> items[1000];
public:
    int getId() const {
        return id;
    }

    void setId(int id) {
        Transaction::id = id;
    }

    int getDate() const {
        return date;
    }

    void setDate(int date) {
        Transaction::date = date;
    }

    const vector<Item *> *getItems() const {
        return items;
    }

    void setItems(vector<Item *> *items) {
        items = Transaction::items;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Transaction::price = price;
    }

private:
    double price;
};

#endif