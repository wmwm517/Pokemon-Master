#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <iomanip>

using namespace std;

string printWhitespace(int n); // Function to print whitespace n times

class Pokemon
// A class that stores various stats of a Pokemon and has functions accordingly.
{
public:
	void Skill(Pokemon& other, int n);
	// Function called when a Pokemon uses a skill
	// other = defense Pokemon
	bool isLive(); 
	// Function to determine whether a Pokemon's HP has become 0
	bool canTry(int Skillnum);
	// Function to determine whether a Pokemon can use nth skill
	int effect(string skillType, string pokemonType);
	// Function that returns what the effect of the attacking Pokemon's skill was.
	void latestSkill(string latestSkill, string lasteffect);
	// Function that stores the skills used in the previous turn and their effects
	
	// getter Function
	// It's called when the battle screen is drawn
	string getName() { return name; }
	string getType() { return type; }
	int getHP() { return HP; }
	string getLastskill() { return lastskill; }
	string getLasteffect() { return lasteffect; }
	string getSkillName(int n) { return skillName[n]; }
	string getSkillType(int n) { return skillType[n]; }
	int getSkillDamage(int n) { return skillDamage[n]; }
	int getSkillCnt(int n) { return skillCnt[n]; }
	int getSkillMaxCnt(int n) { return skillMaxCnt[n]; }
	
protected:
	string name;
	string type;
	int HP;
	// Expressed as an array to implement 4 skills
	string skillName[4];
	string skillType[4];
	int skillDamage[4];
	int skillCnt[4];
	int skillMaxCnt[4]; 
	// Sets the initial values ​​of skills and effects used in the previous turn.
	string lastskill = "-";
	string lasteffect = "";
};

void Pokemon::Skill(Pokemon& other, int n)
{
	// Call the nth value in the skill list
	this->skillName[n];
	this->skillType[n];
	this->skillDamage[n];
	this->skillCnt[n];
	// Determine whether Pokemon can use nth skill
	if (canTry(n))
	{	
		// Save the effect of a skill through the effect function
		int effectResult = effect(skillType[n], other.type);
		// Prints out that the skill was used
		cout << this->name << " used " << skillName[n] << "." << endl;
		// Reduces HP differently depending on the skill's level of effect.
		// If the skill is not very effective, the damage of the skill decrease by 3.
		// If the skill is effective, the damage of the skill is maintained
		// If the skill is not very effective, the damage of the skill increase by .
		if (effectResult == 0)
		{
			cout << "It was not very effective." << endl << endl;
			latestSkill(skillName[n], "It was not very effective.");
			other.HP -= skillDamage[n] - 3;
		}
		if (effectResult == 1)
		{
			cout << "It was effective." << endl << endl;
			latestSkill(skillName[n], "It was effective.");
			other.HP -= skillDamage[n];
		}
		if (effectResult == 2)
		{
			cout << "It was super effective." << endl << endl;
			latestSkill(skillName[n], "It was super effective.");
			other.HP -= skillDamage[n] + 5;
		}

		// Reduces the number of uses of the nth skill by one
		this->skillCnt[n] -= 1;

		// After using the skill, determine whether the HP of the other Pokemon becomes 0.
		if (!other.isLive())
		{
			// Prints the winning and losing Pokémon
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name << endl;
			// terminates the program.
			exit(0);
		}
	}
	// If the Pokemon can't use nth skill, prints it
	else
	{
		cout << this->name << " failed to perform " << skillName[n] << "." << endl << endl;
	}
}


class Specification0 : public Pokemon
// A class that inherits from a class called Pokemon and stores the stats of a specific Pokemon.
// Pokemon No.0: Pikachu
{
public:
	Specification0();
};

Specification0::Specification0(){
	// Initializing Pikachu’s stats
	name = "Pikachu";
	type = "Electric";
	HP = 35;
	skillName[0] = "Tackle", skillName[1] = "Grass Knot", skillName[2] = "Thunderbolt", skillName[3] = "Megabolt";
	skillType[0] = "Normal", skillType[1] = "Grass", skillType[2] = "Electric", skillType[3] = "Electric";
	skillDamage[0] = 4, skillDamage[1] = 8, skillDamage[2] = 10, skillDamage[3] = 15;
	skillCnt[0] = 5, skillCnt[1] = 5, skillCnt[2] = 5, skillCnt[3] = 3;
	skillMaxCnt[0] = 5, skillMaxCnt[1] = 5, skillMaxCnt[2] = 5, skillMaxCnt[3] = 3;
}




class Specification1 : public Pokemon
// Same as Specification0 class
// Pokemon No.1: Dratini
{
public:
	Specification1();
};

