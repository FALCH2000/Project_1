#include "song.h"

void Song::setId(string id){
    this->trackId_= id;
    setUrl();
}

void Song::setName(string name){
    this->Name_=name;
}

void Song::setArtist(string artistName){
    this->artistName_=artistName;
}

void Song::setLength(string length){
    this->Length_= length;
}
string Song::getInformation(){
    string info= this->trackId_+" "+ this->Name_+" "+this->artistName_+" "+this->Length_+" "+this->url_;
    return info;
}

void Song::setUrl() {
    string line, temp="  ",token;
    fstream file;
    file.open("/home/fatima/Documents/fma_small/checksums");
    size_t pos = 0;

    // Borra la primera parte de la fila
    while(getline(file, line)){
        while ((pos = line.find(temp)) != string::npos) {
            token = line.substr(0, pos);
            line.erase(0, pos + temp.length());
        }
        //cout << line << endl;
        std::string str = line;
        auto it = str.find(this->trackId_);
        if (it != std::string::npos){
            string url= "/home/fatima/Documents/fma_small/"+line;
            this->url_= url;
            break; //stops when it find it

        }
        //else
            //cout << "Not found!\n";

    }
    file.close();
}
///------------ getters ------------------
string Song::getId(){
    return this->trackId_;
}
string Song::getName(){
    return this->Name_;
}
string Song::getArtist(){
    return this->artistName_;
}
string Song::getLength(){
    return this->Length_;
}

string Song::getUrl(){
    return this->url_;
}
