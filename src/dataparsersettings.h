#ifndef DataParserSettings_H
#define DataParserSettings_H

#include "QObject"

class DataParserSettings : public QObject
{
    Q_OBJECT

public:

    DataParserSettings();

    void copyTo(DataParserSettings *pDest);

    QString getPath();
    QString getFieldSeparator();
    QString getGroupSeparator();
    QString getDecimalSeparator();
    quint32 getDataRow();
    quint32 getColumn();
    quint32 getLabelRow();
    bool getDynamicSession();
    bool getWatchFileChanges();

    void setPath(QString path);
    void setFieldSeparator(QString fieldSeparator);
    void setGroupSeparator(QString groupSeparator);
    void setDecimalSeparator(QString decimalSeparator);
    void setDataRow(quint32 dataRow);
    void setColumn(quint32 column);
    void setLabelRow(quint32 labelRow);
    void setDynamicSession(bool bDynamicSession);
    void setWatchFileChanges(bool bWatchFileChanges);

signals:
    void dynamicSessionChanged(bool);
    void watchFilechangesChanged(bool);

private:

    QString _path;
    QString _fieldSeparator;
    QString _groupSeparator;
    QString _decimalSeparator;
    quint32 _dataRow;
    quint32 _column;
    quint32 _labelRow;
    bool _bDynamicSession;
    bool _bWatchFileChanges;

};



#endif // DataParserSettings_H
