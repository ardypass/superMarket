#include <iostream>
#include <string>
#include "item.h"
#include "tools.h"
#include "ops.h"

using namespace std;

class ItemOps : public Ops {
private:
    Tools tools;

    Item getFromFileByNumber(int number) {
        Item item;

        fstream fin;
        fin.open(item.getFileName(), ios::in);

        if (fin.fail())
            throw (404);
        string line;
        bool isFound = false;

        while (getline(fin, line)) {
            stringstream st(line);
            string rowNumber, id;
            getline(st, id, ',');
            getline(st, rowNumber, ',');
            try {
                if (stoi(rowNumber) == number) {
                    item.setId(stoi(id));
                    item.setNumber(number);

                    string temp;
                    getline(st, temp, ',');
                    item.setName(temp);

                    temp = "";
                    getline(st, temp, ',');
                    item.setType(temp);

                    temp = "";
                    getline(st, temp, ',');
                    item.setDateAdded(temp);

                    temp = "";
                    getline(st, temp, ',');
                    item.setPrice(stod(temp));

                    isFound = true;
                    break;
                }
            } catch (int e) {
                throw (500);
            }
        }
        if (!isFound)
            throw (204);
        return item;
    }

public:
    void add() {
        int number;
        string name, date, type;
        double price;
        Item item;
        string temp;

        cout << "Item No.: ";
        cin >> temp;
        number = stoi(temp);
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
        cin >> temp;
        price = stod(temp);
        item.setPrice(price);

        tools.writeToFile(item);
    }

    void edit() {
        printf("\tPlease Enter Item Number to Edit\n");
        printf("\tEnter 0 to Back to Main Menu\n");

        string input;
        cin >> input;

        if (input != "0") {
            int itemNum = tools.checkMenuInput(input);

            Item item = getFromFileByNumber(itemNum);
            tools.removeData(&item);
            add();
        }
    }

    void remove() {
        printf("\tPlease Enter Item Number to Remove\n");
        printf("\tEnter 0 to Back to Main Menu\n");

        string input;
        cin >> input;

        if (input != "0") {
            int itemNum = tools.checkMenuInput(input);

            Item item = getFromFileByNumber(itemNum);
            tools.removeData(&item);
        }
    }

    void showDetails() {
        int number;
        cout << "Please Enter Item Number: ";
        cin >> number;

        Item item = getFromFileByNumber(number);
        cout << "Item No.: " << item.getNumber() << endl
             << "Name: " << item.getNumber() << endl
             << "Type: " << item.getType() << endl
             << "Manufacturing Date: " << item.getDateAdded() << endl
             << "Price: " << item.getPrice() << endl;
    }
};
