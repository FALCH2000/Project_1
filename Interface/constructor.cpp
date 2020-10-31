#include "constructor.h"

Constructor::Constructor(string path, string object) {
    this->path_= path;
    this->object_=object;
}

vector<Song *> *Constructor::getSongsList() {

    return &this->SongsList;
}

void Constructor::ParseCSV(int start, int end) {
    if(this->object_=="Songs"){
        Parse_Songs(start,end);
    } else if(this->object_=="Artists"){
        Parse_Artists();
    }
}

void Constructor::Parse_Songs(int start, int end) {
    //--------------- Get All Songs Available ---------------
    if(this->filesInFolder.empty()){
        ParseSongs_OnFolder();
    }

    string line, separator=",", token;
    vector<string> filesList, stringFileList;
    fstream file;
    file.open(this->path_);
    size_t pos = 0;
    getline(file, line);
    for(int i=start; i<=end; i++){
        token = line.substr(0, line.find(separator));
        if(!isPart(token, i)){

            //While inside
            while(!isPart(token, i)) {
                getline(file, line);
                token = line.substr(0, line.find(separator));
            }
        }
        /// -------------------------Song *newSong= new Song; -------------- I'm Here
        int j=0;
        Song* mySong= new Song;
        while ((pos = line.find(separator)) != std::string::npos) {
            token = line.substr(0, line.find(separator));
            if(j==0){
                mySong->setId(token);

            }else if(j==1){
                mySong->setArtist(token);

            }else{
                cout << token<<endl;
                mySong->setLength(token);
            }
            line.erase(0, pos + separator.length());
            j++;
        }
        mySong->setName(line);

        SongsList.push_back(mySong);

        getline(file, line);
    }
}

bool Constructor::isPart(string token, int position){
    string pos= this->filesInFolder[position];

    stringstream temp_1(token);
    stringstream temp_2(pos);
    int x, y;
    temp_1>>x;
    temp_2>>y;
    if(x==y){
        return true;
    }else{
        return false;
    }
}

void Constructor::ParseSongs_OnFolder(){
    string line, temp="/",token;
    vector<string> filesList;

    fstream file;
    file.open("/home/fatima/Documents/fma_small/checksums");
    size_t pos = 0;

    /** Se parsea el csv haciendo split hasta que se obtiene solo el id de las canciones que hay disponibles*/

    while(getline(file, line)){
        while ((pos = line.find(temp)) != string::npos) {
            token = line.substr(0, pos);
            line.erase(0, pos + temp.length());
        }
        //cout << line << endl;
        filesList.push_back(line);
    }

    pos=0; temp=".";
    //borra el .mp3 de las canciones
    for(string word:filesList){
        while ((pos = word.find(temp)) != string::npos) {
            token = word.substr(0, pos);
            filesInFolder.push_back(token);
            word.erase(0, pos + temp.length());
        }
    }
    file.close();
}

void Constructor::Parse_Artists() {
    //_________________ Make Something _________________
}

vector<Song> Constructor::getArtistsList() const {
    return ArtistsList;
}

