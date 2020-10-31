#ifndef SONG_H
#define SONG_H


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/**
 * @brief The Song class provide a class that saves all atributes and methods that are needed to process a song.
 */
class Song {
    string trackId_, artistName_, Length_, Name_, url_;

    /**
     * @brief setUrl is a setter that sets the url where the song is. It's private because the url is setted inside
     * the class.
     */
    void setUrl();
public:
    /**
     * @brief setId sets the id of the song and assign it to the trackId atributte.
     * @param id is a string parameter that is assign to the trackId attribute of the object.
     */
    void setId(string id);
    /**
     * @brief setName sets the name of the song object.
     * @param name is a string parameter that is assign to the name attribute of the object.
     */
    void setName(string name);
    /**
     * @brief setArtist sets the name of the artist of the song object.
     * @param artistName is a string parameter that is assign to the artistName attribute of the object.
     */
    void setArtist(string artistName);
    /**
     * @brief setLength sets the value of the length of the song object.
     * @param length is a string parameter that is assign to the length attribute of the object.
     * The attribute is a string for facilities of implementing, but it could be represented as a long
     * value through a conversion.
     */
    void setLength(string length);

    /** Getters of the class Song. Each one return the object that makes up the name.
    *           All Attributes are string, so all getters return a string
    */

    string getId();
    string getName();
    string getArtist();
    string getLength();
    string getUrl();

    /**
     * @brief getInformation will send all object attributes in a single string value.
     * @return a string with the attributes information.
     */
    string getInformation();

};

#endif // SONG_H
