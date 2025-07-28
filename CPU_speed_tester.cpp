#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int operations, cnt = 0;
    clock_t start_time = clock();
    cin >> operations;
    ifstream cpuinfo("/proc/cpuinfo");
    string line;
    for (int i = 0; i < operations; i++)
    {
        cnt++;
    }
    clock_t end_time = clock(); 
    double elapsed_seconds = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    while (getline(cpuinfo, line)) {
        if (line.rfind("model name", 0) == 0) {
            size_t colon_pos = line.find(":");
            if (colon_pos != string::npos) {
                string model_name = line.substr(colon_pos + 2);
                cout << "CPU Model Name: " << model_name << " can execute " << operations << " in " << fixed << elapsed_seconds << setprecision(6) << " second(s)\n";
                break;
            }
        }
    }
    return 0;
}
