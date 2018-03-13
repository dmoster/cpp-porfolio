/*
Daniel Moster, Section 5, d.moster@me.com
Description: This is the .cpp file for the Song class, containing its member function definitions.
*/


#include "Song.h"
#include <iostream>
#include <string>
using namespace std;


Song::Song(string name, string line, int num) {
   songName = name;
   firstLine = line;
   numPlays = num;
}


void Song::SetName(string name) {
   songName = name;
}


string Song::GetName() const {
   return songName;
}


void Song::SetFirstLine(string line) {
   firstLine = line;
}


string Song::GetFirstLine() const {
   return firstLine;
}


void Song::PrintSongInfo() const {
   cout << songName << ": \"" << firstLine << "\", " << numPlays << " play(s)." << endl;
}


void Song::IncreaseNumPlays() {
   ++numPlays;
}


void Song::PlaySong() {
   cout << firstLine << endl;
   IncreaseNumPlays();
}