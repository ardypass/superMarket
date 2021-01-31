#include <string>
#include "menu.h"
#include "item.h"
#include "tools.h"

class MenuItem: public Menu{
	private:
		void printMenu(){
				printf("\t\tBill Editor\n");
				printf("\t\t===================\n\n");
				
				printf("\t1.Add Item Details\n");
				printf("\t2.Edit Item Details\n");
				printf("\t3.Delete Item Details\n");
				printf("\t4.Back to Main Menu 1\n");
			}
		
		void readUserInput(){
				string input = "";
				scanf("%s", &input);
				
				int option = checkMenuInput(input);
				Item item = new Item();
				switch(option):
					case "1": item.add(); break;
					case "2": item.edit(); break;
					case "3": item.remove(); break;
					case "4": menuOptions(); break;
					default throw(100);
			}
	public:
		void showDetailsMenu(){}		
}
