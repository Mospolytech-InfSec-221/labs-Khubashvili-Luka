
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string file_format(const string file_path);
string file_name(const string file_path);
string file_path(const string file_path);
string file_disk(const string file_path);
bool file_rename(string file_path);
bool file_copy(const string file_path);

int main() {

    cout << "Enter full path: ";
    string full_file_path;
    cin >> full_file_path;

    int choice = 0;
    while (true)
    {
        system("CLS");//clear console
        cout << "===========================\n";
        cout << "1. Task File Format\n" << "2. Task File Name\n" << "3. Task File Path\n" 
             << "4. Task File Disk\n" << "5. Task Rename File\n" << "6. Task Copy File\n" 
             << "7. Exit\n";
        cout << "What do you want to choose? ";
        cin >> choice;
        cout << "===========================\n\n";
        switch (choice)
        {
            case 1:
            {
                cout << "Full path: \'" << full_file_path << "\'" << endl;
                cout << "File format" << endl;
                cout << file_format(full_file_path) << endl;
                system("pause");
                break;
            }
            case 2:
            {
                cout << "Full path: \'" << full_file_path << "\'" << endl;
                cout << "File name" << endl;
                cout << file_name(full_file_path) << endl;
                system("pause");
                break;
            }
            case 3:
            {
                cout << "Full path: \'" << full_file_path << "\'" << endl;
                cout << "File path" << endl;
                cout << file_path(full_file_path) << endl;
                system("pause");
                break;
            }
            case 4:
            {
                cout << "Full path: \'" << full_file_path << "\'" << endl;
                cout << "File disk" << endl;
                cout << file_disk(full_file_path) << endl;
                system("pause");
                break;
            }
            case 5:
            {
                cout << "Full path: \'" << full_file_path << "\'" << endl;
                bool status = file_rename(full_file_path);
                if (status == true) cout << "Rename was successfully" << endl;
                else cout << "ERROR" << endl;
                system("pause");
                break;
            }
            case 6:
            {
                cout << "Full path: \'" << full_file_path << "\'" << endl;
                bool status = file_copy(full_file_path);
                if(status == true) cout << "Copy was successfully" << endl;
                else cout << "ERROR" << endl;
                system("pause");
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
    return 0;
}

string file_format(const string file_path) {  
    int len = file_path.length();
    int ext = file_path.rfind('.');
    string output = file_path.substr(ext, len);
    return output;
}

string file_name(const string file_path) {
    int ext = file_path.rfind('.');
    int last_dash = file_path.rfind("\\");
    string output = file_path.substr(last_dash+1, ext-last_dash-1);
    return output;
}

string file_path(const string file_path) { 
    int len = file_path.length();
    int last_dash = file_path.rfind("\\");
    string output = file_path.substr(0, last_dash+1);
    return output;
}

string file_disk(const string file_path) {
    int len = file_path.length();
    int disk = file_path.find(":");
    string output = file_path.substr(0, disk);
    return output;
}

bool file_rename(string file_path) {
    int len = file_path.length();
    int last_dash = file_path.rfind('\\');
    string file_path_withot_name = file_path.substr(0, last_dash+1);

    cout << "Filename: " << file_path.substr(last_dash + 1, len) << endl;

    cout << "Enter new file name: ";
    string new_filename;
    cin >> new_filename;
    new_filename = file_path_withot_name.append(new_filename).append(file_format(file_path));

    int result = rename(file_path.c_str(), new_filename.c_str());
    if (result != 0) {
        return false;
    }
    return true;
}

bool file_copy(const string full_file_path) {
    fstream file_read;
    file_read.open(full_file_path, fstream::in);
    if (!file_read.is_open()) return false;

    ofstream created_file;
    created_file.open(file_path(full_file_path) + file_name(full_file_path) + "_copy" + file_format(full_file_path), fstream::out);
    if(created_file.fail()) return false;

    string line;
    while (getline(file_read, line))
    {
        created_file << line << '\n';
    }
    file_read.close();
    created_file.close();
    return true;
}
