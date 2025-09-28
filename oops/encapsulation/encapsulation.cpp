#include <iostream>
#include <thread>
#include <chrono> 
using namespace std;

class TataMotorsCarBlueprint{
    private: 
    string brandName;
    string modelName;

    public:
    double currentSpeed =0;
    int currGear = 0;
    bool isEngineOn;

    void setBrandName(string brandName){
        this->brandName = brandName;
    }

    void setModelName(string modelName){
        this->modelName = modelName;
    }

    void startCar(){
        if(isEngineOn){
            cout<<"Your "<<modelName<<" is Already started"<<endl;
        }else{
            cout<<modelName<<" is starting ... please fasten your seat belt"<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Your "<<modelName<<" is now started" << endl;
            isEngineOn = true;
        }
    }

    void stopCar(){
        if(!isEngineOn){
            cout<<"car is Already stopped"<<endl;
        }else{
            cout<<"car is stopping ..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "car is now stopped" << endl;
            isEngineOn = false;
        }
    }
    virtual void accelration() = 0;
    virtual void shiftGear(bool isUp) = 0;
};

class Defender: public TataMotorsCarBlueprint{
    public:
    Defender(string brandName, string modelName){
        setBrandName(brandName);
        setModelName(modelName);
    }
    void accelration(){
        if(isEngineOn){
            cout<<"Car is now running at speed "<<currGear*30<<endl;
        }
    }

    void shiftGear(bool isUp){
        if(isUp){
            currGear++;
        }else{currGear--;}
    }
};

class Harrier: public TataMotorsCarBlueprint{
    public:
    Harrier(string brandName, string modelName){
        setBrandName(brandName);
        setModelName(modelName);
    }
    void accelration(){
        if(isEngineOn){
            cout<<"Car is now running at speed "<<currGear*20<<endl;
        }
    }

    void shiftGear(bool isUp){
        if(isUp){
            currGear++;
        }else{currGear--;}
    }
};
int main(){
    TataMotorsCarBlueprint* defender = new Defender("tata","Defender");

    defender->startCar();
    defender->shiftGear(true);
    defender->accelration();
    defender->shiftGear(true);
    defender->accelration();

    TataMotorsCarBlueprint* harrier = new Harrier("tata","Harrier");

    harrier->startCar();
    harrier->shiftGear(true);
    harrier->accelration();
    harrier->shiftGear(true);
    harrier->accelration();
    return 0;
} 