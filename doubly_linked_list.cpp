#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// Node Declaration 
struct node{
	int info;
	struct node *prev,*next;
}*start;

class doubly_list{
	public :
		
		doubly_list(){
			start = NULL;
		}
		
		int inputposition(){
			int pos; 
			bool check = false; 
			while(!check){
				cout<<"Enter the position : "<<endl; 
				cin>>pos;
				if(pos >= 1 && pos <= getSize()){
					check = true ; 
				}else{
					cout<<"Invalid entry"<<endl; 
				}
			}
			return pos ; 
		}
		
		void create_node(int value){
			struct node *temp, *s;
			temp = new (struct node) ; 
			temp->info = value;
			temp->next = NULL;
			if(start == NULL){
				temp->prev = NULL;
				start = temp;
			}else{
				s = start ; 
				while (s->next != NULL){
					s= s->next; 
				}
				s->next = temp ; 
				temp->prev = s; 
			}
		}
		void insert_begin(int value){
			if (start == NULL){
				cout<<"First Create the list ."<<endl;
				return;
			}
			struct node *temp;
			temp = new (struct node);
			temp->info = value;
			temp->next = start;
			temp->prev = NULL; 
			start->prev = temp; 
			start = temp;
			
			cout<<"Element is inserted "<<endl; 
		}
		void insert_last(int value){
			if (start == NULL){
				cout<<"First create the list ."<<endl;
				return; 
			}
			struct node *temp, *s;
			s = start ;  
			while(s->next != NULL){
				s = s->next ;
			}
			temp->next = NULL ; 
			temp->prev = s ; 
			temp->info = value ; 
			s->next = temp ; 
			
			cout<<"Element is inserted ."<<endl; 
		}
		void insert_pos(int value, int position){
			if (start = NULL){
				cout<<"First create the list ."<<endl;
				return; 
			}
			if (position == 1){
				insert_begin(value) ;
				return;
			}
			if (position == getSize()){
				insert_last(value) ; 
				return; 
			}
			int pos = 0 ;
			struct node *temp, *nptr, *ptr; 
			nptr = start; 
			while (pos < position){
				pos = pos + 1; 
				ptr = nptr;
				nptr = nptr->next; 
			}
			temp ->info = value;
			temp->prev = ptr;
			temp->next = nptr;
			ptr->next = temp;
			nptr->prev = temp; 
			
			cout<<"Element is inserted ."<<endl;
		} 
		void delete_pos(int position){
			
			struct node *s, *tmp, *ptr; 
			if (start == NULL){
				cout<<"This is a empty doubly linked list ."<<endl; 
				return; 
			}
			if (start->next == NULL){
				start = NULL ; 
				return; 
			}
			s = start;
			if (position == 1){
				s = s->next;
				start = s ; 
				return; 
			}
			if (position == getSize()){ 
				while(s->next != NULL){
					s = s->next ; 
				}
				s = s->prev ; 
				s->next = NULL;
				return;  
			}
			int pos = 0; 
			while(pos < position){
				pos = pos + 1;
				tmp = s ; 
				s = s->next; 
			}
			ptr = s->next; 
			tmp->next = ptr ;
			ptr->prev = tmp;  
			
			
			cout<<"Element is deleted ."<<endl;
		}
		void search_element(int value){
			bool found = false;
			struct node *s; 
			s = start;
			int pos = 0 ; 
			while (s != NULL && found != true){
				if(s->info == value){
					found = true;
				}
				pos = pos + 1; 
				s = s->next;
			}
			if(!found){
				cout<<"Element is not found in the linked list ."<<endl; 
				return; 
			}
			
			cout<<"Element is found at position : "<<pos<<endl;
		}
		void display(){
			if(start == NULL){
				cout<<"The list is empty ."<<endl;
				return;
			}
			
			if(start->next == NULL){
				cout<<"Elements in the doubly linked list : "<<start->info<<endl;
				return;
			}
			
			struct node *s; 
			s = start ; 
			cout <<"Elements in the doubly linked list : ";
			while(s!= NULL){
				cout <<s->info<<" "; 
				s = s->next; 
			}
			
			cout<<endl;
		}
		void update(int value, int position){
			if (position == 1){
				start->info = value;
				return; 
			}
			struct node *s; 
			s = start;
			int pos = 0 ; 
			while(pos < position){
				pos = pos+1;
				s = s->next ; 
			}
			s->info = value ; 
			
			cout<<"Updated value to the elements which you want !!! "<<endl; 
		}
		int getSize(){
			struct node *s ; 
			s = start ; 
			int size =  0 ;
			while(s != NULL){
				size =  size + 1; 
				s = s->next ; 
			}
			return size;
		}
		bool checkEmpty(){
			return start == NULL; 
		}
		void reverse(){
			struct node *p1, *p2; 
			p1 = start ; 
			p2 = p1->next; 
			p1->next = NULL ; 
			p1->prev = p2 ; 
			while(p2 != NULL){
				p2->prev = p2->next; 
				p2->next = p1; 
				p1 = p2 ; 
				p2 = p2->next; 
			} 
			start = p1; 
			
			cout <<"List Reversed"<<endl;
		}
		void concatenate(){
		
		}
		void decomposition(){
			
		} 
};

