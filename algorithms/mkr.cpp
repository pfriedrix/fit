#include <iostream>
#include <string>

using namespace std;


class Unit : Array {
public:
    Unit() {
        m_health = 0;
        m_name = "Alex";
        m_strengh = 0;
    }

    Unit(int health, string name, int strengh) {
        setUnit(health, name, strengh);

    }

    void setUnit(int health, string name, int strengh) {
        m_health = health;
        m_name = name;
        m_strengh = strengh;

    }

    void virtual printinfo() {
        cout << "Your unit is: " << m_name << endl << " His health is: " << m_health << endl << " His strengh is: "
             << m_strengh << endl;
    }

protected:
    int m_health;
    string m_name;
    int m_strengh;
};

class RangeUnit : public Unit {
public:
    RangeUnit() {
        m_health = 35;
        m_strengh = 24;
        m_name = "Sasha";
        m_weapon = "Ak-47";
        m_Countbullet = 35;
    }

    RangeUnit(int m_health, string m_name, string weapon, int m_strengh, int bullets) : Unit(m_health, m_name,
                                                                                             m_strengh) {
        m_Countbullet = bullets;
        m_weapon = weapon;
    }

    void printinfo() {
        cout << "Your unit is: " << m_name << endl << " His health is: " << m_health << endl << " His strengh is: "
             << m_strengh << endl << "He has:" << m_weapon << endl << "He has " << m_Countbullet << "bullets";
    }

protected:
    int m_Countbullet;
    string m_weapon;
};

class MeleeUnit : public Unit {
public:
    MeleeUnit(int m_health, string m_name, string weapon, int m_strengh, int armored) : Unit(m_health, m_name,
                                                                                             m_strengh) {
        m_weapon = weapon;
        m_armored = armored;
    }

    void printinfo() {
        cout << "Your unit is: " << m_name << endl << " His health is: " << m_health << endl << " His strengh is: "
             << m_strengh << endl << "He has:" << m_weapon << endl << " His armor is: " << m_armored << endl;

    }

protected:
    string m_weapon;
    int m_armored;
};

class ArmoredRangeUnit : public RangeUnit, public MeleeUnit {
    ArmoredRangeUnit(int m_health, string m_name, string m_weapon, int m_strengh, int armored, int bullets) : RangeUnit(
            m_health, m_name, m_weapon, m_strengh, bullets), MeleeUnit(m_health, m_name, m_weapon, m_strengh, armored) {

    }

};

class Array {
private:
    Unit *objs[10];
    Unit *obj = new Unit();
    objs[0] =
    obj;
};


int main() {
    Unit a(15, "Axe", 45);
    a.printinfo();
    a.setUnit(25, "void", 44);
}