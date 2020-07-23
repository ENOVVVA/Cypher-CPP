#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include "coniow.h"
#include <ctime>

#define Out_Encrypt_File "Encryption.txt"
#define In_Encrypt_File "PUT HERE ENCRYPTED FILE.txt"
#define Log_file "Log.txt"

using namespace std;


void clearScreen(long long _length = 1){
	for (int i = 0; i <= _length; i++){
		printf("\n\n\n\n\n\n\n\n\n\n\n");
	}
}
void Tabulation(long long _length = 1){
	for (int i = 0; i <= _length; i++){
		printf("\t\t\t\t\t\t");
	}
}

void Initialization(){
}

class Log{
time_t start = time(0);
int seconds_since_start = difftime(time(0), start);
long long Seconds_S;
long long Minutes_S;
long long Hours_S;
	public:
	void typeLog(string output,bool scnd_output = 0){
		ofstream log_file (Log_file, fstream::ate);
		if (scnd_output == 0){
			Seconds_S = seconds_since_start%60;
			Minutes_S = seconds_since_start%3600/60;
			Hours_S = seconds_since_start/3600;
			log_file << '[';
			if (Hours_S<10){log_file << '0' << Hours_S;}else log_file << Hours_S;
			log_file << " : ";
			if (Minutes_S<10){log_file << '0' << Minutes_S;}else log_file << Minutes_S;
			log_file << " : ";
			if (Seconds_S<10){log_file << '0' << Seconds_S << ']';}else log_file << Seconds_S;
			log_file << " ---> " << output << endl;
		}else {
			Seconds_S = seconds_since_start%60;
			Minutes_S = seconds_since_start%3600/60;
			Hours_S = seconds_since_start/3600;
			log_file << '[';
			if (Hours_S<10){log_file << '0' << Hours_S;}else log_file << Hours_S;
			log_file << " : ";
			if (Minutes_S<10){log_file << '0' << Minutes_S;}else log_file << Minutes_S;
			log_file << " : ";
			if (Seconds_S<10){log_file << '0' << Seconds_S << ']';}else log_file << Seconds_S;
			log_file << " ---> " << output << endl;
		}
		log_file.close();
	}
};

class Menu{
	bool EncPass;
	bool DecPass;
public:

	void MainMenu(){
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
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << " //-----------------------\\\\" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|| What do you want to do? ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||  ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||   Password Encryption   ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||   Password Decryption   ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||   Check Hash Between    ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||          Exit           ||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << " \\\\-----------------------//" << endl;
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
		cout << "\t\t\t\t\t\t\t\t\t\t" << "/---------------------------\\" << endl;
		Tabulation();
		cin >> DecPass;
	}
};



int main()
{	
	Menu Menu;
	Log Log;
	//Menu.MainMenu();
	Log.typeLog("Initializatied Log System");

	return 0;
}
