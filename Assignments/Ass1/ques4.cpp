#include <iostream>
using namespace std;

struct Node {
	char data;
	Node *next;

	Node(int val) {
		next = NULL;
		data = val;
	}
};

Node* createLL() {
	Node *head = new Node('A');
	Node *one = new Node('B');
	Node *two = new Node('C');
	Node *three = new Node('D');
	Node *four = new Node('E');
	Node *five = new Node('F');
	Node *six = new Node('G');
    Node *seven = new Node('H');
    Node *eight = new Node('I');
	head->next = one;
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;
	six->next = seven;
    seven->next = eight;
    eight->next = three;
	return head;
}

void printLL(Node *head, int length) {
	while(length > 0) {
		cout << head->data << "->";
		head = head->next;
		length--;
	}
	cout << endl;
}

int main() {
    
	Node *head = createLL();
	Node *fastPtr = head;
	Node *slowPtr = head;
	int length = 10; // number of elements in the linked list to be printed
	printLL(head, length);

	while(fastPtr != NULL && fastPtr->next != NULL) {
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;

		if(slowPtr == fastPtr) {
			while(slowPtr != head) {
				slowPtr = slowPtr->next;
				head = head->next;
			}
			cout << "Harshit's node is: ";
			cout << slowPtr->data << endl;
			break;
		}
	}
	return 0;
}