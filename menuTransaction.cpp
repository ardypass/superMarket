#include <string>
#include "menu.h"
#include "transactionOps.cpp"
#include "tools.h"

using namespace std;

class MenuTransaction : public Menu {
private:
    Tools tools;

    void printMenu() {
        printf("\t\tBill Editor\n");
        printf("\t\t===================\n\n");

        printf("\t1.Add Bill\n");
        printf("\t2.Edit Bill\n");
        printf("\t3.Delete Bill\n");
        printf("\t4.Back to Main Menu 1\n");
    }

    void readUserInput() {
        string input = "";
        cin >> input;

        int option = tools.checkMenuInput(input);
        TransactionOps transactionOps;
        switch (option) {
            case 1:
                transactionOps.add();
                break;
            case 2:
                transactionOps.edit();
                break;
            case 3:
                transactionOps.remove();
                break;
            case 4:
                break;
            default:
                throw (100);
        }



    }
};

