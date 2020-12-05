#include "pch.h"
#include "PracticeCPP/MagicSpells.h"

#define main() MAIN_ENTRY(MagicSpells)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Spell {
private:
	string scrollName;
public:
	Spell() : scrollName("") { }
	Spell(string name) : scrollName(name) { }
	virtual ~Spell() { }
	string revealScrollName() {
		return scrollName;
	}
};

class Fireball : public Spell {
private: int power;
public:
	Fireball(int power) : power(power) { }
	void revealFirepower() {
		cout << "Fireball: " << power << endl;
	}
};

class Frostbite : public Spell {
private: int power;
public:
	Frostbite(int power) : power(power) { }
	void revealFrostpower() {
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private: int power;
public:
	Thunderstorm(int power) : power(power) { }
	void revealThunderpower() {
		cout << "Thunderstorm: " << power << endl;
	}
};

class Waterbolt : public Spell {
private: int power;
public:
	Waterbolt(int power) : power(power) { }
	void revealWaterpower() {
		cout << "Waterbolt: " << power << endl;
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;
	}
};
string SpellJournal::journal = "";

// solution from: https://www.geeksforgeeks.org/cpp-program-for-longest-common-subsequence/
void counterspell(Spell *spell)
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	if (Fireball* fire = dynamic_cast<Fireball*>(spell))
	{
		fire->revealFirepower();
	}
	else if (Frostbite* frost = dynamic_cast<Frostbite*>(spell))
	{
		frost->revealFrostpower();
	}
	else if (Waterbolt* water = dynamic_cast<Waterbolt*>(spell))
	{
		water->revealWaterpower();
	}
	else if (Thunderstorm* thunder = dynamic_cast<Thunderstorm*>(spell))
	{
		thunder->revealThunderpower();
	}
	else
	{
		string scrollname = spell->revealScrollName();
		string journal = SpellJournal::read();

		//LCS Length
		const int snL = scrollname.length();
		const int jnL = journal.length();

		vector<int*> LCS;
		LCS.resize(snL + 1);

		for (int i = 0; i <= snL; i++)
		{
			LCS[i] = new int[jnL + 1];
		}

		int i, j;
		for (i = 0; i <= snL; i++)
		{
			for (j = 0; j <= jnL; j++)
			{
				if (i == 0 || j == 0)
					LCS[i][j] = 0;
				else if (scrollname[i - 1] == journal[j - 1])
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}

		cout << LCS[snL][jnL] << endl;

		for (auto lcs : LCS)
		{
			delete[] lcs;
		}

		LCS.clear();
	}
}

class Wizard {
public:
	Spell *cast(ifstream & file) {
		Spell *spell;
		string s; cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell *spell = Arawn.cast(file);
		counterspell(spell);
	}
	return 0;
}