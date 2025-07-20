#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Run shell command normally
int run_shell(string command, bool debug = false) {
    int code = system(command.c_str());
    if (debug) {
        cout << "[qtd] Running command: " << command << endl;
        if (code == 0) {
            cout << "[qtd] Command finished successfully." << endl;
        } else {
            cout << "[qtd] Command failed with code: " << code << endl;
        }
    }
    return code;
}

// Run shell command in a thread
int run_thread(string command, bool debug = false) {
    chrono::high_resolution_clock::time_point timeOnThreadStart; // Define variable to store start time of the thread

    thread shell_thread(run_shell, command, debug); // Start thread

    // If debug is true, print the command being executed and set start time
    if (debug) {
        cout << "[qtd] Started new thread." << endl;
        timeOnThreadStart = chrono::high_resolution_clock::now();
    }

    shell_thread.join(); // Wait for thread to finish

    // If debug is true, calculate and print the time taken until thread join
    if (debug) {
        auto timeOnThreadEnd = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(timeOnThreadEnd - timeOnThreadStart).count();
        cout << "[qtd] Thread joined (" << duration << "ms)" << endl;
    }

    return 0;
}
