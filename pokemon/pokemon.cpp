#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

class Pokemon
{
public:
	void Skill0(Pokemon& other);
	void Skill1(Pokemon& other);
	void Skill2(Pokemon& other);
	void Skill3(Pokemon& other);
	bool isLive();
	bool canTry(int Skillnum);
	int effect(string skillType, string pokemonType);
	void latestSkill(); //쫌이따짜기
protected:
	string name;
	string type;
	string lastskill;
	string lasteffect;
	int HP;
	int Skillcnt[4];
};

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
	if (this->Skillcnt[Skillnum] <= 0)
	{
		return false;
	}
	return true;
}

int Pokemon::effect(string skillType, string pokemonType)
{
	//표짜ㅇㅑ됨^^
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
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
			cout << "+------------------------------+------------------------------+" << endl;
			cout << "| Pikachu (*)                  | Dratini                      |" << endl;
			cout << "| Type: Electric               | Type: Water                  |" << endl;
			cout << "| HP: 35                       | HP: 41                       |" << endl;
			cout << "+------------------------------+------------------------------+" << endl;
			cout << "| Latest Skill: -              | Latest Skill: -              |" << endl;
			cout << "|                              |                              |" << endl;
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

		break;
	}
}