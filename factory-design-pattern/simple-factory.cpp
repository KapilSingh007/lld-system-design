#include<iostream>
using namespace std;
class Notification {
    public:
    virtual void send(string message) = 0;
};

class EmailNotificationService: public Notification {
    public:
        void send(string message) override {
            cout<<"sending message using email\n";
        }
};

class SmsNotificationService: public Notification { 
    public:
        void send(string message) override {
            cout<<"sending message using sms\n";
        }

};

//first way
// class NotificationFactory {
//     public:
//         Notification* createNofication(string type) {
//             if (type == "EMAIL") {
//                 return new EmailNotificationService();
//             }
//             else if (type == "SMS") {
//                 return new SmsNotificationService();
//             }
//             return nullptr;
//         }
// };


//second way
class NotificationFactory {
    public:
        static Notification* createNofication(string type) {
            if (type == "EMAIL") {
                return new EmailNotificationService();
            }
            else if (type == "SMS") {
                return new SmsNotificationService();
            }
            return nullptr;
        }
};
int main() {

    // NotificationFactory *factory = new NotificationFactory();
    // Notification *notification = factory->createNofication("SMS");


    Notification *notification = NotificationFactory::createNofication("SMS");
    notification->send("akjdjsk");

    return 0;
}