#include <string>
#include <stdlib.h>
#include "menuItem.cpp"
#include "menuTransaction.cpp"
#include "menu.h"
#include "tools.h"

using namespace std;

class MainMenu : public Menu {
private:
    MenuItem menuItem;
    MenuTransaction menuTransaction;
    Tools tools;

    void printMenu() {
        printf("\t\tSuper Market Billing\n");
        printf("\t\t===========================\n\n");

        printf("\t1.Bill Report\n");
        printf("\t2.Item Report\n");
        printf("\t3.Exit\n");
    }

    void readUserInput() {
        string input;
        printf("\tPlease Enter Required Option:\n");
        cin >> input;

        int option = tools.checkMenuInput(input);
        switch (option) {
            case 1:
                menuTransaction.showMenu();
                break;
            case 2:
                menuItem.showMenu();
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                throw (400);
        }


    }
};
