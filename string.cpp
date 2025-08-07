#include<iostream>
using namespace std;
int main(){
    int n;q;
    int a[q];
    int count=0;
    cout<<"Enter the no of string:";
    cin>>n;
    string stringList[n];
    string queries[q];
    cout<<"Enter the string:";
    for(int i=0;i<n;i++){
        cin>>stringList[i];
    }
    cout<<"Enter the qeries:";
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(queries[i]==stringList[j]){
                count++;
            }
        }
        count+=a[i];
    }
    return a;
return 0;
}