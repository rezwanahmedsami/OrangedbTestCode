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

class DiskDriver{
    public:
        std::string SizeStatus;
        std::ifstream::pos_type filesize(const char* filename);
        float round(float var);
        double SizeCalculator(const int* sizeByte);
        double  GenrateFileSize(const char* filename);
        double  GetDirSize(std::string dirname);
};


std::ifstream::pos_type DiskDriver::filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

float DiskDriver::round(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

double DiskDriver::SizeCalculator(const int* sizeByte){
    double size;
    int MAX_MEMORY_COUNTER = 1000;
    float sizekb, sizemb, sizegb, sizetb;
    if(*sizeByte >= MAX_MEMORY_COUNTER){
        sizekb = *sizeByte/MAX_MEMORY_COUNTER;
        if (sizekb >= MAX_MEMORY_COUNTER)
        {
            sizemb = round(sizekb / MAX_MEMORY_COUNTER);
            if (sizemb >= MAX_MEMORY_COUNTER)
            {
                sizegb = round(sizemb/MAX_MEMORY_COUNTER);
                if (sizegb >= MAX_MEMORY_COUNTER)
                {
                    sizetb = round(sizegb/MAX_MEMORY_COUNTER);
                    size = sizetb;
                    this->SizeStatus = "Tb";
                }else{
                    size = sizegb;
                    this->SizeStatus = "Gb";
                }
                
            }else{
                // std::cout<<sizemb<<std::endl;
                size = sizemb;
                this->SizeStatus = "Mb";
            }
            
        }else{
            size = sizekb;
            this->SizeStatus = "Kb";
        }
    }else{
        size = *sizeByte;
        this->SizeStatus = "Bytes";
    }
    return size;
}

double  DiskDriver::GenrateFileSize(const char* filename){
    int getSizeInByte = filesize(filename);
    double size = SizeCalculator(&getSizeInByte);
    return size;
}

int main(){
    DiskDriver driver1;
    char filename[] = "file_new.txt";
    double size = driver1.GenrateFileSize(filename);
    std::cout<<size<<std::endl;
}