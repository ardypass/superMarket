#ifndef MENU_H
#define MENU_H

#include <string>
#include <stdlib.h> 
using namespace std;

class Menu{
	protected:
		virtual void printMenu(){}
		virtual void readUserInput(){}
	public:
		void showMenu(){
			this->printMenu();
			this->readUserInput();
		}
};

#endif
