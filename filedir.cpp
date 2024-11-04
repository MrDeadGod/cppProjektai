#include <iostream>
#include <filesystem>
#include <fstream>

#define CONFIG_FAILAS "C:\\Users\\Admin\\Desktop\\c++ projects\\filedirr\\config.txt"

namespace fs = std::filesystem;
using namespace std;

int getFiles(string dir) 
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
        return 0;
}

int readFiles()
{
        string myText;
        ifstream MyFile(CONFIG_FAILAS);
        while (getline (MyFile, myText)) {
                getFiles(myText);
        }
        return 0;
}

int main()
{
        readFiles();
    return 0;
}


/* Config failo pvz:
C:\Users\Admin\Desktop\samsung\media
C:\Users\Admin\Desktop\samsung\pages
C:\Users\Admin\Desktop\c++ projects\filedirr
*/
