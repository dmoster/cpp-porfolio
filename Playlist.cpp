/*
Daniel Moster, Section 5, d.moster@me.com
Description: This is the .cpp file for the Playlist class, containing its member function definitions.
*/


#include "Playlist.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Playlist::Playlist(string name) {
   playlistName = name;
}


void Playlist::SetName(string name) {
   playlistName = name;
}


string Playlist::GetName() const {
   return playlistName;
}


void Playlist::AddToPlaylist(Song* pointerVar) {
   songs.push_back(pointerVar);
}


void Playlist::RemoveFromPlaylist(int songIndex) {
   songs.erase(songs.begin() + songIndex);
}


void Playlist::PlaySongs() const {
   for (unsigned int i = 0; i < songs.size(); ++i) {
      songs.at(i)->PlaySong();
   }
}


void Playlist::ListSongIndex() const {
   for (unsigned int i = 0; i < songs.size(); ++i) {
      cout << i << ": " << songs.at(i)->GetName() << endl;
   }
}


string Playlist::GetSongName(int songIndex) {
   return songs.at(songIndex)->GetName();
}


int Playlist::GetSongListLength() const {
   return songs.size();
}