#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include"Admin.h"
#include"User.h"
#include"Playlist.h"
#include"Song.h"
using namespace std;
class Artist {
private:
    string name;
    Song songs[MAX_SONGS];
    int songcount = 0;
    Playlist playlists[MAX_PLAYLISTS];
    int playlistcount = 0;
    int albumCount = 0;
public:
    Artist() {}
    Artist(string n) : name(n) {}

    void setName(const string& newName) {
        name = newName;
    }
    
       void setAlbumCount(int count) {
        albumCount = count;
    }
};