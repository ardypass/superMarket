#include <iostream>
#include <string>
#include "item.h"
#include "tools.h"

using namespace std;

class ItemOps {
private:
    Tools tools;
public:
    //TODO: check input type mismatch
    void add() {
        int number;
        string name, date, type;
        double price;
        Item item;

        cout << "Item No.: ";
        cin >> number;
        item.setNumber(number);

        cout << "Name of the item: ";
        cin >> name;
        item.setName(name);

        cout << "Manufacturing Date(yyyy-mm-dd): ";
        cin >> date;
        item.setDateAdded(date);

        cout << "Enter type of the item: ";
        cin >> type;
        item.setType(type);

        cout << "Price: ";
        cin >> price;
        item.setPrice(price);

        tools.writeToFile(item);
    }

    void edit() {}

    void remove() {
        int number;
        cout << "Enter number of the item to remove: ";
        cin >> number;
    }
};
