#include<iostream>
#include<vector>
using namespace std;

class Light{

    public:
    void on(){
        cout<<"light is on"<<endl;
    }

    void off(){
        cout<<"light is off"<<endl;
    }
};

class Fan{
    public:
    void on(){
        cout<<"fan is on"<<endl;
    }

    void off(){
        cout<<"fan is off"<<endl;
    }
};

class Command{
    public:
    virtual void execute() = 0;
    virtual void undo() = 0;

    virtual ~Command(){}

};

class LightCommand: public Command {
    Light *light;
    public:

    LightCommand(Light *light){
        this->light = light;
    }
    void execute() override {
        light->on();
    }

    void undo() override {
        light->off();
    }

};

class FanCommand: public Command {
    Fan *fan;
    public:

    FanCommand(Fan *fan){
        this->fan = fan;
    }
    void execute() override {
        fan->on();
    }

    void undo() override {
        fan->off();
    }

};

class RemoteController{
    static const int numberOfButtons = 2;
    Command* buttons[numberOfButtons];
    bool buttonPressed[numberOfButtons];
    public:
    RemoteController() {
        for (int i = 0; i < numberOfButtons; i++) {
            buttons[i] = nullptr;
            buttonPressed[i] = false;  // false = off, true = on
        }
    }

    void setCommand(int i, Command *command){
        if(buttons[i-1] != nullptr){
            delete buttons[i-1];
        }
        buttons[i-1] = command;
        buttonPressed[i-1] = false;
    }

    void pressButton(int i){
        if(!buttonPressed[i-1]){
            buttons[i-1]->execute();
            buttonPressed[i-1] = true;
        }else{
            buttons[i-1]->undo();
            buttonPressed[i-1] = false;
        }
    }
};


int main(){

    Light* livingRoomLight = new Light();
    Fan* ceilingFan = new Fan();

    RemoteController* remote = new RemoteController();
    remote->setCommand(1, new LightCommand(livingRoomLight));
    remote->setCommand(2, new FanCommand(ceilingFan));


    cout << "--- Toggling Light Button 0 ---" << endl;
    remote->pressButton(1);  // ON
    remote->pressButton(1);  // OFF

    cout << "--- Toggling Fan Button 1 ---" << endl;
    remote->pressButton(2);  // ON
    remote->pressButton(2);  // OFF

 

    return 0;

}