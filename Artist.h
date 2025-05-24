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

    void display() const {
        cout << "Esm Chah Chah Zan: " << name << endl;
        cout << "Album ha: " << albumCount << endl;
        cout << "Ahang haye montasher shodeh: " << songcount << endl;
        for (int i = 0; i < songcount; ++i) {
            songs[i].display();
        }
    }

    string getName() const {
        return name;
    }

    void addSong(const Song& song) {
        if (songcount < MAX_SONGS) {
            songs[songcount++] = song;
        }
    }

    void addPlaylist(const Playlist& playlist) {
        if (playlistcount < MAX_PLAYLISTS) {
            playlists[playlistcount++] = playlist;
        }
    }
    
};