/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Quiz 10, time.cpp
*/

#include <iostream>

using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time { 
public:
    int h;
    int m;
};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

int minutesSinceMidnight(Time time) {
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later) {
    int earlyTime, lateTime;
    earlyTime = earlier.h * 60 + earlier.m;
    lateTime = later.h * 60 + later.m;
    return lateTime - earlyTime;
}

Time addMinutes(Time time0, int min) {
    time0.m = time0.m + min;
    while(time0.m >= 60) {
        time0.m = time0.m - 60;
        time0.h = time0.h + 1;
    }
    return time0;
}

string genre(Movie movie){
    string output;
    if (movie.genre == ACTION){
        output = "ACTION";
    } else if (movie.genre == COMEDY){
        output = "COMEDY";
    } else if (movie.genre == DRAMA){
        output = "DRAMA";
    } else if (movie.genre == ROMANCE){
        output = "ROMANCE";
    } else if (movie.genre == THRILLER){
        output = "THRILLER";
    }
    return output;
}

void printTimeSlot(TimeSlot ts){
    string output;
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    output += ts.movie.title + " ";
    output += genre(ts.movie) + " (";
    output += to_string(ts.movie.duration) + " min) ";
    output += "[starts at " + to_string(ts.startTime.h) + ":" + to_string(ts.startTime.m) + ",";
    output += " ends by " + to_string(endTime.h) + ":" + to_string(endTime.m) + ']';
    cout << output;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot next = {nextMovie, addMinutes(ts.startTime, ts.movie.duration)};
    return next;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    TimeSlot earlier, later, end;
    Time endTime;
    int s1 = minutesSinceMidnight(ts1.startTime);
    int s2 = minutesSinceMidnight(ts2.startTime);
    if (s2 > s1){
        earlier = ts1;
        later = ts2;
        endTime = addMinutes(ts1.startTime, ts1.movie.duration);
    } else if (s2 == s1){
        return true;
    } else {
        earlier = ts2;
        later = ts1;
        endTime = addMinutes(ts2.startTime, ts2.movie.duration);
    }
    end = {earlier.movie, endTime};
    if (minutesUntil(earlier.startTime, later.startTime) < end.movie.duration){
        return true;
    }
    return false;
}

int main() {
    Time t1, t2;
    cout << "Enter first time: " << endl;
    cin >> t1.h;
    cin >> t1.m;
    
    Time t3 = addMinutes(t1, 44);
    cout << t3.h << " " << t3.m << endl;

    return 0;
}