#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include "Controller.h"
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

    void onAddPressed();

private:
    Ui::AdminWindow *ui;
    QWidget* a_widget;
    QGridLayout* a_layout;
    QLabel* a_label;

};

#endif // ADMINWINDOW_H
