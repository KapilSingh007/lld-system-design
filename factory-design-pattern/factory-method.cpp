#include<iostream>
using namespace std;
class NotificationFactory {
    public:
    virtual void send() = 0;
};
    
class EmailNotificationService: public NotificationFactory{

    public:

    void send() override {
        cout<<"sending using email\n";
    }
};


class SmsNotificationService: public NotificationFactory{

    public:

    void send() override {
        cout<<"sending using sms\n";
    }
};

class NotificationCreater {
public:
    virtual NotificationFactory *createObj() = 0;


    void send(){
        NotificationFactory *service = createObj();

        service->send();
    }

};

class Email: public NotificationCreater{

    public:
    
    NotificationFactory *createObj() override {
        return new EmailNotificationService;
    }

};

class Sms: public NotificationCreater{

    public:
    
    NotificationFactory *createObj() override {
        return new SmsNotificationService;
    }

};
int main(){

    NotificationCreater *obj = new Email();

    obj->send();
    return 0;
}