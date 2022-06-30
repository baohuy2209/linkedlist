#include <iostream> 
#include <cstdio> 
#include <cstdlib> 

using namespace std; 
struct node{
	int info ; 
	struct node *next ; 
}* start;

class singly_list {
	public:
		singly_list(){
			start = NULL ; 
		}
		
		node* create_node(int); 
		int getSize();
		void insert_begin(); 
		void insert_end(); 
		void insert_pos()
		void delete_pos(); 
		void sort(); 
		void search();
		void update();
		void reverse(); 
		void display();
		
		int input_pos(){
			check = false ; 
			int pos ;
			while(!check){ 
				cin>>pos;
				if(pos <= this.getSize() && pos => 1){
					check = true;
				}else{
					cout<<"Wrong Entry !!! Invalid"<<endl;
				}
			}
			return pos ;
		}
};

int main(){
	int choice, nodes, element, position, i; 
	singly_list sl ; 
	start = NULL; 
	while(1){
		cout<<endl<< " Operations on singly linked list : "<<endl ; 
		cout<<"1. Insert node at beginning ."<<endl ;
		cout<<"2. Insert node at last ."<<endl ; 
		cout<<"3. Insert node at position ."<<endl ; 
		cout<<"4. Delete node at position ."<<endl ; 
		cout<<"5. Sorted linked list ."<<endl ; 
		cout<<"6. Update node value ."<<endl;
		cout<<"7. Search element ."<<endl; 
		cout<<"8. Display linked list ."<<endl; 
		cout<<"9. Reverse linked list ."<<endl; 
		cout<<"10. Exit ."<<endl ; 
		cout<<"Enter the choice : "<<endl ; 
		cin>>choice ; 
		switch(choice){
			case 1:
				cout<<"Inserting node at beginning ."<<endl; 
				sl.insert_begin(); 
				cout<<endl; 
				break;
			case 2:
				cout<<"Inserting node at last ."<<endl; 
				sl.insert_end(); 
				cout<<endl; 
				break; 
			case 3:
				cout<<"Inserting node at position ."<<endl; 
				sl.insert_pos(); 
				cout<<endl; 
				break; 
			case 4:
				cout<<"Deleting node ."<<endl; 
				sl.delete_pos();
				cout<<endl;
				break; 
			case 5:
				cout<<"Sort : "<<endl; 
				sl.sort();
				sl.display();
				cout<<endl;
				break;
			case 6:
				cout<<"Update value :"<<endl;
				sl.update(); 
				sl.display(); 
				cout<<endl;
				break; 
			case 7:
				cout<<"Search value : "<<endl;
				sl.search();
				cout<<endl ; 
				break;
			case 8:
				cout<<"Display elements of linked list ."<<endl; 
				sl.display(); 
				cout<<endl;
				break;
			case 9:
				cout<<"Reverse elements of linked list ."<<endl;
				sl.reverse();
				cout<<endl;
				break;
			case 10:
				cout<<"Exiting ... "<<endl;
				exit(1) ; 
				break;
			default:
				cout<<"Wrong entry!!!"<<endl; 
				break; 
		}
	}
}
node* singly_list::create_node(int value){
	struct node *temp; 
	temp = new (struct node);
	if(temp == NULL){
		cout<<"Memory not allocated "<<endl; 
		return 0;
	}else{
		temp->info = value;
		temp->next = NULL ; 
		return temp 
	}
}

int singly_list::getSize(){
	int size;
	struct node *p; 
	p = start;
	while(p != NULL){
		size = size + 1 ; 
		p = p ->next; 
	}
	return size; 
}

void singly_list::insert_begin(){
	int value; 
	cout<<"Enter the value to create node which is inserted at begin : "<<endl;
	cin>>value; 
	struct node *temp, *p; 
	temp = create_node(value);
	if(start == NULL){
		start = temp;
		start->next = NULL;
	}else{
		p = start ; 
		start = temp ; 
		start->next = p ; 
	}
	cout<<"Element inserted at beginning ."<<endl; 
}

void singly_list::insert_end(){
	int value;
	cout<<"Enter the value to create node which is inserted at last :"<<endl;
	cin>>value;
	struct node *temp, *p; 
	temp = create_node(value) ; 
	p = start; 
	if(start == NULL){
		start = temp;
		start->next = NULL; 
	}else{
		while (p->next != NULL){
			p = p->next ;
		}
		p->next = temp;
		temp->next = NULL;
	}
	
	cout<<"Element inserted at last ."<<endl;
}

