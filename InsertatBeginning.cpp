// Example program to illustrate insert operation in a linked list. 

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
	private:
		Node* head; //class will have a private pointer head node to point to the first node of the linked list.
	public:
		LinkedList(){
			head = NULL ; //initialising the head node with NULL value as at the beginnign the linked list is empty.
		}
		void InsertAtBeginning(int); //this method takes an integer value as data for the newly created linked list
		void PrintList(); //this method prints the value in the linked list.
};

void LinkedList::InsertAtBeginning(int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

void LinkedList::PrintList(){
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
	LinkedList list;
	list.PrintList();// at this point , the linked list is empty.
	
	list.InsertAtBeginning(1);
	list.PrintList(); // linked list has  : 1
	
	list.InsertAtBeginning(2);
	list.PrintList(); // linked list has  : 2	1
	
	list.InsertAtBeginning(3);
	list.PrintList(); // linked list has  : 3	2	1
	
	list.InsertAtBeginning(4);
	list.PrintList(); // linked list has  : 4	3	2	1
	
	return 0;
	
}


