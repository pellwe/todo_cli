#include <iostream>
#include "todo.h"

int startup() {
    int choice = 0;
    std::cout<<"Welcome to ur TODO list!\nWhat would u like to do?\n";
    std::cout<<"1. View Tasks    2. Add Task    3. Delete Task    4. Quit\n...";
    std::cin>>choice;
    return choice;
}

int main() {
    todo_list list;
    bool active = true;
    
    while(active) {
        switch(startup()) {
        case 1:
            list.print_list();
            break;
        case 2:
            list.add_task();
            break;
        case 3:
            list.delete_task();
            break;
        case 4:
            return 0;
        default:
            std::cout<<"Invalid Number!";
        }
    }
}
