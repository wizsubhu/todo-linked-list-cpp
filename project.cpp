/*** C++ CODE FOR TO DO LIST ***/
#include<iostream>
using namespace std;
/*** FUNCTIONS PERFORMED ON A TO DO LIST ***/
void create_tasks();
void add_new_task_in_end();
void delete_tasks();
void view_list();
void edit_list();
void count_tasks();
void search_tasks();
void priority_tasks();
/*** TO DO LIST BASED ON THE CONCEPT OF LINKED LIST ***/
struct tasks{
	string data;
	int priority;
	struct tasks*next;
};
/*** GLOBAL VARIABLES ***/
struct tasks*start=NULL;
struct tasks*ptr;
struct tasks*pre;
struct tasks*current;
int p;
/*** MAIN FUNCTION ***/
int main(){
	int i,condition;
	char x,y;
	while(true){
		cout<<"1..Create tasks list \n"<<"2..Add new task \n"<<"3..Delete tasks \n"<<"4..View list \n"<<"5..Edit list \n"<<"6..Count tasks \n"<<"7..Search task \n"<<"8..Priority task \n"<<"9.. Exit  \n";
		cin>>condition;
		/*** SWITCH CASES TO SELECT DESIRED FUNCTION ***/
		switch(condition){
			case 1:{
				create_tasks();
				cout<<"Task added"<<endl;
				break;
			}
			case 2:{
				add_new_task_in_end();
				cout<<"New task added"<<endl;
				break;
			}
			case 3:{
				delete_tasks();
				cout<<"Deleted"<<endl;
				break;
			}
			case 4:{
				view_list();
				break;
			}
			case 5:{
				edit_list();
				break;
			}
			case 6:{
				count_tasks();
				break;
			}
			case 7:{
				search_tasks();
				break;
			}
			case 8:{
				priority_tasks();
				break;
			}
			case 9:{
				exit(0);
				break;
			}
		}
	}	
	
	
	return 0;
}
/*** THE VERY FIRST TASK IN THE TO DO LIST ***/
void create_tasks(){
	struct tasks*newtask1=new tasks;
	cout<<"Enter 1st task "<<endl;
	start=newtask1;
	cin>>newtask1->data;
	cout<<"Enter the priority of the task "<<endl;
	cin>>p;
	newtask1->priority=p;
	newtask1->next=NULL;
}
/*** ADDING UP TASK IN THE TO DO LIST ***/
void add_new_task_in_end(){
	struct tasks*newtask=new tasks;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=newtask;
	cout<<"Add new task  "<<endl;
	cin>>newtask->data;
	cout<<"Enter the priority of the task "<<endl;
	cin>>p;
	newtask->priority=p;
	newtask->next=NULL;
}
/*** TO DELETE ANY TASK AFTER COMPLETION ***/
void delete_tasks(){
	string deletetask;
	cout<<"Enter the task to be deleted "<<endl;
	cin>>deletetask;
	cout<<endl<<endl;
	ptr=start;
	pre=ptr;
	while(ptr->data !=deletetask){
		pre=ptr;
		ptr=ptr->next;
	}
	pre->next=ptr->next;
	
}
/*** TO COUNT THE NUMBER OF TASKS IN THE TO DO LIST ***/
void count_tasks(){
	int Count=1;
	ptr=start;
	while(ptr->next!=NULL){
		Count++;
		ptr=ptr->next;
	}
	cout<<"The number of task in To Do List is "<<Count<<endl;
}
/*** TO EDIT ANY PRESENT TASK IN TO DO LIST ***/
void edit_list(){
	string Search,Edited;
	cout<<"Enter the task to be edited "<<endl;
	cin>>Search;
	ptr=start;
	while(ptr->data!=Search){
	ptr=ptr->next;
	}
	cout<<"Enter the edited task "<<endl;
	cin>>Edited;
	ptr->data=Edited;
}
/*** SEARCH THE PRIORITY OF THE GIVEN TASK ***/
void search_tasks(){
	string task;
	cout<<"Enter the task for search priority "<<endl;
	cin>>task;
	ptr=start;
	while(ptr->data!=task){
		ptr=ptr->next;
	}
	cout<<"Priority for the following task "<<ptr->priority<<endl;
	
} 
/*** TO DISPLAY THE TO DO LIST ***/
void view_list(){
		ptr=start;
		cout<<"Your current To Do list is "<<endl;
	while(ptr!=NULL){
		cout<<ptr->priority<<". ";
		cout<<ptr->data;
		cout<<" "<<endl;
		ptr=ptr->next;
	}
	cout<<endl;
}
/*** ARRANGE THE TO DO LIST AS PER THE INCREASING PRIORITY ***/
void priority_tasks(){
	cout<<"List with increasing priority"<<endl;
	ptr=start;
	pre=ptr;
	string temp;
	int current;
	while(pre->next!=NULL){
		ptr=pre->next;
		while(ptr!=NULL){
		if(pre->priority > ptr->priority){
			temp = pre->data;
			pre->data = ptr->data;
			ptr->data = temp;
			current = pre->priority;
			pre->priority=ptr->priority;
			ptr->priority=current;	
		}
		ptr=ptr->next;
	}
	pre=pre->next;
	}
		ptr=start;
		cout<<"Your current To Do list is "<<endl;
	while(ptr!=NULL){
		cout<<ptr->priority<<". ";
		cout<<ptr->data;
		cout<<" "<<endl;
		ptr=ptr->next;
	}
	cout<<endl;
}
