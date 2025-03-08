#include <iostream>
using namespace std;

typedef struct Node {
    string songName;
    Node *link;
} Node;

Node* createNode(string data);

void traverse(Node *head){
    Node *temp = new Node; //create a temporary node
    temp = head; // assign temporary node as head

    cout << "My Playlist" <<endl;
    while(temp != NULL){ //Loop through the nodes
    cout << temp->songName<< "->" <<endl;
    if(temp-> link == NULL){ // if tail is reached
    cout << "NULL"<<endl; // print NULL after
    }
    temp = temp->link;
    }
}

//Create new Node
    Node *createNode(string data){
        Node *newNode = new Node; //Create new Node instance
        newNode->songName = data; //assign data
        newNode->link = NULL;//assign link
        
        return newNode;
    }

    Node* insertAtEnd(string data, Node* head) {
    if (head == NULL) { // if the linked list is empty
        Node* newNode = createNode(data); // create node
        head = newNode; // assign new node as head
        cout << "A new node has been inserted at the end \n" << endl; // print out message
        return head;
    }
    
    Node* temp = head; 
    
    while (temp->link != NULL) {
        temp = temp->link; // move to the next node
    }

    Node* newNode = createNode(data);
    temp->link = newNode; // Link the new node to the last element

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

    
    Node *insertAtBeginning(string data, Node *head){
        Node *newNode = createNode(data);
        newNode->link = head;
        
        head = newNode;
        
        cout << "A new node has been inserted at the beginning \n" <<endl;
        
        return head;
    }
    
    string insertAfter(string after, string data, Node *head){
        Node *temp = new Node;
        temp = head;
        
        while(temp->songName.compare(after) != 0){
            if(temp == NULL){
                return "No such song exist, please try again later.";
            }
            
            temp = temp->link;
            
        }
        Node *newNode = createNode(data);
        newNode->link = temp->link;
        temp->link = newNode;
        
        return "An new node has been added after" + after + "\n";
    }


int main() {
    Node* head = createNode("Sanctuary by Joji");
    head = insertAtEnd("Heaven by Bryan Adams", head);
    head = insertAtEnd("Secret Love Song by Little Mix", head);
    head = insertAtEnd("I Don't Want to Miss a Thing by Aerosmith", head);
    
    head = insertAtBeginning("Ikaw at Ako by Johnoy Danao", head);
    head = insertAtBeginning("You'll Be Safe Here by Rico Blanco", head);
    head = insertAtBeginning("Ikaw Parin ang Pipiliin ko by Cup of Joe", head);
    head = insertAtBeginning("Sunstz by Cigarettes After Sex", head);

    cout << insertAfter("Ikaw at Ako by Johnoy Danao", "Wag mong aminin by Rico Blanco", head);
    //cout << insertAfter("You'll Be Safe Here by Rico Blanco","Walang kumakatok by Zild", head);
    //cout << insertAfter("Ikaw Parin ang Pipiliin ko by Cup of Joe","Ikaw at Ako by Tj Monterde", head);
    traverse(head);
    return 0;
}


