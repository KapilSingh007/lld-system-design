#include<iostream>
using namespace std;

class ICharacter {
    public:
    virtual string getAbility() = 0;
};

class Mario: public ICharacter {
    public:
    string getAbility() override {
        return "Mario";
    }
};

class HeightDecorator: public ICharacter {

    ICharacter *character;

    public:

    HeightDecorator(ICharacter* character) {
        this->character = character;
    }

    string getAbility() override {
        return character->getAbility() + " now has height power too";
    }
};


class GunDecorator: public ICharacter {

    ICharacter *character;

    public:

    GunDecorator(ICharacter* character) {
        this->character = character;
    }
    
    string getAbility() override {
        return character->getAbility() + " now has gun power too";
    }
};


class StarDecorator: public ICharacter {

    ICharacter *character;

    public:

    StarDecorator(ICharacter* character) {
        this->character = character;
    }
    
    string getAbility() override {
        return character->getAbility() + " now has star power too";
    }
};

int main() {

    ICharacter *mario = new Mario();
    cout << "Basic Character: " << mario->getAbility() << endl;
    
    mario = new HeightDecorator(mario);
    cout << "After HeightUp: " << mario->getAbility() << endl;

    mario = new GunDecorator(mario);
    cout << "After GunPowerUp: " << mario->getAbility() << endl;


    mario = new StarDecorator(mario);
    cout << "After StarPowerUp: " << mario->getAbility() << endl;
    return 0;
}