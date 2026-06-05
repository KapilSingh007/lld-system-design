#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class DocumentEditor{
    private:
        vector<string> elements;
        string renderedDocument="";

    public:
        
        void addElement(string ele){
            elements.push_back(ele);
        }

        void render(){
            for(string ele: elements){
                cout<<ele<<"\n";
                if(ele.substr(ele.size()-4) == ".png"){
                    renderedDocument += "[Image: " + ele + "]\n";
                }else{
                    renderedDocument += ele + "\n";
                }
            }
        }

        void saveDocument(){
            ofstream outFile("document.txt");
            if (outFile) {
                outFile << renderedDocument;
                outFile.close();
                cout << "Document saved to document.txt" << endl;
            } else {
                cout << "Error: Unable to open file for writing." << endl;
            }
        }
};
int main(){
    DocumentEditor *documentEditor = new DocumentEditor();
    documentEditor->addElement("hello world");
    documentEditor->addElement("this_is_basic_document_image.png");
    documentEditor->addElement("finish");
    documentEditor->render();
    documentEditor->saveDocument();
    return 0;
}