#include<iostream>
using namespace std;


// implementation 

class Sender{
    public:
    virtual void send(string message) = 0;
};
class EmailSender: public Sender{
    public:
    void send(string message) override{
        cout<<"Sending through email: message: "<<message<<endl;
    }
};

class SmsSender: public Sender{
    public:
    void send(string message) override{
        cout<<"Sending through sms: message: "<<message<<endl;
    }
};

class WhatsappSender: public Sender{
    public:
    void send(string message) override{
        cout<<"Sending through whatsapp: message: "<<message<<endl;
    }
};

//Abstraction

class Notification{
    protected:
    Sender *sender;
    public:
    Notification(Sender *sender){
        this->sender  = sender;
    }
    virtual void send(string message) = 0;
};

class AlertNotification: public Notification {
    public:
    AlertNotification(Sender* sender): Notification(sender){}
    void send(string message) override {
        this->sender->send(message);
    }
};



int main() {

    Sender *sender = new WhatsappSender();

    Notification *alert = new AlertNotification(sender);

    alert->send("skfnskdbfnks");
    return 0;
}