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
        merge sort1(merge &m2){
            Node* t1=head;
            Node* t2=m2.head;
            merge result;
            while(t1 && t2){
                if(t1->data >t2->data){
                    result.insert(t2->data);
                    t2=t2->next;
                }
                else if(t1->data < t2->data){
                    result.insert(t1->data);
                    t1=t1->next;
                }
                else{
                    result.insert(t1->data);
                    t1=t1->next;
                    t2=t2->next;
                }

            }
            while(t1){
                result.insert(t1->data);
                t1=t1->next;
            }  
             while(t2){
                result.insert(t2->data);
                t2=t2->next;
            }
            return result;
        }
        
};
int main(){
    merge m1,m2,result;
    cout<<"Enter the Fisrt LInked list"<<endl;
    m1.insert(5);
    m1.insert(10);
    m1.insert(105);
    m1.display();
    cout<<endl;

    cout<<"Enter the Second LInked list"<<endl;
    m2.insert(20);
    m2.insert(25);
    m2.insert(30);
    m2.display();
    cout<<endl;
     
    result=m1.sort1(m2);
    cout<<"The merge sort Linked LIst is :"<<endl;
    result.display();
    cout<<endl;
    return 0;
}