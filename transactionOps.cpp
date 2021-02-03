#include <string>
#include <iostream>
#include "transaction.h"
#include "ops.h"

class TransactionOps : public Ops {
private:
    Tools tools;

    Transaction getFromFileByNumber(int number) {
        Transaction transaction;

        fstream fin;
        fin.open(transaction.getFileName(), ios::in);

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
                    transaction.setId(stoi(id));
                    transaction.setNumber(number);

                    string temp;
                    getline(st, temp, ',');
                    transaction.setDate(temp);

                    temp = "";
                    getline(st, temp, ',');
                    transaction.setItemsId(temp);

                    temp = "";
                    getline(st, temp, ',');
                    transaction.setPrice(stod(temp));

                    isFound = true;
                    break;
                }
            } catch (int e) {
                throw (500);
            }
        }
        if (!isFound)
            throw (204);
        return transaction;
    }

public:
    //TODO: check input and input type
    void add() {
        int number;
        string date, itemsId;
        double price;
        Transaction transaction;

        cout << "Bill number: ";
        cin >> number;
        transaction.setNumber(number);

        cout << "Date of Transaction: ";
        cin >> date;
        transaction.setDate(date);

        cout << "Enter the number of items in this format (item1;item2;...) :\n ";
        cin >> itemsId;
        transaction.setItemsId(itemsId);

        cout << "Price: ";
        cin >> price;
        transaction.setPrice(price);

        tools.writeToFile(transaction);
    }

    void edit() {
        printf("\tPlease Enter Bill Number to Edit\n");
        printf("\tEnter 0 to Back to Main Menu\n");

        string input;
        cin >> input;

        if (input != "0") {
            int itemNum = tools.checkMenuInput(input);

            Transaction transaction = getFromFileByNumber(itemNum);
            tools.removeData(&transaction);
            add();
        }
    }

    void remove() {
        printf("\tPlease Enter Bill Number to Remove\n");
        printf("\tEnter 0 to Back to Main Menu\n");

        string input;
        cin >> input;

        if (input != "0") {
            int itemNum = tools.checkMenuInput(input);

            Transaction transaction = getFromFileByNumber(itemNum);
            tools.removeData(&transaction);
        }
    }

    void showDetails() {
        int number;
        cout << "Please Enter Item Number: ";
        cin >> number;

        //TODO: show items name in the transaction
        Transaction transaction = getFromFileByNumber(number);
        cout << "Transaction No.: " << transaction.getNumber() << endl
             << "Date: " << transaction.getNumber() << endl
             << "Items in Bill: " << transaction.getItemsId() << endl
             << "Price: " << transaction.getPrice() << endl;
    }
};