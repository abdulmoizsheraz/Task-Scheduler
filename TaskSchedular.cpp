#include<iostream>
using namespace std;

struct Task{
	int id;
	string title;
	string desc;
	string dueDate;
    float priority; 
	Task* next;
	Task* prev;
};

class TaskScheduler{
	private:
		Task* head;
		
	public:
         TaskScheduler(){
		this->head = NULL;
		 // Here add this.tail=null
	}

    // function to add at first position
    void addTask(int id, string title, string desc, string dueDate, float priority){
    Task* task = new Task{id, title, desc, dueDate, priority};   
    task->next = head;
    task->prev = NULL; 

    if(head != NULL){
        head->prev = task;
    }
    head = task; 
}


    // function to display the list
   void displayTasks(){
    // Sorting the tasks based on priority in descending order before displaying
    Task* current = head;
    Task* index = NULL;
    float tempPriority;
    int tempId;
    string tempTitle, tempDesc, tempDueDate;

    while(current != NULL){
        index = current->next;

        while(index != NULL){
            if(current->priority < index->priority){
                // Swap the priority values
                tempPriority = current->priority;
                current->priority = index->priority;
                index->priority = tempPriority;

                // Swap other task details
                tempId = current->id;
                current->id = index->id;
                index->id = tempId;

                tempTitle = current->title;
                current->title = index->title;
                index->title = tempTitle;

                tempDesc = current->desc;
                current->desc = index->desc;
                index->desc = tempDesc;

                tempDueDate = current->dueDate;
                current->dueDate = index->dueDate;
                index->dueDate = tempDueDate;
            }
            index = index->next;
        }
        current = current->next;
    }

    // Display the sorted tasks
    current = head;
    while(current != NULL){
        cout<<"ID: "<<current->id<<endl;
        cout<<"Title: "<<current->title<<endl;
        cout<<"Description: "<<current->desc<<endl;
        cout<<"Due Date: "<<current->dueDate<<endl;
        cout<<"Priority: "<<current->priority<<endl;
        cout<<" "<<endl;
        current = current->next;
    }
    }
};
// Make a functions:
//  that will automatically sort our DOUBLY linked list according to priority etc.
//  that search the Task by by Date (near to far), by priority set by him ( at the start ) .
//  that search by Category i.e fitness category will give all the tasks related to fitness ( we can search by string category/priority already defined in Task Node Stucture.
// that enables user to edit the task first user will search task by name ( added already ) then update it ,Updated Node will go in the Place of which user wants to change.
int main(){
	// add a while loop that is always true and also it will display some list first of all as soon as user enters the app he should get the menu to enter his priority so that we can sort our linkedlist accordingly
	TaskScheduler list;
    int choice, id;
    float priority;
    string title, desc, dueDate;
    cout<<"*********Welcome to Task Scheduler*********"<<endl;
   do {
        cout<<"\n<----Our Menu Card---->\n";
        cout<<"1. Add a task\n";
        cout<<"2. Display the tasks\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout<<"Enter ID: ";
            cin>>id;
            cout<<"Enter Title: ";
            cin.ignore(); 
            getline(cin, title);
            cout<<"Enter Description: ";
            getline(cin, desc);
            cout<<"Enter Due Date: ";
            cin>>dueDate;
            cout<<"Enter your task priority (1 for high), (0.5 for medium), (0 for low): ";
            cin>>priority;
            list.addTask(id, title, desc, dueDate, priority);
            break;

        case 2:
            cout<<"\nDisplaying all tasks..."<<endl;
            list.displayTasks();
            break;

        case 3:
             cout<<"Exiting the program"<<endl;
            break;

        default:
            cout<<"Invalid choice. Please enter a valid option.\n";
        }

    }while(choice != 0);

    return 0;
}
