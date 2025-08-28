#include<iostream>
using namespace std;
struct Node{
    string title;
    string artist;
    double duration;
    Node* next;
};
class Playlist{
    private:
    Node* head;
    public:
        Playlist() : head(nullptr) {}
        void addsong(){
           
            for(int i=0;i<2;i++){
                Node* newnode=new Node;
                newnode->next = nullptr;
                cout<<"ENter song "<<i+1<<"  title:";
                getline(cin, newnode->title);

                cout<<"Enter song "<<i+1<<" artist:";
                getline(cin, newnode->artist);

                cout<<"Enter song "<<i+1<<" duration:";
                cin>>newnode->duration;
                cin.ignore(); // To ignore the newline character left in the input r

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
        void remove(string title1){
            if(head==nullptr) return; // Empty playlist
            if(head->title==title1){
                Node* temp=head;
                head=head->next;
                delete temp;
                return;
            }
            Node* curr=head;
            while(curr->next!=nullptr && curr->next->title!=title1){
                curr=curr->next;
            }
            if(curr->next==nullptr){
                cout<<"Song not found!"<<endl;
                return;
            }
            Node* temp=curr->next;
            curr->next=temp->next;
            delete temp;
            cout<<"Song removed successfully!"<<endl;
        }
        void display() {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        cout << "\nPlaylist songs:\n";
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Title: " << temp->title
                 << ", Artist: " << temp->artist
                 << ", Duration: " << temp->duration << endl;
            temp = temp->next;
        }
    }
        void search(string title2) {
            Node* temp = head;
            while (temp != nullptr) {
            if (temp->title == title2) {
                cout << "Song found!" << endl;
                cout << "Title: " << temp->title
                     << ", Artist: " << temp->artist
                     << ", Duration: " << temp->duration << endl;
                return;
            }
            temp = temp->next;
            }
        cout << "Song not found!" << endl;
        }
        
        void maximum() {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* maxSong = head;

        while (temp != nullptr) {
            if (temp->duration > maxSong->duration) {
                maxSong = temp;
            }
            temp = temp->next;
        }

        cout << "\nLongest song:\n";
        cout << "Title: " << maxSong->title
             << ", Artist: " << maxSong->artist
             << ", Duration: " << maxSong->duration << endl;
    }
        ~Playlist() {
            Node* current = head;
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
        }
};
int main(){
    Playlist p;
    p.addsong();
  //  p.display();
    string title1;
    cout << "Enter title of song to remove: ";
    getline(cin, title1);

    p.remove(title1);
    p.display();
    string title2;
    cout << "Enter title of song to search: ";
    getline(cin, title2);
    p.search(title2);
    p.maximum();
    return 0;


}