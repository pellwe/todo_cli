#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

void save_tasks(std::vector<std::pair<std::string, bool>> list1) {
    std::ofstream my_file("data.txt");
    std::size_t length = list1.size();
    for(std::size_t i = 0; i < length; i++) {
        my_file<<list1[i].first<<"\n"<<list1[i].second<<"\n";
    }
    my_file.close();
}

std::vector<std::string> load_tasks() {
    std::vector<std::string> my_tasks;
    std::string line;
    std::ifstream my_read_file("data.txt");
    while(getline(my_read_file, line)) {
        my_tasks.push_back(line);
    }
    my_read_file.close();
    return my_tasks;
}
