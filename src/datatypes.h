#ifndef Datatypes_H
#define Datatypes_H

#include "QObject"

class DataTypes : public QObject
{
    Q_OBJECT

public:

    typedef struct
    {
        QString path;
        QString fieldSeparator;
        QString groupSeparator;
        QString decimalSeparator;
        quint32 dataRow;
        quint32 column;
        quint32 labelRow;
        bool dynamicSession;

    } DataFileSettings;

private:

};



#endif // Datatypes_H