int inputdata(){
	int data; 
	cout<<"Enter the data : "<<endl ;
	cin>>data; 
	
	return data; 
}

int main (){
	int choice; 
	doubly_list dl;
	
	cout<<"Operations on Doubly linked list list"<<endl;
	cout<<"0. Create a list "<<endl ; 
	cout<<"1. Insert at beginning ."<<endl; 
	cout<<"2. Insert at last ."<<endl; 
	cout<<"3. Insert at position "<<endl;
	cout<<"4. Delete node at position ."<<endl ; 
	cout<<"5. Get size of doubly linked list ."<<endl ; 
	cout<<"6. Update node value ."<<endl;
	cout<<"7. Search element ."<<endl; 
	cout<<"8. Display linked list ."<<endl; 
	cout<<"9. Reverse linked list ."<<endl; 
	cout<<"10. Check empty ."<<endl;
	cout<<"11. Concatenate two list ."<<endl;
	cout<<"12. Decomposition two list ."<<endl;
	cout<<"13. Exit ."<<endl ; 
	bool ck = true;
	
	do {
		cout<<"Enter your choice : "<<endl ; 
		cin>>choice;
		switch(choice){
			case 0:
				int value ; 
				value = inputdata() ;
				dl.create_node(value) ; 
				cout<<endl; 
				dl.display() ; 
				break; 
			case 1:
				int value ;
				value = inputdata() ; 
				dl.insert_begin(value) ; 
				cout<<endl;
				dl.display();
				break;
			case 2:
				int value; 
				value = inputdata(); 
				dl.insert_last(value) ; 
				cout<<endl; 
				dl.display();
				break;
			case 3:
				int value, pos;
				value = inputdata();
				pos = dl.inputposition() ;  
				dl.insert_pos(value,pos) ; 
				cout<<endl; 
				dl.display();
				break;
			case 4:
				int position; 
				position = dl.inputposition() ; 
				dl.delete_pos(position);
				cout<<endl; 
				dl.display();
				break; 
			case 5:
				cout<<"Size of the doubly linked list : "<<dl.getSize()<<endl;
				break; 
			case 6:
				int value, pos;
				value = inputdata();
				pos = dl.inputposition() ; 
				dl.update(value,pos) ; 
				cout<<endl;
				dl.display() ;
				break;  
			case 7:
				int value;
				value = inputdata() ; 
				dl.search_element(value) ;
				cout<<endl;
				break;
			case 8:
				dl.display();
				cout<<endl ; 
				break; 
			case 9:
				dl.reverse();
				cout<<endl; 
				break;
			case 10:
				cout<<"Empty status : "<<dl.checkEmpty() ; 
				break; 
			case 11:
				dl.concatenate() ; 
				cout<<endl; 
				break;
			case 12:
				dl.decomposition() ; 
				cout<<endl; 
				break ; 
			case 13:
				ck = false;
			default:
				cout<<"Wrong try !!! Invalid "<<endl ;
				break; 
		}
	}while(ck) ; 
	return 0;
}
