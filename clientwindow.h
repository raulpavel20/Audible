#ifndef AUDIBLE_CLIENTWINDOW_H
#define AUDIBLE_CLIENTWINDOW_H

#include <QMainWindow>
#include "Controller.h"
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class ClientWindow : public QMainWindow {
    Q_OBJECT

    public:
        ClientWindow(QWidget *parent = nullptr);
        ~ClientWindow();

    public slots:
        void showOptions();
        void viewList();
        void deleteBook();
        void onBookDelete();


    private:
        Ui::ClientWindow *ui{};
        QWidget mainWidget;
        Controller databaseCtrl, clientCtrl;
        QLineEdit *title = new QLineEdit();

};


#endif //AUDIBLE_CLIENTWINDOW_H
