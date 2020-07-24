#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <ncurses.h>

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

class Menu : public Log{
	bool EncPass;
	bool DecPass;
	bool MainMenu_B;
	bool MainEncrypt_B;
	bool MainDecrypt_B;
	bool MainSettings_B;
 
	int Arrow_MainMenu=1;
public:

	void MainMenu(){
		//clearScreen();
		
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t" << "###             ###	//########	####         ##	     ##        ##" << endl;
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
		cout << "\t\t\t\t\t\t\t\t\t\t\t"  <<"||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||";
		if (Arrow_MainMenu==1) cout << "\033[37;44m\033[1m        Encrypt          \033[0m";
		else 
			cout << " \t  Encrypt\t   ";
			cout << "||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||";
		if (Arrow_MainMenu==2) cout << "\033[37;44m\033[1m   Decrypt         \033[0m";
		else 
			cout << " \t  Decrypt \t   ";
			cout << "||" << endl;
		
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||";
		if (Arrow_MainMenu==3) cout << "\033[37;44m\033[1m    Check Hash Between         \033[0m";
		else 
			cout << "   Check Hash Between    ";
			cout << "||" << endl;
		
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||";
		if (Arrow_MainMenu==4) cout << "\033[37;44m\033[1m        Settings         \033[0m";
		else 
			cout << "        Settings         ";
			cout << "||" << endl;
		
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||-------------------------||" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << "||";
		if (Arrow_MainMenu==5) cout << "\033[37;44m\033[1m        Exit         \033[0m";
		else 
			cout << "          Exit           ";
			cout << "||" << endl;
		
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << " \\\\-----------------------//" << endl;
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t  < Select >\t  < Help >";
	}

	/*void getKeyboard(char* key){
		while (1==1){
		switch(getch()){
			case ''
		}
		}
	}*/

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

	void CheckMenu(){
		clearScreen();

		cout << "\t\t\t\t\t\t\t\t"	<< "//########	##        ##	//########	//########	##    ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##‾‾‾‾‾‾‾‾	##        ##	##‾‾‾‾‾‾‾‾	##‾‾‾‾‾‾‾‾	##   ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##        	##        ##	##        	##        	##  ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##        	##________##	##________	##        	## ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##        	############	##########	##        	####" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##        	##‾‾‾‾‾‾‾‾##	##‾‾‾‾‾‾‾‾	##        	## ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##        	##        ##	##        	##        	##  ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##        	##        ##	##        	##        	##   ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "##________	##        ##	##________	##________	##    ##" << endl;
		cout << "\t\t\t\t\t\t\t\t"	<< "\\\\########	##        ##	\\\\########	\\\\########	##     ##" << endl;
	}

	void Settings(){

	}
};



int main()
{	
	//initscr();
	Menu Menu;
	Log Log;
	Menu.MainMenu();
	Log.typeLog("Initializatied Log System");

	//endwin();
	return 0;
}



