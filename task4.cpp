1#include <iostream>
#include <string>
using namespace std;
int main()
{
    string tasks[100];
    bool done[100];
    int n = 0;
    int ch;
    do {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();

        if (ch == 1) 
        {
            if (n < 100) {
                cout << "Enter task: ";
                getline(cin, tasks[n]);
                done[n] = false;
                n++;
                cout << "Task added.\n";
            } else
                cout << "List full, cannot add more.\n";
        }

        else if (ch == 2) 
        {
            if (n == 0)
                cout << "No tasks yet.\n";
            else {
                cout << "\n--- Task List ---\n";
                for (int i = 0; i < n; i++) {
                    cout << i + 1 << ". " << tasks[i];
                    if (done[i]) cout << " [Completed]";
                    else cout << " [Pending]";
                    cout << endl;
                }
            }
        }

        else if (ch == 3) 
        {
            if (n == 0) 
            {
                cout << "No tasks yet.\n";
            } else {
                int num;
                cout << "Task number to mark done: ";
                cin >> num;
                if (num >= 1 && num <= n) {
                    done[num - 1] = true;
                    cout << "Marked as completed.\n";
                } else
                    cout << "Invalid number.\n";
            }
        }

        else if (ch == 4) 
        {
            if (n == 0) {
                cout << "No tasks yet.\n";
            } else {
                int num;
                cout << "Task number to remove: ";
                cin >> num;
                if (num >= 1 && num <= n) {
                    for (int i = num - 1; i < n - 1; i++) {
                        tasks[i] = tasks[i + 1];
                        done[i] = done[i + 1];
                    }
                    n--;
                    cout << "Removed.\n";
                } else
                    cout << "Invalid number.\n";
            }
        }

        else if (ch == 5) {
            cout << "Exiting... bye!\n";
        }

        else {
            cout << "Invalid choice, try again.\n";
        }

    } while (ch != 5);
    return 0;
}