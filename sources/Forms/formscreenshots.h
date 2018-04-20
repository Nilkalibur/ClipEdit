/*
================================================
* File:         formscreenshots.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMSCREENSHOOTS_H
#define FORMSCREENSHOOTS_H

// Includes
// --------

#include <QWidget>
#include<QPixmap>
#include<QButtonGroup>

// Forward Declaration
namespace Ui
{
    class FormScreenshots;
}


///
/// \brief The FormScreenshots class : his charge is to making a Screenshot
/// of two types: WholeScreenShot and window
///

class FormScreenshots
    :   public QWidget
{
    Q_OBJECT

    public:
///
/// \brief The TypeCapture enum : enum with the type of capture
///

    enum TypeCapture {WholeScreen};

 ///
 /// \brief FormScreenshots : constructor
 /// \param parent
 ///
        explicit FormScreenshots(QWidget* parent = 0);

        ~FormScreenshots();

    private:

        // Ui
        Ui::FormScreenshots *ui;
        ///
        /// \brief m_typecapture : WholeScreen and window.
        ///
        TypeCapture m_typecapture;
        ///
        /// \brief m_pixmap : the pixmap of the window screenshoted.
        ///
        QPixmap m_pixmap;
        ///
        /// \brief m_buttongroup : we group the radio button who are included in different frames.
        QButtonGroup m_buttongroup;

     private slots:
        ///
        /// \brief Capture : capture slot in WholeScreen and window
        ///
        void Capture();
        ///
        /// \brief CaptureWholeScreen : this method take all Desktop
        ///
        void CaptureWholeScreen();

    signals:
        ///
        /// \brief InsertImageText signal sent when text is to be inserted in TextEdit.
        ///
        void InsertImageText(QString);


};

#endif // FORMSCREENSHOOTS_H
