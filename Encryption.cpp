#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <ncurses.h>

#define Out_Encrypt_File "Encryption.txt"
#define In_Encrypt_File "PUT HERE ENCRYPTED FILE.txt"
#define Log_file "Log.txt"

using namespace std;


void clearScreen(long long _length = 1){
	for (int i = 0; i <= _length; i++){
		printw("\n\n\n\n\n\n\n\n\n\n\n");
	}
}
void Tabulation(long long _length = 1){
	for (int i = 0; i <= _length; i++){
		printw("\t\t\t\t\t\t");
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
			log_file << " ---> " << output << '\n';
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
			log_file << " ---> " << output << '\n';
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
	bool Input_B;

	size_t Key;
	int Arrow_MainMenu=0;
public:

	void MainMenu(){
		//clearScreen();
		
		printw ("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t###             ###	//########	####         ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t## ##         ## ##	##		## ##        ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t##   ##     ##   ##	##        	##  ##       ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t##     ##_##     ##	##________	##   ##      ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t##               ##	##########	##    ##     ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t##               ##	##		##     ##    ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t##               ##	##        	##      ##   ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t##               ##	##        	##       ##  ##	     ##        ##\n") ;
		printw ("\t\t\t\t\t\t\t\t##               ##	##________	##        ## ##	     ###      ###\n") ;
		printw ("\t\t\t\t\t\t\t\t##               ##	\\\\########	##         ####	      ##########\n") ;
		printw ("\t\t\t\t\t\t\t\t_________________________________________________________________________\n\n\n\n");
		printw ("\t\t\t\t\t\t\t\t\t\t\t //-----------------------\\\\\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t|| What do you want to do? ||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||  $$$$$$$$$$$$$$$$$$$$$  ||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (Arrow_MainMenu==1) printw ("\033[37;44m\033[1m        Encrypt          \033[0m");
		else 
			printw (" \t  Encrypt\t   ");
			printw ("||\n");
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (Arrow_MainMenu==2) printw ("\033[37;44m\033[1m   Decrypt         \033[0m");
		else 
			printw (" \t  Decrypt \t   ");
			printw ("||\n") ;
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (Arrow_MainMenu==3) printw ("\033[37;44m\033[1m    Check Hash Between         \033[0m");
		else 
			printw ("   Check Hash Between    ");
			printw ("||\n");
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (Arrow_MainMenu==4) printw ("\033[37;44m\033[1m        Settings         \033[0m");
		else 
			printw ("        Settings         ");
			printw ("||\n") ;
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (Arrow_MainMenu==5) printw ("\033[37;44m\033[1m        Exit         \033[0m");
		else 
			printw ("          Exit           ");
			printw ("||\n");
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t \\\\-----------------------//\n");
		printw ("\n\n\t\t\t\t\t\t\t\t\t\t\t  < Select >\t  < Help >\n");
		refresh();
	}
	void EncMenu(){
		clearScreen();

		printw ("\t\t\t\t\t\t\t //########	####         ##	  //########	#########     ##        ##  #####    ##############"  );
		printw ("\t\t\t\t\t\t\t ##	    	## ##        ##	  ##		  	##      ##     ##      ##   ##  ##         ##      "  );
		printw ("\t\t\t\t\t\t\t ##        	##  ##       ##	  ##        	##       ##     ##    ##    ##   ##        ##      "  );
		printw ("\t\t\t\t\t\t\t ##________	##   ##      ##	  ##      	##        ##     ##  ##     ##   ##        ##         "  );
		printw ("\t\t\t\t\t\t\t ##########	##    ##     ##	  ##      	##       ##       ####      ##   ##        ##         "  );
		printw ("\t\t\t\t\t\t\t ##	  		##     ##    ##	  ##        	##     ###         ##       ##  ##         ##      "  );
		printw ("\t\t\t\t\t\t\t ##        	##      ##   ##	  ##        	########           ##       #####          ##      "  );
		printw ("\t\t\t\t\t\t\t ##        	##       ##  ##	  ##        	##    ###          ##       ##             ##      "  );
		printw ("\t\t\t\t\t\t\t ##________	##        ## ##	  ##________	##      ##         ##       ##             ##      "  );
		printw ("\t\t\t\t\t\t\t \\\\########	##         ####	  \\\\########	##       ##        ##       ##             ##      "  );
		printw ("\t\t\t\t\t\t\t -_____________________________________________________________________________________________- \n\n");
		printw ("\t\t\t\t\t\t\t\t\t\t       At least 4 characters \n\n");
		printw ("\t\t\t\t\t\t\t\t\t\t\t  Enter password: "  );
		printw ("\t\t\t\t\t\t\t\t\t\t       _------------------_"  );
		Tabulation();
		cin >> EncPass;
	}

	void DecMenu(){
		clearScreen();

		printw ("\t\t\t\t\t\t ########		//########    //########    #########    ##        ##    #####    ##############       "  );
		printw ("\t\t\t\t\t\t ##	##      ##		      ##		      ##      ##    ##      ##     ##  ##         ##           "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##            ##            ##       ##    ##    ##      ##   ##        ##           "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##________    ##     	    ##        ##    ##  ##       ##   ##        ##             "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##########    ##    	    ##       ##      ####        ##   ##        ##             "  );
		printw ("\t\t\t\t\t\t ##       ##   ##		      ##            ##     ###        ##         ##  ##         ##      "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##            ##            ########          ##         #####          ##           "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##            ##            ##    ###         ##         ##             ##           "  );
		printw ("\t\t\t\t\t\t ##	##      ##________    ##________    ##      ##        ##         ##             ##           "  );
		printw ("\t\t\t\t\t\t ########		\\\\########    \\\\########    ##       ##       ##         ##             ##         "  );
		printw ("\t\t\t\t\t\t -______________________________________________________________________________________________- \n\n");
		printw ("\t\t\t\t\t\t\t\t\t\t   Enter Encryption Password: "  );
		printw ("\t\t\t\t\t\t\t\t\t\t /---------------------------\\"  );
		Tabulation();
		cin >> DecPass;
	}

	void CheckMenu(){
		clearScreen();

		printw ("\t\t\t\t\t\t\t\t"	"//########	  ##        ##	//########	//########	##    ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"##		  	  ##        ##	##		  	##		  	##   ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"##        	  ##        ##	##        	##        	##  ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"##        	  ##________##	##________	##        	## ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"##        	  ############	##########	##        	####"  );
		printw ("\t\t\t\t\t\t\t\t"	"##        	  ##		##	##		  	##        	## ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"##        	  ##        ##	##        	##        	##  ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"##        	  ##        ##	##        	##        	##   ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"##________	  ##        ##	##________	##________	##    ##"  );
		printw ("\t\t\t\t\t\t\t\t"	"\\\\#######  ##	    ##        ##	\\\\########	\\\\########	##     ##"  );
	}

	void Settings(){

	}

	void Input(){
		Input_B = 0;
		while (!Input_B){
			switch (Key){
			//case :
			}
		}
	}
};



int main()
{	
	initscr();
	raw();
	keypad(stdscr,1);
	noecho();
	Menu Menu;
	Log Log;
	Menu.MainMenu();
	Log.typeLog("Initializatied Log System");
	sleep(2);
	endwin();
	return 0;
}



