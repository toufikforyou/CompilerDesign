#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input_file("input.txt");

    regex kw_patterns = regex(R"(\b(?:char|int|float|if|else)\b)");
    regex variable_patterns = regex(R"([a-zA-Z_]\w*)");
    regex number_patterns = regex(R"(\d+(\.\d+)?)");
    regex oparator_patterns = regex(R"(<=|>=|==|!=|[+\-*/=<>])");
    regex perenthisis_patterns = regex(R"([{()}])");
    regex separator_patterns = regex(R"([,;'])");

    string text;
    char ch;

    while (input_file.get(ch))
    {
        text += ch;
    }

    size_t pos(0);
    while (pos < text.length())
    {
        bool matches = false;

        for (int i = 0; i < 1; i++)
        {
            smatch match;
            string sub = text.substr(pos);
            if (regex_search(sub, match, kw_patterns, regex_constants::match_continuous))
            {
                cout << "[kw " << match.str() << "]";
                matches = true;
                pos += match.length();
                break;
            }
            if (regex_search(sub, match, variable_patterns, regex_constants::match_continuous))
            {
                cout << "[id " << match.str() << "]";
                matches = true;
                pos += match.length();
                break;
            }
            if (regex_search(sub, match, number_patterns, regex_constants::match_continuous))
            {
                cout << "[num " << match.str() << "]";
                matches = true;
                pos += match.length();
                break;
            }
            if (regex_search(sub, match, oparator_patterns, regex_constants::match_continuous))
            {
                cout << "[op " << match.str() << "]";
                matches = true;
                pos += match.length();
                break;
            }
            if (regex_search(sub, match, perenthisis_patterns, regex_constants::match_continuous))
            {
                cout << "[per " << match.str() << "]";
                matches = true;
                pos += match.length();
                break;
            }
            if (regex_search(sub, match, separator_patterns, regex_constants::match_continuous))
            {
                cout << "[sep " << match.str() << "]";
                matches = true;
                pos += match.length();
                break;
            }
        }
        if (!matches)
        {
            pos++;
        }
    }

    cout << endl;

    return 0;
}