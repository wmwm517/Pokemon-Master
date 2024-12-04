#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

class Pokemon
{
public:
	virtual void Skill(Pokemon& other, int n) {};
	bool isLive();
	bool canTry(int Skillnum);
	int effect(string skillType, string pokemonType);
	void latestSkill(string latestSkill, string lasteffect);
	virtual string getSkillName(int n) {};
	virtual string getSkillType(int n) {};
	virtual int getSkillDamage(int n) {};
	virtual int getSkillCnt(int n) {};
	virtual int getSkillMaxCnt(int n) {};
	string name;
	string type;
	string lastskill = "-";
	string lasteffect = "";
	int HP;
	int skillCnt[4];
protected:

};



class Specification0 : public Pokemon
{
public:
	Specification0();
	string getSkillName(int n) { return skillName[n]; }
	string getSkillType(int n) { return skillType[n]; }
	int getSkillDamage(int n) { return skillDamage[n]; }
	int getSkillCnt(int n) { return skillCnt[n]; }
	int getSkillMaxCnt(int n) { return skillMaxCnt[n]; }
	string name;
	string type;
	int HP;
	string skillName[4];
	string skillType[4];
	int skillDamage[4];
	int skillCnt[4];
	int skillMaxCnt[4]; 
	void Skill(Pokemon& other, int n);
};

Specification0::Specification0(){
	name = "Dratini";
	type = "Water";
	HP = 41;
	skillName[0] = "Wrap", skillName[1] = "Aqua Tail", skillName[2] = "Water Pulse", skillName[3] = "Hyper Beam";
	skillType[0] = "Normal", skillType[1] = "Water", skillType[2] = "Water", skillType[3] = "Normal";
	skillDamage[0] = 4, skillDamage[1] = 3, skillDamage[2] = 13, skillDamage[3] = 20;
	skillCnt[0] = 10, skillCnt[1] = 5, skillCnt[2] = 2, skillCnt[3] = 1;
	skillMaxCnt[0] = 10, skillMaxCnt[1] = 5, skillMaxCnt[2] = 2, skillMaxCnt[3] = 1;
}

void Specification0::Skill(Pokemon& other, int n)
{
	this->skillName[n];
	this->skillType[n];
	this->skillDamage[n];
	this->skillCnt[n];

	if (canTry(skillCnt[n]))
	{
		int effectResult = effect(skillType[n], other.type);
		cout << this->name << " used " << skillName << "." << endl;
		if (effectResult == 0)
		{
			cout << "It was not very effective." << endl;
			latestSkill(skillName[n], "It was not very effective.");
			other.HP -= skillDamage[n] - 3;
		}
		if (effectResult == 1)
		{
			cout << "It was effective." << endl;
			latestSkill(skillName[n], "It was effective.");
			other.HP -= skillDamage[n];
		}
		if (effectResult == 2)
		{
			cout << "It was super effective." << endl;
			latestSkill(skillName[n], "It was super effective.");
			other.HP -= skillDamage[n] + 5;
		}

		this->skillCnt[n] -= 1;

		if (!other.isLive())
		{
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name;
			return;
		}
	}
	else
	{
		cout << this->name << " failed to perform " << skillName << "." << endl;
	}
}



class Specification1 : public Pokemon
{
public:
	Specification1();
	string getSkillName(int n) { return skillName[n]; }
	string getSkillType(int n) { return skillType[n]; }
	int getSkillDamage(int n) { return skillDamage[n]; }
	int getSkillCnt(int n) { return skillCnt[n]; }
	int getSkillMaxCnt(int n) { return skillMaxCnt[n]; }
	string name;
	string type;
	int HP;
	string skillName[4];
	string skillType[4];
	int skillDamage[4];
	int skillCnt[4];
	int skillMaxCnt[4]; 
	void Skill(Pokemon& other, int n);
};

Specification1::Specification1() {
	name = "Pikachu";
	type = "Electric";
	HP = 35;
	skillName[0] = "Tackle", skillName[1] = "Grass Knot", skillName[2] = "Thunderbolt", skillName[3] = "Megabolt";
	skillType[0] = "Normal", skillType[1] = "Grass", skillType[2] = "Electric", skillType[3] = "Electric";
	skillDamage[0] = 4, skillDamage[1] = 8, skillDamage[2] = 10, skillDamage[3] = 15;
	skillCnt[0] = 5, skillCnt[1] = 5, skillCnt[2] = 5, skillCnt[3] = 3;
	skillMaxCnt[0] = 5, skillMaxCnt[1] = 5, skillMaxCnt[2] = 5, skillMaxCnt[3] = 3;
}

