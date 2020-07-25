#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10 
#define Out_Encrypt_File "Encryption.txt"
#define In_Encrypt_File "PUT HERE ENCRYPTED FILE.txt"
#define Log_file "Log.txt"
#define Settings_file_PATH "Settings.txt"

using namespace std;

WINDOW *menu_win;
char *MainMenuN[] = { 
			"Encrypt",
			"Decrypt",
			"Check Hash Between",
			"Settings",
			"Exit",
		  };

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
class Log{
time_t start = time(0);
int seconds_since_start = difftime(time(0), start);
long long Seconds_S;
long long Minutes_S;
long long Hours_S;
bool Log_B;
bool Pointer_Settings = 0;
string InSettings;
	public:
	void Initialization(){
		ifstream settings_file(Settings_file_PATH, fstream::in);
		while (!settings_file.eof()){
			getline(settings_file, InSettings);
			if (Pointer_Settings==0){
			if (InSettings == "Log_Save=1") {
			Log_B = 0;
			Pointer_Settings=1;
			typeLog("Pointer == 1");
			typeLog(InSettings);
			}
			else Log_B = 1;
			}
		}
		settings_file.close();
		if (Log_B==1){
		ofstream log_file (Log_file, fstream::trunc);
		log_file << "\t\t\t\t###___Initializatied Log System___###\n";
		log_file.close();
		} else { ofstream log_file (Log_file, fstream::app);
		log_file << "\t\t\t\t###___Initializatied Log System___###\n";
		log_file.close();
		}
	}
	void typeLog(string output,bool scnd_output = 0){
		ofstream log_file (Log_file, fstream::app);
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
	bool MainMenu_B = 1;
	bool MainEncrypt_B;
	bool MainDecrypt_B;
	bool MainSettings_B;
	bool InputProtected_B;
	bool Input_B;
	string ChIP;
	string ChI;
	size_t Key;
	int Main_Menu_N_Choice = sizeof(*MainMenuN) / sizeof(char *);
	int highlightU_D = 1;
	int highlightL_R = 1;
	int Choice_MainMenuU_D;
	int Choice_MainMenuL_R;
	short TrackPoint; // MainMenu - 1, EncMenu - 2, DecMenu - 3, Settings - 4

public:
	Log Log;
	

/*void print_box(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < Main_Menu_N_Choice; ++i)
	{	if(highlight == i + 1)
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", MainMenuN[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", MainMenuN[i]);
		++y;
	}
	wrefresh(menu_win);
}*/

	void MainMenu(){
		clear();
		
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
		if (highlightU_D==1){
			attron(A_REVERSE | A_BLINK);
			printw (" \t  Encrypt\t   ");
			attroff(A_REVERSE | A_BLINK);
		}
		else 
			printw (" \t  Encrypt\t   ");
			printw ("||\n");
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (highlightU_D==2){
		attron(A_REVERSE | A_BLINK);
		printw (" \t  Decrypt \t   ");
		attroff(A_REVERSE | A_BLINK);}
		else 
			printw (" \t  Decrypt \t   ");
			printw ("||\n") ;
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (highlightU_D==3){
			attron(A_REVERSE | A_BLINK);
			printw ("   Check Hash Between    ");
			attroff(A_REVERSE | A_BLINK);
			 
		}
		else 
			printw ("   Check Hash Between    ");
			printw ("||\n");
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (highlightU_D==4){
		attron(A_REVERSE | A_BLINK);
		printw ("        Settings         ");
		attroff(A_REVERSE | A_BLINK);
		}
		else 
			printw ("        Settings         ");
			printw ("||\n") ;
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t||-------------------------||\n") ;
		printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (highlightU_D==5){
			attron(A_REVERSE | A_BLINK);
			printw ("          Exit           ");
			attroff(A_REVERSE | A_BLINK);
		}
		else 
			printw ("          Exit           ");
			printw ("||\n");
		
		printw ("\t\t\t\t\t\t\t\t\t\t\t \\\\-----------------------//\n");
		printw ("\n\n\t\t\t\t\t\t\t\t\t\t  ");
		if (highlightL_R == 1){
			attron(A_REVERSE | A_BLINK);
			printw ("< Select >");
			attroff(A_REVERSE | A_BLINK);
		}
		else printw ("< Select >");
		printw ("\t  ");
		if (highlightL_R == 2){
			attron(A_REVERSE | A_BLINK);
			printw ("< Help >");
			attroff(A_REVERSE | A_BLINK);
		}
		else printw ("< Help >");
		printw ("\t");
		if (highlightL_R == 3){
			attron(A_REVERSE | A_BLINK);
			printw ("< Back >\n");
			attroff(A_REVERSE | A_BLINK);
		}
		else printw ("< Back >\n");
		
		refresh();
	}
	void EncMenu(){
		clear();

		printw ("\n\t\t\t\t\t\t\t //########	####         ##	  //########	#########     ##        ##  #####    ##############"  );
		printw ("\n\t\t\t\t\t\t\t ##	    	## ##        ##	  ##	  	##      ##     ##      ##   ##  ##         ##      "  );
		printw ("\n\t\t\t\t\t\t\t ##        	##  ##       ##	  ##        	##       ##     ##    ##    ##   ##        ##      "  );
		printw ("\n\t\t\t\t\t\t\t ##________	##   ##      ##	  ##      	##        ##     ##  ##     ##   ##        ##         "  );
		printw ("\n\t\t\t\t\t\t\t ##########	##    ##     ##	  ##      	##       ##       ####      ##   ##        ##         "  );
		printw ("\n\t\t\t\t\t\t\t ##	  	##     ##    ##	  ##        	##     ###         ##       ##  ##         ##      "  );
		printw ("\n\t\t\t\t\t\t\t ##        	##      ##   ##	  ##        	########           ##       #####          ##      "  );
		printw ("\n\t\t\t\t\t\t\t ##        	##       ##  ##	  ##        	##    ###          ##       ##             ##      "  );
		printw ("\n\t\t\t\t\t\t\t ##________	##        ## ##	  ##________	##      ##         ##       ##             ##      "  );
		printw ("\n\t\t\t\t\t\t\t \\\\########	##         ####	  \\\\########	##       ##        ##       ##             ##      "  );
		printw ("\n\t\t\t\t\t\t\t -_____________________________________________________________________________________________- \n\n");
		printw ("\n\t\t\t\t\t\t\t\t\t\t       At least 4 characters \n\n");
		printw ("\n\t\t\t\t\t\t\t\t\t\t\t  Enter password: "  );
		printw ("\n\t\t\t\t\t\t\t\t\t\t       _------------------_"  );
		Tabulation();
		refresh();
		cin >> EncPass;
	}

	void DecMenu(){
		clear();

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
		refresh();
		cin >> DecPass;
	}

	void CheckMenu(){
		clear();

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
		refresh();
	}

	void Settings(){

	};

	void Exit(){

	}

	void EncHelp(){
		clear();
		printw ("HelpEnc");
	}

	void DecHelp(){
		clear();
		printw ("HelpDec");
	}

	void CheckHelp(){
		clear();
		printw ("HelpCheck");
	}

	void SettingsHelp(){
		clear();
		printw ("HelpSetting");
	}

	void ExitHelp(){
		clear();
		printw ("HelpExit");
	}

	void InputMainMenu(){
		
	while(1)
	{	Key = getch();
		switch(Key)
		{	case KEY_UP:
				highlightU_D--;
				if (highlightU_D <= 0)
					highlightU_D=5;
					MainMenu();
					break;
			case KEY_DOWN:
			highlightU_D++;
			if (highlightU_D >= 6)
				highlightU_D = 1;
				MainMenu();
				break;
			case KEY_LEFT:
			highlightL_R--;
			if (highlightL_R <= 0) highlightL_R=3;
			MainMenu();
			break;
			case KEY_RIGHT:
			highlightL_R++;
			if (highlightL_R >= 4) highlightL_R = 1;
			MainMenu();
			break;
			case 10:
				Choice_MainMenuU_D = highlightU_D;
				Choice_MainMenuL_R = highlightL_R;
				LogicalProccess();
				break;
			default:
				break;
		}
	};
}
	void InputProtected(){
		while (InputProtected_B){
		switch (Key){
			
			default: break;
		}
		}
};

	void LogicalProccess(){
		if (MainMenu_B){
		if (Choice_MainMenuU_D == 1){
		Choice_MainMenuU_D = 1;
		highlightU_D = 1;
		if (Choice_MainMenuL_R==1){
		EncMenu();
		} else EncHelp();
		} else if (Choice_MainMenuU_D == 2){
		Choice_MainMenuU_D = 1;
		highlightU_D = 1;
		if (Choice_MainMenuL_R==1){
		DecMenu();
		} else DecHelp();
		} else if (Choice_MainMenuU_D == 3){
		Choice_MainMenuU_D = 1;
		highlightU_D = 1;
		if (Choice_MainMenuL_R==1){
		CheckMenu();
		} else CheckHelp();
		} else if (Choice_MainMenuU_D == 4){
		Choice_MainMenuU_D = 1;
		highlightU_D = 1;
		if (Choice_MainMenuL_R==1){
		Settings();
		} else SettingsHelp();
		} else if (Choice_MainMenuU_D == 5){
		if (Choice_MainMenuL_R==1){
		Exit();
		} else ExitHelp();
		if (Choice_MainMenuL_R== 3){
			//if (TrackPoint==1) Log.typeLog("")

		}
		}
	}
	}
};

int main()
{	
	initscr();
	clear();
	keypad(stdscr,1);
	noecho();
	cbreak();
	Menu Menu;
	Log Log;
	Log.Initialization();
	Menu.MainMenu();
	Log.typeLog("Catboy Kami");
	Menu.InputMainMenu();
	endwin();
	return 0;
}