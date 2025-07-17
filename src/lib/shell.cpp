#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int run_shell(string command) {
    system(command.c_str());
    return 0;
}

int run_thread(string command, bool debug = false) {
    thread shell_thread(run_shell, command);
    chrono::high_resolution_clock::time_point timeOnThreadStart;

    if (debug) {
        cout << "[qtd] Started new thread: " << command << endl;
        timeOnThreadStart = chrono::high_resolution_clock::now();
    }
    shell_thread.join();
    if (debug) {
        auto timeOnThreadEnd = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(timeOnThreadEnd - timeOnThreadStart).count();
        cout << "[qtd] Thread joined (" << duration << "ms)" << endl;
    }
    return 0;
}
