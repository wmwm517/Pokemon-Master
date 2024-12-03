#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

class Pokemon
{
public:
	virtual void Skill0(Pokemon& other);
	virtual void Skill1(Pokemon& other);
	virtual void Skill2(Pokemon& other);
	virtual void Skill3(Pokemon& other);
	bool isLive();
	bool canTry(int Skillnum);
	int effect(string skillType, string pokemonType);
	void latestSkill(string latestSkill, string lasteffect);
	string name;
	string type;
	string lastskill = "-"; //constructer에서 초기화를 -로 해주기
	string lasteffect = "";
	int HP;
	int SkillCnt[4];
protected:

};

class Specification0 : public Pokemon
{
public:
	string name = "Pikachu";
	string type = "Electric";
	int HP = 35;
	string skillName[4] = {"Tackle", "Grass Knot", "Thunderbolt", "Megabolt"};
	string skillType[4] = {"Normal", "Grass", "Electric", "Electric"};
	int skillDamage[4] = {4, 8, 10, 15};
	int skillCnt[4] = {5, 5, 5, 3};
	int skillMaxCnt[4] = {5, 5, 5, 3}; 
	void Skill0(Pokemon& other);
	void Skill1(Pokemon& other);
	void Skill2(Pokemon& other);	
	void Skill3(Pokemon& other);
};

class Specification1 : public Pokemon
{
public:
	string name = "Dratini";
	string type = "Water";
	int HP = 41;
	string skillName[4] = {"Wrap", "Aqua Tail", "Water Pulse", "Hyper Beam"};
	string skillType[4] = {"Normal", "Water", "Water", "Normal"};
	int skillDamage[4] = {4, 3, 13, 20};
	int skillCnt[4] = {10, 5, 2, 1};
	int skillMaxCnt[4] = {10, 5, 2, 1};
	void Skill0(Pokemon& other);
	void Skill1(Pokemon& other);
	void Skill2(Pokemon& other);	
	void Skill3(Pokemon& other);
};

class Specification2 : public Pokemon
{
public:
	string name = "Eevee";
	string type = "Normal";
	int HP = 55;
	string skillName[4] = {"Tackle", "Sand Attack", "Bite", "Rain Dance"};
	string skillType[4] = {"Normal", "Ground", "Normal", "Water"};
	int skillDamage[4] = {4, 8, 12, 15};
	int skillCnt[4] = {5, 3, 3, 1};
	int skillMaxCnt[4] = {5, 3, 3, 1};
	void Skill0(Pokemon& other);
	void Skill1(Pokemon& other);
	void Skill2(Pokemon& other);	
	void Skill3(Pokemon& other);
};

class Specification3 : public Pokemon
{
public:
	string name = "Charmander";
	string type = "Fire";
	int HP = 39;
	string skillName[4] = {"Tackle", "Flamethrower", "Dig", "Heat Wave"};
	string skillType[4] = {"Normal", "Fire", "Ground", "Fire"};
	int skillDamage[4] = {4, 11, 7, 5};
	int skillCnt[4] = {5, 5, 5, 5};
	int skillMaxCnt[4] = {5, 5, 5, 5};
	void Skill0(Pokemon& other);
	void Skill1(Pokemon& other);
	void Skill2(Pokemon& other);	
	void Skill3(Pokemon& other);
};

class Specification4 : public Pokemon
{
public:
	string name = "Palkia";
	string type = "Water";
	int HP = 90;
	string skillName[4] = {"Hydro Pump", "Earth Power", "Surf", "Spatial Rend"};
	string skillType[4] = {"Water", "Ground", "Water", "Normal"};
	int skillDamage[4] = {12, 15, 13, 30};
	int skillCnt[4] = {10, 10, 10, 10};
	int skillMaxCnt[4] = {10, 10, 10, 10};
	void Skill0(Pokemon& other);
	void Skill1(Pokemon& other);
	void Skill2(Pokemon& other);	
	void Skill3(Pokemon& other);
};

void Specification0::Skill0(Pokemon& other)
{
	string skillName = this->skillName[0];
	string skillType = this->skillType[0];
	int skillDamage = this->skillDamage[0];
	int skillCount = this->skillCnt[0];

	if (canTry(skillCount))
	{
		int effectResult = effect(skillType, other.type);
		cout << this->name << " used " << skillName << "." << endl;
		if (effectResult == 0)
		{
			cout << "It was not very effective." << endl;
			latestSkill(skillName, "It was not very effective.");
			other.HP -= skillDamage - 3;
		}
		if (effectResult == 1)
		{
			cout << "It was effective." << endl;
			latestSkill(skillName, "It was effective.");
			other.HP -= skillDamage;
		}
		if (effectResult == 2)
		{
			cout << "It was super effective." << endl;
			latestSkill(skillName, "It was super effective.");
			other.HP -= skillDamage + 5;
		}

		skillCount -= 1;

		if (!other.isLive())
		{
			cout << "===============================================================" << endl;
			cout << "Match Result: " << this->name << " defeats " << other.name;
			exit(0);
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
	if (this->SkillCnt[Skillnum] <= 0)
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

		Pokemon p1, p2;


		for (int i=0; i<2; i++)
		{
			if(i==0){
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " <<p1.name<<" (*)                  | "<<p2.name<<"                      |" << endl;
				cout << "| Type: "<<p1.type<<"               | Type: "<<p2.type<<"                  |" << endl;
				cout << "| HP: "<<p1.HP<<"                       | HP: "<<p2.HP<<"                       |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| Latest Skill: " << p1.lastskill << "-              | Latest Skill: " << p2.lastskill << "              |" << endl;
				cout << "| " << p1.lasteffect << "                             | " << p2.lasteffect << "                             |" << endl;
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
			else if(i==1){
				cout << "+-------------------------------------------------------------+" << endl;
				cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| " <<p1.name<<"                      | "<<p2.name<<" (*)                  |" << endl;
				cout << "| Type: "<<p1.type<<"               | Type: "<<p2.type<<"                  |" << endl;
				cout << "| HP: "<<p1.HP<<"                       | HP: "<<p2.HP<<"                       |" << endl;
				cout << "+------------------------------+------------------------------+" << endl;
				cout << "| Latest Skill: "<<p1.lastskill<<"              | Latest Skill: "<<p2.lastskill<<"              |" << endl;
				cout << "| "<<p1.lasteffect<<"                             | "<<p2.lasteffect<<"                             |" << endl;
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