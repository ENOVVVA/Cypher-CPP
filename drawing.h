#include <ncurses.h>

void MainMenu(){

		if (TrackPoint!=1){
			Log.typeLog("Main Menu Called");
			highlightU_D=1;
			highlightL_R=1;
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

void EncMenu(short highlightU_D,short highlightL_R,short TrackPoint){
		if (TrackPoint!=2){
			Log.typeLog("Encrypt Menu Called");
			highlightU_D=1;
			highlightL_R=1;
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

void DecMenu(short highlightU_D,short highlightL_R,short TrackPoint){
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

void CheckMenu(short highlightU_D,short highlightL_R,short TrackPoint){
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

void Settings(short highlightU_D,short highlightL_R,short TrackPoint){
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
