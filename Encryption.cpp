#include "iostream"

using namespace std;

long long iterration = 0;

class Menu{

public:

	void clearScreen(long long _length = 99){
   	printf ("\n\n\n\n\n\n\n\n");
	}

	void show(){
		if (iterration > 0) iterration = 0;
		clearScreen();
		cout << "\t\t\t\t\t\t\t\t" << "###             ###	//########	####         ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "## ##         ## ##	##‾‾‾‾‾‾‾‾	## ##        ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##   ##     ##   ##	##        	##  ##       ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##     ##_##     ##	##________	##   ##      ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##               ##	##########	##    ##     ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##               ##	##‾‾‾‾‾‾‾‾	##     ##    ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##               ##	##        	##      ##   ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##               ##	##        	##       ##  ##	     ##        ##" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##               ##	##________	##        ## ##	     ###      ###" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "##               ##	\\\\########	##         ####	      ##########" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "_________________________________________________________________________" << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "What do you want to do?\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << "1. Password Encryption." << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << "-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << "2. Password Decryption." << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << "-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << "3. Exit." << endl;
	}
};


int main()
{
	Menu menu;

	menu.show();

	return 0;
}
