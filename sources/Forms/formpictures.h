/*
================================================
* File:         formpictures.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMPICTURES_H
#define FORMPICTURES_H

// Includes
// --------

#include <QWidget>


// Forward Declaration
namespace Ui
{
    class FormPictures;
}


// Class
// -----

class FormPictures: public QWidget
{
    Q_OBJECT


    public:

        // Constructor, destructor
        explicit FormPictures(QWidget* parent = 0);

        ~FormPictures();

       void getPictureValues(QString &path, int &height, int &width, int &shade_grey, int &trans, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos);

public slots:
    void chose_picture();
private:

        // Ui
        Ui::FormPictures *ui;

signals:
        void ImageChoosen();

};

#endif
