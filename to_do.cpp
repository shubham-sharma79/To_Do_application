#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the menu options
void displayMenu() {
    cout << "\n===== To-Do List Application =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "===================================\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> tasks; // Vector to store tasks

    int choice;
    string task;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter task: ";
                cin.ignore(); // Ignore previous newline character
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task added!\n";
                break;
            case 2:
                if(tasks.empty()) {
                    cout << "No tasks to display.\n";
                } else {
                    cout << "Tasks:\n";
                    for(int i = 0; i < tasks.size(); ++i) {
                        cout << i+1 << ". " << tasks[i] << endl;
                    }
                }
                break;
            case 3:
                int index;
                if(tasks.empty()) {
                    cout << "No tasks to delete.\n";
                } else {
                    cout << "Enter task number to delete: ";
                    cin >> index;
                    if(index < 1 || index > tasks.size()) {
                        cout << "Invalid task number.\n";
                    } else {
                        tasks.erase(tasks.begin() + index - 1);
                        cout << "Task deleted!\n";
                    }
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while(choice != 4);

    return 0;
}
