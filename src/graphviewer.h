#ifndef GraphViewer_H
#define GraphViewer_H

#include <QObject>
#include <QVector>
#include <QMouseEvent>

#include "qcustomplot.h"

class GraphViewer : public QObject
{
    Q_OBJECT
public:
    explicit GraphViewer(QCustomPlot * pPlot, QObject *parent);

    void clear();
    void setupGraph(QList<QList<double> > *pDataLists, QStringList *pLabels);
    void exportGraphImage(QString imageFile);
    void manualScaleXAxis(qint64 min, qint64 max);
    void manualScaleYAxis(qint64 min, qint64 max);
    void showGraph(quint32 index, bool bShow);

public slots:
    void autoScaleXAxis();
    void autoScaleYAxis(); 

private slots:
    void generateTickLabels();
    void selectionChanged();
    void mousePress(QMouseEvent *event);
    void mouseRelease(QMouseEvent *event);
    void mouseMove(QMouseEvent *event);
    void mouseWheel();
    void axisDoubleClicked(QCPAxis * axis);
    void beforeReplot();

private:

    QCustomPlot * _pPlot;

    static const QList<QColor> _colorlist;

    QVector<QString> tickLabels;

    bool draggingLegend;
    QPointF dragLegendOrigin;

    static const quint32 _cMinuteTripPoint = 5*60*1000; /* in ms */
    static const quint32 _cHourTripPoint = 10*60*60*1000; /* in ms */

};

#endif // GraphViewer_H
