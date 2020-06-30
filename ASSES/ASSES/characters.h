#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//Soldier Class
class SOLDIERS{
private:
	string name;
	int level, hp, strenght, shield;
	float specialAttack;
	

public:
	void setUpSoldier(string);
	int attack();
	void takingDamage(int);
	bool dead();
	int getHp();
	string getName();
	int punch();
	int shoot();
	void displaySoldier();
	

};

//Asari Class
class ASARI{
private:
	string name;
	int level, hp, strenght, shield;
	float specialAttack;

public:
	void setUpAsari(string);
	int attack();
	void takingDamage(int);
	bool dead();
	int getHp();
	string getName();
	int bionic();
	int shoot();
	void displayAsari();
	

};


class KROGAN{
private:
	string name;
	int level, hp, strenght, shield;
	float specialAttack;

public:
	void setUpKrogan(string);
	int attack();
	void takingDamage(int);
	bool dead();
	int getHp();
	string getName();
	int punch();
	int shotgun();
	void displayKrogan();

};



//ENEMIES classes
class ZOMBIE{
private:
	string name;
	int level, hp, strenght, shield;
	float specialAttack;

public:
	void setUpZombie(string);
	int attack();
	void takingDamage(int);
	bool dead();
	int getHp();
	string getName();
	


};

void displayWelcome();
void displayThanks();
void displayTurn();
void displayChoiceA();
void displayChoiceS();
void displayChoiceK();
void displayInstructions();

void displayWin();

void displayLost();

/*class myException : public exception{
public:
	virtual const char* what() const throw(){
		return ""
	}

};
*/

