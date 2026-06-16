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

class CharacterDecorator: public ICharacter {
    
    protected:
    ICharacter *character;
    public:
    CharacterDecorator(ICharacter* character){
        this->character = character;
    }
};

class HeightDecorator: public CharacterDecorator {

    public:

    HeightDecorator(ICharacter* character): CharacterDecorator(character){}

    string getAbility() override {
        return character->getAbility() + " now has height power too";
    }
};


class GunDecorator: public CharacterDecorator {

    public:

    GunDecorator(ICharacter* character): CharacterDecorator(character){}
    
    string getAbility() override {
        return character->getAbility() + " now has gun power too";
    }
};


class StarDecorator: public CharacterDecorator {

    public:

    StarDecorator(ICharacter* character): CharacterDecorator(character){}
    
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