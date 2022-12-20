#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <iterator>
#include <list>

using namespace std;

class Hero
{
public:
	string weaponName;
	string name;
	int id;
	int damege;
	int weapon;
	int odul;
	int armor;
	Hero() {};
	Hero(string weaponName, string name, int  id, int damege, int weapon, int armaor)
	{
		odul = 0;
		this->weaponName = weaponName;
		this->armor = armaor;
		this->damege = damege;
		this->id = id;
		this->weapon = weapon;
		this->name = name;
	}
	void karaktersec();

	// set ve get methodlar�n� yazd�m
	int getDamege()
	{
		return  damege;
	}
	void setDamege(int dmg)
	{
		damege = dmg;
	}

	int getweapon()
	{
		return  weapon;
	}
	void setweapon(int dmg)
	{
		weapon = dmg;
	}
	int getArmor()
	{
		return  armor;
	}
	void setARmor(int dmg)
	{
		armor = dmg;
	}

	string getName()
	{
		return  name;
	}
	void setARmor(string dmg)
	{
		name = dmg;
	}
	int getodul()
	{
		return  odul;
	}
	void setodul(int dmg)
	{
		odul = dmg;
	}
};
void Hero::karaktersec()
{
	string weaponName;
	string name;
	int id;
	int damege;
	int weapon;
	int armor;

	cout << "Hangi Karaketri Se�mek �stiyrosunuz?" << endl << endl;

	cout << "********************Heros*************************" << endl;
	cout << "\t1.Bozay�\t\t\t\t |\nZ�rh: 50\t\t\t\t\t |\nHasar : 5\t\t\t\t\t |\nSilah G�c� : 2\t\t\t\t\t |\nSilah Ad� : Mavi Pen�e" << "\t\t\t\t |" << endl;
	cout << "\t\t\t\t\t\t |" << endl;
	cout << "**************************************************" << endl;


	cout << "********************Heros*************************" << endl;
	cout << "\t2.Ay �avas��s�\t\t\t\t |\nZ�rh: 20\t\t\t\t\t |\nHasar : 10\t\t\t\t\t |\nSilah G�c� : 3\t\t\t\t\t |\nSilah Ad� : Gece Oku" << "\t\t\t\t |" << endl;
	cout << "\t\t\t\t\t\t |" << endl;
	cout << "**************************************************" << endl;




	cout << "********************Heros*************************" << endl;
	cout << "\t3.Kara B�y�c�\t\t\t\t |\nZ�rh: 5\t\t\t\t\t\t |\nHasar : 1\t\t\t\t\t |\nSilah G�c� : 9\t\t\t\t\t |\nSilah Ad� : Merlin Asa�" << "\t\t\t\t |" << endl;
	cout << "\t\t\t\t\t\t |" << endl;
	cout << "**************************************************" << endl;

	cin >> id;
	if (id == 1)
	{
		string weaponName = "Mavi Pen�e";
		string name = "Bozay�";
		int damege = 5;
		int weapon = 2;
		int armor = 50;
		Hero(weaponName, name, id, damege, weapon, armor);
	}
	if (id == 2)
	{
		string weaponName = "Gece Oku";
		string name = "Ay �avas��s�";
		int damege = 10;
		int weapon = 3;
		int armor = 20;
		Hero(weaponName, name, id, damege, weapon, armor);
	}
	if (id == 3)
	{
		string weaponName = "Merlin Asa�";
		string name = "Kara B�y�c�";
		int damege = 1;
		int weapon = 9;
		int armor = 5;
		Hero(weaponName, name, id, damege, weapon, armor);
	}
} // hero �e�eme methodu




class Location  // nerede oldugunu bilmek i�in bir abstarct class olu�turdum ve burda extensdds i�lemi uygulacag�m
{
protected:
	Hero hero;
	string name;
public:
	Location(Hero hero)
	{
		this->hero = hero;
	}
	virtual bool getLocation() = 0;

	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;

	}
};

class NormLoc : public Location {
public:
	string name;
	NormLoc(Hero hero, string name) : Location(hero) {
	}

	bool getLocation()
	{
		return true;
	}
};

