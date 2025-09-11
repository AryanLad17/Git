#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
class DLL{
    private:
        Node* head;
    public:
        DLL(): head(NULL) {}
        void insert(int n){
        for(int i=0;i<n;++i){
            Node* newnode=new Node;
            cout<<"Enter the data for Node "<<i+1<<": ";
            cin>>newnode->data;
            newnode->next=nullptr;
            newnode->prev=nullptr;
            if(head==nullptr){
                head=newnode;
            }
            else{
                Node* temp=head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->prev=temp;
            }
        } 
    }
    void display(){
         cout<<"Doubly Linked list :";
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void reverse(){
        Node* temp=head;
        cout<<"The linkedlist is reverse:";
        while(temp->next!=NULL){
            temp=temp->next;
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
    void delete1(){
       Node* temp=head->next;
       delete head;
       head=temp;
       if(head!=NULL) head->prev=NULL;
        
    }
void datadelete(int a){
				if (head == NULL) {
        			cout << "List is empty. Element not found." << endl;
        		return;
    			}

    			Node* temp = head;
				
				while(temp!=NULL){
					if(temp->data==a){
						if(temp==head){
							head=temp->next;
							if(head!=nullptr){
								head->prev=NULL;
							}
						}
						else{
							temp->prev->next=temp->next;
							if(temp->next!=NULL){
								temp->next->prev=temp->prev;
							}
						}
						delete temp;
					}
					temp=temp->next;
				}
			}
};
int main(){
   
    DLL d;
    d.insert(5);
    d.display();
    d.reverse();
   // d.delete1();
    d.datadelete(2);
    d.display();
    // Free allocated memory
    
    return 0;
}