#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct task {    
    std::string name = "";
    bool completed = false;

    struct task* next; 
};

class todo_list {
    private:
        task* head;
        task* tail;

    public:
        todo_list() { //this is a constructor which auto assigns some values to the class as all iteratios of this class will need these values assigned to them
            head = nullptr; 
            tail = nullptr;
        }

        std::vector<std::pair<std::string, bool>> get_values() {
            task* current = head;
            std::vector<std::pair<std::string, bool>> values;
            std::pair<std::string, bool> full_task;
            while(current != nullptr) {
                full_task = {current->name, current->completed};
                values.push_back(full_task);
                current = current->next;
            }
            return values;
        }
        
        int access_task(std::string target, bool deletion) {
            task* current = head; //points to the address of the current task, which atp is the head of the linked list  
            task* previous = nullptr; //points to the task before the current, atp being nothing as the current is the first
            while(current != nullptr) {  //while the current task is not a nullptr(nothing) the function searches for the target 
                if(current->name == target) { //checks if the current tasks name is the same as the target task
                    if(deletion) {
                        if(head == tail) {
                            head = nullptr;
                            tail = nullptr;
                        }
                        else if(previous == nullptr) { //checks if the target task is the first task(the head)
                            head = current->next; //removes the head from the list by pointing head to the next task
                        }
                        else if(current == tail) { //ensures that tail is always a valid task (and the last task)
                            tail = previous;
                            previous->next = nullptr;
                        }
                        else { //if the target task was not the head(so any task after the first one) then this will be whats run
                            previous->next = current->next; //skip over current, removing it from the list
                        }
                        delete current; //frees the memory that was used for the deleted task
                        std::cout<<"Task Deleted !\n";
                        return 0;
                    }
                    else {
                        current->completed = true;
                        std::cout<<"Task Completed !\n";
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

        void add_task(std::string task_name) {   //adds a new task to the end of the list
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
    
        ~todo_list() { //this is a destructor, it cleans up the memory when the program closes
            task* current = head;
            while(current != nullptr) {
                task* next_task = current->next;
                delete current;
                current = next_task;
            }
        }
};