void Specification1::Skill(Pokemon& other, int n)
{
	this->skillName[n];
	this->skillType[n];
	this->skillDamage[n];
	this->skillCnt[n];

	if (canTry(skillCnt[n]))
	{
		int effectResult = effect(skillType[n], other.type);
		cout << this->name << " used " << skillName << "." << endl;
		if (effectResult == 0)
		{
			cout << "It was not very effective." << endl;
			latestSkill(skillName[n], "It was not very effective.");
			other.HP -= skillDamage[n] - 3;
		}
		if (effectResult == 1)
		{
			cout << "It was effective." << endl;
			latestSkill(skillName[n], "It was effective.");
			other.HP -= skillDamage[n];
		}
		if (effectResult == 2)
		{
			cout << "It was super effective." << endl;
			latestSkill(skillName[n], "It was super effective.");
			other.HP -= skillDamage[n] + 5;
		}

		this->skillCnt[n] -= 1;

		if (!other.isLive())
		{
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name;
			return;
		}
	}
	else
	{
		cout << this->name << " failed to perform " << skillName << "." << endl;
	}
}



class Specification2 : public Pokemon
{
public:
	Specification2();
	string getSkillName(int n) { return skillName[n]; }
	string getSkillType(int n) { return skillType[n]; }
	int getSkillDamage(int n) { return skillDamage[n]; }
	int getSkillCnt(int n) { return skillCnt[n]; }
	int getSkillMaxCnt(int n) { return skillMaxCnt[n]; }
	string name;
	string type;
	int HP;
	string skillName[4];
	string skillType[4];
	int skillDamage[4];
	int skillCnt[4];
	int skillMaxCnt[4]; 
	void Skill(Pokemon& other, int n);
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

void Specification2::Skill(Pokemon& other, int n)
{
	this->skillName[n];
	this->skillType[n];
	this->skillDamage[n];
	this->skillCnt[n];

	if (canTry(skillCnt[n]))
	{
		int effectResult = effect(skillType[n], other.type);
		cout << this->name << " used " << skillName << "." << endl;
		if (effectResult == 0)
		{
			cout << "It was not very effective." << endl;
			latestSkill(skillName[n], "It was not very effective.");
			other.HP -= skillDamage[n] - 3;
		}
		if (effectResult == 1)
		{
			cout << "It was effective." << endl;
			latestSkill(skillName[n], "It was effective.");
			other.HP -= skillDamage[n];
		}
		if (effectResult == 2)
		{
			cout << "It was super effective." << endl;
			latestSkill(skillName[n], "It was super effective.");
			other.HP -= skillDamage[n] + 5;
		}

		this->skillCnt[n] -= 1;

		if (!other.isLive())
		{
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name;
			return;
		}
	}
	else
	{
		cout << this->name << " failed to perform " << skillName << "." << endl;
	}
}



class Specification3 : public Pokemon
{
public:
	Specification3();
	string getSkillName(int n) { return skillName[n]; }
	string getSkillType(int n) { return skillType[n]; }
	int getSkillDamage(int n) { return skillDamage[n]; }
	int getSkillCnt(int n) { return skillCnt[n]; }
	int getSkillMaxCnt(int n) { return skillMaxCnt[n]; }
	string name;
	string type;
	int HP;
	string skillName[4];
	string skillType[4];
	int skillDamage[4];
	int skillCnt[4];
	int skillMaxCnt[4]; 
	void Skill(Pokemon& other, int n);
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

void Specification3::Skill(Pokemon& other, int n)
{
	this->skillName[n];
	this->skillType[n];
	this->skillDamage[n];
	this->skillCnt[n];

	if (canTry(skillCnt[n]))
	{
		int effectResult = effect(skillType[n], other.type);
		cout << this->name << " used " << skillName << "." << endl;
		if (effectResult == 0)
		{
			cout << "It was not very effective." << endl;
			latestSkill(skillName[n], "It was not very effective.");
			other.HP -= skillDamage[n] - 3;
		}
		if (effectResult == 1)
		{
			cout << "It was effective." << endl;
			latestSkill(skillName[n], "It was effective.");
			other.HP -= skillDamage[n];
		}
		if (effectResult == 2)
		{
			cout << "It was super effective." << endl;
			latestSkill(skillName[n], "It was super effective.");
			other.HP -= skillDamage[n] + 5;
		}

		this->skillCnt[n] -= 1;

		if (!other.isLive())
		{
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name;
			return;
		}
	}
	else
	{
		cout << this->name << " failed to perform " << skillName << "." << endl;
	}
}



class Specification4 : public Pokemon
{
public:
	Specification4();
	string getSkillName(int n) { return skillName[n]; }
	string getSkillType(int n) { return skillType[n]; }
	int getSkillDamage(int n) { return skillDamage[n]; }
	int getSkillCnt(int n) { return skillCnt[n]; }
	int getSkillMaxCnt(int n) { return skillMaxCnt[n]; }
	string name;
	string type;
	int HP;
	string skillName[4];
	string skillType[4];
	int skillDamage[4];
	int skillCnt[4];
	int skillMaxCnt[4]; 
	void Skill(Pokemon& other, int n);
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

void Specification4::Skill(Pokemon& other, int n)
{
	this->skillName[n];
	this->skillType[n];
	this->skillDamage[n];
	this->skillCnt[n];

	if (canTry(skillCnt[n]))
	{
		int effectResult = effect(skillType[n], other.type);
		cout << this->name << " used " << skillName << "." << endl;
		if (effectResult == 0)
		{
			cout << "It was not very effective." << endl;
			latestSkill(skillName[n], "It was not very effective.");
			other.HP -= skillDamage[n] - 3;
		}
		if (effectResult == 1)
		{
			cout << "It was effective." << endl;
			latestSkill(skillName[n], "It was effective.");
			other.HP -= skillDamage[n];
		}
		if (effectResult == 2)
		{
			cout << "It was super effective." << endl;
			latestSkill(skillName[n], "It was super effective.");
			other.HP -= skillDamage[n] + 5;
		}

		this->skillCnt[n] -= 1;

		if (!other.isLive())
		{
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name;
			return;
		}
	}
	else
	{
		cout << this->name << " failed to perform " << skillName << "." << endl;
	}
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
	// 0:효과별로, 1:효과짱, 2:효과대박짱

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
}

void Pokemon::latestSkill(string latestSkillName, string latestEffect)
{
	this->lastskill = latestSkillName;
	this->lasteffect = latestEffect;
}

int main()
{
	bool isRunning = true;
	while (isRunning)
	{
		int num1, num2;
		cout << "Choose a Pokemon(0~4): ";
		cin >> num1;
		cout << "Choose a Pokemon(0~4): ";
		cin >> num2;

		if (num2 == num1);
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

		for (int i=0; i<2; i++)
		{
			int skillnum;
			if(i==0){
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " <<p1->name<<" (*)                  | "<<p2->name<<"                      |" << endl;
				cout << "| Type: "<<p1->type<<"               | Type: "<<p2->type<<"                  |" << endl;
				cout << "| HP: "<<p1->HP<<"                       | HP: "<<p2->HP<<"                       |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| Latest Skill: " << p1->lastskill << "-              | Latest Skill: " << p2->lastskill << "              |" << endl;
				cout << "| " << p1->lasteffect << "                             | " << p2->lasteffect << "                             |" << endl;
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
				p1->Skill(*p2, skillnum);
			}
			else if(i==1){
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " <<p1->name<<"                      | "<<p2->name<<" (*)                  |" << endl;
				cout << "| Type: "<<p1->type<<"               | Type: "<<p2->type<<"                  |" << endl;
				cout << "| HP: "<<p1->HP<<"                       | HP: "<<p2->HP<<"                       |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| Latest Skill: "<<p1->lastskill<<"              | Latest Skill: "<<p2->lastskill<<"              |" << endl;
				cout << "| "<<p1->lasteffect<<"                             | "<<p2->lasteffect<<"                             |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| (0) Tackle                   | (0) Wrap                     |" << endl;
				cout << "|     - Type: Normal           |     - Type: Normal           |" << endl;
				cout << "|     - Damage: 4              |     - Damage: 4              |" << endl;
				cout << "|     - Count: 5(5)            |     - Count: 10(10)          |" << endl;
				cout << "| (1) Grass Knot               | (1) Aqua Tail                |" << endl;
				cout << "|     - Type: Grass            |     - Type: Water            |" << endl;
				cout << "|     - Damage: 8              |     - Damage: 3              |" << endl;
				cout << "|     - Count: 5(5)            |     - Count: 5(5)            |" << endl;
				cout << "| (2) Thunderbolt              | (2) Water Pulse              |" << endl;
				cout << "|     - Type: Electric         |     - Type: Water            |" << endl;
				cout << "|     - Damage: 10             |     - Damage: 13             |" << endl;
				cout << "|     - Count: 5(5)            |     - Count: 2(2)            |" << endl;
				cout << "| (3) Megabolt                 | (3) Hyper Beam               |" << endl;
				cout << "|     - Type: Electric         |     - Type: Normal           |" << endl;
				cout << "|     - Damage: 15             |     - Damage: 20             |" << endl;
				cout << "|     - Count: 3(3)            |     - Count: 1(1)            |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "Choose a skill (0~3): ";	
			}

		}

		break;
	}
}