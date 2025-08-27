#include <iostream>
#include <unistd.h>     // fork, getpid, getppid
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // wait
using namespace std;

int main() {
    int n;
    pid_t pid;

    cout << "Enter number of child processes to create: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        pid = fork();  // Create child

        if (pid < 0) {
            cerr << "Fork failed!" << endl;
            return 1;
        }
        else if (pid == 0) {
            // Child process
            cout << "Child " << i+1 
                 << ": PID = " << getpid() 
                 << ", Parent PID = " << getppid() << endl;
            return 0;  // Child exits after printing
        }
        else {
            // Parent continues to next iteration
        }
    }

    // Parent waits for all children
    while (wait(NULL) > 0);

    return 0;
}
