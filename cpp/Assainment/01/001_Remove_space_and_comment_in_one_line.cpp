#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string removeComments(const string &code)
{
    string result;
    bool singleLine = false;
    bool multuLine = false;

    for (size_t i = 0; i < code.length(); i++)
    {
        if (singleLine)
        {
            if (code[i] == '\n')
            {
                singleLine = false;
                result += ' ';
            }
        }
        else if (multuLine)
        {
            if (code[i] == '*' && code[i + 1] == '/')
            {
                multuLine = false;
                i++;
            }
        }
        else
        {
            if (code[i] == '/' && code[i + 1] == '/')
            {
                singleLine = true;
                i++;
            }
            else if (code[i] == '/' && code[i + 1] == '*')
            {
                multuLine = true;
                i++;
            }
            else
            {
                result += code[i];
            }
        }
    }

    return result;
}

string removeExtraWhitespace(const string &code)
{
    string result;
    bool in_space = false;

    for (char ch : code)
    {
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            if (!in_space)
            {
                result += ' ';
                in_space = true;
            }
        }
        else
        {
            result += ch;
            in_space = false;
        }
    }

    return result;
}

int main()
{
    fstream input("input.c");
    ofstream output("output.txt");

    if (!input)
    {
        cout << "Error opening files!" << endl;
        return 0;
    }

    string code, line;
    while (getline(input, line))
    {
        code += line + '\n';
    }

    string noComments = removeComments(code);
    string cleaned = removeExtraWhitespace(noComments);

    output << cleaned;

    cout << "\nOutput: " << cleaned << "\n\n";

    input.close();

    return 0;
}
