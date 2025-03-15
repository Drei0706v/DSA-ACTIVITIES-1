#include <iostream>
using namespace std;

typedef struct Node {
	string songName;
	Node *link;
} Node;

Node* createNode(string data);

void traverse(Node *head) {
	Node *temp = head;
	cout << "My Playlist" << endl;
	while(temp != NULL) {
		cout << temp->songName << "->" << endl;
		if(temp->link == NULL) {
			cout << "NULL" << endl;
		}
		temp = temp->link;
	}
}

Node* createNode(string data) {
	Node *newNode = new Node;
	newNode->songName = data;
	newNode->link = NULL;
	return newNode;
}

Node* insertAtEnd(string data, Node* head) {
	if (head == NULL) {
		Node* newNode = createNode(data);
		head = newNode;
		return head;
	}

	Node* temp = head;
	while (temp->link != NULL) {
		temp = temp->link;
	}

	Node* newNode = createNode(data);
	temp->link = newNode;
	return head;
}

Node* insertAtBeginning(string data, Node *head) {
	Node *newNode = createNode(data);
	newNode->link = head;
	head = newNode;
	return head;
}

string insertAfter(string after, string data, Node *head) {
	Node *temp = head;
	while(temp != NULL && temp->songName.compare(after) != 0) {
		temp = temp->link;
	}

	if (temp == NULL) {
		return "No such song exists, please try again later.";
	}

	Node *newNode = createNode(data);
	newNode->link = temp->link;
	temp->link = newNode;
	return "A new node has been added after " + after + "\n";
}

string deleteAtEnd(Node* head) {
	if (head == NULL) {
		return "The linked list is empty.";
	}

	if (head->link == NULL) {
		delete head;
		return "The head has been deleted.";
	}

	Node* temp = head;
	while (temp->link->link != NULL) {
		temp = temp->link;
	}

	delete temp->link;
	temp->link = NULL;
	return "A node has been deleted at the end \n";
}

Node* deleteFromBeginning(Node* head) {
	if (head == NULL) {
		return NULL;
	}

	Node* temp = head;
	head = head->link;
	delete temp;
	return head;
}

Node* deleteFromGivenNode(string givenSong, Node* head) {
	if (head == NULL) {
		return NULL;
	}

	if (head->songName.compare(givenSong) == 0) {
		head = deleteFromBeginning(head);
		return head;
	}

	Node *temp = head;
	while(temp->link != NULL && temp->link->songName.compare(givenSong) != 0) {
		temp = temp->link;
	}

	if (temp->link == NULL) {
		return head;
	}

	Node* nodeToDelete = temp->link;
	temp->link = temp->link->link;
	delete nodeToDelete;
	return head;
}



int main() {
	Node* head = createNode("Sanctuary by Joji");
	traverse(head);
	head = insertAtEnd("Heaven by Bryan Adams", head);
	traverse(head);
	head = insertAtEnd("Secret Love Song by Little Mix", head);
	traverse(head);
	head = insertAtEnd("I Don't Want to Miss a Thing by Aerosmith", head);
	traverse(head);




	head = insertAtBeginning("Ikaw at Ako by Johnoy Danao", head);
	traverse(head);
	head = insertAtBeginning("You'll Be Safe Here by Rico Blanco", head);
	traverse(head);
	head = insertAtBeginning("Ikaw Parin ang Pipiliin ko by Cup of Joe", head);
	traverse(head);
	head = insertAtBeginning("Sunstz by Cigarettes After Sex", head);
	traverse(head);




	cout << insertAfter("Ikaw at Ako by Johnoy Danao", "Wag mong aminin by Rico Blanco", head);
	traverse(head);
	cout << insertAfter("You'll Be Safe Here by Rico Blanco","Walang kumakatok by Zild", head);
	traverse(head);
	cout << insertAfter("Ikaw Parin ang Pipiliin ko by Cup of Joe","Ikaw at Ako by Tj Monterde", head);
	traverse(head);



	cout << "Playlist before deletions:" << endl;
	traverse(head);

	cout << "Playlist before deletions:" << endl;
	traverse(head);

	cout << "\nDeleting the song at the end (\"Sunstz by Cigarettes After Sex\"):" << endl;
	cout << deleteAtEnd(head) << endl;
	traverse(head);

	cout << "\nDeleting the song at the beginning (\"Sanctuary by Joji\"):" << endl;
	head = deleteFromBeginning(head);
	traverse(head);

	cout << "\nDeleting a specific song (\"Secret Love Song by Little Mix\" - least favorite):" << endl;
	head = deleteFromGivenNode("Secret Love Song by Little Mix", head);
	traverse(head);


	return 0;
}


