#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <sstream>

using namespace std;

class Tools {
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
};

#endif