class SafeHouse : public NormLoc
{
public:
	SafeHouse(Hero hero) :NormLoc(hero, "G�venli ev") {}

	bool getLocation()
	{

		hero.setARmor(hero.getArmor());
		cout << "Can Doldu" << endl;
		cout << "Yenilenmi� Can�n�z : " + hero.getArmor();
		return true;

	}
};


// burada Canavarlar�n ait olan t�m �zelkleri bir class da toplad�m ve burdan extends ettim
class Monster {
private:
	string name;
	int Damage, healty, odul, maxmonster;

public:
	Monster() {}
	Monster(string name, int damage, int healty, int odul, int maxmonster) {
		this->name = name;
		this->Damage = damage;
		this->healty = healty;
		this->odul = odul;
		this->maxmonster = maxmonster;
	}

	int MonsterCount()
	{
		// Bu fonkisiyonun amc� Bize Kar��m�za KA� adet D��man ��kart�cak RAnd�m SAy� �reticek

		int Count;
		for (int i = 0; i <= 3; i++)
		{
			Count = rand();
		}

		return Count;
	}
	string getName()
	{
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	int getDamage() {
		return Damage;
	}

	void setDamage(int damage) {
		Damage = damage;
	}

	int getHealty() {
		return healty;
	}

	void setHealty(int healty) {
		this->healty = healty;
	}

	int getOdul() {
		return odul;
	}

	void setOdul(int odul) {
		this->odul = odul;
	}

	int getMaxmonster() {
		return maxmonster;
	}

	void setMaxmonster(int maxmonster) {
		this->maxmonster = maxmonster;
	}
};

// Buras� Monster Classtan T�rettigimiz D��manlar Burada Extends i�lemi uygulad�k
class Vampire : public Monster {
public:


	Vampire() : Monster("Vampire", 3, 7, 2, MonsterCount())
	{

	}
};

class Zombie : public Monster {
public:

	Zombie() : Monster("zombie", 3, 7, 2, MonsterCount())
	{

	}
};

class Bear : public Monster {
public:

	Bear() : Monster("Bear", 3, 7, 2, MonsterCount())
	{

	}
};




class BattleLoc : Location {
private:
	Monster  mns;
protected:
	string ItemName;
public:

	BattleLoc(Hero hero, string name, Monster mns, string ItemName) :Location(hero)
	{
		this->mns = mns;
		this->name = name;
		this->ItemName = ItemName;

	}

	bool getLocation()
	{
		string input;
		int mnsCount = mns.MonsterCount();
		cout << "SU an Burdas�n�z : " + getName() << endl;
		cout << "Dikatli ol " + mnsCount << " Kadar D��man var" + mns.getName() + " ya��yor" << endl;
		cout << "�ava� i�in <s> kullan" << endl;
		cout << "Ka�mak i�in <k> kullan" << endl;
		cin >> input;

	}

	void   playerStats() {
		// tamamlanmad�
		cout << endl;
		cout << "========================" << endl;
		cout << endl;
		cout << "�sminiz: " + hero.getName() << endl;
		cout << "Sagl�k : " + hero.getArmor() << endl;
		cout << "Senin Vurdugun " + hero.getDamege() << endl;
		cout << "Paran: " + hero.getodul() << endl;
		//cout << "z�rh";// buraya inv cl�as� olu�tur �yle bak
			//cout << "silkah;
	}
	void  enmeyStast()
	{
		// buras� canvarlar�   degerlerini g�recegimiz yer tamamnland�
		cout << mns.getName() + " degerleri: " << endl;
		cout << endl;
		cout << "========================" << endl;
		cout << endl;
		cout << "Can: " + mns.getHealty() << endl;
		cout << "Hasar: " + mns.getDamage() << endl;
		cout << "�d�l" + mns.getOdul() << endl;
	}

