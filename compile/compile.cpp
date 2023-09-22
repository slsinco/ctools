#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
        char file[100];
        string fullname = "";
        int cpp=0;

        if (argc<2) {
                cout << "Enter file name to compile ";
                cin.getline(file, 100);
                fullname = file;
        } else if (argc<3) {
                fullname.append(string(argv[1]));
        } else if (argc<4) {
                if (string(argv[1]) != "-cpp") {
                        cout << "************************************" << endl;
                        cout << "* Compiles c files by default   " << "   *" << endl;
                        cout << "* Usage: compile [-cpp] <filename> *" << endl;
                        cout << "************************************" << endl;
                        return 0;
                }
                cpp=1;
                fullname.append(string(argv[2]));
        } else {
                cout << "************************************" << endl;
                cout << "* Too many arguments: " << argc << "            *" << endl;
                cout << "* Usage: compile [-cpp] <filename> *" << endl;
                cout << "************************************" << endl;
                return 0;
        }

        size_t lastindex = fullname.find_last_of(".");
        string rawname = fullname.substr(0, lastindex);

        //cout << "fullname =" << fullname << endl;
        //cout << "rawname =" << rawname << endl;

        string str = "gcc ";
        if (!cpp) {
                str = str + "-o " + rawname + " " + fullname;
        } else {
                str = str + "-lstdc++ -o " + rawname + " " + fullname;
        }
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

