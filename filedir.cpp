#include <iostream>
#include <filesystem>

#define GETFILES(x) for(const auto &entry : fs::directory_iterator(x))

namespace fs = std::filesystem;

int main()
{
    std::string dir = "C:\\Users\\Admin\\Desktop";
    std::cout << "The files of " << dir << " directory are:" << std::endl << std::endl;

    GETFILES(dir) {
            std::cout << "Path: " << entry.path() << std::endl;
            std::cout << "Name: " << entry.path().filename() << std::endl;
            std::cout << "Size: " << (entry.file_size() / 1000) << " MB" << std::endl;
    }   
    return 0;
}
