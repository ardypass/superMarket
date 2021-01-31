#include <string>

class Tools{
	public:
		/* Checking for invalid input option chosen by the user
		*  TODO: handle more than 1 digit option	
		*/
		int checkMenuInput(string input){
			if(input.size()>1)
				throw(100);
			else
			{
				int option = (int) input[0];
				if(option > 0 && option <= 9)
					return option;
				else
					throw(100);
			}
		}
}

