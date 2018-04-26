/*
================================================
* File:         formcharts.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#ifndef FORMCHARTS_H
#define FORMCHARTS_H

#include <QWidget>
#include <QString>
#include <QColor>

#include "baseform.h"
#include "../Items/graphsgraphicsitem.h"


// Forward Declaration
namespace Ui
{
    class FormCharts;
}


// Class
// -----

class FormCharts
    :   public BaseForm
{
    Q_OBJECT

    public:

        explicit FormCharts(QWidget* parent = 0);

        ~FormCharts();

    void GetChartsValues(int &vChartType, QString &vChartTitle, QString &vXAxis, QString &vYAxis,
                         QColor &vBackColor, QColor &vColor, int &vWidth, int &vHeight);

    void GetChartsValues( GraphsInfo &infos);

    // Load data
    void loadFromItem(BaseGraphicItem* item) const;

public slots:

private:

        Ui::FormCharts *ui;

private slots:

   void createChart();
    //   void fillColorArrowChanged(const QColor& color);
    //   void outlineColorArrowChanged(const QColor& color);

signals:

    void FormCreateChart( const GraphsInfo & newGraphsInfo);

};

#endif
