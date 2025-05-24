#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include"Admin.h"
#include"Artist.h"
#include"Playlist.h"
#include"User.h"
using namespace std;
class Song {
public:
    string title;
    string artist;
    int year;
    string genre;

    Song() {}
    Song(string t, string a, int y, string g)
        : title(t), artist(a), year(y), genre(g) {}


};
