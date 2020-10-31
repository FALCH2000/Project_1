#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <iostream>
#include <vector>
#include "song.h"
#include <fstream>
#include <sstream>

using namespace std;

class Constructor
{       
private:
    vector<Song> ArtistsList; 
    vector<string> filesInFolder; /**< Saves the id tracks that exist in folder of music library fma_small */
    string path_,object_; 

    /**
     * @brief Parse_Songs Parse the file given to get Songs List in the vector SongsList or ArtistList
     * @param start is to mark the beginning of songs to parse int the file
     * @param end is to mark the end of songs to parse in the file
     */
    void Parse_Songs(int start, int end);

    void Parse_Artists();

    /**
     * @brief ParseSongs_OnFolder Parse songs on CSV file in the library and save the id of each song in a vector.
     * This Parse songs that are available on the library to load and play.
     */
    void ParseSongs_OnFolder();

    /**
     * @brief isPart indicates whether a song is available in the library for playback or not.
     * @param token is the id of the current song
     * @param position is the current number where have to be compared the id token. This is used to get de id of
     * the song in that position in filesInFolder
     * @return true if the token corresponds to an id from the list filesInFolder and it's available, false if not.
     */
    bool isPart(string token, int position);

public:
    vector<Song*> SongsList; /**< Saves the songs objects that is asked for. */

    /**
     * @brief Constructor is thge constructor of the class. Will construct artist objects or songs object according
     * of the parameter object.
     * @param path is the path of the csv for being analyzed and parsed.
     * @param object is the object to be created, it can be Artists Objects or Songs Objects.
     */
    Constructor(string path, string object);

    /**
     * @brief getSongsList is the getter of the songsList created.
     * @return a pointer to the song List created after all the parsing.
     */
    vector<Song*> *getSongsList();


    vector<Song> getArtistsList() const;
    /**
     * @brief ParseCSV parse the csv given in the path of the constructor.
     * @param start is the start point where want to do the search and therefore, to create and return songs
     * objects.
     * @param end is the end point where want to do the search.
     */
    void ParseCSV(int start, int end);
};

#endif // CONSTRUCTOR_H
