#include <bits/stdc++.h>

using namespace std;


int main() {

    ifstream myInput("input.c");

    if (!myInput) {
        cerr << "Error: Cannot open input file.\n";
        return 0;
    }

    string code((istreambuf_iterator<char>(myInput)), istreambuf_iterator<char>());

    const vector<pair<string, regex>> patterns = {
        {"kw",     regex(R"(\b(char|int|float|if|else)\b)")},
        {"id",     regex(R"(\b[a-zA-Z_][a-zA-Z0-9_]*\b)")},
        {"num",    regex(R"(\b\d+(\.\d+)?\b)")},
        {"unkn",   regex(R"(\b\d+\.[a-zA-Z0-9]+\b)")},
        {"op",     regex(R"(<=|>=|==|!=|[+\-*/=<>])")},
        {"par",    regex(R"([\(\)])")},
        {"sep",    regex(R"([,;'])")},
        {"ws",     regex(R"(\s+)")}
    };

    size_t pos = 0;
    while (pos < code.length()) {
        bool matched = false;
        for (const auto& [type, pattern] : patterns) {
            smatch match;
            string sub = code.substr(pos);
            if (regex_search(sub, match, pattern, regex_constants::match_continuous)) {
                if (type != "ws") {
                    cout << "[" << type << " " << match.str() << "] ";
                }
                pos += match.length();
                matched = true;
                break;
            }
        }
        if (!matched) {
            cout << "[unkn " << code[pos] << "] ";
            pos++;
        }
    }

    cout << endl;
    return 0;
}
