#include <iostream> 

using namespace std; 

class DequeEmptyException{
	public :
		DequeEmptyException(){
			cout<<"Deque empty"<<endl ; 
		}
};

class Node{
	int data;
	Node *prev ; 
	Node *next ; 
};

class Deque{
	private:
		int count; 
		Node *front; 
		Node *rear; 
	public:
		Deque(){
			count = 0; 
			front = NULL ; 
			rear = NULL ; 
		}
		void InsertFront(int element){
			// Create new node 
			
			Node *tmp; 
			tmp->next = NULL;
			tmp->prev = NULL; 
			tmp->data = element; 
			if(isEmpty()){
				front = tmp; 
				rear = tmp; 
			}else{
				tmp->next = front;
				front->prev = tmp;
				front = tmp;
			}
			count++; 
		}
		
		int RemoveFront(){
			if(isEmpty()){
				throw new DequeEmptyException() ; 
			}
			
			// Data in front node 
			int ret = front->data;
			
			Node *tmp = front; 
			if(front->next != NULL){
				
				// Delete node and fix link 
				front = front->next;
				front->prev = NULL;
			}else{
				front = NULL ; 
			}
			
			delete tmp ; 
			
			count--;
			
			return ret ;
		}
		
		void InsertBack(int element){
			// Create a new node 
			
			Node *tmp; 
			tmp->data = element;
			tmp->next = NULL ; 
			tmp->prev = NULL ; 
			if(isEmpty()){
				front = tmp;
				rear = tmp;
			}else{
				rear->next = tmp; 
				tmp->prev = rear; 
				rear = tmp; 
			}
			
			count++; 
			
		}
		
		int RemoveBack(){
			if(isEmpty()){
				throw new DequeEmptyException() ; 
			}
			
			int ret = rear->data; 
			
			Node *tmp = rear; 
			if(front->next == NULL){
				front = NULL; 
			}else{
				rear = rear->prev;
				rear->next = NULL;
			}
			delete tmp; 
			count--;
			
			return ret; 
		}
		
		int getSize(){
			return count++;
		}
		
		bool isEmpty(){
			return count == 0 ? true:false ; 
		}
		
		int Front(){
			if(isEmpty()){
				throw new DequeEmptyException() ; 
			}
			return front->data;
		}
		
		int Back(){
			if(isEmpty()){
				throw new DequeEmptyException() ; 
			}
			return rear->data;
		}
};
