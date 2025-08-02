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

     regex kw_patterns(R"(\b(?:char|int|float|if|else)\b)");
    regex variable_patterns(R"([a-zA-Z_]\w*)");
    regex number_patterns(R"(\d+(\.\d+)?)");
    regex oparator_patterns(R"(<=|>=|==|!=|[+\-*/=<>])");
    regex perenthisis_patterns(R"([{()}])");
    regex separator_patterns(R"([,;'])");
    regex ws_patterns(R"(\s+)");

    size_t position = 0;

    while (position < text.length())
    {
        bool matche = false;
        for (int i = 0; i < 1; i++)
        {
            smatch m;
            string sub = text.substr(position);

            if (regex_search(sub, m, kw_patterns, regex_constants::match_continuous))
            {
                cout << "[" << "kw" << " " << m.str() << "] ";
                matche = true;
                position += m.length();
                break;
            }
            if (regex_search(sub, m, variable_patterns, regex_constants::match_continuous))
            {
                cout << "[" << "id" << " " << m.str() << "] ";
                matche = true;
                position += m.length();
                break;
            }
            if (regex_search(sub, m, number_patterns, regex_constants::match_continuous))
            {
                cout << "[" << "num" << " " << m.str() << "] ";
                matche = true;
                position += m.length();
                break;
            }
            if (regex_search(sub, m, oparator_patterns, regex_constants::match_continuous))
            {
                cout << "[" << "op" << " " << m.str() << "] ";
                matche = true;
                position += m.length();
                break;
            }
            if (regex_search(sub, m, perenthisis_patterns, regex_constants::match_continuous))
            {
                cout << "[" << "par" << " " << m.str() << "] ";
                matche = true;
                position += m.length();
                break;
            }
            if (regex_search(sub, m, separator_patterns, regex_constants::match_continuous))
            {
                cout << "[" << "sep" << " " << m.str() << "] ";
                matche = true;
                position += m.length();
                break;
            }
        }
        if (!matche)
        {
            position++;
        }
    }

    cout << endl;
    return 0;
}
