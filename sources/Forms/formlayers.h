/*
================================================
* File:         formlayers.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage Layers
================================================
*/

#ifndef FORMSLAYERS_H
#define FORMSLAYERS_H

// Includes
// --------


#include <QWidget>
#include <QGraphicsScene>

#include "Classes/layeritemmodel.h"
#include "Forms/baseform.h"

class QLabel;
class QPushButton;
class QTableWidgetItem;
class BaseGraphicItem;

// Forward Declaration
namespace Ui
{
    class FormLayers;
}

// Class
// -----

class FormLayers
    :   public BaseForm
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormLayers(QWidget* parent = 0);
        ~FormLayers();

        // Setter
        void setScene(QGraphicsScene & scene);

        // Update
        void updateLayers();

        // Select item
        void selectItem();

        // Translation
        void retranslate();

    private slots:

        // Cells
        void actionClicked(int line, int col);

        // Buttons
        void actionUp();
        void actionDown();
        void actionCopy();
        void actionDelete();

    private:

        // Ui
        Ui::FormLayers* ui;
        QGraphicsScene* m_scene;

        // Table model
        QStandardItemModel* m_model;

        // Holders
        int m_nLabel;
        int m_lineSelected;

        BaseGraphicItem * m_itemSelected;

        // Utils
        QLabel* cellIcon(const QIcon& icon);
        QLabel* cellIcon(const QString& filename);

        // Init
        void initForm();
        void fillDynamicStrings();
};

#endif
