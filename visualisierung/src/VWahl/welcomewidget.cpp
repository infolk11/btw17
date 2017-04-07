#include "welcomewidget.h"

WelcomeWidget::WelcomeWidget(QWidget *parent) : QWidget(parent)
{
    init();
}

/**
 * Initializes the gui components
 *
 * @brief WelcomeWidget::init
 */
void WelcomeWidget::init()
{
    mainLayout = new QVBoxLayout(this);
    label = new QLabel("welcome",this);
    mainLayout->addWidget(label);
}

