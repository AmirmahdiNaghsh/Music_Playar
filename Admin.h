#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include"User.h"
#include"Artist.h"
#include"Playlist.h"
#include"Song.h"
using namespace std;
class Admin {
private:
    const string username = "admin";
    const string password = "1234";

public:
    Song systemSongs[MAX_SONGS];
    int systemSongcount = 0;

    Playlist systemPlaylists[MAX_PLAYLISTS];
    int systemPlaylistcount = 0;

    Artist systemArtists[MAX_ARTISTS];
    int systemArtistcount = 0;

    void sortSongsAlphabetically() {
        for (int i = 0; i < systemSongcount - 1; ++i) {
            for (int j = i + 1; j < systemSongcount; ++j) {
                if (systemSongs[i].title > systemSongs[j].title) {
                    Song temp = systemSongs[i];
                    systemSongs[i] = systemSongs[j];
                    systemSongs[j] = temp;
                }
            }
        }
        cout << "Ahang-ha be surat abc moratab shodand.\n";
    }

    void filterSongsByArtist(const string& artistName) {
        for (int i = 0; i < systemSongcount; ++i) {
            if (systemSongs[i].artist == artistName) {
                systemSongs[i].display();
            }
        }
    }

    void filterSongsByGenre(const string& genre) {
        for (int i = 0; i < systemSongcount; ++i) {
            if (systemSongs[i].genre == genre) {
                systemSongs[i].display();
            }
        }
    }

    

};