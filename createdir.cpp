// C++ program to create a directory in Linux

#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

int main()
{

	// Creating a directory
	if (mkdir("/usr/local/test", 0777) == -1)
		cerr << "Error : " << strerror(errno) << endl;

	else
		cout << "Directory created";
}

