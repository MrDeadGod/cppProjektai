#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#define CONFIG_FAILAS "C:\\Users\\Admin\\Desktop\\c++ projects\\filedirr\\config.txt"

namespace fs = std::filesystem;
using namespace std;

static int get_file();
static int read_file();
static int output_file();

struct out_put {
        fs::path path;
        fs::path name;
        float size;
};

int main()
{
        read_file();
        return 0;
}

static int get_file(string dir, int files) 
{
        for (const auto &entry : fs::directory_iterator(dir)) {

                int size = 3;
                out_put input[size];
                for (int i = 1; i < size; i++) {
                        input[i].path = entry.path();
                        input[i].name = entry.path().filename();
                        if (entry.is_regular_file()) {
                                input[i].size = (entry.file_size() / 1024.0 / 1024.0);
                        } else {
                                input[i].size = 0;
                        }
                }
                for (int i = 1; i < size; i++) {
                        cout << input[i].path << endl;
                        cout << input[i].name << endl;
                        if (entry.is_regular_file()) {
                                cout << input[i].size << endl;
                        } else {
                                cout << setprecision(2) << input[i].size << endl;
                        }
                }
                files = files+1;
                
        }
        return dir, files;
}

static int read_file()
{
        int files = 0;
        int tfiles = 0;
        string myText;
        ifstream MyFile(CONFIG_FAILAS);
        while (getline (MyFile, myText)) {
                get_file(myText, files);
                cout << myText << endl << files << endl;
                tfiles = files + tfiles;
        }
        cout << tfiles << endl;
        return 0;
}

static int output_file() {
        return 0;
}


/* Config failo pvz:
 *C:\Users\Admin\Desktop\samsung\media
 *C:\Users\Admin\Desktop\samsung\pages
 *C:\Users\Admin\Desktop\c++ projects\filedirr
 */