	void afterHit()
		// sald�rdan sonra ne oldugu tamanland�
	{
		cout << " Karakter ismi:" + hero.getName() << endl;
		cout << " Karakter Hasar�: " + hero.getDamege() << endl;
		cout << "Karakter Sagl�kg� : " + hero.getArmor() << endl;
		cout << "Karakter Paras�: " + hero.getodul() << endl;

	}
	bool combat(int mnsCount)
	{
		char input;
		int defMnsHelty = mns.getHealty();
		for (int i = 0; i < mnsCount; i++)
		{
			playerStats();
			enmeyStast();
			while (hero.getArmor() > 0 && mns.getHealty() > 0)
			{
				cout << "<V> vur veya <K> ka�" << endl;
				cin >> input;
				if (input == 'v')
				{
					cout << "Vurdunuz " << endl;
					afterHit();
					if (mns.getHealty() <= 0)
					{

					}

					mns.setHealty(mns.getHealty() - hero.getDamege());
					cout << hero.getName() + " CAn� :" << hero.getArmor() << endl;
					cout << endl;
					cout << "Canvar size Vurdu" << endl;
					hero.setARmor(hero.getArmor() - mns.getDamage());
					cout << mns.getName() + " Can� : " << mns.getHealty();
					cout << endl;
				}
				else
				{
					break;
				}
			}
			if (mns.getHealty() < 0 && hero.getArmor() > 0)
			{
				cout << "T�m D���malr� yendiniz" << endl;
				cout << "Hesab�n�za" + mns.getOdul() * mns.MonsterCount() << endl;
				int MoneyGeldi = mns.getOdul() * mns.MonsterCount();


				hero.setodul(MoneyGeldi + hero.getodul());
				cout << "G�ncel Para: " + hero.getodul() << endl;
				mns.setHealty(defMnsHelty);

				// Dosyalama i�lmlerini vurada ba�l�yorum
				ofstream Myfile("diedMonster.txt");
				Myfile << "T�m D���malr� yendiniz" << endl;
				Myfile << "Hesab�n�za" + mns.getOdul() * mns.MonsterCount() << endl;
				Myfile << "G�ncel Para: " + hero.getodul() << endl;
				Myfile << "�ld�rd�g�n D��man" + mns.getName() << endl;
			}
			else
			{
				break;
			}

		}
		return true;
	}
};
class river : public BattleLoc
{
public:
	river(Hero hero) : BattleLoc(hero, "river", Bear(), "water")
	{
	}
};

class cave : public BattleLoc
{
public:
	cave(Hero hero) : BattleLoc(hero, "Magara", Zombie(), "food")
	{
	}
};

class foerst : public BattleLoc
{
public:
	foerst(Hero hero) : BattleLoc(hero, "Orman", Vampire(), "ate� cubugu")
	{
	}
};

class item {
public:
	string name;
	int dmg;

	list <item> ::iterator a;


	void listShow(list<item> x)
	{
		list <item> ::iterator a;
		for (a = x.begin(); a != x.end(); ++a)
		{
			cout << a->name << endl;
			cout << a->dmg << endl;
		}
	}
	void add(list <item> r, item* x)
	{
		r.push_back(*x);
	}
};

class ToolStore : public NormLoc {
public:
	// burada linklist ile magazadaki itemleri s�rayalacag�z ve almak istedigi e�yalar� alacak
	ToolStore(Hero hero) : NormLoc(hero, "MAgaza")
	{}
	bool getLocation() {


		return true;
	}

};

class Game
{
public:
	Location location();
	Hero hero();
	void login();
	void start();
};
void Game::start()
{
	while (true)
	{
		cout << endl;
		cout << "=======================" << endl;
		cout << endl;
		cout << "Eylem Ger�ele�tirmek i�in bir yer �e�" << endl;
		cout << "1->   G�venli ev <-> Size ait bir ev D��man yok" << endl;
		cout << "2->   Magara <->  Belki Kar��n�za Zombi ��kabilir" << endl;
		cout << "3->   Orman <->  Belki Kar��n�za Vampir ��kabilir" << endl;
		cout << "4->   Nehir <->  Belki Kar��n�za Ay� ��kabilir" << endl;
		cout << "5->   Ma�aza <->  Z�rh ve Silah Sat�n Alabilirsiniz" << endl;
	}
}








int main()
{
	setlocale(LC_ALL, "Turkish");
	Hero dnm;
	dnm.karaktersec();
}