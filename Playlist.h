#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include"Admin.h"
#include"Artist.h"
#include"User.h"
#include"Song.h"
using namespace std;
enum PlayMode {
    TARTIBI,
    TASADOFI,
    TEKRAR
};


class Playlist {
private:
    PlayMode mode = TARTIBI;
    bool islooping = false;

public:
    string name;
    Song Songs[MAX_SONGS_PER_PLAYLIST];
    int songcount = 0;

    Playlist() {}
    Playlist(string n) : name(n) {}
    int currentIndex = 0;

    void setPlayMode(PlayMode m) {
        mode = m;
    }

    void toggleLooping() {
        islooping = !islooping;
    }

    void playNextSong() {
        if (songcount == 0) {
            cout << "Playlist khali ast.\n";
            return;
        }

        if (mode == TARTIBI) {
            Songs[currentIndex].display();
            currentIndex++;
        }
        else if (mode == TASADOFI) {
            int randIndex = rand() % songcount;
            Songs[randIndex].display();
        }
        else if (mode == TEKRAR) {
            Songs[currentIndex].display();
        }

        if (currentIndex >= songcount) {
            if (islooping)
                currentIndex = 0;
            else
                currentIndex = songcount - 1;
        }
    }

    void display() const {
        cout << "Esm Play List: " << name << endl;
        cout << "Tedad Ahang: " << songcount << endl;
        for (int i = 0; i < songcount; ++i) {
            Songs[i].display();
        }
    }


    void addSong(const Song& song) {
        if (songcount < MAX_SONGS_PER_PLAYLIST) {
            Songs[songcount++] = song;
        }
    }

    void removeSong(const string& title) {
        for (int i = 0; i < songcount; ++i) {
            if (Songs[i].title == title) {
                for (int j = i; j < songcount - 1; ++j) {
                    Songs[j] = Songs[j + 1];
                }
                --songcount;
                break;
            }
        }
    }
};
