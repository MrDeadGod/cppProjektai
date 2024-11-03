#include <iostream>
#include <filesystem>

#define GETFILES(x) for(const auto &entry : fs::directory_iterator(x))

namespace fs = std::filesystem;

int main()
{
    std::string dir = "C:\\Users\\Admin\\Documents\\";
    std::cout << "The files of " << dir << " directory are:" << std::endl << std::endl;

    GETFILES(dir) {
            std::cout << "Path: " << entry.path() << std::endl;
            std::cout << "Name: " << entry.path().filename() << std::endl;
            if (entry.is_regular_file()) {
                    std::cout << "Size: " << std::setprecision(2) << (entry.file_size() / 1024.0 / 1024.0) << " MB" << std::endl;
            } else {
                    std::cout << "Size: N/A, it may be because it isn't a regular file" << std::endl;
            }
            std::cout << std::endl;
    }   
    return 0;
}
