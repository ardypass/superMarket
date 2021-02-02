#include <string>
#include <iostream>
#include "transaction.h"

class TransactionOps {
private:
    Tools tools;
    Transaction *find(int number) { return NULL; }

public:
    //TODO: check input and input type
    void add(){
        int number;
        string date, itemsId;
        double price;
        Transaction transaction;

        cout<<"Bill number: ";
        cin>>number;
        transaction.setNumber(number);

        cout<<"Date of Transaction: ";
        cin>>date;
        transaction.setDate(date);

        cout<<"Enter the number of items in this format (item1;item2;...) :\n ";
        cin>>itemsId;
        transaction.setItemsId(itemsId);

        cout<<"Price: ";
        cin>>price;
        transaction.setPrice(price);

        tools.writeToFile(transaction);
    }
    void edit(){}
    void remove(){
        printf("\tPlease Enter Bill Number to Remove\n");
        printf("\tEnter 0 to Back to Main Menu\n");

        string input;
        cin >> input;

        if(input != "0")
        {
            int transId = tools.checkMenuInput(input);
            Transaction *transaction = find(transId);

        }
    }
};