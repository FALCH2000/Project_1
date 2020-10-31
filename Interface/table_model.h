#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H


#include <QAbstractTableModel>
#include "constructor.h"
#include "song.h"

class Table_Model : public QAbstractTableModel
{
    Q_OBJECT

    Constructor *constructor=nullptr; /**< Is the object constructor for being displayed in this table model */
public:
    int rowNumber; /**< Int that saves the row number for being displayed in this table model */
    vector<Song*> *SongsList_Vector; /**< Is the list of Songs for being displayed in the table model.
                                          Is a pointer to the Songs List created from the constructor*/
    Table_Model(QObject *parent= nullptr); /**< Is the constructor of the class */
    /**
     * @brief rowCount establish the number of rows for being displayed in the table model.
     * @return an int of the number of rows.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /**
     * @brief columnCount establish the number of columns for being displayed in the table model.
     * For this project the column Number is 4 and it's constant.
     * @return an int with the number of columns.
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    /**
     * @brief data is an inherited method. Is called to set all the data to be displayed in the table.
     * @return the value to be display in a specific item. Will return a QString and if is invalid,
     * return a QVariant.
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /**
     * @brief headerData set the information to be displayed in the table header
     * @return a QString of the data for being displayed in a column.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    /**
     * @brief chargeSongs load Songs from an csv path specific.
     * @param start mark the start of the songs list for being displayed in the table.
     * @param end mark the end of the songs list for being displayed in the table.
     */
    void chargeSongs(int start, int end);

    /**
     * @brief getUrl gets the url of a specific song that is in a specific row.
     * @param position is the position of the row where the song is.
     * @return the absolute path where the song is.
     */
    QString getUrl(int position);

public slots:

    /**
     * @brief resetModel reset the table model. Allows to update the table over and over again.
     */
    void resetModel();
};

#endif // TABLE_MODEL_H
