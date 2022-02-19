#include <algorithm>
#include <iostream>
#include <cstring>
#include<string>
// for mmap:
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

const char* map_file(const char* fname, size_t& length);

int main()
{
    size_t length;
    string f;
    for (size_t i = 0; i < 100; i++)
    {
        string filename = "./files/fg"+ to_string(i);
        f = map_file(filename, length);
        cout<<f<<endl;
    }
    
}

void handle_error(const char* msg) {
    perror(msg); 
    exit(255);
}

const char* map_file(const char* fname, size_t& length)
{
    int fd = open(fname, O_RDONLY);
    if (fd == -1)
        handle_error("open");

    // obtain file size
    struct stat sb;
    if (fstat(fd, &sb) == -1)
        handle_error("fstat");

    length = sb.st_size;

    const char* addr = static_cast<const char*>(mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0u));
    if (addr == MAP_FAILED)
        handle_error("mmap");

    // TODO close fd at some point in time, call munmap(...)
    return addr;
}