#include <iostream>
#include <string>

std::string get_name() {
    std::string name = "";
    std::cout<<"enter a task name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    return name;
}

struct task {    
    std::string name = "";
    bool completed = false;

    struct task* next; 
};

class todo_list {
    public:
        todo_list() {
            head = nullptr;
            tail = nullptr;
        }
        
        int delete_task() {
            std::string target = get_name();
            task* current = head;
            task* previous = nullptr;

            while(current != nullptr) {
                if(current->name == target) {
                    if(previous == nullptr) {
                        head = current->next;
                        std::cout<<"task deleted.\n";
                        return 0;
                    }
                    else {
                        previous->next = current->next;
                        std::cout<<"task deleted.\n";
                        return 0;
                    }
                }
                else {
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
                std::cout<<current->name<<"\n"<<current->completed<<"\n\n";
                current = current->next;
            }
        }

    private:
        task* head;
        task* tail;
};
