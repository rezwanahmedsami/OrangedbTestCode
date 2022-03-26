#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
//    time_t now = time(0);
   
//    // convert now to string form
//    char* dt = ctime(&now);

//    cout << "The local date and time is: " << dt << endl;

//    // convert now to tm struct for UTC
//    tm *gmtm = gmtime(&now);
//    dt = asctime(gmtm);
//    cout << "The UTC date and time is:"<< dt << endl;


   time_t ttime = time(0);
                 cout << "Number of seconds elapsed since January 1, 1990:" << ttime << endl;
                 tm *local_time = localtime(&ttime);
    
                 cout << "Year: "<< 1900 + local_time->tm_year << endl;
                 cout << "Month: "<< 1 + local_time->tm_mon<< endl;
                 cout << "Day: "<< local_time->tm_mday << endl;
                 cout << "Time: "<< 1 + local_time->tm_hour << ":";
                 cout << 1 + local_time->tm_min << ":";
                 cout << 1 + local_time->tm_sec << endl;
}
