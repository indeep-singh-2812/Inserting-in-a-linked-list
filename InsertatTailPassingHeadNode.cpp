// Example program to illustrate insert operation in a linked list. 
//In this we will show you how to insert node at the tail of a linked list.
// This is the second version of insert node at tail fo linked list by passing head node as argument.

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
		Node* InsertAtTail(int,Node*); //this method takes an integer value as data for the newly created linked list and pointer to head node.
		void PrintList(Node*); //this method takes pointer to head node as argument and prints the value in the linked list.
};

Node* LinkedList::InsertAtTail(int value, Node* head){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL; //since newly created node will always be the last node, so next pointer of it will be NULL
	
	if(head == NULL){ //handling case for empty list. Insert at beginning.
		newNode->next = head;
		head = newNode;
		return head;
	}
	
	Node* counterNode = head;
	
	while(counterNode->next !=NULL){ // reaching end of the list. So it insert at tail operation has complexity of Big-Oh(n) where n is the number of elements in the list.
		counterNode = counterNode->next;
	}
	
	counterNode->next = newNode;
	return head;	
}

void LinkedList::PrintList(Node* head){
	if(head == NULL)
	{
		cout<<"\n List is Empty";
		return; // if the  list is empty, the we will return from the method.
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
	list.PrintList(head);// at this point , the linked list is empty.
	
	head = list.InsertAtTail(1,head);
	list.PrintList(head); // linked list has  : 1
	
	head = list.InsertAtTail(2,head);
	list.PrintList(head); // linked list has  : 1	2
	
	head = list.InsertAtTail(3,head);
	list.PrintList(head); // linked list has  : 1	2	3
	
	head = list.InsertAtTail(4,head);
	list.PrintList(head); // linked list has  : 1	2	3	4
	
	return 0;
	
}


