#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream input("input.c");
    ofstream output("2233081150.txt");

    if (!input.is_open()) {
        cout << "File can't be opened" << endl;
        return 0;
    }

    string line;
    int voidCount = 0, intCount = 0;

    while (getline(input, line)) {
        if (line.find('(') != -1 && line.find(')') != -1 && line.find(';') == -1) {
            if (line.substr(0, 5) == "void ") {
                voidCount++;
            } else if (line.substr(0, 4) == "int ") {
                intCount++;
            }
        }
    }

    output << "Return type\t" << "Counts" << endl;
    output << "Integer    \t" << intCount << "\n";
    output << "Void       \t" << voidCount << "\n";

    return 0;
}
