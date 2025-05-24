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

    void filterSongsByYear(int year) {
        for (int i = 0; i < systemSongcount; ++i) {
            if (systemSongs[i].year == year) {
                systemSongs[i].display();
            }
        }
    }

    void editArtistName(const string& oldName, const string& newName) {
        for (int i = 0; i < systemArtistcount; ++i) {
            if (systemArtists[i].getName() == oldName) {
                systemArtists[i].setName(newName);
                return;
            }
        }
    }

    void displayArtist(const string& artistName) {
        for (int i = 0; i < systemArtistcount; ++i) {
            if (systemArtists[i].getName() == artistName) {
                systemArtists[i].display();
                return;
            }
        }
        cout << "Chah Chah Zan Yaft Nashod.\n";
    }

    void setArtistAlbumCount(const string& artistName, int count) {
        for (int i = 0; i < systemArtistcount; ++i) {
            if (systemArtists[i].getName() == artistName) {
                systemArtists[i].setAlbumCount(count);
                return;
            }
        }
    }


    bool login(const string& u, const string& p) {
        return (u == username && p == password);
    }

    void addSongToSystem(const Song& song) {
        if (systemSongcount < MAX_SONGS) {
            systemSongs[systemSongcount++] = song;
        }
    }

    void createPlaylist(const string& name) {
        if (systemPlaylistcount < MAX_PLAYLISTS) {
            systemPlaylists[systemPlaylistcount++] = Playlist(name);
        }
    }
    void addSongToPlaylist(const string& playlistName, const Song& song) {
        for (int i = 0; i < systemPlaylistcount; ++i) {
            if (systemPlaylists[i].name == playlistName) {
                systemPlaylists[i].addSong(song);
                return;
            }
        }
    }
    void removeSongFromPlaylist(const string& playlistName, const string& title) {
        for (int i = 0; i < systemPlaylistcount; ++i) {
            if (systemPlaylists[i].name == playlistName) {
                systemPlaylists[i].removeSong(title);
                return;
            }
        }
    }
    void createArtistProfile(const string& artistName) {
        if (systemArtistcount < MAX_ARTISTS) {
            systemArtists[systemArtistcount++] = Artist(artistName);
        }
    }
    void addSongToArtist(const string& artistName, const Song& song) {
        for (int i = 0; i < systemArtistcount; ++i) {
            if (systemArtists[i].getName() == artistName) {
                systemArtists[i].addSong(song);
                return;
            }
        }
    }
};