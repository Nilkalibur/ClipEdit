/*
================================================
* File:         mainwindow.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Application's main window
================================================
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes
// --------

#include <QMainWindow>
#include <QMap>
#include <QWidget> // <- This is to implement the delete key from the keyboard for any item
#include <QGraphicsScene>
#include <QRectF>
#include <QTranslator>

#include "Items/basegraphicitem.h"
#include "dialogpreferences.h"

class BaseForm;
class QToolButton;
class QSpinBox;

// Forward declaration
namespace Ui
{
    class MainWindow;
}


// Class
// -----

class MainWindow
    :   public QMainWindow
{
    Q_OBJECT

    public:

        // Constructor & Destructor
        explicit MainWindow(QWidget* parent = 0);
        ~MainWindow();

    protected:

        // Events
        bool eventFilter(QObject* watched, QEvent* event);
        void changeEvent(QEvent* event);
        void keyPressEvent(QKeyEvent* event);

    signals:

        void screenshotTaken(const QPixmap& screenshot);
        //void thisItemSelected(const BaseGraphicItem& itemSelected);  // <- This is to implement the delete key from the keyboard for any item
        //void thisItemSelectedQGI(const QGraphicsItem& itemSelected);  // <- This is to implement the delete key from the keyboard for any item

    private slots:

        // Menu and toolbar
        void save(bool);
        void saveAs(bool);
        void openFile(bool);
        void exportView(bool);
        void actionClicked(bool);
        void resizeScene();
        void slotNew(bool);
        void showAboutDialog(bool);

        // Items
        void slotNumberedBullets();
        void slotTextBoxes();
        void slotPictures();
        void slotGraphs();
        void slotArrows();
        void slotScreenshots();

        // Screenshots
        void takeScreenshot(bool wholeScreen);

        // Layers
        void slotLayers();

        // Selection
        void itemSelected();

        // Settings
        void showPreferences();
        void applyPreferences();

private:

        // Buttons Ids
        enum e_BUTTON_IDS {
            BUTTON_ID_ARROW = 0,
            BUTTON_ID_CHART,
            BUTTON_ID_BULLET,
            BUTTON_ID_CLIPART,
            BUTTON_ID_PICTURE,
            BUTTON_ID_TEXTBOX,
            BUTTON_ID_SCREENSHOT,
            BUTTON_ID_LAYERS,
            NB_BUTTONS
        };

        // UI
        Ui::MainWindow* ui;

        // Forms
        QMap<e_BUTTON_IDS, BaseForm*> m_forms;
        QMap<BaseGraphicItem::CustomTypes, e_BUTTON_IDS> m_bounds;

        // Scene
        QGraphicsScene m_scene;

        QGraphicsRectItem* m_borderSceneItem;

        // App translator
        QTranslator m_translator;

        // Zoom
        QSpinBox* m_spinBoxZoom;

        // Format
        int  m_height ;
        int  m_width ;
        bool m_resized;

        // Building
        void init();
        void buildMenu();
        void buildToolBar();
        void buildForms();
        void buildView();

        // Dynamic strings setter (for retranslation)
        void fillDynamicStrings();
};

#endif