void singly_list::insert_pos(){
	int value,position;
	cout<<"Enter the position to insert node : "<<endl;
	position = this.input_pos();
	cout<<"Enter the value to create node which is insert at "<<position<<" : "<<endl; 
	cin>>value;
	
	struct *temp, *p; 
	p = start; 
	temp = create_node(value) ; 
	
	if(pos == 1){
		if(start == NULL){
			start = temp ; 
			start->next = NULL;
			return ;
		}else{ 
			start = temp ; 
			start->next = p ; 
			return;
		}
	}
	if(pos == getSize()){
		if(start == NULL){
			start = temp;
			start->next = NULL; 
			return;
		}else{
			while (p->next != NULL){
				p = p->next ;
			}
			p->next = temp;
			temp->next = NULL;
			return;
		}
	}
	if(pos > 1 && pos < this.getSize()){
		struct *ptr;
		int pos = 0; 
		while(pos < position){
			pos = pos + 1; 
			ptr = p ; 
			p = p ->next; 
		}
		ptr->next = temp; 
		temp->next = p;
	}
	cout<<"Element inserted at position which is entried from keyboard ."<<endl; 
}
void singly_list::delete_pos(){
	int position;
	cout<<"Enter the position to delete node : "<<endl;
	position = this.input_pos();
	if(start == NULL){
		cout<<"This linked list is empty. "<<endl;
	}else{
		if(start ->next == NULL){
			start = NULL ;
		}else{
			if(position == 1){
				start = NULL;
			}
			else{
				struct *nptr, *ptr; 
				nptr = start; 
				ptr = NULL;
				int pos = 0; 
				while(pos < position){
				pos = pos + 1; 
				ptr = nptr;
				nptr = nptr->next;
				}
				struct node *tmp; 
				tmp = nptr->next; 
				ptr->next = tmp;
			}
		}
	}
	cout<<"Element deleted out of linked list ."<<endl;
}

void singly_list::update(){
	int value, position;
	cout<<"Enter position which you want to update : "<<endl;
	cin>>position; 
	cout<<"Enter the value to update at "<<position<<": "<<endl;
	cin>>value;
	
	struct node *nptr; 
	nptr = start; 
	if(start == NULL){
		cout<<"The linked list is empty . "<<endl; 
	}else{
		if(start->next == NULL){
			start->info = value;
		}else{
			int pos = 0; 
			while(pos < position){
				pos = pos + 1; 
				nptr = nptr->next;
			}
			nptr->info = value;
		}
	}
	cout<<"Updated !!!"<<endl; 
}

void singly_list::sort(){
	int value; 
	struct node *ptr, *nptr, *tmp;
	if(start == NULL){
		cout<<"The linked list is empty . "<<endl;
		return; 
	}
	
	nptr = start;
	while(nptr != NULL){
		for(ptr = nptr->next; ptr != NULL; ptr = ptr->next){
			if(nptr->info > ptr->info){
				value = nptr->info;
				nptr->info = ptr->info;
				ptr->info = value;
			}
		}
		nptr = nptr->next;
	}
	tmp = start;
	cout<<"After sort :"; 
	while(tmp != NULL){
		cout<<tmp->info<<" ";
		tmp = tmp->next; 
	}	
}

void singly_list::search(){
	int value, pos = 0;
	bool flag = false;
	if(start == NULL){
		cout<<"The linked list is empty . "<<endl;
		return;
	}
	cout<<"Enter the value to search in linked list : "<<endl;
	cin>>value;
	
	struct node *ptr; 
	ptr = start; 
	while(ptr != NULL && flag != true) {
		pos++;
		if(ptr->info == value){
			flag = true ; 
			cout<<"Element "<<value<<" is found at position "<<pos<<" ."<<endl;
		}
		ptr = ptr->next; 
	}
	if(!flag){
		cout<<"Element "<<value<<"is not found in linked list ."<<endl;
	}
}

void singly_list::reverse(){
	struct node *ptr1, *ptr2, *ptr3; 
	if(start == NULL){
		cout<<"The linked list is empty . "<<endl;
		return; 
	}
	if(start -> next == NULL){
		return; 
	}
	ptr1 = start; 
	ptr2 = ptr1->next; 
	ptr3 = ptr2->next; 
	ptr1->next = NULL;
	ptr2->next = ptr1;
	while(ptr3 != NULL){
		ptr1 = ptr2; 
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;
	}
	start = ptr2; 
}

void singly_list::display(){
	struct node *ptr;
	if (start == NULL){
		cout<<"The linked list is empty . "<<endl;
		return; 
	}
	if (start->next == NULL){
		cout<<"Linked list : "<<start->info<<endl; 
		return; 
	}
	ptr = start;
	cout<<"Linked list : "; 
	while(ptr != NULL){
		cout<<ptr->info<<" ";
		ptr = ptr->next;
	}
}
