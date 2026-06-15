#include<iostream>
#include<vector>
using namespace std;

class ISubscriber {
    public:
    virtual void update() = 0;
};

class IChannel {
    public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unSubscribe(ISubscriber *subscriber) = 0;
    virtual void notifySubscribers() = 0;

};


class Channel: public IChannel {
    private: 
    vector<ISubscriber*> subscribers;
    string newVideo,name;
    

    public:
    Channel(string name){
        this->name = name;
    }
    void subscribe(ISubscriber *subscriber) override {
        subscribers.push_back(subscriber);
    }

    void unSubscribe(ISubscriber *subscriber) override {
        if(!subscribers.empty()){
            auto x = find(subscribers.begin(),subscribers.end(),subscriber);
            subscribers.erase(x);
        }
    }

    void notifySubscribers() override{
        for(auto x: subscribers) {
            x->update();
        }
    }

    void uploadVideo(string newVideoTitle){
        newVideo = newVideoTitle;
        notifySubscribers();
    }

    string getLatestVideo(){
        return "Checkout our new video " + newVideo;
    }


};

class Subscriber: public ISubscriber {

    Channel *channel;
    string name;

    public:
    Subscriber(string name,Channel *channel) {
        this->channel = channel;
        this->name = name;
    }

    void update() override {
        cout<<"hey " + name + " , " + channel->getLatestVideo() + "\n";
    }

};
int main() {

    Channel *channel = new Channel("Kapil");

    ISubscriber *sub1 = new Subscriber("Varun",channel);
    ISubscriber *sub2 = new Subscriber("Arjun",channel);


    channel->subscribe(sub1);
    channel->subscribe(sub2);


    channel->uploadVideo("video 1");
    channel->unSubscribe(sub1);
    channel->uploadVideo("video 2");
    return 0;
}