#include<iostream>
using namespace std;
struct Node{
    int data;
    string name;
    Node* next;
};
class StudentLinkedList {
    private:
        Node* head;
    public:
        StudentLinkedList():head(nullptr){}
        void intert(int n){
            for(int i=0;i<n;++i){
                Node* newnode=new Node;
                cout<<"Enter the Name of student and MDM "<<i+1<<": ";
                cin>>newnode->name>>newnode->data;
                newnode->next=nullptr;
                if(head==nullptr){
                    head=newnode;
                }
                else{
                    Node* temp=head;
                    while(temp->next!=nullptr){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
            }
        }
        void display(){
            Node* temp=head;
            while(temp!=nullptr){
                cout<<temp->name<<" "<<temp->data<<endl;
                temp=temp->next;
            }
        }
        void same(){
            int count=0;
            Node* temp=head;
            Node* nextnode=temp->next;
            while(nextnode!=nullptr){
                if(temp->data!=nextnode->data){
                    count++;
                }
                nextnode=nextnode->next;
            }
            if(count==0){
                cout<<"All students have same MDM"<<endl;
            }
            cout<<"Total same MDM: "<<(head->data - count)<<endl;
        }    
        void same1(){
            int count=0;
            Node* temp=head;
            while(temp!=nullptr){
                if(temp->data==1){
                    count++;
                }
                else if(temp->data==2){
                    count++;
                }
                else if(temp->data==3){
                    count++;
                }
                else if(temp->data==4){
                    count++;
                }
                else if(temp->data==5){
                    count++;
                }
                temp=temp->next;

            }
            cout<<"Total students in MDM 1: "<<count<<endl;
            cout<<"Total students in MDM 2: "<<count<<endl; 
            cout<<"Total students in MDM 3: "<<count<<endl;
            cout<<"Total students in MDM 4: "<<count<<endl;
            cout<<"Total students in MDM 5: "<<count<<endl;

        }   

};
int main(){
    int n;
    cout<<"Enter the number of student :";
    cin>>n;
    cout<<" Option to choice MDM:";
    cout<<"1.web development\n2.Data Science\n3.Android development\n4.IoT\n5.Cyber Security\n";
    StudentLinkedList sll;
    sll.intert(n);
    cout<<"Student Linked list :"<<endl;
    sll.display();
    cout<<"checking how many student have take different or same MDM"<<endl;
    sll.same();
    sll.same1();
    return 0;

}