#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    int id;
    int number;
    string name;
    string type;
    string dateAdded;
    double price;
    bool deleted;

public:
    int getId() const {
        return id;
    }

    void setId(int id) {
        Item::id = id;
    }

    const string &getName() const {
        return name;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        Item::number = number;
    }

    void setName(const string &name) {
        Item::name = name;
    }

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        Item::type = type;
    }

    const string &getDateAdded() const {
        return dateAdded;
    }

    void setDateAdded(const string &dateAdded) {
        Item::dateAdded = dateAdded;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Item::price = price;
    }

    bool isDeleted() const {
        return deleted;
    }

    void setIsDeleted(bool deleted) {
        Item::deleted = deleted;
    }

    Item(){
        deleted = false;
    }
};

#endif