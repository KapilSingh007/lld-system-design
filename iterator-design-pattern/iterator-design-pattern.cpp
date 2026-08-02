#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Iterator {
    public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};


template<typename T>
class Iterable {
    virtual Iterator<T>* getIterable() = 0;
};

class Song{
    public:
    string artist;
    string name;
    Song(string artist,string name){
        this->artist =artist;
        this->name = name;
    }
};

class Linklist:public Iterable<int>{
    public:
    int data;
    Linklist* next;

    Linklist(int data){
        this->data= data;
        next = nullptr;
    }
    
    Iterator<int>* getIterable() override;

};

class PlayList:public Iterable<Song>{
    vector<Song*> songs;

    public:
    void addSong(Song* song){
        songs.push_back(song);
    }

    Iterator<Song>* getIterable() override;


    

};

class LinklistIterator: public Iterator<int>{
    Linklist* current;

    public:
    LinklistIterator(Linklist* head){
        this->current = head;
    }

    bool hasNext() override{
        return current != nullptr;
    }

    int next() override {
        int data = current->data;
        current = current->next;
        return data;
        
    }
    
};
class PlayListIterator:public Iterator<Song>{
    vector<Song*> songs;
    int sz,i;

    public:
    PlayListIterator(vector<Song*> songs){
        this->songs = songs;
        sz = songs.size();
        i=0;
    }

    bool hasNext() override{
        return i != sz;
    }

    Song next() override{
        return *songs[i++];
    }


};

Iterator<Song>* PlayList::getIterable() {
    return new PlayListIterator(songs);
}

Iterator<int>* Linklist::getIterable() {
    return new LinklistIterator(this);
}





int main(){
    Linklist* head = new Linklist(1);
    head->next = new Linklist(2);
    head->next->next = new Linklist(3);

    Iterator<int>* it = head->getIterable();

    while(it->hasNext()){
        cout<<it->next()<<" ";
    }


    PlayList* playList =  new PlayList();
    playList->addSong(new Song("arjit singh","me phir bhi tum ko"));
    playList->addSong(new Song("atif aslam","aadat"));

    Iterator<Song>* it2 = playList->getIterable();

    while(it2->hasNext()){
        Song song = it2->next();
        cout << "  " << song.name << " by " << song.artist << "\n";
    }


    return 0;

    


}