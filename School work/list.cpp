// Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"                          //you do not need this '#include "stdafx.h"' if you are not using visual studio as a compile
#include <iostream>
using namespace std;

class ListNode {
public:
	int			data;                        //variable named data, type int
	ListNode	*next;                       //pointer next, used to point to next node in list
	ListNode(int element, ListNode *p = 0) { //constructure, takes in an element and assigned the value to the front because P is set to 0
		data = element; next = p;
	}
};
class SinglyList{
private:
	ListNode	*head;                      //private pointer variable head
	ListNode	*tail;                      //private pointer variable tail
public:
	SinglyList() {                          //constructure, creates a list where head is equal to tail, meaning empty list
		head = tail = 0;
	}
	//member functions
	void Add_To_Head(int n) {
		head = new ListNode(n, head);     //gives the node a value n, and set the new node as the head
		if (tail == 0) {                  //if tail is 0, then the head is equal to the tail
			tail = head;
		}
	}
	void Add_To_Tail(int n) {
		if (tail != 0) {                 //if tail is not empty
			tail->next = new ListNode(n);//addes value to the element at the back, given that p is already 0
			tail = tail->next;           //set previous tail as current tail, current tail being that a new element was added to the back      
		}
	}
	int Delete_From_head() {
		int e = head->data;				//data from the head is temporarily stored in e, data retrieved from the pointer head
		ListNode *temp = head;          //create a temporary head
		if (head == tail) {             //if head is equal to tail, there is only 1 node
			head = tail = 0;            //if one node, then set head to tail which makes the list empty
		}
		else head = head->next;         //the current head is dropped and the head following is now the new head
		delete temp;                    //the temp holder for the previous head pointer is dropped
		return e;          
	}
	int Delete_From_Tail(){
		int e = tail->data;             //make e hold the value of tail
		if (head == tail) {             //if one node,
			delete head;                //delete head
			head = tail = 0;            //empty the list
		}
		else {
			ListNode *temp;             //create a temporary pointer
			for (temp = head; temp->next != tail; temp = temp->next);  //set temp equali to head, if the next node is not the tail, then proceed to the next until you reach the tail
			delete tail;                                               //after the loop, if the next node is tail, delete tail
			tail = temp;                                               //set the new tail to the node before the existing tail
			tail->next = 0;                                            //change the pointer of tail = 0, this indictates that this is the tail - because empty pointer
		}
	}
	void Delete_Node(int n) {
		if (head != 0) {               //if list is not empty
			if ((head == tail) && (n == head->data)) {
				delete head;           //if theres only one element, delete head
				head = tail = 0;       //empty the list
			}
			else if (n == head->data) {
				ListNode *temp = head;
				head = head->next;
				delete temp;
			}
			else {                                                        //checks if there are more than one node in the list; - not sure what any of this means, everything beyond this point is speculative
				ListNode *previous, *temp;                                //creates pointers to find previous node, 
				for (previous = head, temp = head->next;                  //use previous to hold the head, then set temp as the proceeding head
					temp != 0 && !(temp->data == n);                      //if temp, the proceeding head, is not equal 0 means, that the node is not empty, then set the data in that node equal to(=) n
					previous = previous->next, temp = temp->next);        //now iterate forward
				if (temp != 0) {
					previous->next = temp->next;                          //make previous node equal to the current node, effectively dropping the one before
					if (temp == tail) {
						tail = previous;                                  //if temp is the same as the tail, then this is the last remaining node
					}
					delete temp;                                          //I think this function deletes a node at a give location 'n', and holds the nodes before and after and then joins them together
				}
			}
		}
	}
};
int main()
{
	SinglyList L;
	L.Add_To_Head(5);

	system("PAUSE");              //feel free to delete this line, I use it for Visual Studio only, if you use xcode or any other compiler, you do not need this line
    return 0;
}

