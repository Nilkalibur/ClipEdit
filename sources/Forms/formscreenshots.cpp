/*
================================================
* File:         formscreenshots.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage sceenshots capture
================================================
*/


#include "formscreenshots.h"
#include "ui_formscreenshots.h"

//add
#include<QTimer>
#include<QWindow>
#include<QDesktopWidget>
#include<QApplication>
#include<QScreen>
#include<QEvent>
#include<QKeyEvent>
#include<QCursor>
#include<QPixmap>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<exception>
#include<QRect>
#include<QPointF>
#include<QGraphicsView>



// Constructor, destructor
// -----------------------

FormScreenshots::FormScreenshots(QWidget* parent)
    :   QWidget(parent), ui(new Ui::FormScreenshots)
{
    ui->setupUi(this);



    //THis makes Qt delete this widget when the widget has accepted the close even.
    this->setAttribute(Qt::WA_DeleteOnClose);

    //Some of these flags depend on whether the underlying window manager supports them
    //Produces a borderless window. The user cannot move or resize a borderless
    //window via the window system.
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    //Indicates that the widget has no background, i.e. when the widget receives paint events,
    //the background is not automatically repainted.
     setAttribute(Qt::WA_NoSystemBackground, true);

    //Indicates that the widget should have a translucent background,
    //i.e., any non-opaque regions of the widgets will be translucent
    //because the widget will have an alpha channel.
    //Setting this flag causes WA_NoSystemBackground to be set
    setAttribute(Qt::WA_TranslucentBackground);

    //Shows the widget in full-screen mode.
     //this->showFullScreen();

    //Go QPushButton
    //connect(ui->pushButtonCapture, SIGNAL(clicked(bool)),
   // this, SLOT(Capture()));
   connect(ui->pushButtonCapture, SIGNAL(clicked(bool)),
            this, SLOT(CaptureWholeScreen()));

 //   connect(ui->radioButtonRegion, SIGNAL(clicked(bool)),
 //           this, SLOT(CaptureRegion()));

    connect(ui->radioButtonWholecapture, SIGNAL(clicked(bool)),
            this, SLOT(CaptureWholeScreen()));



    //This property holds the cursor shape for this widget.
   // m_savedcursor=cursor();

    //A crosshair cursor is used to help the user accurately
    //select a point on the screen.
    //setCursor(Qt::CrossCursor);



    ui->spinBoxDelay->setSuffix(" s "); //OK it works
    ui->spinBoxDelay->setMaximum(60);   //idem
    ui->spinBoxDelay->setValue(1);

    //connect pour tempo: option
//    connect(m_delayspinbox, QOverload<int>::of(&QSpinBox::valueChanged),
//            this, &FormScreenshots::updatehide);




    //OK
    connect(ui->pushButtonCancel, SIGNAL(clicked(bool)),
            this, SLOT(close()));

}

FormScreenshots::~FormScreenshots()
{
    //delete the object
   //setCursor(m_savedcursor);
   delete ui;
}

void FormScreenshots::CaptureWholeScreen()
{
    //step1:
    hide();
    QTimer::singleShot(500, this, SLOT(snapshot()));  // long enough for window manager effects
}

void FormScreenshots::CaptureRegion(bool val, QRect r)
{
   m_formScreenshots->close();

   if(val) {
       m_region =r;
       QTimer::singleShot(200, this, SLOT(CaptureArea()));
   }
}


//void FormScreenshots::CaptureRegion(bool ok, QRect region)
//{
//    //m_formscreenshot->close();
//    if(ok)
//    {
//        m_region=region;
//        QTimer::singleShot(m_delayspinbox->value() * 3000, this,
//                           SLOT(CaptureRegion()));
//    }

//    QScreen *screen = QGuiApplication::primaryScreen();
//    if(const QWindow *window = windowHandle())
//        screen = window->screen();

//    if(!screen) return;
//    this->hide();

//    m_pixmap = screen->grabWindow(0);

//    QRect rec(m_region.x()+1,m_region.y()+1,m_region.width()-1,m_region.height()-1);
//    QPixmap pix=m_pixmap.copy(rec);
//    m_pixmap=pix;

//    FormScreenshots *w = new FormScreenshots(this);


//    connect(w,SIGNAL(InsertImageText(QString)),
//            this, SIGNAL(InsertImageText(QString)));

//  // w->setBackgroundRole(m_pixmap);
//    w->show();

//}

void FormScreenshots::mousePressEvent(QMouseEvent *event)
{    QPoint point1;
     point1 = event->globalPos();


    // Q_UNUSED(event)
    /**
   //code: if m_point0 = m_point1 we get the whole screen.
    m_buttonpressed=true;
    m_point0=event->pos();
    m_point1=m_point0;
    */
    //Whole screen capture
   // CaptureWholeScreen();

//    if(event->MouseButtonPress) {
//        qDebug() << "is clicked";
//        QPoint point;
//        x=point.x();
//        qDebug()<<x;
//        y= point.y();
//        qDebug()<<y;
//        qDebug()<<point;
//    }
}

void FormScreenshots::mouseReleaseEvent(QMouseEvent *event)
{

//    QPoint m_point1;
//    m_point1 = event->globalPos();//get global position according to ur parent-child relationship
//    QPainter m_painter(this);

    //m_painter->
   // p->drawRect(point1, point2);


 //   Q_UNUSED(event)
//    emit mouseReleaseEvent();
//    m_buttonpressed=false;
//    emit dimensionsMade(true, m_region);
//    close();

//    if(event->MouseButtonRelease)
//     {
//         qDebug () << "released";
//        // QPointF point1= ui->graphicsView->mapFromScene(e->posF());
//         QPoint point1;
//         x1=point1.x();
//         qDebug()<<x1;
//         y1= point1.y();
//         qDebug()<<y1;
//         qDebug()<<point1;
//     }
}


void FormScreenshots::snapshot()
{

    //step1
    static int count = 0;

    QPixmap p = QPixmap::grabWindow(QApplication::desktop()->winId());
    p.save(QString("/home/formation/doCapture/screenshot%1.png").arg(count));
    count++;
    show();

    //qApp is global pointer referring to the unique application object.
    QTimer::singleShot(300, qApp, SLOT(quit())); // close the app in 0,3 secs
}

void FormScreenshots::CaptureArea()
{
    //code
//    QScreen *screen = QGuiApplication::primaryScreen();
//    if (const QWindow *window = windowHandle())
//         screen = window->screen();
//    if (!screen)
//           return;
//    this->hide();
//    m_pixmap = screen->grabWindow(0);
//    QRect rec(m_region.x()+1,m_region.y()+1,m_region.width()-1,m_region.height()-1);
//    QPixmap pix=m_pixmap.copy(rec);
//    m_pixmap=pix;

//   FormScreenshots *w = new FormScreenshots(this);
//    connect (w,SIGNAL(InsertImageText(QString)),this,SIGNAL(InsertImageText(QString)));
//    w->show();
}

void FormScreenshots::updatehide()
{
        m_delayspinbox = new QSpinBox(this);
        if (m_delayspinbox->value()== 0) {
           m_hidewindow->setDisabled(true);
            m_hidewindow->setChecked(false);
        } else {
            m_hidewindow->setDisabled(false);
        }

}






