#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include"Admin.h"
#include"Artist.h"
#include"Playlist.h"
#include"Song.h"
using namespace std;
class User {
public:
    string username;
    string password;

    Song savedSongs[MAX_SONGS];
    int savedcount = 0;

    Song favoriteSongs[MAX_SONGS];
    int favoritecount = 0;

    Playlist personalPlaylists[MAX_PLAYLISTS];
    int personalCount = 0;

    string favoritePlaylistNames[MAX_PLAYLISTS];
    int favoritePlaylistCount = 0;

    User() {}
    User(string u, string p) : username(u), password(p) {}

    bool checkLogin(const string& u, const string& p) {
        return (username == u && password == p);
    }

    void saveSong(const Song& song) {
        if (savedcount < MAX_SONGS)
        {
            savedSongs[savedcount++] = song;
        }
    }

    void unsaveSong(const string& title) {
        for (int i = 0; i < savedcount; ++i) {
            if (savedSongs[i].title == title) {
                for (int j = i; j < savedcount - 1; ++j) {
                    savedSongs[j] = savedSongs[j + 1];
                }
                --savedcount;
                break;
            }
        }
    }

    void addFavoriteSong(const Song& song) {
        if (favoritecount < MAX_SONGS)
            favoriteSongs[favoritecount++] = song;
    }
    
    void removeFavoriteSong(const string& title) {
        for (int i = 0; i < favoritecount; ++i) {
            if (favoriteSongs[i].title == title) {
                for (int j = i; j < favoritecount - 1; ++j)
                    favoriteSongs[j] = favoriteSongs[j + 1];
                favoritecount--;
                break;
            }
        }
    }

};