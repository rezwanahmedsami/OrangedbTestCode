#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char oldname[] = "sok";
	char newname[] = "new";
	
	/*	Deletes the file if exists */
	if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";
	
	return 0;
}
