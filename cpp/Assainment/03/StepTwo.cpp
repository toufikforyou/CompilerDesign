#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream myInput("step-one-output.txt");
    ofstream stepTwoOutput("step-two-output.txt");

    if (!myInput)
    {
        cout << "Error: Cannot open input file.\n";
        return 0;
    }

    char c;
    string text;
    while (myInput.get(c))
    {
        text += c;
    }

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '[')
        {
            string format;
            string temp;
            for (int j = i + 1; text[j] != ']'; j++)
            {
                temp += text[j];

                if (text[j] == ' ' && temp != "id ")
                {
                    format.clear();
                    temp.clear();
                    j++;
                }
                format += text[j];
            }
            cout << '[' << format << ']';
            stepTwoOutput << '[' << format << ']';
        }
    }
}