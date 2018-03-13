/*
Daniel Moster, Section 5, d.moster@me.com
Description: This is the header file of the Playlist class, containing member function declarations and private data 
   members.
*/


#ifndef PLAYLIST_H
#define PLAYLIST_H


#include "Song.h"
#include <string>
#include <vector>
using namespace std;


class Playlist {
   public:
      Playlist(string name = "none");
      void SetName(string name);
      string GetName() const;
      void AddToPlaylist(Song* pointerVar);
      void RemoveFromPlaylist(int songIndex);
      void PlaySongs() const;
      void ListSongIndex() const;
      string GetSongName(int songIndex);
      int GetSongListLength() const;

   private:
      string playlistName;
      vector<Song*> songs;
};


#endif