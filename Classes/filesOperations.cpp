#include <glob.h>
#include<iostream>
#include<fstream>
#include<string>
#include <chrono>
#include <cstdio>
#include <dirent.h> 
#include <sys/types.h> 
#include <sys/param.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <vector>

class fileOperations{
    private:
        std::fstream f;
    public:
        bool CreateFile(std::string filename, std::string content);
        std::string Readfile(char* const filename);
        bool DeleteFile(char* const filename);
        int isFileExist(char* const dirname, char* const searching, char*  const result );
        bool UpdateFile(char* const dirname, char* const filename, std::string content);
        bool renameFile(char* const oldname, char* const newname);
        bool CreateDir(std::string dirname, int mode);
        bool DeleteDir(std::string dirname);
        bool isdirExist(std::string dirname);
        bool renameDir(char* const oldname, char* const newname);
};

int fileOperations::isFileExist(char* const dirname, char* const searching, char*  const result ) {
  DIR           *d;
  struct dirent *dir;
  d = opendir( dirname );
  if( d == NULL ) {
    return 1;
  }
  while( ( dir = readdir( d ) ) ) {
    if( strcmp( dir->d_name, "." ) == 0 || 
        strcmp( dir->d_name, ".." ) == 0 ) {
      continue;
    }
    if( dir->d_type == DT_DIR ) {
      chdir( dir->d_name );
      isFileExist(dirname, searching, result );
      chdir( ".." );
    } else {
      if( strcmp( dir->d_name, searching ) == 0 ) {
        int  len;
        getcwd( result, MAXPATHLEN );
        len = strlen( result );
        snprintf( result + len, MAXPATHLEN - len, "/%s", dir->d_name );
        break;
      }
    }
  }
  closedir( d );
  return *result == 0;
};

bool fileOperations::CreateFile(std::string filename, std::string content){
    try
    {
        f.open(filename, std::ios::out);
        f<<content;
        f.close();
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        f.close();
        return false;
    }
};

std::string fileOperations::Readfile(char* const filename){
    std::string content;
    try
    {
        f.open(filename, std::ios::in);
        std::getline(f, content, '\0');
        f.close();
        return content;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        f.close();
        return content;
    }
};

bool fileOperations::DeleteFile(char* const filename){
    int status;
    status = std::remove(filename);
    if (status == 0)
    {
        return true;
    }else{
        return false;
    }
};

bool fileOperations::UpdateFile(char* const dirname, char* const filename, std::string content){
    char buf[MAXPATHLEN] = { 0 };
    int statusfile = this->isFileExist(dirname, filename, buf);
    std::string FileName = std::string(dirname)+"/"+filename;
    if (statusfile == 0)
    {
        this->CreateFile(FileName, content);
        return true;
    }else{
        return false;
    }
}

bool fileOperations::renameFile(char* const oldname, char* const newname){
    if (rename(oldname, newname) != 0)
    {
        return false;
    }else{
        return true;
    }
}

bool fileOperations::CreateDir(std::string  dirname, int mode){
    char buffer[MAXPATHLEN];
    strcpy(buffer, dirname.c_str());
    if (mkdir(buffer, mode) == -1){
		return true;
    }else{
		return true;
    }
}

bool fileOperations::isdirExist(std::string dirname){
    char buffer[MAXPATHLEN];
    strcpy(buffer, dirname.c_str());
    DIR *dir = opendir(buffer);
    if (dir)
    {
        /* Directory exists. */
        closedir(dir);
        return true;
    }
    else if (ENOENT == errno)
    {
        return false;
        /* Directory does not exist. */
    }
    else
    {
        return false;
        /* opendir() failed for some other reason. */
    }
}

bool fileOperations::DeleteDir(std::string dirname){
    std::string GLobdirname = dirname+"/*";
    glob_t glob_result;
    glob(GLobdirname.c_str(),GLOB_TILDE,NULL,&glob_result);
    std::vector<std::string> files;
    for(unsigned int i=0;i<glob_result.gl_pathc;++i){
        files.push_back(std::string(glob_result.gl_pathv[i]));
    }
    globfree(&glob_result);
    char buffer[MAXPATHLEN];
    for (size_t i = 0; i < files.size(); i++)
    {
        strcpy(buffer, files[i].c_str());
        if (this->isdirExist(buffer) == true)
        {
            this->DeleteDir(files[i]);
        }else{
            remove(buffer);
        }
    }
        strcpy(buffer, dirname.c_str());
        remove(buffer);
    return true;
}

bool fileOperations::renameDir(char* const oldname, char* const newname){
    if (rename(oldname, newname) != 0)
    {
        return false;
    }else{
        return true;
    }
}

bool MatchString(std::string str1, std::string str2){
        if(str1.compare(str2) == 0){
            return true;
        }else{
            return false;
        }
    };

int main(int argc, char const *argv[]) {
    
    fileOperations f;
    // std::string arr[40] = {"test1.txt", "test2.txt", "test3.txt", "test4.txt"};
    // std::string contents = "what happend to you buddy?";
    
    // for (size_t i = 0; i < 4; i++)
    // {
    //     // f.CreateFile(arr[i], contents);
    //     std::cout<<"File Content: "<<f.Readfile(arr[i])<<std::endl;
        
    // }
    // char buf[MAXPATHLEN] = { 0 };
    // char dir[] = "./test";
    
    char filename[] = "../.config";
    std::string fc = f.Readfile(filename);
    int line = 0;
    const char* breakpoint = ";";
    std::string  singleLine;
    for (size_t i = 0; i < fc.length(); i++)
    {
        if (strcmp(&fc[i], breakpoint) == 0)
        {
            std::cout<<fc[i]<<std::endl;
            line++;
        }else{
            singleLine += fc[i];
        }
    }
    std::cout<<singleLine<<std::endl;
    
    // if(f.DeleteFile(filename)){
    //     std::cout<<"Successfully file deleted"<<std::endl;
    // }else{
    //     std::cout<<"failed file deleted"<<std::endl;
    // }
    // if(f.isFileExist(dir, filename, buf ) == 0 ){
    //     std::cout<<"file exist test success"<<std::endl;
    // }else{
    //     std::cout<<"file not exist test success"<<std::endl;
    // }
    // f.UpdateFile(dir, filename, "my name is sami");
    // if(f.UpdateFile(dir, filename, contents)){
    //     std::cout<<"Successfully updated file"<<std::endl;
    // }else{
    //     std::cout<<"Failed updated file"<<std::endl;
    // }
    // std::cout<<f.CreateDir("dircreated", 0777)<<std::endl;
    // if(f.CreateDir("dircreated", 0777)){
    //     std::cout<<"success"<<std::endl;
    // }else{
    //     std::cout<<"failed"<<std::endl;
    // }
    // f.DeleteDir("./test");
    // std::cout<<f.isdirExist("dircreateds")<<std::endl;
    // char oldname[] = "test2.txt";
    // char newname[] = "lock.txt";
    // if(f.renameFile(oldname, newname)){
    //     std::cout<<"successfully renamed"<<std::endl;
    // }else{
    //     std::cout<<"failed renamed"<<std::endl;
    // }
    return 0;
}
