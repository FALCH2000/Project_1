#include "table_model.h"

Table_Model::Table_Model(QObject *parent)
    : QAbstractTableModel(parent)
{
}



//-------------------------------------------------------
int Table_Model::rowCount(const QModelIndex & /*parent*/) const
{
    return rowNumber;
}

//-------------------------------------------------------
int Table_Model::columnCount(const QModelIndex & /*parent*/) const
{
    return 4;
}

/**
 * @brief Table_Model::data This method assign the data to be displayed
 * @param index it's a parameter of the method inherited
 * @param role it's a parameter of the method inherited
 * @return the data to be displayed in a qstring
 */
QVariant Table_Model::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole)
    {
        int x= index.row();
        Song *ss= this->SongsList_Vector->at(x);

        if(index.column()==0){
            QString qstr= QString::fromStdString(ss->getId());
            return qstr;
        } else if(index.column()==1){
            QString qstr= QString::fromStdString(ss->getName());
            return qstr;
        }else if(index.column()==2){
            QString qstr= QString::fromStdString(ss->getArtist());
            return qstr;
        }else if(index.column()==3){
            QString qstr= QString::fromStdString(ss->getLength());
            return qstr;
        }

    }

    return QVariant();
}


QVariant Table_Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Song ID");
            case 1:
                return QString("Song Name");
            case 2:
                return QString("Artist Name");
            case 3:
                return QString("Duration");

            }
        }
    }
    return QVariant();
}
/**
 * @brief Table_Model::chargeSongs charge all songs in constructor
 * @param start will mark the start of the songs to load in the constructor
 * @param end will mark the end of the songs to load in the constructor
 */
void Table_Model::chargeSongs(int start, int end){

    if(constructor==nullptr){
        constructor= new Constructor("/home/fatima/Documents/tracks.csv", "Songs");
        constructor->ParseCSV(start,end);

    }else{
        resetModel();
        constructor->ParseCSV(start,end);
    }

    // ----------- SETEAR ESTE VECTOR ---------
    SongsList_Vector = constructor->getSongsList();

    rowNumber=this->SongsList_Vector->size();
}

QString Table_Model::getUrl(int position){
    Song *ss= this->SongsList_Vector->at(position);
    QString qstr= QString::fromStdString(ss->getUrl());
    return qstr;
}

/**
 * @brief Table_Model::SongList it's a signal. Emits when the data change
 * @param VectorSize is the vector of the songs
 * --------------------------- I should erase the method ---------------------------
 */
void Table_Model::resetModel(){
    beginResetModel();
    qDeleteAll(this->SongsList_Vector->begin(), this->SongsList_Vector->end());
    SongsList_Vector->clear();
    endResetModel();

}
