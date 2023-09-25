/*
Author: Jiaxiong Guan
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 2
*/

#include <iostream>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

void allocateNew() {
    g_curr_size = g_curr_size * 2;
    string *newSongNames = new string[g_curr_size];
    string *newArtistNames = new string[g_curr_size];
    int *newSongDurations = new int[g_curr_size];
    string *newGenres = new string[g_curr_size];
    
    for(int i = 0; i < g_number_of_songs; i++) {
        newSongNames[i] = g_song_names[i];
        newArtistNames[i] = g_artist_names[i];
        newSongDurations[i] = g_song_durations[i];
        newGenres[i] = g_genres[i];
    }

    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;

    g_song_names = newSongNames;
    g_artist_names = newArtistNames;
    g_song_durations = newSongDurations;
    g_genres = newGenres;
}

void readSongs(string filename) {
    int index1, index2, index3, index4;
    string holder, header, sub;
    ifstream file(filename);
    if (file.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    getline(file, header);
    while(getline(file, holder)) {  
        if(g_number_of_songs == g_curr_size) {
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
        
        g_song_names[g_number_of_songs] = word1;
        g_artist_names[g_number_of_songs] = word2;
        g_genres[g_number_of_songs] = word3;
        g_song_durations[g_number_of_songs] = stoi(word4);
    
        
        g_number_of_songs++;
    }
}

string * getGenreSongs(string genre, int &genreCount) {
    string *genreSongs = new string[g_number_of_songs];
    int tmp = 0;
    for(int i = 0; i < g_number_of_songs; i++) {
        if(g_genres[i] == genre) {
            genreSongs[tmp] = g_song_names[i];
            genreCount++;
            tmp++;
        }
    }
    return genreSongs;
}

string * getSongsFromDuration(int duration, int &durationsCount, int filter) {
    string *durationSongs = new string[g_number_of_songs];
    int tmp = 0;
    for(int i = 0; i < g_number_of_songs; i++) {
        if(filter == 0) {
            if(g_song_durations[i] > duration) {
                durationSongs[tmp] = g_song_names[i];
                tmp++;
                durationsCount++;
            }
        }
        else if(filter == 1) {
            if(g_song_durations[i] < duration) {
                durationSongs[tmp] = g_song_names[i];
                tmp++;
                durationsCount++;
            }
        }
        if(filter == 2) {
            if(g_song_durations[i] == duration) {
                durationSongs[tmp] = g_song_names[i];
                tmp++;
                durationsCount++;
            }
        }
    }
    return durationSongs;
}

string * getUniqueArtists(int &uniqueCount) {
    string *unique = new string[g_number_of_songs];
    string holder;
    int tmp = 0;
    for(int i = 0; i < g_number_of_songs; i++) {
        bool found = false;
        holder = g_artist_names[i];
        for (int j = 0; j < g_number_of_songs; j++) {
            if (holder == unique[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique[tmp] = holder;
            tmp++;
            uniqueCount++;
        }
    }
    return unique;
}

string getFavoriteArtist() {
    if (g_number_of_songs == 0)
        return "NONE";
    
    string favorite = g_artist_names[0];
    string current = g_artist_names[0];
    int maxCounter = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        int counter = 0;
        current = g_artist_names[i];
        for (int j = 0; j < g_number_of_songs; j++) {
            if(current == g_artist_names[j]) {
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
    for(int i = 0; i < g_number_of_songs; i++) {
        // cout << g_song_names[i] << " " << g_artist_names[i] << " " <<  g_genres[i] << " " << g_song_durations[i] << endl;
        
    }
    
    // int count = 0;
    // string* lmao = getUniqueArtists(count);
    // for (int i = 0; i < count; i++) {
    //     cout << lmao[i] << endl;
    // }

    cout << getFavoriteArtist();
    return 0;
}