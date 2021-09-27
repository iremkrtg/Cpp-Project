#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    //ui->setupUi(this);
    a_widget = new QWidget();
    a_layout = new QGridLayout();
    a_label = new QLabel("oare?");

    a_layout->addWidget(a_label, 9, 4, 1, 1);

    a_widget->setMinimumSize(QSize(800, 200));
    a_widget->setLayout(a_layout);

    this->setWindowTitle("Admin");
    //this->setCentralWidget(a_widget);


}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::onAddPressed()
{
    std::cout << "mama";
}
