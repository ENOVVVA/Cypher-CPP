#include "iostream"
#include <string>
#include <fstream>
#include <vector>

#define ENCRYPTION_FILE "Encryption.txt"

using namespace std;

void clearScreen(long long _length = 1){
	for (int i = 0; i <= _length; i++){
		printf("\n\n\n\n\n\n\n\n\n\n\n");
	}
}
void Tabulation(long long _length = 1){
	for (int i = 0; i <= _length; i++){
		printf("\t\t\t\t\t       ");
	}
}

class Menu{

public:
	bool EncPass;
	bool DecPass;

	void HomeMenu(){
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
		// Але мені в коробці не очень зайшло мені кажеться лібше без неї.
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "/-------------------------\\" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|| What do you want to do?||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#  ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#   Password Encryption   ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#   Password Decryption   ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#   Check Hash Between    ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "#          Exit           ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "\\-------------------------/" << endl;
	}

	void EncMenu(){
		clearScreen();

		cout << "\t\t\t\t\t\t\t\t\t" << "//########	####         ##	    //########" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##‾‾‾‾‾‾‾‾	## ##        ##	    ##‾‾‾‾‾‾‾‾" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##        	##  ##       ##	    ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##________	##   ##      ##	    ##     	  " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##########	##    ##     ##	    ##    	  " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##‾‾‾‾‾‾‾‾	##     ##    ##	    ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##        	##      ##   ##	    ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##        	##       ##  ##	    ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##________	##        ## ##	    ##________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "\\\\########	##         ####	    \\\\########" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "-____________________________________________-" << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t\t" << "      At least 4 characters" << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << " Enter password: " << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << "      _------------------_" << endl;
		Tabulation();
		cin >> EncPass;
	}

	void DecMenu(){
		clearScreen();

		cout << "\t\t\t\t\t\t\t\t\t" << "########	//########	  //########" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##	##      ##‾‾‾‾‾‾‾‾	  ##‾‾‾‾‾‾‾‾" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##	 ##     ##        	  ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##	 ##     ##________	  ##     	  " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##	 ##     ##########	  ##    	  " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##       ##     ##‾‾‾‾‾‾‾‾	  ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##	 ##     ##        	  ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##	 ##     ##        	  ##        " << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "##	##      ##________	  ##________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "########	\\\\########        \\\\########" << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << "-__________________________________________-" << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t\t" << "  Enter Encryption Password: " << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << "_---------------------------_" << endl;
		Tabulation();
		cin >> DecPass;
	}
};

int main()
{	

	Menu Menu;
	Menu.DecMenu();


	return 0;
}
