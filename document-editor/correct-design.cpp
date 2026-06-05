#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class DocumentElement {

    public:
    virtual string render() = 0;
};

class TextElement: public DocumentElement{
    private:
    string text;

    public:
    TextElement(string value) {
        this->text = value;
    }

    string render() override {
        return text + "\n";
    }
};

class ImageElement: public DocumentElement{
 private:
    string path;

    public:
    ImageElement(string value){
        this->path = value;
    }

    string render() override {
        return "[Image: " + path + "]\n";
    }
};

class Document {
    private:
    vector<DocumentElement*> elements;
    string renderedDocument;
    public:
    
    void addElement(DocumentElement* ele){
        elements.push_back(ele);
    }

    string render(){
        for(DocumentElement *ele: elements){
            renderedDocument += ele->render();
        }
        return renderedDocument;
    }
};

class PersistanceDb{
    public:
    virtual void save(string data) = 0;
};

class MongoDb: public PersistanceDb{
    public:
    void save(string data){
        cout<<"saving to mongo db\n";
    }
};

class FileDb: public PersistanceDb{
    public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

class DocumentEditor{
    private:
        Document *document;
        PersistanceDb *db ;
        string renderedDocument;

    public:
        DocumentEditor(Document *document, PersistanceDb *db){
            this->document = document;
            this->db = db;
        }

        void addText(DocumentElement *ele){
            document->addElement(ele);
        }

        void addImage(DocumentElement *ele){
            document->addElement(ele);
        }

        void render(){
            renderedDocument = document->render();
        }

        void saveDocument(){
            db->save(renderedDocument);
        }
};

int main() {
    
    DocumentEditor *documentEditor = new DocumentEditor(new Document(),new FileDb());

    documentEditor->addText(new TextElement("hello world"));
    documentEditor->addImage(new ImageElement("this_is_first_image.png"));
    documentEditor->addText(new TextElement("finish"));
    documentEditor->render();
    documentEditor->saveDocument();
    return 0;
}