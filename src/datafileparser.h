#ifndef DATAFILEPARSER_H
#define DATAFILEPARSER_H

#include "QObject"
#include "QStringList"
#include "QList"
#include "QFile"
#include "dataparsersettings.h"
#include <QFileSystemWatcher>

class DataFileParser : public QObject
{
    Q_OBJECT

public:
    DataFileParser();
    ~DataFileParser();

    DataParserSettings * getDataParseSettings();
    bool loadDataFile(void);
    bool parseData(QList<QList<double> > &dataRows, QStringList &labels);

signals:
    void fileDataChanged();
    void addFileWatchFailed(QString);

private slots:
    void fileDataChange(QString);

private:

    bool readLineFromFile(QFile *file, QString *pLine);
    bool IsCommentLine(QString line);

    QStringList _fileContents;

    DataParserSettings _parseSettings;
    QFileSystemWatcher *_pFileWatcher;

};

#endif // DATAFILEPARSER_H
