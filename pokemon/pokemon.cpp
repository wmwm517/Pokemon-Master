#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void SelectPokemon();
void PrintBattle(const Pokemon& p1, const Pokemon& p2);
void ChooseSkill(Pokemon& a, Pokemon& d);
string UseSkill(Pokemon& a, Pokemon& d);

class Skill {
public:
	string name;
	string type;
	int damege;
	int count;

	Skill(const std::string& name, const std::string& type, int damege, int count)
		: name(name), type(type), damege(damege), count(count) {}
};

class Pokemon
{
public:
	virtual void setName(const std::string& name) { this->name = name; }
	virtual void setHP(int hp) { this->HP = hp; }
	virtual void setType(const std::string& type) { this->type = type; }
	virtual void setSkill(const std::string& skill, const std::string& type, int damege, int count) {}
	vector<Skill> s;

	string getName() const { return name; }
	int getHP() const { return HP; }
	string getType() const { return type; }

private:
	string name;
	string type;
	int HP;
};

class PokemonBuilder
{
private:
	Pokemon p;
public:
	PokemonBuilder& setName(const std::string& name) {
		p.setName(name);
		return *this;
	}
	PokemonBuilder& setHP(int hp) {
		p.setHP(hp);
		return *this;
	}
	PokemonBuilder& setType(const std::string& type) {
		p.setType(type);
		return *this;
	}
	PokemonBuilder& setSkill(const std::string& skill, const std::string& type, int damege, int count) {
		p.s.emplace_back(skill, type, damege, count);
		return *this;
	}
	Pokemon build() {
		return p;
	}
};

std::vector<Pokemon> createPokemons(){
	std::vector<Pokemon> pokemons;

	pokemons.push_back(PokemonBuilder()
		.setName("Pikachu")
		.setHP(35)
		.setType("Electric")
		.setSkill("Tackle", "Normal", 4, 5)
		.setSkill("Grass Knot", "Grass", 8, 5)
		.setSkill("Thunderbolt", "Electric", 10, 5)
		.setSkill("Megabolt", "Electric", 15, 3)
		.build());
	pokemons.push_back(PokemonBuilder()
		.setName("Dratini")
		.setHP(41)
		.setType("Water")
		.setSkill("Wrap", "Normal", 4, 10)
		.setSkill("Aqua Tail", "Water", 3, 5)
		.setSkill("Water Pulse", "Water", 13, 2)
		.setSkill("Hyper Beam", "Normal", 20, 1)
		.build());
	pokemons.push_back(PokemonBuilder()
		.setName("Eevee")
		.setHP(55)
		.setType("Normal")
		.setSkill("Tackle", "Normal", 4, 5)
		.setSkill("Sand Attack", "Ground", 8, 3)
		.setSkill("Bite", "Normal", 12, 3)
		.setSkill("Rain Dance", "Water", 15, 1)
		.build());
	pokemons.push_back(PokemonBuilder()
		.setName("Charmander")
		.setHP(39)
		.setType("Fire")
		.setSkill("Tackle", "Normal", 4, 5)
		.setSkill("Flamethrower", "Fire", 11, 5)
		.setSkill("Dig", "Ground", 7, 5)
		.setSkill("Heat Wave", "Fire", 14, 5)
		.build());
	pokemons.push_back(PokemonBuilder()
		.setName("Palkia")
		.setHP(90)
		.setType("Water")
		.setSkill("Hydro Pump", "Water", 12, 10)
		.setSkill("Earth Power", "Ground", 15, 10)
		.setSkill("Surt", "Water", 13, 10)
		.setSkill("Spatial Rend", "Normal", 30, 10)
		.build());

	return pokemons;
}

std::pair<Pokemon, Pokemon> SelectPokemon(const std::vector<Pokemon>& pokemons)
{
	int p1, p2;
	cout << "Choose a Pokemon(0~4): ";
	cin >> p1;
	cout << "Choose a Pokemon(0~4): ";
	cin >> p2;

	if (p1 == p2)
	{
		cout << "You have to choose Pokemons different from each other.";
		exit(0);
	}
	else
	{
		return { pokemons[p1], pokemons[p2] };
	}
}

void PrintBattle(const Pokemon& p1, const Pokemon& p2)
{
	
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
	cout << "+------------------------------+------------------------------+" << endl;
	cout << "| " << p1.getName() << setw(29 - p1.getName().length());
	cout << "| " << p2.getName() << setw(29 - p2.getName().length()) << "|" << endl;
	cout << "| Type: " << p1.getType() << setw(23 - p1.getType().length());
	cout << "| Type: " << p2.getType() << setw(23 - p2.getType().length()) << "|" << endl;
	cout << "| HP: " << p1.getHP() << setw(25 - to_string(p1.getHP()).length());
	cout << "| HP: " << p2.getHP() << setw(25 - to_string(p2.getHP()).length()) << "|" << endl;
	cout << "+------------------------------+------------------------------+" << endl;
	cout << "| Latest Skill: " << p1.setSkill[0].name << setw(15 - p1.setSkill[0].name);
	cout << "| Latest Skill: " << p2.setSkill[0].name << setw(15 - p2.setSkill[0].name) << "|" << endl;
	cout << "| " << UseSkill(p1, p2) << setw(29 - UseSkill(p1, p2));
	cout << "| " << UseSkill(p2, p1) << setw(29 - UseSkill(p2, p1)) << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "+------------------------------+------------------------------+" << endl;
}

void ChooseSkill(Pokemon& a, Pokemon& d)
{
	int skill;
	cout << "Choose a skill (0~3): ";

}

string UseSkill(Pokemon& a, Pokemon& d)
{
	return "It was super effective.";
	return "It was effective.";
	return "It was not very effective.";
	return "";

}

int main() {
	std::vector<Pokemon> pokemons = createPokemons();

	auto selectpokemons = SelectPokemon(pokemons);
	while (true);
	{
		PrintBattle(selectpokemons.first, selectpokemons.second);
	}
	return 0;
}