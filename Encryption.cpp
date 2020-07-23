#include "iostream"

using namespace std;
class Menu{

public:

	void clearScreen(long long _length = 2){
		for (int i = 0; i <= _length; i++){
			printf("\n\n\n\n\n\n\n\n");
		}
	}

	void show(){

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
		cout << "\t\t\t\t\t\t\t\t" << "_________________________________________________________________________" << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "What do you want to do?\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "  Password Encryption" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "  Password Decryption" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "  Check Hash Between" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "-----------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << " Exit" << endl;
	}
};
   

int main()
{
	Menu menu;
 	menu.show();

	return 0;
}
