/*
================================================
* File:         formcliparts.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formcliparts.h"
#include "ui_formcliparts.h"

#include "../Canvas_Items/Item_Arrow.h"

// Constructor, destructor
// -----------------------

FormCliparts::FormCliparts(One_Layered_Canvas& app_canvas, QWidget *parent) :
    QWidget(parent), One_Form(app_canvas), ui(new Ui::FormCliparts) {

    ui->setupUi(this);

    connect(ui->test_button, SIGNAL( clicked(bool) ), this, SLOT( event_onClick(bool) ));
}


FormCliparts::~FormCliparts() {
    delete ui;

    list_arrows.clear();
}


void FormCliparts::event_onClick(bool) {
    Item_Arrow* arrow = new Item_Arrow();

    if (arrow != NULL) {
        list_arrows.append(arrow);

        canvas.add_widget(arrow);
    }
}
