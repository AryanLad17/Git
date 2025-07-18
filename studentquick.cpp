#include<iostream>
using namespace std;
class student {
    private:
        string name;
        int id;
        double cgpi;
    public:
        void getdata(){
            cout<<"Enter the Name ,ID and CGPI of the student:";
            cin>>name>>id>>cgpi;
        }
        void display(){
            cout<<"Name:"<<name<<"\nID:"<<id<<"\nCGPI:"<<cgpi<<endl;
        }
        double getcgpi(){
            return cgpi;
        }
        friend void swap(student &s1,student &s2){
            student temp=s1;
             s1=s2;
            s2=temp;
        }
};
int partition(student a[],int start,int end){
    double pivot=a[start].getcgpi();
    int low=start+1;
    int high=end;
    while(true){
        while(low<=high && a[low].getcgpi()<=pivot)
            low++;
        while(low<=high && a[high].getcgpi()>pivot)
            high--;
        if(low>high)
            break;
        swap(a[low],a[high]);

    }
    swap(a[start],a[high]);
    return high;
}
void quick(student a[],int start, int end){
    int j;
    if(start<end){
        j=partition(a,start,end);
        quick(a,start,j-1);
        quick(a,j+1,end);
    }
}
int main(){
    int n;
    cout<<"Enter the number of students:";
    cin>>n;
    student students[100];
    for(int i=0;i<n;i++){
        cout<<"Student"<<i+1<<":\n";
        students[i].getdata();
    }
    quick(students ,0,n-1);
    cout<<"Sorted students by cgpi :"<<endl;
    for(int i=0;i<n;i++){
        students[i].display();
    }
    return 0;
}