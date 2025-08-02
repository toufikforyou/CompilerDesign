#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream myInput("input.c");

    if (!myInput)
    {
        cout << "Error: Cannot open input file.\n";
        return 0;
    }

    string text;
    char c;

    while (myInput.get(c))
    {
        text += c;
    }

    const vector<pair<string, regex>> patterns = {
        {"kw", regex(R"(\b(?:char|int|float|if|else)\b)")},
        {"id", regex(R"([a-zA-Z_]\w*)")},
        {"num", regex(R"(\d+(\.\d+)?)")},
        {"unkn", regex(R"(\d+\.[a-zA-Z0-9]+)")},
        {"op", regex(R"(<=|>=|==|!=|[+\-*/=<>])")},
        {"par", regex(R"([{()}])")},
        {"sep", regex(R"([,;'])")},
        {"ws", regex(R"(\s+)")}};

    size_t pos = 0;
    while (pos < text.length())
    {
        bool matched = false;
        for (const auto &[type, pattern] : patterns)
        {
            smatch match;
            string sub = text.substr(pos);
            if (regex_search(sub, match, pattern))
            {
                if (type != "ws")
                {
                    cout << "[" << type << " " << match.str() << "] ";
                }
                pos += match.length();
                matched = true;
                break;
            }
        }
        if (!matched)
        {
            cout << "[unkn " << text[pos] << "] ";
            pos++;
        }
    }

    cout << endl;
    return 0;
}