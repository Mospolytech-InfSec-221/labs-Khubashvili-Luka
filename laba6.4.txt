#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;


int main()
{
    string name;
    unsigned long size;
    set <string> check;
    int point;
    map <string, int> list;
    
    
    cout << "Enter full name and points. Enter 'exit' for exit: " << endl;
    while (name != "exit")
    {
        size = check.size();
        cout << "Enter name: ";
        getline(cin, name);
        if (name == "exit")
        {
            break;
        }
        cout << "Enter points: ";
        cin >> point;
        cin.ignore();
        check.insert(name);
        if (size != check.size())
        {
            list.insert(make_pair(name, point));
        }
    }

    for (auto s = list.begin(); s != list.end(); s++)
    {
        cout << s->first << "\t" << s->second << endl;
    }
    cout << endl;

}