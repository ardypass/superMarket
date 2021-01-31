#include <string>
#include "menu.h"
#include "transaction.h"

class MenuTransaction: public Menu{
	private:
		void printMenu(){
			printf("\tPlease Enter Transaction Number:\n");
		}

		void readUserInput(){
			string input;
			scanf("%s", &input);
			
			Transaction transaction = new Transaction();
			transaction = transaction.find(transCode);
	
			transaction.printData();					
		}
}

