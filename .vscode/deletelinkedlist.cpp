#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class LinkedList{
	private:
		Node* head;
	public:
	LinkedList(){
		head=NULL;
	}
	void insert(int n){		
		for(int i=0;i<n;++i){
			Node* newnode=new Node;
			cout<<"Enter the data"<<i+1<<" : ";
			cin>>newnode->data;
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
	void Linkedlist(){
		Node* temp=head;
		while(temp!=nullptr){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void deletelist(int d,int n){
		Node* temp=head;
		Node* prev=NULL;
		if (temp->data == d) {
        	head = temp->next;
        	delete temp;
        	return;
    	}			
		for(int i = 0; i < n; ++i) {
   if(temp == NULL){
        cout << "Data Notfound" << endl;
        return;
    }
    prev->next = temp->next;
    Node* toDelete = temp;   // store current node to delete
    temp = temp->next;       // move temp forward BEFORE deleting
    delete toDelete;         // delete old node safely
}

// After deletion, print list from head
temp = head;
while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->next;
}
cout << endl;

		//Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}	
	
/*	int whatdoesitdo(){
		Node* temp1=head;
		Node* temp2=head;
		while(temp1 && temp1->next){
			temp1=temp1->next->next;
			temp2=temp2->next;
		}
		return temp2->data;
	}  */
	
};
int main(){
	int n;
	cout<<"Enter the Number elements in List:";
	cin>>n;
	LinkedList l;
	l.insert(n);
	l.Linkedlist();
	int d;
	cout<<"Enter the elements to be delete :";
	cin>>d;
	l.deletelist(d,n);
//	l.whatdoesitdo();
	
return 0;
}