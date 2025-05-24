#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include"Artist.h"
#include"Admin.h"
#include"User.h"
#include"Playlist.h"
#include"Song.h"
using namespace std;

const int MAX_SONGS = 100;
const int MAX_PLAYLISTS = 100;
const int MAX_ARTISTS = 100;
const int MAX_SONGS_PER_PLAYLIST = 100;


int main() {
    srand(time(0)); 

    Admin admin;
    User user("user1", "pass1");

    string username, password;
    cout << "Vared kardan be onvan Admin:\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (!admin.login(username, password)) {
        cout << "Voroud Namoshakhas. Barname kharej shod.\n";
        return 0;
    }

    cout << "\n==== Barname Admin Spotify ====\n";

    int choice;
    do {
        cout << "\n1. Sakhte Ahang\n";
        cout << "2. Sakhte Playlist\n";
        cout << "3. Ezafe Ahang be Playlist\n";
        cout << "4. Namayesh Ahang-ha (hame)\n";
        cout << "5. Filter bar asas Chah Chah Zan\n";
        cout << "6. Filter bar asas Sabk\n";
        cout << "7. Filter bar asas Sal\n";
        cout << "8. Sort ABC Ahang-ha\n";
        cout << "9. Sakhte Profile Chah Chah Zan\n";
        cout << "10. Ezafe Ahang be Chah Chah Zan\n";
        cout << "11. Namayesh Profile Chah Chah Zan\n";
        cout << "12. Taghir Name Chah Chah Zan\n";
        cout << "13. Set Tedad Album Chah Chah Zan\n";
        cout << "14. Play List Pakhsh (Tartibi/Tasadofi/Tekrar + Loop)\n";
        cout << "0. Khorooj\n";

        cout << "Entekhab shoma: ";
        cin >> choice;

        if (choice == 1) {
            string title, artist, genre;
            int year;
            cout << "Esm ahang: "; cin >> title;
            cout << "Esm chah chah zan: "; cin >> artist;
            cout << "Sal: "; cin >> year;
            cout << "Sabk: "; cin >> genre;
            Song song(title, artist, year, genre);
            admin.addSongToSystem(song);
            cout << "Ahang sakhte shod.\n";
        }
        else if (choice == 2) {
            string name;
            cout << "Esm Playlist: ";
            cin >> name;
            admin.createPlaylist(name);
            cout << "Playlist sakhte shod.\n";
        }
        else if (choice == 3) {
            string playlist, title, artist, genre;
            int year;
            cout << "Esm Playlist: "; cin >> playlist;
            cout << "Esm Ahang: "; cin >> title;
            cout << "Esm Chah Chah Zan: "; cin >> artist;
            cout << "Sal: "; cin >> year;
            cout << "Sabk: "; cin >> genre;
            Song song(title, artist, year, genre);
            admin.addSongToPlaylist(playlist, song);
            cout << "Ahang be playlist ezafe shod.\n";
        }

        else if (choice == 4) {
            for (int i = 0; i < admin.systemSongcount; ++i)
                admin.systemSongs[i].display();
        }
        else if (choice == 5) {
            string name;
            cout << "Esm Chah Chah Zan: ";
            cin >> name;
            admin.filterSongsByArtist(name);
        }
        else if (choice == 6) {
            string genre;
            cout << "Sabk: ";
            cin >> genre;
            admin.filterSongsByGenre(genre);
        }
        else if (choice == 7) {
            int year;
            cout << "Sal: ";
            cin >> year;
            admin.filterSongsByYear(year);
        }
        else if (choice == 8) {
            admin.sortSongsAlphabetically();
        }
        else if (choice == 9) {
            string artist;
            cout << "Esm Chah Chah Zan: ";
            cin >> artist;
            admin.createArtistProfile(artist);
            cout << "Profile sakhte shod.\n";
        }
        else if (choice == 10) {
            string title, artist, genre;
            int year;
            cout << "Esm Chah Chah Zan: "; cin >> artist;
            cout << "Esm Ahang: "; cin >> title;
            cout << "Sal: "; cin >> year;
            cout << "Sabk: "; cin >> genre;
            Song song(title, artist, year, genre);
            admin.addSongToArtist(artist, song);
            cout << "Ahang ezafe shod be artist.\n";
        }
        else if (choice == 11) {
            string artist;
            cout << "Esm Chah Chah Zan: ";
            cin >> artist;
            admin.displayArtist(artist);
        }
        else if (choice == 12) {
            string oldName, newName;
            cout << "Esm ghadimi: "; cin >> oldName;
            cout << "Esm jadid: "; cin >> newName;
            admin.editArtistName(oldName, newName);
        }
        else if (choice == 13) {
            string artist;
            int count;
            cout << "Esm Chah Chah Zan: "; cin >> artist;
            cout << "Tedad Album: "; cin >> count;
            admin.setArtistAlbumCount(artist, count);
        }
        else if (choice == 14) {
            string name;
            int mode, loop;
            cout << "Esm Playlist: ";
            cin >> name;
            for (int i = 0; i < admin.systemPlaylistcount; ++i) {
                if (admin.systemPlaylists[i].name == name) {
                    Playlist& pl = admin.systemPlaylists[i];
                    cout << "1. Tartibi\n2. Tasadofi\n3. Tekrar\n";
                    cout << "Mode pakhsh: ";
                    cin >> mode;
                    pl.setPlayMode(static_cast<PlayMode>(mode - 1));
                    cout << "Loop kon? (1=Yes / 0=No): ";
                    cin >> loop;
                    if (loop) pl.toggleLooping();

                    char cont;
                    do {
                        pl.playNextSong();
                        cout << "Dale pakhsh badi? (y/n): ";
                        cin >> cont;
                    } while (cont == 'y');
                }
            }
        }

    } while (choice != 0);

    cout << "Khorooj az barname.\n";
    return 0;
}



