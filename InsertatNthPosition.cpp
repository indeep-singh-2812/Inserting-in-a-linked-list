// Example program to illustrate insert operation in a linked list at Nth position.. 

//Author - Indeep Singh
//Date -   1-5-2017

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
		void InsertAtNthPosition(int,int); //this method takes an integer value as data for the newly created linked list and the position at which the node is to be inserted.
		void PrintList(); //this method prints the value in the linked list.
};

void LinkedList::InsertAtNthPosition(int value, int position){
	Node* node = new Node;
	node->data = value;
	if(head == NULL){
		if(position!=1){ //if list is empty, and position is not 1, then its not a valid condition.
			cout<<"\n List is empty. Please enter appropriate position.\n";
			return;
		} else{ // if list is empty and position is 1, then insert it at beginning.
			node->next = head;
			head = node;
			return;
		}
	} else if(position==1){ // if position is 1, an dlist is not empty, insert at beginning.
		node->next = head;
		head = node;
	} else { // list is not empty and position is not 1, then traverse the list till you reach the position and then change the pointer to nodes.
		Node* counter = head;
		for(int i =0;i<position - 2;i++){
			counter = counter->next;
		}
		node->next = counter->next;
		counter->next = node;
	}
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
	
	list.InsertAtNthPosition(1,4); //invalid position 4 as list is empty.
	
	list.InsertAtNthPosition(1,1); //inserting node with value 1 at position 1
	list.PrintList();
	
	list.InsertAtNthPosition(2,2); //inserting node with value 2 at position 2
	list.PrintList();
	
	list.InsertAtNthPosition(3,2); //inserting node with value 3 at position 2
	list.PrintList();
	
	list.InsertAtNthPosition(5,1); //inserting node with value 5 at position 1
	list.PrintList();
	
	return 0;
	
}


