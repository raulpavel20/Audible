#ifndef AUDIBLE_MAINWINDOW_H
#define AUDIBLE_MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void adminWindow() { qInfo() << "WORK IN PROGRESS"; }
        void clientWindow();

    private:
        Ui::MainWindow *ui;
};

#endif //AUDIBLE_MAINWINDOW_H