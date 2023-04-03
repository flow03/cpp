#include <iostream>
#include <string>

// class Attacker	// interface
// {
	// virtual void attack() const = 0;
// };

class Weapon //: public Attacker
{
public:
	Weapon(int damage, int range) : _damage(damage), _range(range){}
	
	virtual void attack() const = 0;
	
protected:
	int _damage;
	int _range;
};

struct Sword : public Weapon
{
	Sword(int damage, int range) : Weapon(damage, range){}
	
	void attack() const override
	{
		std::cout << "Удар мечом с уроном " << _damage << std::endl;
	}
};

struct Crossbow : public Weapon
{
	Crossbow(int damage, int range) : Weapon(damage, range){}
	
	void attack() const override
	{
		std::cout << "Выстрел из арбалета с уроном " << _damage << std::endl;
	}
};

class Character
{
public:
	Character(std::string name, Weapon * weapon) 
	: _name(name), _weapon(weapon)
	{}
	
	void changeWeapon(Weapon * newWeapon)
	{
		this->_weapon = newWeapon;
	}
	
	void attack() const
	{
		_weapon->attack();
	}
	
private:
	std::string _name;
	Weapon * _weapon;
};

int main()	// int argc, char * argv[]
{
	Sword sword = Sword(15, 2);
	Sword * p_sword = &sword;
	Character character = Character("Warrior", p_sword);
	character.attack();
	
	Crossbow crossbow = Crossbow(40, 100);
	Crossbow * p_crossbow = &crossbow;
	character.changeWeapon(p_crossbow);
	character.attack();
	
	// delete sword, crossbow;
	
	return 0;
}