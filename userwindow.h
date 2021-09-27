#ifndef USERWINDOW_H
#define USERWINDOW_H

#include "Controller.h"
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

    void onAddPressed();

private:
    Ui::UserWindow *ui;
    QWidget* a_widget;
    QGridLayout* a_layout;
    QLabel* a_label;

};

#endif // USERWINDOW_H
