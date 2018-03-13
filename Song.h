/*
Daniel Moster, Section 5, d.moster@me.com
Description: This is the header file of the Song class, containing member function declarations and private data 
   members.
*/


#ifndef SONG_H
#define SONG_H


#include <string>
using namespace std;


class Song {
public:
   Song(string songName = "none", string firstLine = "unknown", int numPlays = 0);
   void SetName(string name);
   string GetName() const;
   void SetFirstLine(string line);
   string GetFirstLine() const;
   void PrintSongInfo() const;
   void IncreaseNumPlays();
   void PlaySong();

private:
   string songName;
   string firstLine;
   int numPlays;
};


#endif