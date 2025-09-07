#include <bits/stdc++.h>
using namespace std;

struct Task {
    string description;
    bool completed;
    time_t createdAt;

    // Default constructor
    Task() {
        description = "";
        completed = false;
        createdAt = time(nullptr);
    }

    // Parameterized constructor
    Task(string desc) {
        description = desc;
        completed = false;
        createdAt = time(nullptr);
    }

    void display(int id) const {
        cout << "ID: " << id << " | " << description
             << " | Status: " << (completed ? "Done" : "Pending")
             << " | Created: " << put_time(localtime(&createdAt), "%Y-%m-%d %H:%M:%S") << "\n";
    }
};

class TaskManager {
private:
    map<int, Task> tasks;
    int nextId = 1;

public:
    void addTask() {
        string desc;
        cout << "Enter task description: ";
        cin.ignore();
        getline(cin, desc);
        tasks[nextId] = Task(desc);
        cout << "Task added with ID: " << nextId << "\n";
        nextId++;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        for (map<int, Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
            int id = it->first;
            const Task& task = it->second;
            task.display(id);
        }
    }

    void markCompleted() {
        int id;
        cout << "Enter task ID to mark as completed: ";
        cin >> id;
        if (tasks.count(id)) {
            tasks[id].completed = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task ID.\n";
        }
    }

    void removeTask() {
        int id;
        cout << "Enter task ID to remove: ";
        cin >> id;
        if (tasks.erase(id)) {
            cout << "Task removed.\n";
        } else {
            cout << "Invalid task ID.\n";
        }
    }
};

int main() {
    TaskManager manager;
    int choice;

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addTask(); break;
            case 2: manager.viewTasks(); break;
            case 3: manager.markCompleted(); break;
            case 4: manager.removeTask(); break;
            case 5: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
