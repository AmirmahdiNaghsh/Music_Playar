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
};
