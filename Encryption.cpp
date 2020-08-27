// Author : Land Maze
// All rights reserved and copyright protected
// Licensed GNU c.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <ncurses.h>



#define STUFF highlightU_D, highlightL_R, TrackPoint
#define WIDTH 30
#define HEIGHT 10 
#define Out_Encrypt_File "Encryption.txt"
#define In_Encrypt_File "PUT HERE ENCRYPTED FILE.txt"
#define Log_file "txt"
#define Settings_file_PATH "Settings.txt"
using namespace std; // I'm using namespace STD for economy time, i do not use and other namespace

bool Color_B; // Global string for all classes
string password; // Global string for all classes
string text; // Global string for all classes


// Very stupid function
 void clearScreen(long long _length = 1){
 	for (int i = 0; i <= _length; i++){
 		printw("\n\n\n\n\n\n\n\n\n\n\n");
 	}
 }
 
 // Again stupid function
 void Tabulation(long long _length = 1){
 	for (int i = 0; i <= _length; i++){
 		printw("\t\t\t\t\t\t");
 	}
 }

class Menu{
	protected:
	time_t start;
	long long Seconds_S;
	long long Minutes_S;
	long long Hours_S;
	bool Pointer_Settings;
	bool Log_B;
	string InSettings;
	bool EncPass;
	bool DecPass;
	bool MainMenu_B;
	bool MainEncrypt_B;
	bool MainDecrypt_B;
	bool CheckMenu_B;
	bool MainSettings_B;
	bool InputProtected_B;
	bool MainExit_B;
	bool EncHelp_B;
	bool DecHelp_B;
	bool CheckHelp_B;
	bool SettingsHelp_B;
	bool ExitHelp_B;
	bool Input_B_B;
	bool Log_Save_B;
	bool Language_B;
	bool Secure_Input_B;
	char decision;
	short Language_N; // En=1, Ru=2, Ua=3
	string ChIP;
	string ChI;
	string line;
	size_t Key;
	int8_t highlightU_D;
	int8_t highlightL_R;
	int8_t Choice_MainMenuU_D;
	int8_t Choice_MainMenuL_R;
	int8_t Choice_SettingsU_D;
	int8_t Choice_SettingsL_R;
	short MainMenu_N_U_D;
	short MainMenu_N_L_R;
	short Settings_N;
	short TrackPoint; // MainMenu - 1, EncMenu - 2, DecMenu - 3, CheckMenu - 4 Settings - 5, Exit - 6, EncMenuHelp - 7, DecMenuHelp - 8, CheckMenuHelp - 9, SettingsHelp - 10, ExitHelp - 11
	string password;
	string text;	
	int8_t PP;
	int8_t keyC; // How long the key is
	int8_t keys; // Key
	int8_t textC; // How many characters
	string texts;
	char textArray[255];
public:
// Must be constructor but he stupid
	Menu(){
	MainMenu_N_U_D = 5;
	MainMenu_N_L_R = 3;
	highlightU_D = 1;
	highlightL_R = 1;
	Settings_N = 4;
	TrackPoint = 0;
	Language_N = 1;
	Language_B = 0;
	MainMenu_B = 1;
	Pointer_Settings = 0;
	start = time(0);
}

// Main menu, starting for default
	void MainMenu(){

		if (TrackPoint!=1){
			typeLog("Main Menu Called");
			highlightU_D=1;
			highlightL_R=1;
			TrackPoint=1;
			initscr();
		}
		clear();
		attron(A_BOLD);
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
		attroff(A_BOLD);
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
			printw ("\t\t\t\t\t\t\t\t\t\t\t||");
		if (highlightU_D==6){
			attron(A_REVERSE | A_BLINK);
			printw ("  Server (In progress)   ");
			attroff(A_REVERSE | A_BLINK);
		}
		else 
			printw ("  Server (In progress)   ");
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

// Method that calling inside the class
	void CheckMenu(){
		if (TrackPoint!=4){
			typeLog("Main Menu Called");
			TrackPoint=4;
		}
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

// Method that calling inside the class
	void Settings(){
		if (TrackPoint!=5){
			typeLog("Settings Menu Called");
			highlightU_D=1;
			TrackPoint=5;
		}
	clear();
	printw ("\n\n\n\n\n\n\t\t\t\t                                                                    \t      ___________\n");                                                                  
	printw("\t\t\t\t\t\t\t     /#######   //########  ##############  ##############  ######   /###########       /####### \n");
	printw("\t\t\t\t\t\t\t    //          ##	    ##############  ##############  ######  /###########|      //        \n");
	printw("\t\t\t\t\t\t\t   //           ##                ##              ##                ##         #|     //         \n");
	printw("\t\t\t\t\t\t\t  //            ##________        ##              ##          ##    ##         #|    //          \n");
	printw("\t\t\t\t\t\t\t //             ##########        ##              ##          ##    ##              //           \n");
	printw("\t\t\t\t\t\t\t \\\\=====\\\\      ##	          ##              ##          ##    ##     _______  \\\\=====\\\\\n");
	printw("\t\t\t\t\t\t\t         //     ##                ##              ##          ##    ##     |#|  ||          //   \n");
	printw("\t\t\t\t\t\t\t        //      ##                ##              ##          ##    ##          ||         //    \n");
	printw("\t\t\t\t\t\t\t       //       ##________        ##              ##          ##    ##          ||        //     \n");
	printw("\t\t\t\t\t\t\t ######/        \\\\########        ##              ##          ##    #############|  ######/      \n");
	printw ("\n\n\n\n\t\t\t\t\t\t\t\t\t\tLog Saving >>>  ");
	if (Log_Save_B){
	attron(A_UNDERLINE| A_BOLD);
	printw ("ON");
	attroff(A_UNDERLINE| A_BOLD);
	printw (" - OFF");
	} else {
	printw ("ON - ");
	attron(A_UNDERLINE| A_BOLD);
	printw ("OFF");
	attroff(A_UNDERLINE| A_BOLD);
	}
	printw ("\n\n\n\n\t\t\t\t\t\t\t\t\t\tLanguage  >>>     ");
	if(Language_N==1){
	attron(A_UNDERLINE | A_BOLD);
		printw("English");
	attroff(A_UNDERLINE | A_BOLD);
	printw("     Russian     Ukranian");
	} else if (Language_N==2){
	printw("English     ");
	attron(A_UNDERLINE | A_BOLD);
		printw("Russian");
	attroff(A_UNDERLINE | A_BOLD);
	printw("     Ukranian");
	}else if (Language_N==3){
	printw("English     ");
	printw("Russian     ");
	attron(A_UNDERLINE | A_BOLD);
		printw("Ukranian");
	attroff(A_UNDERLINE | A_BOLD);
	}
	printw ("\n\n\n\n\t\t\t\t\t\t\t\t\t\tColor     >>> 	   ||");
	if (Color_B){
	attron(A_UNDERLINE | A_BOLD | COLOR_GREEN);
	printw ("Green Mode");
	attroff(A_UNDERLINE | A_BOLD | COLOR_GREEN);
	printw("||\t  ||Normal mode||");
	} else {
	attron(COLOR_GREEN);
	printw ("Green Mode||\t  ||");
	attroff(COLOR_GREEN);
	attron(A_UNDERLINE | A_BOLD | COLOR_WHITE);
	printw("Normal mode||");
	attroff(A_UNDERLINE | A_BOLD | COLOR_WHITE);
	printw("||\n");
	}
	refresh();
	};

// Method that calling inside the class
	short Exit(){
		clear();
		endwin();
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYou will exit this proces in 3 seconds\n\t\t\t\t\t\t\t\tAre you sure about that? Y/N ---> ";
		std::cin >> decision;
		if (decision == 'Y'|| decision == 'y'){
			return true;
		} else MainMenu();
	}

// Method that calling inside the class
	void Server(){
	printw ("Waiting for connection for");
	refresh();
}

// Method for help that calling inside the class
	void EncHelp(){
		if (TrackPoint!=7){
			typeLog("Main Menu Called");
			TrackPoint=7;
		}else{
		clear();
		printw ("HelpEnc");
		}
	}

// Method for help that calling inside the class
	void DecHelp(){
		if (TrackPoint!=8){
			typeLog("Main Menu Called");
			TrackPoint=8;
		clear();
		printw ("HelpDec");
		}
	}

// Method for help that calling inside the class
	void CheckHelp(){
		if (TrackPoint!=9){
			typeLog("Main Menu Called");
			TrackPoint=9;
		clear();
		printw ("HelpCheck");
		}
	}

// Method for help that calling inside the class
	void SettingsHelp(){
		if (TrackPoint!=10){
			typeLog("Main Menu Called");
			TrackPoint=10;
		clear();
		printw ("HelpSetting");
		}
	}

// Method for help that calling inside the class
	void ExitHelp(){
		if (TrackPoint!=11){
			typeLog("Main Menu Called");
			TrackPoint=11;
		clear();
		printw ("HelpExit");
		}
	}

// Checking setting from Settings.txt at start program
	void CheckerSettings(){
		ifstream settings_file(Settings_file_PATH, fstream::in);
		while (!settings_file.eof()){
			getline(settings_file, line);
			if (line=="Log_Save=1")
			Log_Save_B=1;
			if (!Language_B){
			if (line=="Language=2"){
			Language_N=2;
			Language_B=1;
			}else
			if (line=="Language=1"){
			Language_N=1;
			Language_B=1;
			}else	
			if (line=="Language=3"){
			Language_N=3;
			Language_B=1;
			}
			}
			if (line=="Green_Mode=1")
			Color_B=1;
			if (line=="Secure_Input=1")
			Secure_Input_B=1;
		}
		ifstream close;
	}

// Method for reading key pressed
	void MainInput(){
		if (int d=0 !=1 ) {
		MainMenu();
		d++;
		}
	while(1)
	{	Key = getch();
		switch(Key)
		{	
			case KEY_UP:
			if (MainMenu_B){
			highlightU_D--;
			if (highlightU_D>MainMenu_N_U_D)
			highlightU_D=1;
			else if (highlightU_D<1)
			highlightU_D=MainMenu_N_U_D;
			MainMenu();
			} else if (MainEncrypt_B){

			} else if (MainDecrypt_B){

			} else if (MainSettings_B){
			highlightU_D++;
			if (highlightU_D>Settings_N)
			highlightU_D=1;
			if (highlightU_D<1)
			highlightU_D=Settings_N;
			} else if (MainExit_B){

			}
			break;
			case KEY_DOWN:
			if (MainMenu_B){
			highlightU_D++;
			if (highlightU_D>MainMenu_N_U_D)
			highlightU_D=1;
			else if (highlightU_D<1)
			highlightU_D=MainMenu_N_U_D;
			MainMenu();
			} else if (MainEncrypt_B){

			} else if (MainDecrypt_B){

			} else if (MainSettings_B){
			highlightU_D--;
			if (highlightU_D>Settings_N)
			highlightU_D=1;
			if (highlightU_D<1)
			highlightU_D=Settings_N;
			} else if (MainExit_B){

			}
			break;
			case KEY_LEFT:
			if (MainMenu_B){
			highlightL_R--;
			if (highlightL_R>MainMenu_N_L_R)
			highlightL_R=1;
			else if (highlightL_R<1)
			highlightL_R=MainMenu_N_L_R;
			MainMenu();
			}
			break;
			case KEY_RIGHT:
			if (MainMenu_B){
			highlightL_R++;
			if (highlightL_R>MainMenu_N_L_R)
			highlightL_R=1;
			else if (highlightL_R<1)
			highlightL_R=MainMenu_N_L_R;
			MainMenu();
			}
					
			break;
			case 10:
			if (MainMenu_B){
			Choice_MainMenuL_R=highlightL_R;
			Choice_MainMenuU_D=highlightU_D;
			} else if (MainEncrypt_B){

			} else if (MainDecrypt_B){

			} else if (MainSettings_B){
			Choice_SettingsL_R=highlightL_R;
			Choice_SettingsU_D=highlightU_D;
			} else if (MainExit_B){

			}
			LogicalProccess();
			break;
			
			default: break;
			};
		}
	}

// Method for LogicalProccess in menu (ONLY IN MENU)
	void LogicalProccess(){
		switch (TrackPoint){
			case 1 : {
			if (Choice_MainMenuL_R==1)
            if (Choice_MainMenuU_D==1)
				Encryption();
			 else if (Choice_MainMenuU_D==2)
				Decrypt();
			 else if (Choice_MainMenuU_D==3)
				CheckMenu();
			 else if (Choice_MainMenuU_D==4)
				Settings();
			 else if (Choice_MainMenuU_D==5)
				Exit();
			 else if (Choice_MainMenuU_D==6)
			 	Server();
			
	break;
				}
		case 2 : {
	break;
		}
		case 3 : {
	break;
		}
		case 4 : {
	break;
		}
		case 5 : {
	break;
		}
		case 6 : {
	break;
		}
		default : break;
	}	
}

// Method for Initialization Log System
	void Initialization(){
		ifstream settings_file(Settings_file_PATH, fstream::in);
		while (!settings_file.eof()){
			getline(settings_file, InSettings);
			if (Pointer_Settings==0){
			if (InSettings == "Log_Save=1") {
			Log_B = 1;
			Pointer_Settings=1;
			}
			else Log_B = 0;
			}
		}
		settings_file.close();
		if (Log_B==1){
		ofstream log_file (Log_file, fstream::app);
		log_file << "\t\t\t\t###___Initializatied Log System___###\n";
		log_file.close();
		} else { ofstream log_file (Log_file, fstream::trunc);
		log_file << "\t\t\t\t###___Initializatied Log System___###\n";
		log_file.close();
		}
	}

// Method for logging in Log.txt
	void typeLog(string output,bool scnd_output = 0){

		ofstream log_file (Log_file, fstream::app);
			int seconds_since_start = difftime(time(0), start);
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
			log_file.close();
	}

// function for encrypt. LOGICAL, isn't it?
	void Encryption(){ 
		if (TrackPoint!=2){
			typeLog("Encrypt Menu Called");
			highlightU_D=1;
			highlightL_R=1;
			TrackPoint=2;
		}
		endwin();
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnter you text to encrypt\t\tTip: At least 4 characters and 1 number\t-->";
		int i = 0;
		int key;
		std::string text;
		std::getline(cin, text);
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnter you key to encrypt\t\tTip: Only numbers allowed\t-->";
		cin >> key;
		string out;
		for(auto el : text)
			out += (char)( el + key);
		cout << "\n\n\tHere's your result <" << out << '>';
		Exit();
	} 

	void Decrypt(){
		if (TrackPoint!=3){
			typeLog("Decrypt Menu Called");
			highlightU_D=1;
			highlightL_R=1;
			TrackPoint=3;
		}
		endwin();
		int key;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tEnter a text to decrypt --> ";
		getline(cin, text);
		cout << "\n\tEnter key to decrypt --> ";
		cin >> key;
		string out;
		for(auto el : text)
			out += (char)( el - key);
		cout << "\n\n\tHere's your result <" << out << '>';
	}
};

int main(int argc, char* argv[])
{	
	initscr();
	clear();
	keypad(stdscr,1);
	noecho();
	cbreak();
	//start_color();
	Menu Menu;
	Menu.Initialization();
	Menu.CheckerSettings();
	Menu.MainInput();
	Menu.typeLog("###___End of Program___###\n\n");
	endwin();
	return 0;
}