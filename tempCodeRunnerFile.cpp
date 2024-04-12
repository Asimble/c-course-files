#include <iostream>
using namespace std;

class AllData
{
    public:

    string name;
    int age;
    string gender;
    string city;

    void Input(){
        cout<<"Enter name: "<<endl;
        cin>>n;
        cout<<"Enter age: "<<endl;
        cin>>a;
        cout<<"Enter gender: "<<endl;
        cin>>g;
        cout<<"Enter city: "<<endl;
        cin>>c;
    }

    AllData (string n, int a, string g, string c){

        name= n;
        age=  a;
        gender= g;
        city= c;

    }

    void Output(){

        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
        cout<<city<<endl;
    }

    void DisplayData{
        AllData.Input();
    }
};

int main(){
    DisplayData;
}