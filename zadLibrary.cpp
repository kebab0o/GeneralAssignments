#include<iostream>
using namespace std;
/*Create an application for Library System, where each item should be characterized
by Author’s name, book ID and title, department ID (expressing field of study), and publishing
year. The application should allow user to set and display the characteristics of a single item, and
get individual item characteristics. Write a code to test the system*/

struct Characteristics{
    string name;
    int BookID;
    string title;
    int depID;
    int pubYear;
};
class Library{
private:
    Characteristics* ch;
    int count;
public:
    Library();
    ~Library();
void Setter(const Characteristics& ch1);
void Getter(int count1);
};

Library::Library(){
    ch=new Characteristics[80];
    count=0;
}

Library::~Library(){
    delete [] ch;
    ch=nullptr;
}


void Library::Setter(const Characteristics& ch1){
    ch[count]=ch1;
    Getter(count);
    count++;

}

void Library::Getter(int count1){

        cout<<ch[count1].name<<endl;
        cout<<ch[count1].BookID<<endl;
        cout<<ch[count1].title<<endl;
        cout<<ch[count1].depID<<endl;
        cout<<ch[count1].pubYear<<endl;
}

int main(int argc,char** argv){
    Library l1;
    char odg;
    char od2;
    string name;
    int BookID;
    string title;
    int depID;
    int pubYear;
    int ID;
    do{
        cout<<"Zelite li unijeti novu knjigu? (y/n) "<<endl;
        cin>>odg;
        if(odg=='n'){
            break;
        }
        cin>>name>>BookID>>title>>depID>>pubYear;
        Characteristics c1={name,BookID,title,depID,pubYear};
        l1.Setter(c1);
        cout<<"Zelite li ispisati neku knjigu? (y/n)"<<endl;
        cin>>od2;
        if(od2=='y'){
            cout<<"Unesite ID knjige koju trazite (poredane su hronoloski po ID)"<<endl;
            cin>>ID;
            l1.Getter(ID);
        }

    }while(odg!='n');

}

