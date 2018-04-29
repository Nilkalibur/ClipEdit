/*
================================================
* File:         formlayers.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage Layers
================================================
*/

// Includes
// --------

#include <QDebug>

#include "formlayers.h"
#include "ui_formlayers.h"
#include "Items/basegraphicitem.h"
#include "Classes/layeritemdelegate.h"
#include "Classes/layeritemmodel.h"

// Constructor, destructor
// -----------------------

FormLayers::FormLayers(QWidget* parent)
    :   QWidget(parent), ui(new Ui::FormLayers)
{
    ui->setupUi(this);

    m_scene = NULL;

    initForm();
    updateLayers();
}

FormLayers::~FormLayers()
{
    delete ui;
}

// Init
// ----

void FormLayers::initForm()
{
    ui->tableWidgetLayers->clear();
    ui->tableWidgetLayers->setRowCount(0);
    ui->tableWidgetLayers->setColumnCount(4);

    ui->tableWidgetLayers->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList labels;
    labels << tr("Visibility") << tr("Type") << tr("Name") << tr("Z-Value");
    ui->tableWidgetLayers->setHorizontalHeaderLabels(labels);
    ui->tableWidgetLayers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetLayers->horizontalHeader()->show();
    ui->tableWidgetLayers->verticalHeader()->hide();
    ui->tableWidgetLayers->setShowGrid(true);
    ui->tableWidgetLayers->setAlternatingRowColors(true);

    ui->tableWidgetLayers->setItemDelegate(new LayerItemDelegate());
    //ui->tableWidgetLayers->setModel(new LayerItemModel());

    ui->tableWidgetLayers->setContextMenuPolicy(Qt::CustomContextMenu);

    // connect
    connect(ui->tableWidgetLayers, &QTableWidget::cellActivated, this, &FormLayers::cellActivated);
    connect(ui->tableWidgetLayers, &QTableWidget::customContextMenuRequested, this, &FormLayers::contextMenu);

    connect (ui->tableWidgetLayers, SIGNAL(cellClicked(int,int)), this, SLOT(actionClicked(int ,int)));

    connect (ui->buttonUp, SIGNAL(clicked(bool)), this, SLOT(actionUp()));
    connect (ui->buttonDown, SIGNAL(clicked(bool)), this, SLOT(actionDown()));
    connect (ui->buttonAdd, SIGNAL(clicked(bool)), this, SLOT(actionAdd()));
    connect (ui->buttonSupp, SIGNAL(clicked(bool)), this, SLOT(actionSupp()));

}

// Slots
// -----

void FormLayers::actionClicked(int line , int col)
{
    qDebug() << "FormLayers::ActionClicked()" << line << col;

    if (!m_scene)
        return;

    m_lineSelected = line;
    m_columnSelected = col;

    m_itemSelected = dynamic_cast<BaseGraphicItem*>(m_scene->items(Qt::AscendingOrder)[m_lineSelected + 1]);

    if (!m_itemSelected)
        return;

    m_scene->clearSelection();
    m_itemSelected->setSelected(true);

    qDebug() << "FormLayers::ActionClicked()" << m_itemSelected;

    if (m_columnSelected == 0)
    {
        m_itemSelected->setVisible(!m_itemSelected->isVisible());

        updateLayers();
    }
}

void FormLayers::actionUp()
{
    qDebug() << "FormLayers::ActionUp()";

    if (!m_itemSelected)
        return;

    qreal zValue = m_itemSelected->zValue() + 0.1;
    m_itemSelected->setZValue(zValue);

    updateLayers();
}

void FormLayers::actionDown()
{
    qDebug() << "FormLayers::ActionDown()";

    if (!m_itemSelected)
        return;

    qreal zValue = m_itemSelected->zValue() - 0.1;
    m_itemSelected->setZValue(zValue);

    updateLayers();
}

void FormLayers::actionAdd()
{
    qDebug() << "FormLayers::ActionAdd()";

    if (!m_itemSelected)
        return;

//    m_scene->addItem(new BaseGraphicItem(m_itemSelected));
//    m_scene->addItem(new QGraphicsItem(m_itemSelected));

    updateLayers();
}

