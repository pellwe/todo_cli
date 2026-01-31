#include <iostream>
#include <string>
#include <vector>
#include "todo.h"
#include "storage.h"

std::string get_name() {
    std::string name = "";
    std::cout<<"enter a task name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    return name;
}

int startup() {
    int choice = 0;
    std::cout<<"Welcome to ur TODO list!\nWhat would u like to do?\n";
    std::cout<<"1. View Tasks    2. Add Task    3. Delete Task    4. Quit\n...";
    std::cin>>choice;
    return choice;
}

int main() {
    todo_list list;
    
    std::vector<std::string> loaded_tasks = load_tasks();
    size_t length = load_tasks().size();
    for(size_t i = 0; i < length; i++) {
        list.add_task(loaded_tasks[i]);
    }

    bool active = true;
    
    while(active) {
        switch(startup()) {
        case 1:
            list.print_list();
            break;
        case 2:
            list.add_task(get_name());
            break;
        case 3:
            list.delete_task(get_name());
            break;
        case 4:
            save_tasks(list.get_values());
            return 0;
        default:
            std::cout<<"Invalid Number!";
        }
    }
}
