#include<iostream>
#include<cmath>
#define MAX 20
using namespace std;

class ADTQueue {
	int rear, front, q[MAX];
	
	public:
		ADTQueue() {
			rear = -1;
			front = 0;
		}
		void MakeEmpty() {
			rear = -1;
			front = 0;
		}
		bool ISFull() {
			if(rear == MAX-1) {
				return true;
			}
			else return false; 
		}
		bool IsEmpty() {
			if(rear<front) {
				return true;
			}
			else return false;
		}
		void Enqueue(int q[MAX], int x) {
			if(ISFull()) {
				cout<<"Queue is full."<<endl;
			}
			else {
				rear = rear + 1;
				q[rear] = x;
			}
		}
		void Dequeue() {
			if(IsEmpty()) {
				cout<<"Queue is empty."<<endl;
			}
			else {
				int temp = q[front];
				front = front + 1;
			}
		}
		void Traverse() {
			if(IsEmpty()) {
				cout<<"Queue is empty. It cannot traverse."<<endl;
			}
			else {
				for(int i = front; i <= rear; i++) {
					cout<<" "<<q[i];
				}
			}
		}
};
int main() {
	ADTQueue qu;
	int choice;
	
	cout<<"----Menu----"<<endl;
	cout<<"\n1. Make Empty Queue."<<endl;
	cout<<"\n2. Enqueue Operation."<<endl;
	cout<<"\n3. Dequeue Operation."<<endl;
	cout<<"\n4. Traverse."<<endl;
	
	cout<<"\nEnter your choice: "<<endl;
	cin>>choice;
	
	do {
		switch(choice) {
			case 1:
				cout<<"Empty Queue"<<endl;
				qu.MakeEmpty();
				break;
				
			case 2:
				cout<<"Enqueue Operation"<<endl;
				qu.Enqueue();
				break;
				
			case 3:
				cout<<"Dequeue Operation"<<endl;
				qu.Dequeue();
				break;
				
			case 4:
				cout<<"Traverse"<<endl;
				qu.Traverse();
				break;
				
			default:
				cout<<"Invalid choice. Enter another choice."<<endl;
		}
	} while(choice != 5);
	return 0;
}
