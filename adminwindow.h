#ifndef AUDIBLE_ADMINWINDOW_H
#define AUDIBLE_ADMINWINDOW_H

#include <QMainWindow>
#include "Controller.h"
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

class AdminWindow : public QMainWindow {
Q_OBJECT

public:
    AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

public slots:
    void showOptions();
    void viewList();
    void deleteBook();
    void addBook();
    void editBook();
    void onBookDelete();
    void onAddButton();
    void onBookEdit();

private:
    Ui::AdminWindow *ui{};
    QWidget mainWidget;
    Controller databaseCtrl;
    QLineEdit *titleLine = new QLineEdit();
    QLineEdit *authorLine = new QLineEdit();
    QLineEdit *yearLine = new QLineEdit();
    QLineEdit *descriptionLine = new QLineEdit();
    QLineEdit *coverLine = new QLineEdit();
    QLineEdit *genreLine = new QLineEdit();

};

#endif //AUDIBLE_ADMINWINDOW_H
