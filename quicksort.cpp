#include<iostream>
using namespace std;
int partition(int a[],int start, int end ){
    int pivot=a[start];
    int low=start+1;
    int high=end;
    while(true){
        while(low<=high && a[low]<=pivot)
            low++;
        while(low<=high && a[high]>pivot)
            high--;
        if(low>high)
            break;
            swap(a[low],a[high]);
        }
    swap(a[start],a[high]);
    return high;
}
void quick(int a[],int start,int end){
    int j;
    if(start<end){
        j=partition(a,start,end);
        quick(a,start,j-1);
        quick(a,j+1,end);
    }
}
int main(){
    int a[10],n;
    cout<<"Enter the nubmer elements in array :";
    cin>>n;
    cout<<"Enter the array :";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick(a,0,n-1);
    cout<<"Sorted array is:";
    for(int i=0 ;i<n; i++){
        cout<<a[i]<<" ";
        }
        return 0;
}