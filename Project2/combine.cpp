/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 2 Task C
*/

#include <iostream>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

class Song{
public:
    string name;
    string artist;
    int duration;
    string genre;
};

int g_capacity = 2;
int g_size = 0;

Song *g_songs = new Song[g_capacity];

void allocateNew() {
    g_capacity = g_capacity * 2;
    Song *newSongs = new Song[g_capacity];
    
    for(int i = 0; i < g_size; i++) {
        newSongs[i] = g_songs[i];
    }

    delete[] g_songs;
    g_songs = newSongs;
}

void readSongs(string filename) {
    int index1, index2, index3, index4;
    string holder, header, sub;
    ifstream file(filename);
    if (file.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    while(getline(file, holder)) {  
        if(g_size == g_capacity) {
            allocateNew();
        }

        index1 = holder.find(":");
        index2 = holder.find("-");
        sub = holder.substr(index2 + 1, holder.length());
        index3 = sub.find("-");
        index4 = sub.find(" ");

        string word1 = holder.substr(0, index1);
        string word2 = holder.substr(index1 + 1, index2 - index1 - 1);
        string word3 = holder.substr(index2 + 1, index3);
        string word4 = holder.substr(index3 + index2 + 2, index4);

        g_songs[g_size].name = word1;
        g_songs[g_size].artist = word2;
        g_songs[g_size].genre = word3;
        g_songs[g_size].duration = stoi(word4);
        
        g_size++;
    }
}

Song * getSongsFromDuration(int duration, int &durationsCount, int filter) {
    Song *durationSongs = new Song[g_size];
    durationsCount = 0;
    for(int i = 0; i < g_size; i++) {
        if(filter == 0) {
            if(g_songs[i].duration > duration) {
                durationSongs[durationsCount].artist = g_songs[i].artist;
                durationSongs[durationsCount].name = g_songs[i].name;
                durationSongs[durationsCount].duration = g_songs[i].duration;
                durationSongs[durationsCount].genre = g_songs[i].genre;
                durationsCount++;
            }
        }
        else if(filter == 1) {
            if(g_songs[i].duration < duration) {
                durationSongs[durationsCount].artist = g_songs[i].artist;
                durationSongs[durationsCount].name = g_songs[i].name;
                durationSongs[durationsCount].duration = g_songs[i].duration;
                durationSongs[durationsCount].genre = g_songs[i].genre;
                durationsCount++;
            }
        }
        if(filter == 2) {
            if(g_songs[i].duration == duration) {
                durationSongs[durationsCount].artist = g_songs[i].artist;
                durationSongs[durationsCount].name = g_songs[i].name;
                durationSongs[durationsCount].duration = g_songs[i].duration;
                durationSongs[durationsCount].genre = g_songs[i].genre;
                durationsCount++;
            }
        }
    }
    return durationSongs;
}

Song * getGenreSongs(string genre, int &genreCount) {
    Song *genreSongs = new Song[g_size];
    genreCount = 0;
    for(int i = 0; i < g_size; i++) {
        if(g_songs[i].genre == genre) {
            genreSongs[genreCount].artist = g_songs[i].artist;
            genreSongs[genreCount].name = g_songs[i].name;
            genreSongs[genreCount].duration = g_songs[i].duration;
            genreSongs[genreCount].genre = g_songs[i].genre;
            genreCount++;
        }
    }

    return genreSongs;
}

string* getUniqueArtists(int &uniqueCount) {
    string *unique = new string[g_size];
    uniqueCount = 0;
    for(int i = 0; i < g_size; i++) {
        bool found = false;
        for (int j = 0; j < g_size; j++) {
            if (g_songs[i].artist == unique[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique[uniqueCount] = g_songs[i].artist;
            uniqueCount++;
        }
    }
  
    return unique;
}

string getFavoriteArtist() {
    if (g_size== 0)
        return "NONE";
    
    string favorite = g_songs[0].artist;
    string current = g_songs[0].artist;
    int maxCounter = 0;
    for (int i = 0; i < g_size; i++) {
        int counter = 0;
        current = g_songs[i].artist;
        for (int j = 0; j < g_size; j++) {
            if(current == g_songs[j].artist) {
                counter++;
            }
        }
        if(counter > maxCounter) {
            favorite = current;
            maxCounter = counter;
        }
    }
    return favorite;
}

int main() {
    readSongs("example.txt");

    cout << getFavoriteArtist() << endl;
    cout << g_size;

    int count = 0;
    getGenreSongs("Hiphop",count);
    return 0;
}

