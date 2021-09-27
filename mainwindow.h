#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include  "Controller.h"
#include "adminwindow.h"
// #include "userwindow.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidgetItem>
#include <QListWidget>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller* ctrl, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //main window
    void onAdminPressed();
    void onUserPressed();
    void onLoadPressed();
    void onFilePressed();
    //void onCloseWindow();

    //admin window
    void onAddPressed();
    void onRemovePressed();
    void onUpdatePressed();
    void onUndoPressedAdmin();
    void onRedoPressedAdmin();
    void onCloseAdminPressed();

    //user window
    //void onItemClicked();
    void onAddWish();
    void onRemoveWish();
    void onUndoPressedUser();
    void onRedoPressedUser();
    void onCloseUserPressed();

    void populate();
    void populateWish();
    void populateList();

private:
    //central widget
    Ui::MainWindow *ui;
    Controller* m_controller;
    QWidget* m_widget;
    QGridLayout* m_layout;
    QPushButton* m_admin;
    QPushButton* m_user;
    QLabel* m_data;
    //QPushButton* m_close;

    //admin window
    AdminWindow* m_adminWindow;
    QPushButton* load_ctrl;
    QLineEdit* file_name;
    QPushButton* load_file;
    QPushButton* close_admin;
    QShortcut* shortcut;

    //add performance
    QWidget* add_widget;
    QGridLayout* add_layout;
    QLabel* addWidget_label;
    QLabel* artist_label;
    QLineEdit* artist;
    QLabel* country_label;
    QLineEdit* country;
    QLabel* day_label;
    QLineEdit* day;
    QLabel* stage_label;
    QLineEdit* stage;
    QLabel* link_label;
    QLineEdit* link;
    QPushButton* add_performance;

    //remove performance
    QWidget* remove_widget;
    QGridLayout* remove_layout;
    QLabel* remove_label;
    QLabel* artist_remove;
    QLineEdit* input_remove;
    QPushButton* remove_performance;

    //update performance
    QWidget* update_widget;
    QGridLayout* update_layout;
    QLabel* update_label;
    QLabel* artist_to_update;
    QLineEdit* artist_to_up;
    QLabel* artist_up;
    QLineEdit* artist_new;
    QLabel* country_up;
    QLineEdit* country_new;
    QLabel* day_up;
    QLineEdit* day_new;
    QLabel* stage_up;
    QLineEdit* stage_new;
    QLabel* link_up;
    QLineEdit* link_new;
    QPushButton* update_performance;

    //Display repo
    QListWidget* display_repo;

    //user window
    AdminWindow* user_window;
    QListWidget* repository;
    QListWidget* wish_list;
    QLineEdit* artist_wish;
    QPushButton* add_wish;
    QLineEdit* artist_wish_remove;
    QPushButton* remove_wish;
    QPushButton* close_user;
    QLabel* wishlist;
    QLabel* repo_label;


 };
#endif // MAINWINDOW_H
