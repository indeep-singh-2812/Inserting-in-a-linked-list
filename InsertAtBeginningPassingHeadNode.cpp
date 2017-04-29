// Example program to illustrate insert operation in a linked list but we will pass and insert the head node from the Insert and Print function. 
// In this example, we will not keep head node as private member to the class.

//Author - Indeep Singh
//Date - 29-4-2017

#include <iostream>
#include <string>

using namespace std;

//creating structure of a node of linked list.
struct Node{
	int data;
	Node* next;
};

//creating a class to expose methods for performing operations on a linked list.
class LinkedList{
	public:
		Node* InsertAtBeginning(int, Node*); //this method takes an integer value as data for the newly created linked list and the head node pointer.
		void PrintList(Node*); //this method takes head node as argument and prints the value in the linked list.
};

Node* LinkedList::InsertAtBeginning(int value, Node* head){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	return head;
}

void LinkedList::PrintList(Node* head){
	
	if(head == NULL){
		cout<<"\n List is empty ";
		return;
	}
	
	Node* counterNode = head; // we are initialising a new node with head because we dont want to change/modify our head node in while loop.
	cout<<"\n Data in list is: ";
	while(counterNode != NULL){
		cout<<"\t" <<counterNode->data;
		counterNode = counterNode->next;
	}	
}

int main()
{
	Node* head = NULL;
	LinkedList list;
	list.PrintList(head);
	
	head = list.InsertAtBeginning(1, head);
	list.PrintList(head);// linked list has  : 1
	
	head = list.InsertAtBeginning(2, head);
	list.PrintList(head);// linked list has  : 2	1
	
	head = list.InsertAtBeginning(3, head);
	list.PrintList(head);// linked list has  : 3	2	1
	
	head = list.InsertAtBeginning(4, head);
	list.PrintList(head);// linked list has  : 4	3	2	1
	
	return 0;
	
}