Specification1::Specification1() {
	// Initializing Dratini’s stats
	name = "Dratini";
	type = "Water";
	HP = 41;
	skillName[0] = "Wrap", skillName[1] = "Aqua Tail", skillName[2] = "Water Pulse", skillName[3] = "Hyper Beam";
	skillType[0] = "Normal", skillType[1] = "Water", skillType[2] = "Water", skillType[3] = "Normal";
	skillDamage[0] = 4, skillDamage[1] = 3, skillDamage[2] = 13, skillDamage[3] = 20;
	skillCnt[0] = 10, skillCnt[1] = 5, skillCnt[2] = 2, skillCnt[3] = 1;
	skillMaxCnt[0] = 10, skillMaxCnt[1] = 5, skillMaxCnt[2] = 2, skillMaxCnt[3] = 1;
}




class Specification2 : public Pokemon
// Same as Specification0 class
// Pokemon No.2: Eevee
{
public:
	Specification2();
};

Specification2::Specification2() {
	// Initializing Eevee’s stats
	name = "Eevee";
	type = "Normal";
	HP = 55;
	skillName[0] = "Tackle", skillName[1] = "Sand Attack", skillName[2] = "Bite", skillName[3] = "Rain Dance";
	skillType[0] = "Normal", skillType[1] = "Ground", skillType[2] = "Normal", skillType[3] = "Water";
	skillDamage[0] = 4, skillDamage[1] = 8, skillDamage[2] = 12, skillDamage[3] = 15;
	skillCnt[0] = 5, skillCnt[1] = 3, skillCnt[2] = 3, skillCnt[3] = 1;
	skillMaxCnt[0] = 5, skillMaxCnt[1] = 3, skillMaxCnt[2] = 3, skillMaxCnt[3] = 1;	
}



class Specification3 : public Pokemon
// Same as Specification0 class
// Pokemon No.3: Charmander
{
public:
	Specification3();
};

Specification3::Specification3() {
	// Initializing Charmander’s stats
	name = "Charmander";
	type = "Fire";
	HP = 39;
	skillName[0] = "Tackle", skillName[1] = "Flamethrower", skillName[2] = "Dig", skillName[3] = "Heat Wave";
	skillType[0] = "Normal", skillType[1] = "Fire", skillType[2] = "Ground", skillType[3] = "Fire";
	skillDamage[0] = 4, skillDamage[1] = 11, skillDamage[2] = 7, skillDamage[3] = 14;
	skillCnt[0] = 5, skillCnt[1] = 5, skillCnt[2] = 5, skillCnt[3] = 5;
	skillMaxCnt[0] = 5, skillMaxCnt[1] = 5, skillMaxCnt[2] = 5, skillMaxCnt[3] = 5;	
}




class Specification4 : public Pokemon
// Same as Specification0 class
// Pokemon No.4: Palkia
{
public:
	Specification4();
};

Specification4::Specification4() {
	// Initializing Palkia’s stats
	name = "Palkia";
	type = "Water";
	HP = 90;
	skillName[0] = "Hydro Pump", skillName[1] = "Earth Power", skillName[2] = "Surf", skillName[3] = "Spatial Rend";
	skillType[0] = "Water", skillType[1] = "Ground", skillType[2] = "Water", skillType[3] = "Normal";
	skillDamage[0] = 12, skillDamage[1] = 15, skillDamage[2] = 13, skillDamage[3] = 30;
	skillCnt[0] = 10, skillCnt[1] = 10, skillCnt[2] = 10, skillCnt[3] = 10;
	skillMaxCnt[0] = 10, skillMaxCnt[1] = 10, skillMaxCnt[2] = 10, skillMaxCnt[3] = 10;	
}




bool Pokemon::isLive()
// Function to determine whether a Pokemon's HP has become 0
{	
	// If Poemon's HP is lower than 0, return false
	// Otherwise, return true
	if (this->HP <= 0)
	{
		return false;
	}
	return true;
}

bool Pokemon::canTry(int Skillnum)
// Function to determine whether a Pokemon can use nth skill
{	
	// If Pokemon's nth skill count is lower than 0, return false
	// Otherwise, return true
	if (this->skillCnt[Skillnum] <= 0)
	{
		return false;
	}
	return true;
}

