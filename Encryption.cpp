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
bool Color_B;


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
bool Pointer_Settings = 0;
bool Log_B;
string InSettings;
	public:
	
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
	bool Language_B = 0;
	short Language_N = 1; // En=1, Ru=2, Ua=3
	string ChIP;
	string ChI;
	string line;
	size_t Key;
	int highlightU_D = 1;
	int highlightL_R = 1;
	int Choice_MainMenuU_D;
	int Choice_MainMenuL_R;
	const short MainMenu_N_U_D = 5;
	const short MainMenu_N_L_R = 3;
	const short Settings_N = 4;

	short TrackPoint = 0; // MainMenu - 1, EncMenu - 2, DecMenu - 3, CheckMenu - 4 Settings - 5, Exit - 6, EncMenuHelp - 7, DecMenuHelp - 8, CheckMenuHelp - 9, SettingsHelp - 10, ExitHelp - 11

public:

	Log Log;

	void Check_TrackPointer(short id){
			if (TrackPoint!= id){
			TrackPoint = id;
			if (TrackPoint==1)
			MainMenu_B = 1;
			 else {
				MainMenu_B = 0;
				if (TrackPoint==2)
					MainEncrypt_B = 1;
				 else {
					MainEncrypt_B = 0;
					if (TrackPoint==3)
						MainDecrypt_B = 1;
					 else {
						MainDecrypt_B = 0;
						if (TrackPoint==4) 
						CheckMenu_B = 1;
						else{
							CheckMenu_B = 0;
							if (TrackPoint==5)
							MainSettings_B = 1;
							else {
								MainSettings_B = 0;
								if (TrackPoint==6)
								MainExit_B = 1;
								else {
									MainExit_B = 0;
									if (TrackPoint==7)
									EncHelp_B = 1;
									else {
										EncHelp_B = 0;
										if (TrackPoint==8)
										DecHelp_B = 1;
										else {
											DecHelp_B = 0;
											if (TrackPoint==9)
											CheckHelp_B=1;
											else {
												CheckHelp_B = 0;
												if (TrackPoint==10)
												SettingsHelp_B=1;
												else {
													SettingsHelp_B = 0;
													if (TrackPoint==11)
													ExitHelp_B=1;
													else ExitHelp_B=0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	void MainMenu(){
		if (TrackPoint!=1){
			Log.typeLog("Main Menu Called");
			highlightU_D=1;
			highlightL_R=1;
			Check_TrackPointer(1);
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
		if (TrackPoint!=2){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(2);
		}
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
		
	}

	void DecMenu(){
		if (TrackPoint!=3){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(3);
		}
		clear();

		printw ("\t\t\t\t\t\t ########		//########    //########    #########    ##        ##    #####    ##############       "  );
		printw ("\t\t\t\t\t\t ##	##      ##		      ##		      ##      ##    ##      ##     ##  ##         ##           "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##            ##            ##       ##    ##    ##      ##   ##        ##           "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##________    ##     	    ##        ##    ##  ##       ##   ##        ##             "  );
		printw ("\t\t\t\t\t\t ##	  ##    ##########    ##    	    ##       ##      ####        ##   ##        ##             "  );
		printw ("\t\t\t\t\t\t ##      ##    ##		      ##            ##     ###        ##         ##  ##         ##      "  );
		printw ("\t\t\t\t\t\t ##	  ##    ##            ##            ########          ##         #####          ##           "  );
		printw ("\t\t\t\t\t\t ##	 ##     ##            ##            ##    ###         ##         ##             ##           "  );
		printw ("\t\t\t\t\t\t ##	##      ##________    ##________    ##      ##        ##         ##             ##           "  );
		printw ("\t\t\t\t\t\t ########		\\\\########    \\\\########    ##       ##       ##         ##             ##         "  );
		printw ("\t\t\t\t\t\t -______________________________________________________________________________________________- \n\n");
		printw ("\t\t\t\t\t\t\t\t\t\t   Enter Encryption Password: "  );
		printw ("\t\t\t\t\t\t\t\t\t\t /---------------------------\\"  );
		Tabulation();
		refresh();
		
	}

	void CheckMenu(){
		if (TrackPoint!=4){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(4);
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

	void Settings(){
		if (TrackPoint!=5){
			Log.typeLog("Settings Menu Called");
			highlightU_D=1;
			Check_TrackPointer(5);
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
	printw("Ukranian");
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

	void Exit(){
		if (TrackPoint!=6){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(6);
		}else{
			printw ("Exit");
			refresh();
		}
	}

	void EncHelp(){
		if (TrackPoint!=7){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(7);
		}else{
		clear();
		printw ("HelpEnc");
		}
	}

	void DecHelp(){
		if (TrackPoint!=8){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(8);
		clear();
		printw ("HelpDec");
		}
	}

	void CheckHelp(){
		if (TrackPoint!=9){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(9);
		clear();
		printw ("HelpCheck");
		}
	}

	void SettingsHelp(){
		if (TrackPoint!=10){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(10);
		clear();
		printw ("HelpSetting");
		}
	}

	void ExitHelp(){
		if (TrackPoint!=11){
			Log.typeLog("Main Menu Called");
			Check_TrackPointer(11);
		clear();
		printw ("HelpExit");
		}
	}

	void CheckerSettings(){
		ifstream settings_file(Settings_file_PATH, fstream::in);
		while (!settings_file.eof()){
			getline(settings_file, line);
			if (!Log_Save_B)
			if (line=="Log_Save=1")
			Log_Save_B=1;
			if (!Language_B)
			if (line=="Language=ru_RU"){
			Language_N=2;
			Language_B=1;
			}else
			if (line=="Language=en_EN"){
			Language_N=1;
			Language_B=1;
			}else	
			if (line=="Language=ua_UA"){
			Language_N=3;
			Language_B=1;
			}
			if (line=="Green_Mode=1")
			Color_B=1;
		}
	}

	void MainInput(){
		
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

			} else if (MainExit_B){

			}
			LogicalProccess();
			break;
			
			default:
			break;
			};
		}
	}

	void InputProtected(){

}

	void LogicalProccess(){
			if (MainMenu_B){
			if (Choice_MainMenuL_R==1){
            if (Choice_MainMenuU_D==1)
				EncMenu();
			 else if (Choice_MainMenuU_D==2)
				DecMenu();
			 else if (Choice_MainMenuU_D==3)
				CheckMenu();
			 else if (Choice_MainMenuU_D==4)
				Settings();
			 else if (Choice_MainMenuU_D==5)
				Exit();
			
			}
			} else if (MainEncrypt_B){

			} else if (MainDecrypt_B){

			} else if (MainSettings_B){

			} else if (MainExit_B){

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
	//start_color();
	Menu Menu;
	Log Log;
	Log.Initialization();
	Menu.CheckerSettings();
	if (Color_B){
	attron(COLOR_GREEN);
	}
	Menu.MainMenu();
	Menu.MainInput();
	endwin();
	Log.typeLog("###___End of Program___###\n\n");
	return 0;
}