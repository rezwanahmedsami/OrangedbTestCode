#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <filesystem>
#include <iomanip>

using namespace std;

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

float round(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

float SizeCalculator(const int* sizeByte){
    float size;
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
                }else{
                    size = sizegb;
                }
                
            }else{
                size = sizemb;
            }
            
        }else{
            size = sizekb;
        }
    }
    return size;
}

// char GetFileList(){
//     return "ds";
// }

int main() {
    // int getSizeInByte = filesize("big.txt");
    // float size = SizeCalculator(&getSizeInByte);
    // cout<<"File size is: "<<size<<endl;
    return EXIT_SUCCESS;
}