#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QVBoxLayout>
#include <QLabel>

class WelcomeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomeWidget(QWidget *parent = 0);

private:
    void init();

    QVBoxLayout *mainLayout;
    QLabel *label;

signals:

public slots:
};

#endif // WELCOMEWIDGET_H
