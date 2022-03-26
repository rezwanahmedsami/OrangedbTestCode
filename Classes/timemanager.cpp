#include <iostream>
#include <ctime>
#include<string>



class TimeManager{
    private:
        time_t now = time(0);
        tm *local_time = localtime(&this->now);

    public:
        inline char*  GetLocalDateAndTime();
        inline char*  GetUtcDateAndTime();
        inline int GetNumberOfSeconds();
        inline int GetLocaldtYear();
        inline int GetLocaldtMonth();
        inline int GetLocaldtDay();
        inline int GetLocaldtHour();
        inline int GetLocaldtMin();
        inline int GetLocaldtSec();
};

inline char*  TimeManager::GetLocalDateAndTime(){
    char* dt = ctime(&this->now);
    return dt;
}

inline char*  TimeManager::GetUtcDateAndTime(){
    tm *gmtm = gmtime(&this->now);
    char* dt = asctime(gmtm);
    return dt;
}

inline int  TimeManager::GetNumberOfSeconds(){
    return this->now;
}

inline int TimeManager::GetLocaldtYear(){
    int Y =  1900 + this->local_time->tm_year;
    return Y;
}

inline int TimeManager::GetLocaldtMonth(){
    int Y =  1 + this->local_time->tm_mon;
    return Y;
}

inline int TimeManager::GetLocaldtDay(){
    int Y =  this->local_time->tm_mday;
    return Y;
}

inline int TimeManager::GetLocaldtHour(){
    int Y =  1 + this->local_time->tm_hour ;
    return Y;
}

inline int TimeManager::GetLocaldtMin(){
    int Y =  1 + this->local_time->tm_min;
    return Y;
}

inline int TimeManager::GetLocaldtSec(){
    int Y =  1 + this->local_time->tm_sec;
    return Y;
}

int main(){
    TimeManager t1;
    std::cout<<"T: "<<t1.GetLocaldtHour()<<":"<<t1.GetLocaldtMin()<<":"<<t1.GetLocaldtSec()<<std::endl;
}