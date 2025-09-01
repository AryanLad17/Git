#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class merge{
    private:
        Node* head;
        Node* tail;
    public:
        merge(): head(NULL),tail(NULL) {}
        void insert(int x){
			Node* newnode=new Node;
			newnode->data = x;
			newnode->next=NULL;
			
			if(head==NULL){
				head=newnode;
                tail=newnode;
			}
			else{
				tail->next=newnode;
                tail=newnode;
			}
		}
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        Node* sort1(Node* list1 ,Node* list2){
            Node* t1=list1;
            Node* t2=list2;
            Node* dummp=new Node;
            dummp->next = NULL;
            Node* temp=dummp;
            while(t1 && t2){
                if(t1->data > t2->data){
                    temp->next=t2;
                    t2=t2->next;
                    temp=temp->next;                    
                }
                else if(t1->data < t2->data){
                    temp->next=t1;
                    t1=t1->next;
                    temp=temp->next;                    
                }
                else{
                    temp->next=t1;
                    t1=t1->next;
                    temp=temp->next;
                    temp->next=t2;                   
                    t2=t2->next;
                    temp=temp->next;    
                }
            }
                while(t1){
                    temp->next=t1;
                    t1=t1->next;
                    temp=temp->next; 
                }
                while(t2){
                    
                    temp->next=t2;
                    t2=t2->next;
                    temp=temp->next;
                }
                
            
            return dummp->next;
        }
        Node* gethead(){
            return head;
        }
};
int main(){
    merge m1,m2;
    cout<<"Enter the Fisrt LInked list"<<endl;
    m1.insert(1);
    m1.insert(2);
    m1.insert(4);
    m1.display();
    cout<<endl;

    cout<<"Enter the Second LInked list"<<endl;
    m2.insert(1);
    m2.insert(3);
    m2.insert(4);
    m2.display();
    cout<<endl;

    Node* result=m1.sort1(m1.gethead(),m2.gethead());
    cout<<"Merged Linked List is : "<<endl;
    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }
    return 0;
}