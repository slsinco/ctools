#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
        char file[100];
        string fullname = "";

        if (argc<2) {
                cout << "Enter file name to compile ";
                cin.getline(file, 100);
                fullname = file;
        } else if (argc>1 && argc<3) {
                fullname.append(string(argv[1]));
        } else {
                cout << "Too many arguments: " << argc << endl;
                return 0;
        }

        size_t lastindex = fullname.find_last_of(".");
        string rawname = fullname.substr(0, lastindex);

        //cout << "fullname =" << fullname << endl;
        //cout << "rawname =" << rawname << endl;

        string str = "gcc ";
        str = str + "-o " + rawname + " " + fullname;
        rawname = "./" + rawname;


        // Convert to char* for system() function
        const char* command = str.c_str();
        const char* executable = rawname.c_str();

        cout << "\nCompiling file using " << command << endl;
        system(command);

        cout << "\nRunning file" << endl;
        system(executable);

        return 0;

}

