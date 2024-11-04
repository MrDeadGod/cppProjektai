#include <iostream>
#include <filesystem>
#include <fstream>

#define CONFIG_FAILAS "C:\\Users\\Admin\\Desktop\\c++ projects\\filedirr\\config.txt"

namespace fs = std::filesystem;
using namespace std;

static void get_file();
static void read_file(); // nežinau ar reikėjo abi padaryt void, bet pažiūrėjus į kodą, abi funkcijos nenaudojo gražinamosios vertės

int main()
{
        read_file();
        return 0;
}

static void get_file(string dir) 
{
        for(const auto &entry : fs::directory_iterator(dir)) {
                cout << "Path: " << entry.path() << endl;
                cout << "Name: " << entry.path().filename() << endl;
                if (entry.is_regular_file()) {
                        cout << "Size: " << std::setprecision(2) << (entry.file_size() / 1024.0 / 1024.0) << " MB" << endl;
                } else {
                        cout << "Size: N/A, it may be because it isn't a regular file" << endl;
                }
                cout << endl;
        }
}

static void read_file()
{
        string myText;
        ifstream MyFile(CONFIG_FAILAS);
        while (getline (MyFile, myText)) {
                get_file(myText);
        }
}


/* Config failo pvz:
C:\Users\Admin\Desktop\samsung\media
C:\Users\Admin\Desktop\samsung\pages
C:\Users\Admin\Desktop\c++ projects\filedirr
*/
