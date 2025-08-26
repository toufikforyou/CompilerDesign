#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream myInput("input.txt");

    if (!myInput)
    {
        cout << "Error: Cannot open input file.\n";
        return 0;
    }

    string line;
    while (getline(myInput, line))
    {
        cout << line << endl;
    }

    cout << endl;

    // logic here....

    return 0;
}