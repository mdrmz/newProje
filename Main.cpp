#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <iterator>


using namespace std;

class Hero
{
public:
	string weaponName;
	string name1;
	int id;
	int damege;
	int weapon;
	int odul = 0;
	int armor;
	Hero() {};
	Hero(string weaponName, string name, int  id, int damege, int weapon, int armaor)
	{
		
		this->weaponName = weaponName;
		this->armor = armaor;
		this->damege = damege;
		this->id = id;
		this->weapon = weapon;
		name1 = name;
	}
	Hero karaktersec();

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
		return  name1;
	}
	void setName(string newName)
	{
		name1 = newName;
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
Hero Hero::karaktersec()
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
		Hero hero2("Mavi Pen�e", "Bozay�", id, 5, 2, 50);
		return hero2;
	}
	if (id == 2)
	{
		string weaponName = "Gece Oku";
		string name = "Ay �avas��s�";
		int damege = 10;
		int weapon = 3;
		int armor = 20;
		Hero Hero3(weaponName, name, id, damege, weapon, armor);
		return Hero3;
	}
	if (id == 3)
	{
		string weaponName = "Merlin Asa�";
		string name = "Kara B�y�c�";
		int damege = 1;
		int weapon = 9;
		int armor = 5;
		Hero Hero4(weaponName, name, id, damege, weapon, armor);
		return Hero4;
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

		int a;
		srand(time(NULL));
		a = 1 + rand() % 5;
		return a;
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
	Hero hero1;
	BattleLoc(Hero hero, string name, Monster mns, string ItemName) :Location(hero)
	{
		this->mns = mns;
		this->name = name;
		this->ItemName = ItemName;
		this->hero1 = hero;
	}

	bool getLocation()
	{
		int mnsCount = mns.MonsterCount();
		cout << "SU an Burdas�n�z : " + getName() << endl;
		cout << "Dikatli ol " << mnsCount << " Adet D��man var " + mns.getName() << " 'ler ya��yor" << endl;

		if (combat(mnsCount)) {



		}
		return true;
	}

	void   playerStats() {
		// tamamlanmad�
		cout << endl;
		cout << "========================" << endl;
		cout << endl;
		cout << "isminiz: " << hero1.getName() << endl;
		cout << "Saglik : " << hero1.getArmor() << endl;
		cout << "Senin Vurdugun " << hero1.getDamege() << endl;
		cout << "Paran: " << hero1.getodul() << endl;
		//cout << "z�rh";// buraya inv cl�as� olu�tur �yle bak
			//cout << "silkah;
	}
	void  enmeyStast()
	{
		// buras� canvarlar�   degerlerini g�recegimiz yer tamamnland�
		cout << "========================" << endl;
		cout << mns.getName() << " degerleri: " << endl;
		cout << endl;
		cout << "Can: " << mns.getHealty() << endl;
		cout << "Hasar: " << mns.getDamage() << endl;
		cout << "odul" << mns.getOdul() << endl;
	}

	void afterHit()
		// sald�rdan sonra ne oldugu tamanland�
	{
		cout << " Karakter ismi:" << hero.getName() << endl;
		cout << " Karakter Hasar�: " << hero.getDamege() << endl;
		cout << "Karakter Sagl�kg� : " << hero.getArmor() << endl;
		cout << "Karakter Paras�: " << hero.getodul() << endl;

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
					cout << hero.getName() << " CAn :" << hero.getArmor() << endl;
					cout << endl;
					cout << "Canvar size Vurdu" << endl;
					hero.setARmor(hero.getArmor() - mns.getDamage());
					cout << mns.getName() << " Can : " << mns.getHealty();
					cout << endl;
				}
				else
				{
					break;
				}
			}
			if (mns.getHealty() < 0 && hero.getArmor() > 0)
			{
				cout << "T�m Dusmanları yendiniz" << endl;
				cout << "Hesabınıza" << mns.getOdul() * mns.MonsterCount() << " Kadar �d�l geldi" << endl;
				int MoneyGeldi = mns.getOdul() * mns.MonsterCount();

				hero.setodul(MoneyGeldi + hero.getodul());
				cout << "G�ncel Para: " << hero.getodul() << endl;
				mns.setHealty(defMnsHelty);
				// Dosyalama işlmlerini vurada başlıyorum
				ofstream Myfile("diedMonster.txt", std::ofstream::app);
				if (Myfile.is_open())
				{
					Myfile << "Tüm Dusumalari yendiniz\t";
					Myfile << "Hesabınıza : " << mns.getOdul() * mns.MonsterCount();
					Myfile << "\tGüncel Para: " << hero.getodul();
					Myfile << "\tÖldürdügün Düşman " + mns.getName() << endl;

				}
			}
			else
			{
				break;
				return true;
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

class forest : public BattleLoc
{
public:
	forest(Hero hero) : BattleLoc(hero, "Orman", Vampire(), "ate� cubugu")
	{
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
	Hero hero;
	hero = hero.karaktersec();


	int secim;
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
		cout << "Se�iminiz : ";
		cin >> secim;
		cout << endl;

		switch (secim)
		{
		case 1: {
			SafeHouse sh(hero);
			sh.getLocation();
			break;
		}
		case 2: {
			cave cv(hero);
			cv.getLocation();

			break;
		}
		case 3: {
			forest forest(hero);
			forest.getLocation();
			break;
		}
		case 4: {
			river River(hero);
			River.getLocation();
			break;
		}
		case 5: {

			break;
		}
		default:
			NormLoc(hero, "Yol");

		}
	}
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	Game game;
	game.start();
}