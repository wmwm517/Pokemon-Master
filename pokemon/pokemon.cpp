#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <iomanip>

using namespace std;
string printWhitespace(int n);

class Pokemon
{
public:
	void Skill(Pokemon& other, int n);
	bool isLive();
	bool canTry(int Skillnum);
	int effect(string skillType, string pokemonType);
	void latestSkill(string latestSkill, string lasteffect);
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
	string skillName[4];
	string skillType[4];
	int skillDamage[4];
	int skillCnt[4];
	int skillMaxCnt[4]; 
	string lastskill = "-";
	string lasteffect = "";
};

void Pokemon::Skill(Pokemon& other, int n)
{
	this->skillName[n];
	this->skillType[n];
	this->skillDamage[n];
	this->skillCnt[n];

	if (canTry(skillCnt[n]))
	{
		int effectResult = effect(skillType[n], other.type);
		cout << this->name << " used " << skillName[n] << "." << endl;
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

		this->skillCnt[n] -= 1;

		if (!other.isLive())
		{
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name << endl;
			exit(0);
		}
	}
	else
	{
		cout << this->name << " failed to perform " << skillName[n] << "." << endl << endl;
	}
}


class Specification0 : public Pokemon
{
public:
	Specification0();
};

Specification0::Specification0(){
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
{
public:
	Specification1();
};

Specification1::Specification1() {
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
{
public:
	Specification2();
};

Specification2::Specification2() {
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
{
public:
	Specification3();
};

Specification3::Specification3() {
	name = "Charamander";
	type = "Fire";
	HP = 39;
	skillName[0] = "Tackle", skillName[1] = "Flamethrower", skillName[2] = "Dig", skillName[3] = "Heat Wave";
	skillType[0] = "Normal", skillType[1] = "Fire", skillType[2] = "Ground", skillType[3] = "Fire";
	skillDamage[0] = 4, skillDamage[1] = 11, skillDamage[2] = 7, skillDamage[3] = 14;
	skillCnt[0] = 5, skillCnt[1] = 5, skillCnt[2] = 5, skillCnt[3] = 5;
	skillMaxCnt[0] = 5, skillMaxCnt[1] = 5, skillMaxCnt[2] = 5, skillMaxCnt[3] = 5;	
}




class Specification4 : public Pokemon
{
public:
	Specification4();
};

Specification4::Specification4() {
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
{
	if (this->HP <= 0)
	{
		return false;
	}
	return true;
}

bool Pokemon::canTry(int Skillnum)
{
	if (this->skillCnt[Skillnum] <= 0)
	{
		return false;
	}
	return true;
}

int Pokemon::effect(string skillType, string pokemonType)
{
	// 0:"It was not very effective", 1:"It was effective", 2:"It was super effective"

	if (skillType == "Normal")
	{
		return 1;
	}
	else if (skillType == "Ground")
	{
		if (pokemonType == "Normal" || pokemonType == "Ground" || pokemonType == "Fire")
		{
			return 1;
		}
		else if (pokemonType == "Electric" || pokemonType == "Grass")
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
		if (pokemonType == "Normal" || pokemonType == "Water" ||
			pokemonType == "Grass" || pokemonType == "Fire")
		{
			return 1;
		}
		else if (pokemonType == "Electric")
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
		if (pokemonType == "Normal" || pokemonType == "Ground")
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
	else if (skillType == "Grass")
	{
		if (pokemonType == "Normal")
		{
			return 1;
		}
		else if (pokemonType == "Fire")
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
		if (pokemonType == "Normal" || pokemonType == "Electric")
		{
			return 1;
		}
		else if (pokemonType == "Grass" || pokemonType == "Fire")
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
{
	string str = "";
	for (int i; i < n; i++)
	{
		str += " ";
	}
	return str;
}

int main()
{
	bool isRunning = true;
	int num1, num2;
	cout << "Choose a Pokemon(0~4): ";
	cin >> num1;
	cout << "Choose a Pokemon(0~4): ";
	cin >> num2;

	if (num2 == num1)
	{
		cout << "You have to choose Pokemons different from each other.";
		return 0;
	}	
	Pokemon *p1;
	Pokemon *p2;

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
		{
			int skillnum;
			if (i == 0) {
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " << p1->getName() << " (*)" << printWhitespace(25 - p1->getName().length()) << "|";
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
				cout << "|     - Count: " << p1->getSkillCnt(0) << "(" << p1->getSkillMaxCnt(0) << ")" << printWhitespace(14 - to_string(p1->getSkillCnt(0)).length() - to_string(p1->getSkillMaxCnt(0)).length()) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(0) << "(" << p2->getSkillMaxCnt(0) << ")" << printWhitespace(14 - to_string(p2->getSkillCnt(0)).length() - to_string(p2->getSkillMaxCnt(0)).length()) <<"|" << endl;
				cout << "| (1) " << left << setw(25) << p1->getSkillName(1) << "|";
				cout << " (1) " << left << setw(25) << p2->getSkillName(1)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(1) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(1) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(1) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(1) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(1) << "(" << p1->getSkillMaxCnt(1) << ")" << printWhitespace(14 - to_string(p1->getSkillCnt(1)).length() - to_string(p1->getSkillMaxCnt(1)).length()) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(1) << "(" << p2->getSkillMaxCnt(1) << ")" << printWhitespace(14 - to_string(p2->getSkillCnt(1)).length() - to_string(p2->getSkillMaxCnt(1)).length()) <<"|" << endl;
				cout << "| (2) " << left << setw(25) << p1->getSkillName(2) << "|";
				cout << " (2) " << left << setw(25) << p2->getSkillName(2)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(2) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(2) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(2) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(2) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(2) << "(" << p1->getSkillMaxCnt(2) << ")" << printWhitespace(14 - to_string(p1->getSkillCnt(2)).length() - to_string(p1->getSkillMaxCnt(2)).length()) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(2) << "(" << p2->getSkillMaxCnt(2) << ")" << printWhitespace(14 - to_string(p2->getSkillCnt(2)).length() - to_string(p2->getSkillMaxCnt(2)).length()) <<"|" << endl;
				cout << "| (3) " << left << setw(25) << p1->getSkillName(3) << "|";
				cout << " (3) " << left << setw(25) << p2->getSkillName(3)  << "|" << endl;
				cout << "|     - Type: " << left << setw(17) << p1->getSkillType(3) << "|";
				cout << "     - Type: " << left << setw(17) << p2->getSkillType(3) << "|" << endl;
				cout << "|     - Damage: " << left << setw(15) << p1->getSkillDamage(3) <<"|";
				cout << "     - Damage: " << left << setw(15) << p2->getSkillDamage(3) << "|" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(3) << "(" << p1->getSkillMaxCnt(3) << ")" << printWhitespace(14 - to_string(p1->getSkillCnt(3)).length() - to_string(p1->getSkillMaxCnt(3)).length()) << "|";
				cout << "     - Count: "  << p2->getSkillCnt(3) << "(" << p2->getSkillMaxCnt(3) << ")" << printWhitespace(14 - to_string(p2->getSkillCnt(3)).length() - to_string(p2->getSkillMaxCnt(3)).length()) <<"|" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "Choose a skill (0~3): ";
				cin >> skillnum;
				p1->Skill(*p2, skillnum);
			}
			else if (i== 1) {
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " << p1->getName() <<"                      | "<< p2->getName() << " (*)                  |" << endl;
				cout << "| Type: "<< p1->getType() <<"               | Type: "<< p2->getType() <<"                  |" << endl;
				cout << "| HP: " << p1->getHP() << "                       | HP: " << p2->getHP() << "                       |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| Latest Skill: " << p1->getLastskill() << "              | Latest Skill: " << p2->getLastskill() << "              |" << endl;
				cout << "| " << p1->getLasteffect() << "                             | " << p2->getLasteffect() << "                             |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| (0) " << p1->getSkillName(0) << "                   | (0) " << p2->getSkillName(0) << "                     |" << endl;
				cout << "|     - Type: " << p1->getSkillType(0) << "           |     - Type: " << p2->getSkillType(0) << "           |" << endl;
				cout << "|     - Damage: " << p1->getSkillDamage(0) << "              |     - Damage: " << p2->getSkillDamage(0) << "              |" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(0) << "(" << p1->getSkillMaxCnt(0) << ")           |     - Count: " << p2->getSkillCnt(0) << "(" << p2->getSkillMaxCnt(0) << ")" << "          |" << endl;
				cout << "| (1) " << p1->getSkillName(1) << "               | (1) " << p2->getSkillName(1) << "                |" << endl;
				cout << "|     - Type: " << p1->getSkillType(1) << "            |     - Type: " << p2->getSkillType(1) << "            |" << endl;
				cout << "|     - Damage: " << p1->getSkillDamage(1) << "              |     - Damage: " << p2->getSkillDamage(1) << "              |" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(1) << "(" << p1->getSkillMaxCnt(1) << ")           |     - Count: " << p2->getSkillCnt(1) << "(" << p2->getSkillMaxCnt(1) << ")" << "          |" << endl;
				cout << "| (2) " << p1->getSkillName(2) << "               | (2) " << p2->getSkillName(2) << "                |" << endl;
				cout << "|     - Type: " << p1->getSkillType(2) << "            |     - Type: " << p2->getSkillType(2) << "            |" << endl;
				cout << "|     - Damage: " << p1->getSkillDamage(2) << "              |     - Damage: " << p2->getSkillDamage(2) << "              |" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(2) << "(" << p1->getSkillMaxCnt(2) << ")           |     - Count: " << p2->getSkillCnt(2) << "(" << p2->getSkillMaxCnt(2) << ")" << "          |" << endl;
				cout << "| (3) " << p1->getSkillName(3) << "               | (3) " << p2->getSkillName(3) << "                |" << endl;
				cout << "|     - Type: " << p1->getSkillType(3) << "            |     - Type: " << p2->getSkillType(3) << "            |" << endl;
				cout << "|     - Damage: " << p1->getSkillDamage(3) << "              |     - Damage: " << p2->getSkillDamage(3) << "              |" << endl;
				cout << "|     - Count: " << p1->getSkillCnt(3) << "(" << p1->getSkillMaxCnt(3) << ")           |     - Count: " << p2->getSkillCnt(3) << "(" << p2->getSkillMaxCnt(3) << ")" << "          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "Choose a skill (0~3): ";
				cin >> skillnum;
				p2->Skill(*p1, skillnum);
			}
		}
	}
}