#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <sstream>
#include <fstream>
#include "transaction.h"

using namespace std;

class Tools {
private:
    int findLastId(string fileName){
        fstream fin;
        int id = 0;
        fin.open(fileName, ios::in);
        if(fin.is_open())
        {
            string line;
            while (getline(fin, line))
                ++id;
        }
        fin.close();
        return id;
    }
public:
    /* Checking for invalid input option chosen by the user
    */
    int checkMenuInput(string input) {
        stringstream st(input);
        int option;
        st >> option;
        if (option == 0)
            throw (100);
        else
            return option;

    }

    /* File Operations */
    void writeToFile(Item item) {
        string fileName = "itemsReport.csv";
        item.setId(findLastId(fileName)+1);
        fstream fout;

        fout.open(fileName, ios::out | ios::app);
        fout << item.getId() << ", "
        << item.getName() << ", "
        << item.getType() << ", "
        << item.getDateAdded() << ", "
        << item.getPrice() << ", "
        << item.isDeleted() << endl;

        fout.close();
    }

    void writeToFile(Transaction transaction) {
        string fileName = "transactionReport.csv";
        transaction.setId(findLastId(fileName)+1);
        fstream fout;

        fout.open(fileName, ios::out | ios::app);
        fout << transaction.getId() << ", "
             << transaction.getNumber() << ", "
             << transaction.getDate() << ", "
             << transaction.getItemsId() << ", "
             << transaction.getPrice() << ", "
             << transaction.isDeleted() <<endl;

        fout.close();
    }

    void readFile(string fileName) {
        fstream fin;
        fin.open(fileName, ios::in);
    }

    void updateFile(string fileName) {
        fstream fin, fout;
        fin.open("reportcard.csv", ios::in);
        fout.open("reportcardnew.csv", ios::out);
    }
};

#endif
