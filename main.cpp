#include <iostream>
#include "mainMenu.cpp"

using namespace std;

/* Starting the app with creating a menu */
void runApp() {
    MainMenu mainMenu;

    while (true) {
        mainMenu.showMenu();
    }
}

int main() {
    try {
        runApp();
    } catch (int e) {
        if (e == 100)
            cout << "Wrong Input!! Restarting the app..." << endl;
        else
            cout << "Something went wrong!! Restarting the app..." << endl;

        runApp();
    }

    return 0;
}
