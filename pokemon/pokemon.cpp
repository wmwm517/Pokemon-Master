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
protected:
	string name;
	string type;
	string lastskill;
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
		break;
	}
}