#include <iostream>
#include <deque>
#include <string>

using namespace std;

bool palindromcheck(string& str)
{
    deque <char> palindrom;
    double len = str.length();
    int k = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
        if (str[i] != ' ') palindrom.push_front(str[i]);
        else k++;
        cout << palindrom.front();

    }
    cout << endl;

    len -= k;
    for (int i = 1; i <= len / 2; i++)
    {
        if (palindrom.front() == palindrom.back())
        {
            cout << palindrom.front() << " " << palindrom.back();
            cout << endl;
            palindrom.pop_back();
            palindrom.pop_front();
        }

    }

    if ((palindrom.front() == palindrom.back()) && !palindrom.empty())
    {
        palindrom.pop_front();
    }
    if (palindrom.empty()) return 1;
    else return 0;
}

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin,str);
    bool check = palindromcheck(str);
    if (check != 0)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
    return 0;
}
