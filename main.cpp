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
        if (e == 400)
            cout << "Wrong Input!! Restarting the app..." << endl;
        else if (e == 404)
            cout << "File Not Found!! Restarting the app..." << endl;
        else if (e == 204)
            cout << "Data Not Found!! Restarting the app..." << endl;
        else if (e == 500)
            cout << "Internal Error!! Restarting the app..." << endl;
        else
            cout << "Something went wrong!! Restarting the app..." << endl;

        runApp();
    } catch (const std::invalid_argument& ) {
        cout << "Wrong Input!! Restarting the app..." << endl;
        runApp();
    }

    return 0;
}
