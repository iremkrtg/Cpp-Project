#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    //ui->setupUi(this);
    a_widget = new QWidget();
    a_layout = new QGridLayout();
    a_label = new QLabel("oare?");

    a_widget->setMinimumSize(QSize(800, 200));
    a_widget->setLayout(a_layout);

    this->setWindowTitle("Admin");
    this->setCentralWidget(a_widget);


}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::onAddPressed()
{
    std::cout << "mama";
}
