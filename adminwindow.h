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

    private:
        Ui::AdminWindow *ui{};
        QWidget mainWidget;
        Controller databaseCtrl;

};

#endif //AUDIBLE_ADMINWINDOW_H