void FormLayers::actionSupp()
{
    qDebug() << "FormLayers::ActionSupp()";

    if (!m_itemSelected)
        return;

    m_scene->removeItem(m_itemSelected);
    ui->tableWidgetLayers->removeRow(m_lineSelected);

    updateLayers();
}

// Update
// ------

void FormLayers::updateLayers()
{
    qDebug() << "FormLayers::updateLayers()";

    if (!m_scene)
        return;

    ui->tableWidgetLayers->setRowCount(0);

    foreach (QGraphicsItem* it, m_scene->items(Qt::AscendingOrder))
    {
        BaseGraphicItem* item = dynamic_cast<BaseGraphicItem*>(it);

        if (item)
        {
            int row = ui->tableWidgetLayers->rowCount()+1;
            ui->tableWidgetLayers->setRowCount(row);

            // 1ere colonne
            if (item->isVisible())
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 0, cellIcon(QIcon(":/icons/icons/eye-icon.png")));
            }
            else
            {
                ui->tableWidgetLayers->setCellWidget(row - 1, 0, cellIcon(QIcon(":/icons/icons/eye-transparent-icon.png")));
            }

            // 2eme colonne
            switch (item->type())
            {
                case BaseGraphicItem::CustomTypes::TextBoxGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/textbox-icon.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ArrowGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/arrow-icon-2.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ChartGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/chart-icon-2.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ClipartGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/clipart-icon.png")));
                } break;
                case BaseGraphicItem::CustomTypes::PictureGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/picture-icon.png")));
                } break;
               case BaseGraphicItem::CustomTypes::NumberedBulletGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/numbered-bullet-icon.png")));
                } break;
                case BaseGraphicItem::CustomTypes::ScreenshotGraphicsItem:
                {
                    ui->tableWidgetLayers->setCellWidget(row - 1, 1, cellIcon(QIcon(":/icons/icons/screenshot-icon.png")));
                } break;
                default:
                {
                    // Default
                } break;
            }

            static const int ObjectName = 0;
            if (item->data(ObjectName).toString().isEmpty())
            {
                item->setData(ObjectName, "Itemx"+QString::number(row));
            }

            ui->tableWidgetLayers->setCellWidget(row-1, 2, new QLabel(item->data(ObjectName).toString()));
            ui->tableWidgetLayers->setCellWidget(row-1, 3, new QLabel(QString::number(item->zValue())));
        }
    }

    // Init
    m_lineSelected = -1;
    m_columnSelected = -1;
    //m_itemSelected = NULL;
}

// Getters
// -------

// Setters
// -------

void FormLayers::setScene(QGraphicsScene& scene)
{
    m_scene = &scene;
    updateLayers();
}

QLabel* FormLayers::cellIcon(const QIcon& icon)
{
    QLabel* label = new QLabel(this);
    label->setPixmap(icon.pixmap(QSize(24,24)));
    return label;
}

QLabel* FormLayers::cellIcon(const QString& filename)
{
    QLabel* label = new QLabel(this);
    QIcon*icon = new QIcon(filename);
    label->setPixmap(icon->pixmap(QSize(24,24)));
    return label;
}


void FormLayers::cellActivated(int row, int column)
{
    qDebug() << "FormLayers::cellActivated()" << row << column;

//    const QTableWidgetItem *item = filesTable->item(row, 0);
//    openFile(fileNameOfItem(item));
}

void FormLayers::contextMenu(const QPoint &pos)
{
    qDebug() << "FormLayers::contextMenu()" << pos;

//    const QTableWidgetItem *item = filesTable->itemAt(pos);
//    if (!item)
//        return;
//    QMenu menu;
//#ifndef QT_NO_CLIPBOARD
//    QAction *copyAction = menu.addAction("Copy Name");
//#endif
//    QAction *openAction = menu.addAction("Open");
//    QAction *action = menu.exec(filesTable->mapToGlobal(pos));
//    if (!action)
//        return;
//    const QString fileName = fileNameOfItem(item);
//    if (action == openAction)
//        openFile(fileName);
//#ifndef QT_NO_CLIPBOARD
//    else if (action == copyAction)
//        QGuiApplication::clipboard()->setText(QDir::toNativeSeparators(fileName));
//#endif
}


