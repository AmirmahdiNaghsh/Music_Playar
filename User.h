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

    
};