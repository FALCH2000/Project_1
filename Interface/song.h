#ifndef SONG_H
#define SONG_H


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Song {
    string trackId_, artistName_, Length_, Name_, url_;
    void setUrl();
public:
    void setId(string id);
    void setName(string name);
    void setArtist(string artistName);
    void setLength(string length);
    string getId();
    string getName();
    string getArtist();
    string getLength();
    string getUrl();

    string getInformation();

};

#endif // SONG_H
