#include<iostream>
#include<random>
#include<ctime>
#include<limits>

using namespace std;
int main()
{
   std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);
    int count=0;
    int x = distr(gen);
     int a;
    while(count<8)
    {
       
        cout<<"Enter the number :";
        cin>>a;
        if(a==x){
            cout<<"You guessed it right!"<<endl;
            break;

        }
        else if(a>x){
            cout<<"The number is smaller than actuly one "<<endl;
        }
        else{
            cout<<"The number is greater than actually one "<<endl;
        }
        count++;
        
    }
    if(count == 8 && a != x){
    cout << "Sorry! You didn't guess the number. The correct number was " << x << "." << endl;

    }
    return 0;
}