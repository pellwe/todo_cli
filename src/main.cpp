
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <chrono>
#include "todo.h"
#include "storage.h"
#include "streaks.h"

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
    std::cout<<"1. View Tasks    2. Add Task    3. Complete Task    4. Delete Task    5. Quit\n...";
    std::cin>>choice;
    return choice;
}

int main() {
    streak s1;
    std::cout<<s1.get_completion();
    todo_list list;
    
    std::vector<std::string> loaded_tasks = load_tasks();
    size_t length = load_tasks().size();
    for(size_t i = 0; i < length; i+=2) {
        list.add_task(loaded_tasks[i], std::stoi(loaded_tasks[i+1]));
    }

    bool active = true;
    
    while(active) {
        switch(startup()) {
        case 1:
            list.print_list();
            break;
        case 2:
            list.add_task(get_name(), false);
            break;
        case 3:
            list.access_task(get_name(), false); //remember to add the edit/delete feature !!!
            break;
        case 4:
            list.access_task(get_name(), true);
            break;
        case 5:
            save_tasks(list.get_values());
            return 0;
        default:
            std::cout<<"Invalid Input !";
            return 0;
        }
    }
}
