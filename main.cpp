#include <iostream>
#include "menu.h"
using namespace std;

/* Starting the app with creating a menu */
void runApp(){
	MainMenu mainMenu = new MainMenu();
		
	while(1){
		mainMenu.showMenu();
	}
}

int main(){
	try{
		runApp();
	}catch(){
		printf("Something went wrong!! Restarting the app...");
		runApp();
	}
	
	return 0;
}
