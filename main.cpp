/*
Daniel Moster, Section 5, d.moster@me.com
Description: 

This lab was coded using Visual Studio.
Dr. Seppi has allowed me until December 16th at the end of the day to complete this lab with no late penalty.


Test Cases
Case 1
Input: Added a mix of 3 songs to 2 different playlists and "played" each playlist (4 times and once, respectively)
Expected Output: Play count of songs totaling 8, 4, and 3
Result: Passed

Case 2
Input: [addp (ENTER) list1 addp (ENTER) list2 addp (ENTER) list3 delp (ENTER) 1 (ENTER) listp]
Expected Output: [list1(ENTER)list3]
Result: Passed

Case 3
Input: Added a playlist and several songs, then added them to the playlist and went to delete one
Expected Output: A list of playlists, followed by the list of songs on the selected playlists
Result: The list of songs printed was an index of the library, not the playlist itself - helped me discover that I 
   needed a separate ListSongIndex() function just for playlists
*/


#include "Song.h"
#include "Playlist.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void GetLineNotWS(string& inpString) {
   getline(cin, inpString);
   if (inpString.find_first_not_of(" \t") == std::string::npos) {
      getline(cin, inpString);
   }
}


void AddSongs(vector<Song*>& songs) {
   int numSongs = songs.size();
   string userInput = "";

   cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;

   while (userInput != "STOP") {
      cout << "Song Name: ";
      GetLineNotWS(userInput);
      if (userInput != "STOP") {
         ++numSongs;
         songs.resize(numSongs);
         songs.at(numSongs - 1) = new Song;
         songs.at(numSongs - 1)->SetName(userInput);
         cout << "Song's first line: ";
         GetLineNotWS(userInput);
         songs.at(numSongs - 1)->SetFirstLine(userInput);
      }
   }
   cout << endl;
}


void ListSongs(const vector<Song*>& songs) {
   for (unsigned int i = 0; i < songs.size(); ++i) {
      songs.at(i)->PrintSongInfo();
   }
}


void AddPlaylist(vector<Playlist>& playlists) {
   int numPlaylists = playlists.size();
   string userInput = "";

   cout << "Playlist Name: ";
   GetLineNotWS(userInput);
   cout << endl;

   playlists.resize(numPlaylists + 1);
   (playlists.at(playlists.size() - 1)).SetName(userInput);
}


void ListPlaylists(const vector<Playlist>& playlists) {
   for (unsigned int i = 0; i < playlists.size(); ++i) {
      cout << i << ": " << (playlists.at(i)).GetName() << endl;
   }
}


void ListSongIndex(const vector<Song*>& songs) {
   for (unsigned int i = 0; i < songs.size(); ++i) {
      cout << i << ": " << songs.at(i)->GetName() << endl;
   }
}


void AddSongToPlaylist(vector<Playlist>& playlists, vector<Song*>& songs) {
   int playlistIndex = 0;
   int songIndex = 0;
   Song* pointerVar;

   ListPlaylists(playlists);
   cout << "Pick a playlist index number: ";
   cin >> playlistIndex;

   ListSongIndex(songs);
   cout << "Pick a song index number: ";
   cin >> songIndex;
   cout << endl;

   pointerVar = songs.at(songIndex);
   (playlists.at(playlistIndex)).AddToPlaylist(pointerVar);
}


void PlayPlaylist(vector<Playlist>& playlists) {
   int playlistIndex = 0;

   ListPlaylists(playlists);
   cout << "Pick a playlist index number: ";
   cin >> playlistIndex;
   cout << endl;
   cout << "Playing first lines of playlist: " << (playlists.at(playlistIndex)).GetName() << endl;
   (playlists.at(playlistIndex)).PlaySongs();
   cout << endl;
}


void DeletePlaylist(vector<Playlist>& playlists) {
   int playlistIndex = 0;

   ListPlaylists(playlists);
   cout << "Pick a playlist index number to delete: ";
   cin >> playlistIndex;
   playlists.erase(playlists.begin() + playlistIndex);
}


void DeleteSongFromPlaylist(vector<Playlist>& playlists, vector<Song*>& songs) {
   int playlistIndex = 0;
   int songIndex = 0;

   ListPlaylists(playlists);
   cout << "Pick a playlist index number: ";
   cin >> playlistIndex;

   (playlists.at(playlistIndex)).ListSongIndex();
   cout << "Pick a song index number to delete: ";
   cin >> songIndex;
   cout << endl;

   (playlists.at(playlistIndex)).RemoveFromPlaylist(songIndex);
}


void DeleteSongFromLibrary(vector<Playlist>& playlists, vector<Song*>& songs) {
   int songIndex = 0;

   ListSongIndex(songs);
   cout << "Pick a song index number: ";
   cin >> songIndex;
   cout << endl;

   for (unsigned int i = 0; i < playlists.size(); ++i) {
      for (unsigned int j = ((playlists.at(i)).GetSongListLength()); j > 0; --j) {
         if (songs.at(songIndex)->GetName() == (playlists.at(i)).GetSongName(j - 1)) {
            (playlists.at(i)).RemoveFromPlaylist(j - 1);
         }
      }
   }

   delete songs.at(songIndex);
   songs.erase(songs.begin() + songIndex);
}


void PrintOptions() {
   cout << "add      Adds a list of songs to the library" << endl;
   cout << "list     Lists all the songs in the library" << endl;
   cout << "addp     Adds a new playlist" << endl;
   cout << "addsp    Adds a song to a playlist" << endl;
   cout << "listp    Lists all the playlists" << endl;
   cout << "play     Plays a playlist" << endl;
   cout << "delp     Deletes a playlist" << endl;
   cout << "delsp    Deletes a song from a playlist" << endl;
   cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
   cout << "options  Prints this options menu" << endl;
   cout << "quit     Quits the program" << endl << endl;
}


int main() {
   string userInput = "";
   vector<Song*> songs;
   vector<Playlist> playlists;


   cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;


   do {
      cout << "Enter your selection now: ";
      cin >> userInput;
      cout << endl;

      if (userInput == "add") {
         AddSongs(songs);
      }
      else if (userInput == "list") {
         ListSongs(songs);
         cout << endl;
      }
      else if (userInput == "addp") {
         AddPlaylist(playlists);
      }
      else if (userInput == "addsp") {
         AddSongToPlaylist(playlists, songs);
      }
      else if (userInput == "listp") {
         ListPlaylists(playlists);
         cout << endl;
      }
      else if (userInput == "play") {
         PlayPlaylist(playlists);
      }
      else if (userInput == "delp") {
         DeletePlaylist(playlists);
      }
      else if (userInput == "delsp") {
         DeleteSongFromPlaylist(playlists, songs);
      }
      else if (userInput == "delsl") {
         DeleteSongFromLibrary(playlists, songs);
      }
      else if ((userInput == "options") || (userInput != "quit")) {
         PrintOptions();
      }

   } while (userInput != "quit");


   cout << "Goodbye!" << endl;


//   system("pause");
   return 0;
}