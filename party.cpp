#include<iostream>
using namespace std;
struct member{
    string name;
    int band;
};
int main(){
    member m[10];
    int n,c=0;
    cout<<"Enter the number of member in the party:";
    cin>>n;
    cout<<"Enter the name and band color of each member\n(if color is blue then type 1 else type any other number):";
    for(int i=0;i<n;i++){
        cin>>m[i].name>>m[i].band;
        if(m[i].band==1){
            c++;
        }
    }
       cout << "\nMember List:\n";
    for(int i = 0; i < n; i++) {
        cout << m[i].name << " - ";
        if(m[i].band == 0)
            cout << "Blue\n";
        else
            cout << "Other Colour\n";
    }

    if(c==0){
        cout<<"BOYS";
    }
    else {
        cout<<"GIRLS";
    }
        cout<<endl;
return 0;
    

}
