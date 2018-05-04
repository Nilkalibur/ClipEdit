#ifndef SAVE_H
#define SAVE_H
#include <QString>
#include <QDomElement>
#include <QGraphicsScene>
#include "mainwindow.h"
#include "Items/picturesgraphicsitem.h"
#include "Items/textboxitem.h"
#include "Items/arrowsgraphicsitem.h"
#include "Items/numberedbulletgraphicitem.h"
#include "Items/picturesgraphicsitem.h"
#include "Forms/formarrows.h"
#include "Forms/formcharts.h"
#include "Forms/formcliparts.h"
#include <QSettings>
#include "Forms/formlayers.h"
#include "Forms/formnumberedbullets.h"
#include "Forms/formpictures.h"
#include "Forms/formscreenshots.h"
#include "Forms/formtextboxes.h"
#include "Items/graphsgraphicsitem.h"

class Save
{
public:
    Save(QGraphicsScene*,QString);
    Save(QList<QGraphicsItem *>,QRectF,QRectF,QColor,bool);
    Save(QList<QGraphicsItem *>,QString,QRectF,QRectF, QColor,bool);
    //QDomElement setLayer()
    static QString verifyExtension(QString,QString);
    static QString current_filename;
    static bool fileNameExists();

    void save();
    QGraphicsRectItem* open();
private:
    QList<QGraphicsItem *> m_listItems;
    QGraphicsScene *m_scene;
    int countItems;
    FormArrows *m_formArrows;
    FormCharts *m_formCharts;
    FormCliparts *m_formCliparts;
    FormLayers *m_formLayers;
    FormNumberedBullets *m_formBullets;
    FormPictures *m_formPicture;
    FormScreenshots *m_formScreenshots;
    FormTextBoxes *m_formTextBoxes;
    QColor m_backgroundColor;
    QRectF m_globalRectF;
    QRectF m_sceneRectF;
    bool m_resized;
};

#endif // SAVE_H
