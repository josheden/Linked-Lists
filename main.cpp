#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Node {

public:
	Node(int = 0);  		// constructor with default value for
							// info field
	int info;                 	// data
	Node * next;
};

//A function that returns the number of Nodes in a linked 
//list pointed to by the pointer ptr
int count(Node *&head) {
	int count = 0;
	Node *ptr = head;
	if (ptr == nullptr) {
		cout << "No Nodes to count" << endl;
	}
	while (ptr != nullptr) {
		count++;
		ptr = ptr->next;

	}
	return count;
}

//A function the returns the sum of all integers stored in Nodes in  a linked list pointed to by the pointer ptr
int sum(Node *&head) {
	int total = 0;
	Node *ptr = head;
	while (ptr != nullptr) {
		total += ptr->info;
		ptr = ptr->next;
	}
	cout << "\n\nThe total is " << total << "." << endl;
	return total;
}

//A function that copies a linked list pointed to by ptr and returns a 
//pointer to the copied list.  Please note: the copied 
//list should be independent of the original list; the original
//list can be destroyed and the copy should still remain.

Node * copy(Node * head) {
	Node *copy = nullptr;
	if (head == nullptr) 
		return head;
	Node *trace = new Node;
	copy = trace;
	while (head != nullptr) {
		trace->info = head->info;
		trace->next = nullptr;
		head = head->next;
		if (head != nullptr) {
			trace->next = new Node;
			trace = trace->next;
		}
	}
	//trace = copy;
	return copy;	
}

//this works whether head is null or head is a full linked list
//& is necessary or else it would never update the head
void insert_at_front(int val, Node *&head) {
	Node* currentPtr = new Node;
	currentPtr->info = val;
	currentPtr->next = head;
	head = currentPtr;

}
bool find_link(Node* head, int value) {
	Node *ptr = head;
	bool found = false;
	while (ptr != nullptr && !found) {
		if (ptr->info == value) {
			found = true;
			cout << "Value " << value << " found!" << endl;
		}
		else
			ptr = ptr->next;
	}
	if (!found)
		cout << "Value has not been found." << endl;
	return found;
}

bool findAndDelete(Node *&head, int value) {
	bool found = false;
	Node *ptr = head;
	Node *prev = nullptr;
	while (ptr != nullptr && !found) {
		if (ptr->info == value)
			found = true;
		else {
			prev = ptr;
			ptr = ptr->next;
		}
	}
	if (found) {
		if (ptr == head) {
			head = head->next;
			delete ptr;
			ptr = head;
			return found;
		}
		else {
			prev->next = ptr->next;
			delete ptr;
			ptr = nullptr;
			return found;
		}
	}
	return found;
}

void delete_first_node(Node *& head) {
	Node *ptr = head;
	if (ptr == nullptr)
		cout << "\n\nNo nodes in list to delete." << endl;
	else {
		head = head->next;
		cout << "\n\nNode with info " << ptr->info << " has been deleted." << endl;
		delete ptr;
		ptr = head;
	}
}

void printNodes(Node *&head) {
	Node * ptr = head;
	if (ptr == nullptr) {
		cout << "No nodes to print in list." << endl;
	}
	while (ptr != nullptr) {
		cout << ptr->info << " ";
		ptr = ptr->next;
	}
}

void deleteList(Node *&head) {
	Node * ptr = head;
	while (ptr != nullptr) {
		head = head->next;
		delete ptr;
		ptr = head;
	}
}
	
	void AddAtPosition(Node *&head, int val, int position) {
		Node *ptr = head;
		Node *current = nullptr;
		int count = 0;
		for (int i = 0; i < position - 1; i++) {
			ptr = ptr->next;

		}
		current = ptr->next;
		ptr->next = new Node;
		ptr->next->info = val;
		ptr = ptr->next;
		ptr->next = current;
	}


// Constructor
Node::Node(int data)
{
	info = data;
	next = nullptr;
}

int main() {
	Node *head = nullptr;
	int value;
	int _count;
	bool quit = false;
	char menu;
	cout << "------------------------------" << endl;
	cout << "Welcome to More Linked Lists!" << endl;
	cout << "------------------------------" << endl;
	while (!quit) {
		cout << "\n\nA. Add node." << endl;
		cout << "P. Print node(s)" << endl;
		cout << "D. Delete first node." << endl;
		cout << "F. Find value in node." << endl;
		cout << "G. Find and delete node." << endl;
		cout << "L. Delete list." << endl;
		cout << "S. Find sum of nodes in list." << endl;
		cout << "T. Count number of nodes." << endl;
		cout << "C. Copy old linked list into new one." << endl;
		cout << "U. Add at position." << endl;
		cout << "Q. Quit program." << endl;

		cout << "----------------Choice: ";
		cin >> menu;

		switch (menu) {
		case 'a':
		case 'A': {
			cout << "Enter node value: ";
			cin >> value;
			insert_at_front(value, head);
			break;
		}
		case 'p':
		case 'P': {
			cout << "Printing node(s): ";
			printNodes(head);
			break;
		}
		case 'd':
		case 'D': {
			cout << "Deleting first node in list.";
			delete_first_node(head);
			break;
		}
		case 'f':
		case 'F': {
			cout << "Enter value wished to find: ";
			int value;
			cin >> value;
			find_link(head, value);
			break;
		}
		case 'g':
		case 'G': {
			cout << "node wished to delete: ";
			int value;
			cin >> value;
			findAndDelete(head, value);
			break;
		}
		case 'l':
		case 'L': {
			cout << "Deleting list......." << endl;
			deleteList(head);
			break;
		}
		case 's':
		case 'S': {
			cout << "\n\n";
			cout << "---------------------------------------------" << endl;
			cout << "Calculating sum of nodes in list now........." << endl;
			cout << "---------------------------------------------" << endl;
			sum(head);
			break;
		}
		case 't':
		case 'T': {
			cout << "\nNumber of nodes in list is " 
				<< count(head) << "." << endl;
			break;
		}
		case 'c':
		case 'C': {
			cout << "\n\nNew linked list is now" << endl;
			Node *ptr = copy(head);
			printNodes(ptr);
			break;
		}
		case 'u':
		case 'U': {
			cout << "\n\nWhich position would you like to add at? ";
			cin >> _count;
			cout << "\nWhich value would you like to add? ";
			cin >> value;
			AddAtPosition(head, value, _count);
			printNodes(head);
			break;
		}
		case 'q':
		case 'Q': {
			quit = true;
		}
		}

	}

	system("PAUSE");
	return 0;
}
