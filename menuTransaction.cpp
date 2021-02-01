#include <string>
#include "menu.h"
#include "transaction.cpp"
using namespace std;

class MenuTransaction: public Menu{
	private:
		void printMenu(){
			printf("\tPlease Enter Transaction Number:\n");
		}

		void readUserInput(){
			string input;
			cin>>input;
			
			Transaction* transaction;
			transaction = transaction->find(input);
	
			transaction->printData();					
		}
};

