#include "presentationwindow.h"
#include "ui_presentationwindow.h"

PresentationWindow::PresentationWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PresentationWindow)
{
    ui->setupUi(this);
}

PresentationWindow::~PresentationWindow()
{
    delete ui;
}
