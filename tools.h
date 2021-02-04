#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <map>
#include "transaction.h"

using namespace std;

class Tools {
private:
    int findLastId(string fileName) {
        fstream fin;
        int id = 0;
        fin.open(fileName, ios::in);
        if (fin.is_open()) {
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
            throw (400);
        else
            return option;

    }

    /* File Operations */
    void writeToFile(Item item) {
        string fileName = item.getFileName();
        item.setId(findLastId(fileName) + 1);
        fstream fout;

        fout.open(fileName, ios::out | ios::app);
        fout << item.getId() << ", "
             << item.getNumber() << ", "
             << item.getName() << ", "
             << item.getType() << ", "
             << item.getDateAdded() << ", "
             << item.getPrice() << endl;

        fout.close();
    }

    void writeToFile(Transaction transaction) {
        string fileName = transaction.getFileName();
        transaction.setId(findLastId(fileName) + 1);
        fstream fout;

        fout.open(fileName, ios::out | ios::app);
        fout << transaction.getId() << ", "
             << transaction.getNumber() << ", "
             << transaction.getDate() << ", "
             << transaction.getItemsId() << ", "
             << transaction.getPrice() << endl;

        fout.close();
    }

    void removeData(Item *fromItem) {
        if (fromItem == NULL)
            throw (500);

        string fileName = fromItem->getFileName();
        fstream fout, fin;
        fin.open(fileName, ios::in);
        fout.open(fileName + "Temp", ios::out);

        string line;
        while (getline(fin, line)) {
            stringstream st(line);
            string rowNumber, id;
            getline(st, id, ',');
            getline(st, rowNumber, ',');
            try {
                if (fromItem->getNumber() == stoi(rowNumber))
                    continue;
                else
                    fout << line << endl;

            } catch (int e) {
                throw (500);

            }
        }
        fin.close();
        fout.close();

        remove(fileName.c_str());
        rename((fileName + "Temp").c_str(), fileName.c_str());
    }

    void removeData(Transaction *fromTr) {
        if (fromTr == NULL)
            throw (500);

        string fileName = fromTr->getFileName();
        fstream fout, fin;
        fin.open(fileName, ios::in);
        fout.open(fileName + "Temp", ios::out);

        string line;
        while (getline(fin, line)) {
            stringstream st(line);
            string rowNumber, id;
            getline(st, id, ',');
            getline(st, rowNumber, ',');
            try {
                if (fromTr->getNumber() == stoi(rowNumber))
                    continue;
                else
                    fout << line;

            } catch (int e) {
                throw (500);

            }
        }
        fin.close();
        fout.close();

        remove(fileName.c_str());
        rename((fileName + "Temp").c_str(), fileName.c_str());
    }
};

#endif
