#include <string>
#include "menu.h"
#include "transaction.h"
#include "tools.h"

using namespace std;

class MenuTransaction : public Menu {
private:
    Tools tools;

    void printMenu() {
        printf("\tPlease Enter Transaction Number\n");
        printf("\tEnter 0 to Back to Main Menu\n");
    }

    void readUserInput() {
        string input;
        cin >> input;


        if(input != "0")
        {
            int transId = tools.checkMenuInput(input);
            Transaction *transaction;
            transaction = transaction->find(transId);

            transaction->printData();
        }

    }
};

