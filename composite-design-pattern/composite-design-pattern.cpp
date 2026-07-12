#include<iostream>
using namespace std;
class FileSystemItem{
    protected:
        string name;
        int size;
    public:
        virtual void ls(int indent = 0) = 0;
        virtual void openAll(int indent = 0) = 0;
        virtual int getSize() = 0;
        virtual FileSystemItem* cd(string target) = 0;
        virtual string getName() = 0;
        virtual bool isfolder() = 0;
};
class File: public FileSystemItem{

    public:
    File(string name, int size){
        this->size = size;
        this->name = name;
    }
    void ls(int indent = 0) override {
        cout << string(indent, ' ') << name << "\n";
    }
    void openAll(int indent = 0) override{
        cout << string(indent, ' ') << name << "\n";
    }
    int getSize() override {
        return size;
    }
    FileSystemItem* cd(string target) override {
        return nullptr;
    }

    string getName() override {
        return name;
    };
    
    bool isfolder() override{
        return false;
    }
};
class Folder: public FileSystemItem{
    vector<FileSystemItem*> children;
    public:
    Folder(string name){
        this->name = name;
    }
    void add(FileSystemItem* item){
        children.push_back(item);
    }
    void ls(int indent = 0) override {
        for(FileSystemItem* item: children){
            if(item->isfolder()){
                cout << string(indent, ' ') << " + "<< item->getName() << "\n";
            }else{
                cout << string(indent, ' ') << item->getName() << "\n";
            }
        }
    }
    void openAll(int indent = 0) override{
        cout << string(indent, ' ') << "+ " << name << "\n";
        for(FileSystemItem* item: children){
            item->openAll(indent+1);
        }
    }
    int getSize() override {
        int total =0;
        for(FileSystemItem* item: children){
            total += item->getSize();
        }
        return total;
    }

    FileSystemItem* cd(string target) override {
        for(FileSystemItem* item: children){
            if(item->isfolder() && item->getName() == target){
                return item;
            }
        }

        return nullptr;
    }

    string getName() override {
        return name;
    };

    bool isfolder() override{
        return true;
    }
};
int main(){
    Folder* root = new Folder("root");
    root->add(new File("file1.txt", 1));
    root->add(new File("file2.txt", 1));

    Folder* docs = new Folder("docs");
    docs->add(new File("resume.pdf", 1));
    docs->add(new File("notes.txt", 1));
    root->add(docs);

    Folder* images = new Folder("images");
    images->add(new File("photo.jpg", 1));

    root->add(images);

    root->ls();

    docs->ls();

    root->openAll();

     FileSystemItem* cwd = root->cd("docs");
    if (cwd != nullptr) {
        cwd->ls();
    } else {
        cout << "\n Could not cd into docs \n";
    }

    cout << root->getSize();

    return 0;
}