int Pokemon::effect(string skillType, string pokemonType)
{
	// Function that returns what the effect of the attacking Pokemon's skill was.
	// If the skill was not very effective, return 0.
	// If the skill was effective, return 1.
	// If the skill was super effective, return 2.

	if (skillType == "Normal")
	{
		return 1;
	}
	else if (skillType == "Ground")
	{
		if (pokemonType == "Normal" || pokemonType == "Ground" || pokemonType == "Water")
		{
			return 1;
		}
		else if (pokemonType == "Electric" || pokemonType == "Fire")
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	else if (skillType == "Electric")
	{
		if (pokemonType == "Normal" || pokemonType == "Fire")
		{
			return 1;
		}
		else if (pokemonType == "Ground" || pokemonType == "Electric" || pokemonType == "Grass")
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	else if (skillType == "Water")
	{
		if (pokemonType == "Normal" || pokemonType == "Electric")
		{
			return 1;
		}
		else if (pokemonType == "Water" || pokemonType == "Grass")
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	else if (skillType == "Grass")
	{
		if (pokemonType == "Normal" || pokemonType == "Electric")
		{
			return 1;
		}
		else if (pokemonType == "Water")
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	else if (skillType == "Fire")
	{
		if (pokemonType == "Normal" || pokemonType == "Ground" || pokemonType == "Electric")
		{
			return 1;
		}
		else if (pokemonType == "Water" || pokemonType == "Fire")
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	return 0;
}

void Pokemon::latestSkill(string latestSkillName, string latestEffect)
{
	this->lastskill = latestSkillName;
	this->lasteffect = latestEffect;
}

string printWhitespace(int n)
// Function to return n whitespace
// Used to maintain line spacing on the battle screen
{
	string str = "";
	for (int i = 0; i < n; i++)
	{
		str += " ";
	}
	return str;
}

int main()
{
	// The battle turn must be repeated until the HP of either Pokémon reaches 0.
	bool isRunning = true;
	
	// Receive the value of two Pokemon from the user
	int num1, num2;
	cout << "Choose a Pokemon(0~4): ";
	cin >> num1;
	cout << "Choose a Pokemon(0~4): ";
	cin >> num2;

	// If the two Pokémon are the same, print a text and end the program.
	if (num2 == num1)
	{
		cout << "You have to choose Pokemons different from each other.";
		return 0;
	}	

	// If the two Pokémon are the same, print a text and end the program.
	Pokemon *p1;
	Pokemon *p2;

	// Specifies the class inherited from pokemon according to the value received from the user.
	if (num1 == 0)
	{
		p1 = new Specification0();
	}
	else if (num1 == 1)
	{
		p1 = new Specification1();
	}
	else if (num1 == 2)
	{
		p1 = new Specification2();
	}
	else if (num1 == 3)
	{
	p1 = new Specification3();
	}
	else if (num1 == 4)
	{
		p1 = new Specification4();
	}

	if (num2 == 0)
	{
		p2 = new Specification0();
	}
	else if (num2 == 1)
	{
		p2 = new Specification1();
	}
	else if (num2 == 2)
	{
		p2 = new Specification2();
	}
	else if (num2 == 3)
	{
		p2 = new Specification3();
	}
	else if (num2 == 4)
	{
	p2 = new Specification4();
	}

	while (isRunning)
	{
		for (int i=0; i<2; i++)
		// Draw a battle screen
		// Implement p1’s turn and p2’s turn separately.
		{
			int skillnum; // skillnumth skill will be used
			if (i == 0) {
				// p1's turn
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " << left << setw(29) << p1->getName() + " (*)" << "|";
				cout << " " << left << setw(29) << p2->getName() << "|" << endl;
				cout << "| Type: " << left << setw(23) << p1->getType() << "|";
				cout << " Type: " << left << setw(23) << p2->getType() << "|"  << endl;
				cout << "| HP: " << left << setw(25) << p1->getHP() << "|";
				cout << " HP: " << left << setw(25) << p2->getHP() << "|" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| Latest Skill: " << left << setw(15) << p1->getLastskill() << "|";
				cout << " Latest Skill: " << left << setw(15) << p2->getLastskill() << "|" << endl;
				cout << "| " << left << setw(29) << p1->getLasteffect() << "| ";
				cout << left << setw(29) << p2->getLasteffect() << "|" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| (0) " << left << setw(25) << p1->getSkillName(0) << "|";
				cout << " (0) " << left << setw(25) << p2->getSkillName(0)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(0) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(0) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(0) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(0) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(0) << "(" << p1->getSkillMaxCnt(0) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(0)).length() + to_string(p1->getSkillMaxCnt(0)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(0) << "(" << p2->getSkillMaxCnt(0) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(0)).length() + to_string(p2->getSkillMaxCnt(0)).length())) <<"|" << endl;
				cout << "| (1) " << left << setw(25) << p1->getSkillName(1) << "|";
				cout << " (1) " << left << setw(25) << p2->getSkillName(1)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(1) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(1) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(1) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(1) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(1) << "(" << p1->getSkillMaxCnt(1) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(1)).length() + to_string(p1->getSkillMaxCnt(1)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(1) << "(" << p2->getSkillMaxCnt(1) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(1)).length() + to_string(p2->getSkillMaxCnt(1)).length())) <<"|" << endl;
				cout << "| (2) " << left << setw(25) << p1->getSkillName(2) << "|";
				cout << " (2) " << left << setw(25) << p2->getSkillName(2)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(2) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(2) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(2) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(2) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(2) << "(" << p1->getSkillMaxCnt(2) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(2)).length() + to_string(p1->getSkillMaxCnt(2)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(2) << "(" << p2->getSkillMaxCnt(2) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(2)).length() + to_string(p2->getSkillMaxCnt(2)).length())) <<"|" << endl;
				cout << "| (3) " << left << setw(25) << p1->getSkillName(3) << "|";
				cout << " (3) " << left << setw(25) << p2->getSkillName(3)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(3) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(3) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(3) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(3) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(3) << "(" << p1->getSkillMaxCnt(3) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(3)).length() + to_string(p1->getSkillMaxCnt(3)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(3) << "(" << p2->getSkillMaxCnt(3) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(3)).length() + to_string(p2->getSkillMaxCnt(3)).length())) <<"|" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				
				// Receives the index value of the skill to be used by p1 from the user.
				cout << "Choose a skill (0~3): ";
				cin >> skillnum;

				// p1(attacker) uses skillnumth skill to p2(defender)
				p1->Skill(*p2, skillnum);
			}
			else if (i== 1) {
				// p2's turn
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " << left << setw(29) << p1->getName() << "|";
				cout << " " << left << setw(29) << p2->getName() + " (*)" << "|" << endl;
				cout << "| Type: " << left << setw(23) << p1->getType() << "|";
				cout << " Type: " << left << setw(23) << p2->getType() << "|"  << endl;
				cout << "| HP: " << left << setw(25) << p1->getHP() << "|";
				cout << " HP: " << left << setw(25) << p2->getHP() << "|" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| Latest Skill: " << left << setw(15) << p1->getLastskill() << "|";
				cout << " Latest Skill: " << left << setw(15) << p2->getLastskill() << "|" << endl;
				cout << "| " << left << setw(29) << p1->getLasteffect() << "| ";
				cout << left << setw(29) << p2->getLasteffect() << "|" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| (0) " << left << setw(25) << p1->getSkillName(0) << "|";
				cout << " (0) " << left << setw(25) << p2->getSkillName(0)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(0) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(0) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(0) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(0) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(0) << "(" << p1->getSkillMaxCnt(0) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(0)).length() + to_string(p1->getSkillMaxCnt(0)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(0) << "(" << p2->getSkillMaxCnt(0) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(0)).length() + to_string(p2->getSkillMaxCnt(0)).length())) <<"|" << endl;
				cout << "| (1) " << left << setw(25) << p1->getSkillName(1) << "|";
				cout << " (1) " << left << setw(25) << p2->getSkillName(1)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(1) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(1) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(1) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(1) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(1) << "(" << p1->getSkillMaxCnt(1) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(1)).length() + to_string(p1->getSkillMaxCnt(1)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(1) << "(" << p2->getSkillMaxCnt(1) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(1)).length() + to_string(p2->getSkillMaxCnt(1)).length())) <<"|" << endl;
				cout << "| (2) " << left << setw(25) << p1->getSkillName(2) << "|";
				cout << " (2) " << left << setw(25) << p2->getSkillName(2)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(2) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(2) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(2) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(2) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(2) << "(" << p1->getSkillMaxCnt(2) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(2)).length() + to_string(p1->getSkillMaxCnt(2)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(2) << "(" << p2->getSkillMaxCnt(2) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(2)).length() + to_string(p2->getSkillMaxCnt(2)).length())) <<"|" << endl;
				cout << "| (3) " << left << setw(25) << p1->getSkillName(3) << "|";
				cout << " (3) " << left << setw(25) << p2->getSkillName(3)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(3) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(3) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(3) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(3) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(3) << "(" << p1->getSkillMaxCnt(3) << ")" << printWhitespace(14 - (to_string(p1->getSkillCnt(3)).length() + to_string(p1->getSkillMaxCnt(3)).length())) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(3) << "(" << p2->getSkillMaxCnt(3) << ")" << printWhitespace(14 - (to_string(p2->getSkillCnt(3)).length() + to_string(p2->getSkillMaxCnt(3)).length())) <<"|" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				
				// Receives the index value of the skill to be used by p1 from the user.
				cout << "Choose a skill (0~3): ";
				cin >> skillnum;

				// p2(attacker) uses skillnumth skill to p1(defender)
				p2->Skill(*p1, skillnum);
			}
		}
	}
}