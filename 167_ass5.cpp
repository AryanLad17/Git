#include<iostream>
using namespace std;
struct Node{
    string data;
    Node* next;
    Node* prev;
};
class CLL{
    private:
        Node* tail;;
        int value;
        
    public:
        CLL(): tail(NULL) ,value(5){}
        void insert(){
            for(int i=0;i<value;i++){
                Node* newnode=new Node();
                cout<<"Enter the Name of children "<<i+1<<" : ";
                cin>>newnode->data;
                newnode->next=NULL;
                newnode->prev=NULL;
                if(tail==NULL){
                    tail=newnode;
                    tail->next=tail;
                    tail->prev=tail;
                }
                else{
                    Node* head=tail->next;                    
                    newnode->next=head;
                    newnode->prev=tail;
                    tail->next=newnode;
                    tail->prev=newnode;
                    tail=newnode;
                }
            }
        }   
        void Attempts(){            
           if (tail == NULL) return;

            Node* head=tail->next;
            while(head->next!=head){
                int passes = rand() % 5 + 1;
                for(int i=1;i<=passes;i++){
                    head=head->next;
                }
                cout<<"Child "<<head->data<<" is out!"<<endl;
                Node* todelete=head;
                if(head==tail){
                    tail=todelete->prev;
                    tail->next=todelete->next;
                    todelete->next->prev=tail;
                    head=tail->next;
                    delete todelete;
                    
                }
                else{
                    todelete->prev->next=todelete->next;
                    todelete->next->prev=todelete->prev;
                    head=todelete->next;
                    delete todelete;
                }
            }
             cout << "Last remaining child is: " << head->data << endl;
        }
        void leave(string name){
            if(tail==NULL) return ;
            Node* temp=tail->next;
            if(temp==tail && temp->data==name){
                delete temp;
                tail=NULL;
                return;
            }
            if(tail->data==name){
                Node* todelete=tail;
                tail=todelete->prev;
                tail->next=todelete->next;
                todelete->next->prev=tail;
                delete todelete;
                return;
            }
            while(temp->next!=tail->next){
                if(temp->data==name) break;
                temp=temp->next;
            }
            if(temp->data==name){
                Node* todelete=temp;
                todelete->prev->next=todelete->next;
                todelete->next->prev=todelete->prev;
                delete todelete;
                return;
            }
            cout<<"Child not found!"<<endl;
        }
        void display(){
            Node* temp=tail->next;
            do{
                cout<<temp->data<<" ";
                temp=temp->next;
            }while(temp!=tail->next);
            cout<<endl;
        }
        void join(int n){
            if(tail==NULL) return;
            Node* nn=new Node;
            cout<<"Enter the name of new child:";
            cin>>nn->data;
            Node* head=tail->next;
            for(int i=0;i<n && head!=tail;i++){
                head=head->next;
            }
            nn->next=head->next;
            nn->prev=head;
            head->next=nn;
            head->next->prev=nn;
            head=nn;
            if(head==tail){
                tail=nn;
            }   
        }
};
int main(){
    CLL c;
    c.insert();
    c.display();
    c.leave("a");
    c.display();
    c.Attempts();
    c.display();
    c.join(2);
    c.display();
    return 0;
}