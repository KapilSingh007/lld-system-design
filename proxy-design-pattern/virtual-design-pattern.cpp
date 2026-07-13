#include<iostream>
using namespace std;

class Image{
    public:
    virtual void display() = 0;

};
class HighResolutionImage: public Image{
    
    string imagePath;
    public:
    HighResolutionImage(string path){
        this->imagePath = path;
    }

    void display() override{
        cout<<"here is image"<<imagePath<<endl;
    }
};
class ProxyImage: public Image{
    Image* realImage;

    public:

    void display() override {
        if(!realImage){
            realImage = new HighResolutionImage("image1.png");
        }
        realImage->display();
    }

};

int main(){

    Image* imageRenderer = new ProxyImage();

    imageRenderer->display();
    return 0;
}