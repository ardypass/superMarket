#include <string>
#include "menu.h"
#include "itemOps.cpp"
#include "tools.h"

using namespace std;

class MenuItem : public Menu {
private:
    Tools tools;

    void printMenu() {
        printf("\t\tItem Editor\n");
        printf("\t\t===================\n\n");

        printf("\t1.Add Item Details\n");
        printf("\t2.Edit Item Details\n");
        printf("\t3.Delete Item Details\n");
        printf("\t4.Show Item Details\n");
        printf("\t5.Back to Main Menu 1\n");
    }

    void readUserInput() {
        string input = "";
        cin >> input;

        int option = tools.checkMenuInput(input);
        ItemOps itemOPs;
        switch (option) {
            case 1:
                itemOPs.add();
                break;
            case 2:
                itemOPs.edit();
                break;
            case 3:
                itemOPs.remove();
                break;
            case 4:
                itemOPs.showDetails(); break;
            case 5:
                break;
            default:
                throw (400);
        }

    }

};
