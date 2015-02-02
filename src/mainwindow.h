#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>

#include "datafileparser.h"
#include "dataparsersettings.h"
#include "graphviewer.h"
#include "loadfiledialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void getDataFileSettings();
    void exitApplication();
    void reloadDataFile();
    void dataFileChange();
    void fileWatchFail();
    void prepareImageExport();
    void showAbout();
    void showXAxisScaleDialog();
    void showYAxisScaleDialog();
    void showHideGraph(bool bState);
    void watchFileChanged(bool bState);
    void dynamicSessionChanged(bool bState);

private:
    bool updateGraph(DataFileParser *_pDataFileParser);

    Ui::MainWindow * _ui;

    GraphViewer * _pGraphViewer;
    DataFileParser * _pParser;
    QMenu * _pGraphShowHide;

    static const QString _cWindowTitle;
};

#endif // MAINWINDOW_H
