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
    int lineNumber = 1;

    stack<pair<char, int>> braceStack;

    while (getline(myInput, line))
    {
        for (char c : line)
        {
            if (c == '{')
            {
                braceStack.push({'{', lineNumber});
            }
            else if (c == '}')
            {
                if (!braceStack.empty())
                {
                    braceStack.pop();
                }
                else
                {
                    cout << "Error: closing brace '}' found on line " << lineNumber << ".\n";
                }
            }
        }
        lineNumber++;
    }

    while (!braceStack.empty())
    {
        auto [brace, lineNum] = braceStack.top();
        braceStack.pop();
        cout << "Error: opening brace '{' found on line " << lineNum << ".\n";
    }

    myInput.close();

    return 0;
}
