#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

vector<Task> todoList;

void addTask() {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    todoList.push_back(Task(desc));
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        string status = todoList[i].completed ? "Completed" : "Pending";
        cout << i + 1 << ". [" << status << "] " << todoList[i].description << "\n";
    }
    cout << "\n";
}

void markCompleted() {
    int index;
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    todoList[index - 1].completed = true;
    cout << "Task marked as completed!\n";
}

void removeTask() {
    int index;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    todoList.erase(todoList.begin() + index - 1);
    cout << "Task removed successfully!\n";
}

void showMenu() {
    cout << "\n To-Do List Manager \n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
