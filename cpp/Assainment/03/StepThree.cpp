#include <bits/stdc++.h>
using namespace std;

class Symbol
{
public:
    int sl;
    string name, idType, dataType, scope, value;
    Symbol(int sl, string name, string dataType) : sl(sl), name(name), dataType(dataType), idType(""), scope(""), value("") {}
};

vector<Symbol> table;

bool isDataType(const string &s) { return s == "int" || s == "float" || s == "double"; }
bool isID(const string &s) { return s.size() > 3 && s.substr(0, 2) == "id"; }
string getIDName(const string &s) { return s.substr(3); }

int findSymbol(const string &name, const string &scope)
{
    for (int i = table.size() - 1; i >= 0; i--)
    {
        if (table[i].name == name && table[i].scope == scope)
            return i;
    }
    return -1;
}

void display(ofstream &out)
{
    out << left << setw(8) << "Sl. No."
        << setw(10) << "Name"
        << setw(10) << "IdType"
        << setw(12) << "DataType"
        << setw(10) << "Scope"
        << setw(25) << "Value" << "\n";
    out << string(75, '-') << "\n";

    for (auto &s : table)
    {
        out << setw(8) << s.sl
            << setw(10) << s.name
            << setw(10) << s.idType
            << setw(12) << s.dataType
            << setw(10) << (s.scope.empty() ? "global" : s.scope)
            << setw(25) << s.value
            << "\n";
    }
}

int main()
{
    ifstream in("step-two-output.txt");
    ofstream out("step-three-output.txt");
    if (!in.is_open())
    {
        cout << "Cannot open input file\n";
        return 0;
    }

    string content((istreambuf_iterator<char>(in)), {});
    vector<string> tokens;
    for (size_t i = 0; i < content.size(); i++)
    {
        if (content[i] == '[')
        {
            size_t j = content.find(']', i);
            if (j != string::npos)
            {
                tokens.push_back(content.substr(i + 1, j - i - 1));
                i = j;
            }
        }
    }

    string scope = "global";
    int sl = 1;
    set<string> functionNames;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (i > 0 && isDataType(tokens[i - 1]) && isID(tokens[i]))
        {
            string dtype = tokens[i - 1];
            string name = getIDName(tokens[i]);

            if (i + 1 < tokens.size() && tokens[i + 1] == "(")
            {
                if (findSymbol(name, "global") == -1)
                {
                    Symbol s(sl++, name, dtype);
                    s.idType = "func";
                    s.scope = "global";
                    table.push_back(s);
                    functionNames.insert(name);
                }
                scope = name;
                continue;
            }

            if (findSymbol(name, scope) != -1 || functionNames.count(name))
                continue;

            Symbol s(sl++, name, dtype);
            s.idType = "var";
            s.scope = scope;

            if (i + 1 < tokens.size() && tokens[i + 1] == "=")
            {
                string val = "";
                size_t j = i + 2;
                while (j < tokens.size() && tokens[j] != ";")
                {
                    if (!val.empty())
                        val += " ";
                    val += tokens[j];
                    j++;
                }
                s.value = val;
            }
            table.push_back(s);
        }

        if (i > 0 && isDataType(tokens[i - 1]) && isID(tokens[i]) && scope != "global")
        {
            string pname = getIDName(tokens[i]);
            if (findSymbol(pname, scope) == -1)
            {
                Symbol s(sl++, pname, tokens[i - 1]);
                s.idType = "var";
                s.scope = scope;
                table.push_back(s);
            }
        }

        if (isID(tokens[i]) && i + 1 < tokens.size() && tokens[i + 1] == "=")
        {
            string name = getIDName(tokens[i]);
            int idx = findSymbol(name, scope);
            if (idx != -1 && i + 2 < tokens.size())
            {
                string val = tokens[i + 2];
                if (tokens[i + 3] == "(")
                    val = "";
                table[idx].value = val;
            }
        }

        if (tokens[i] == "}")
            scope = "global";
    }

    display(out);
}
