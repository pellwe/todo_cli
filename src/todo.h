#include <iostream>
#include <string>

std::string get_name() {
    std::string name = "";
    std::cout<<"enter a task name: ";
    std::cin.ignore(); //clears any newlines that may have been lingering (therefore preventing the program from moving on without taking user input)
    std::getline(std::cin, name); //used instead of std::cin as it can take in whitespaces too
    return name;
}

struct task {    
    std::string name = "";
    bool completed = false;

    struct task* next; 
};

class todo_list {
    public:
        todo_list() { //this is a constructor which auto assigns some values to the class as all iteratios of this class will need these values assigned to them
            head = nullptr; 
            tail = nullptr;
        }
        
        int delete_task() {
            std::string target = get_name();
            task* current = head; //points to the address of the current task, which atp is the head of the linked list  
            task* previous = nullptr; //points to the task before the current, atp being nothing as the current is the first

            while(current != nullptr) {  //while the current task is not a nullptr(nothing) the function searches for the target 
                if(current->name == target) { //checks if the current tasks name is the same as the target task
                    if(previous == nullptr) { //checks if the target task is the first task(the head)
                        head = current->next; //changes the head to the next task, removing the head and deleting the task
                        std::cout<<"task deleted.\n";
                        return 0;
                    }
                    else { //if the target task was not the head(so any task after the first one) then this will be whats run
                        previous->next = current->next; //the previous task is made equal to the current one (removing the task)
                        std::cout<<"task deleted.\n";
                        return 0;
                    }
                }
                else { //this advances the checking to the next task, as the task just checked was not the target
                    previous = current;
                    current = current->next;
                }    
            } 
            std::cout<<"could not find task with name "<<target<<"!\n";
            return 0;
        }

        void add_task() {   //adds a new task to the end of the list
            std::string task_name = get_name();
            task* temp = new task;
            temp->name = task_name;
            temp->next = nullptr;

            if(head == nullptr) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
        }

        void print_list() {   //allows user to view thier tasks
            task* current = head;
            
            std::cout<<"TODO:\n";
            while(current != nullptr) {
                std::cout<<current->name<<": "<<current->completed<<"\n\n";
                current = current->next;
            }
        }

    private:
        task* head;
        task* tail;
};
