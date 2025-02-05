
#include <iostream>
#include <string>

using namespace std;

class teacher{
    public : 
    string name ;
    string subj ;

    void changeSubj(string newSubj){
        subj = newSubj ; 
    }
};

int main(){
    teacher t1 ;
    t1.name = "auu";
    t1.subj = "sid";
    cout<< t1.name << endl;

    return 0 ; 
}