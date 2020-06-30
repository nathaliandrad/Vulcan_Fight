#include "characters.h"
#include "Header.h"
#include <time.h>
#include <fstream>


void main(){

	srand(time(NULL));

	SOLDIERS s1;
	ASARI a1;
	KROGAN krg;
	ZOMBIE zmb;
	char option;
	

	displayWelcome(); //welcome screen

	begin:do
	{	//game menu
		cout << "\n\n\n\t\tMENU\t\t\n\n";
		cout << "\t1.INSTRUCTIONS\n";
		cout << "\t2.VIEW CHARACTERS\n";
		cout << "\t3.START THE GAME\n";
		cout << "\t4.EXIT GAME\n\n";

		cout << "\nPlease Enter your Option: ";
		cin >> option;

		switch (option){
		case '1':
			displayInstructions(); //Instructions Screen
			break;

		case '2':
			s1.displaySoldier();//Displays Soldier Character
			a1.displayAsari();//Displays Asari Character
			krg.displayKrogan();//Displays Krogan Character

			break;
		
		case '3':
		{
			system("cls");
			cout << "\n\n\t\t\tDISPLAYING HIGHEST HIGH SCORE EVER: \n\n\n";

			int highScore;
			string highScorer;

			ifstream fin;
			fin.open("highscore.txt");
			fin >> highScore;
			fin >> highScorer;
			fin.close();
			cout << "\n\n\t HighScore: " << highScore << "\t Name: " << highScorer << "\n\n\n\n"; //Highest Scorer of the game

			cout << "--------------------------------------------LET'S  START  THE  GAME!----------------------------------------\n\n\n";
			system("pause");

			char c;
			cout << "\n\n\t\tDo you want to play with ASARI[a], SOLDIER COMMANDER[s] or KROGAN[k]?";
			cin >> c;
			cout << "\n\n\n";

			if (c == 's' || c == 'S'){ //In case of choosing Soldier
				displayChoiceS();
				s1.setUpSoldier("COMMANDER SHEPARD");
				cout << "\n\n";
				zmb.setUpZombie("ZOMBIESzz");
				cout << "\n\n";
				system("pause");

				while (s1.dead() != true && !zmb.dead()){ //While Soldier and Zombie are not dead, the game will keep going
					system("cls");
					int turn = (rand() % 3) + 1;
					if (turn == 1){
						if (!s1.dead())
							zmb.takingDamage(s1.attack());//In case is Soldiers Turn, Zombie will take damage
					}
					else if (turn == 2)
					{
						if (!zmb.dead())
							s1.takingDamage(zmb.attack());//In case is Zombies Turn, Soldier will take damage
					}
					else if (turn == 3) //turn 3 gives option for the player to choose an action
					{
						if (!s1.dead() && !zmb.dead()){ 
							char choice;

							displayTurn();
							cout << "\n\nSoldier, press [p] to punch the Zombies or press [s] to shoot the zombies OR [q]TO QUIT GAME: ";
							cin >> choice;

							for (int i = 0; i < 1; i++){
								if (choice == 'p' || choice == 'P'){
									zmb.takingDamage(s1.punch());
								}
								else if (choice == 's' || choice == 'S'){
									zmb.takingDamage(s1.shoot());
								}
								else if (choice == 'q' || choice == 'Q'){
									cout << "\n\n\n\t\t\tExit Selected!!!";
									goto begin;
								}
								else
									cout << "\t\nYou have lost your chance to Play. Please enter a valid option Next Time!!!!\n\n";
							}
						}
					}
					cout << "------------------------------------------------------------------------------------------------------------\n\n\n";
					Sleep(1600);

				}

				int score = 0;
				if (s1.dead()){ //If soldier Dies
					cout << "\t" << zmb.getName() << " have eaten your soldier \n\n ";
					score = zmb.getHp() * 3;

					displayLost();
					cout << "\tSorry, Try Again!!!\n\n";
				}
				else //If Zombie dies
				{
					cout << "\t" << s1.getName() << " have killed all Zombies\n\n";
					score = s1.getHp() * 3;
					displayWin();

					cout << "\tCONGRATULATIONS " << s1.getName() << "!!!\n\n";
				}
				cout << "\tSCORE: " << score << "\n\n\n\n";

				if (score > highScore) //If score is higher than the last recorded high score
				{
					string name;

					cout << "\n\n\t\tNew HighScore!!!\n\n";
					cout << "Please enter your Name: ";
					cin.ignore(1000, '\n');
					getline(cin, name);

					ofstream fout;
					fout.open("highscore.txt", ios::trunc);
					if (fout.good())
						fout << score << " " << name; //writes on the file, name and score

					fout.close();
				}

				system("pause");

			}

			else if (c == 'a' || c == 'A'){ //In case of choosing Asari
				displayChoiceA();
				a1.setUpAsari("LIARA SONI");
				cout << "\n\n";
				zmb.setUpZombie("ZOMBIESzz");
				cout << "\n\n";
				system("pause");

				while (a1.dead() != true && !zmb.dead()){//While Asari and Zombie are not dead, the game will keep going

					int turn = (rand() % 3) + 1; //repeats same process as the soldier

					if (turn == 1){
						if (!a1.dead())
							zmb.takingDamage(a1.attack());
					}
					else if (turn == 2)
					{
						if (!zmb.dead())
							a1.takingDamage(zmb.attack());
					}
					else if (turn == 3){
						if (!a1.dead() && !zmb.dead()){
							char choice;


							displayTurn();
							cout << "\n\nAsari, press [b] to use bionic powers the Zombies or press [s] to shoot the zombies OR [q]TO QUIT GAME: ";
							cin >> choice;

							for (int i = 0; i < 1; i++){
								if (choice == 'b' || choice == 'B'){
									zmb.takingDamage(a1.bionic());
								}
								else if (choice == 's' || choice == 'S'){
									zmb.takingDamage(a1.shoot());
								}
								else if (choice == 'q' || choice == 'Q'){
									cout << "\n\n\n\t\t\tExit Selected!!!";
									goto begin;
								}
								else
									cout << "\t\nYou have lost your chance to Play. Please enter a valid option Next Time!!!!\n\n";
							}
						}

					}

					cout << "------------------------------------------------------------------------------------------------------------\n\n\n";
					Sleep(1600);

				}

				int score = 0;
				if (a1.dead()){
					cout << "\t" << zmb.getName() << " have eaten your ASARI!! \n\n ";
					score = zmb.getHp() * 3;
					displayLost();

					cout << "\tSorry, Try Again!!!\n\n";
				}
				else
				{
					cout << "\t" << a1.getName() << " abducted all zombies\n\n";
					score = a1.getHp() * 3;

					displayWin();

					cout << "\tCONGRATULATIONS " << a1.getName() << "!!!\n\n";

				}
				cout << "\tSCORE: " << score << "\n\n\n\n";

				if (score > highScore)
				{
					string name;

					cout << "\n\n\t\tNew HighScore!!!\n\n";
					cout << "Please enter your Name: ";
					cin.ignore(1000, '\n');
					getline(cin, name);

					ofstream fout;
					fout.open("highscore.txt", ios::trunc);
					if (fout.good())
						fout << score << " " << name;

					fout.close();
				}

				system("pause");
			}
			else
			{
				if (c == 'k' || c == 'K'){ //In case the choice is Krogan
					displayChoiceK();
					krg.setUpKrogan("WREX URDNOT");
					cout << "\n\n";
					zmb.setUpZombie("ZOMBIESzz");
					cout << "\n\n";
					system("pause");

					while (krg.dead() != true && !zmb.dead()){//While Krogan and Zombie are not dead, the game will keep going

						int turn = (rand() % 3) + 1; //same process

						if (turn == 1){
							if (!krg.dead())
								zmb.takingDamage(krg.attack());
						}
						else if (turn == 2)
						{
							if (!zmb.dead())
								krg.takingDamage(zmb.attack());
						}
						else if (turn == 3){
							if (!krg.dead() && !zmb.dead()){
								char choice;

								displayTurn();
								cout << "\n\nKrogan, press [k] to kick the Zombies or press [s] to shoot the zombies OR[q]TO QUIT GAME: ";
								cin >> choice;

								for (int i = 0; i < 1; i++){
									if (choice == 'k'){
										zmb.takingDamage(krg.punch());

									}
									else if (choice == 's'){
										zmb.takingDamage(krg.shotgun());

									}
									else if (choice == 'q' || choice == 'Q'){
										cout << "\n\n\n\t\t\tExit Selected!!!";
										goto begin;
									}
									else
										cout << "\t\nYou have lost your chance to Play. Please enter a valid option Next Time!!!!\n\n";
								}
							}
						}

						cout << "------------------------------------------------------------------------------------------------------------\n\n\n";
						Sleep(1600);
					}

					int score = 0;
					if (krg.dead()){
						cout << "\t" << zmb.getName() << " have eaten your Krogan\n\n ";
						score = zmb.getHp() * 3;
						displayLost();

						cout << "\tSorry, Try Again!!!\n\n";
					}
					else
					{
						cout << "\t" << krg.getName() << " smashed all zombies\n\n";
						score = krg.getHp() * 3;

						displayWin();

						cout << "\tCONGRATULATIONS " << krg.getName() << "!!!\n\n";

					}
					cout << "\tSCORE: " << score << "\n\n\n\n";

					if (score > highScore)
					{
						string name;

						cout << "\n\n\t\tNew HighScore!!!\n\n";
						cout << "Please enter your Name: ";
						cin.ignore(1000, '\n');
						getline(cin, name);

						ofstream fout;
						fout.open("highscore.txt", ios::trunc);
						if (fout.good())
							fout << score << " " << name;

						fout.close();
					}

					system("pause");

				}
				else
				{
					if (c != 'a' && c!='A' && c!='s' && c != 'S'&& c != 'k' && c!='K') //in case the user enters a not acetable character
						cout << "\t\n\nPlease enter a valid entry\n\n";
				}
			}
		}
			break;

		case '4':
			cout << "\n\nEXIT SELECTED!\n\n"; //exiting the game
			break;

		default:
			cout << "\n\n\n\t\tPlease enter a Valid Menu Entry!\n\n\n"; //defalt message in case of different character entry
			break;
		}

	} while (option != '4'); //keeps displaying until the option is not 4

	cout << "\n\n\n";
	displayThanks(); //display a thanks message

	system("pause");

}