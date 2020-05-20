#include "mainwindow.h"
#include "clientwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto adminButton = new QPushButton("I am ADMIN", this);
    auto clientButton = new QPushButton("I am CLIENT", this);

    adminButton->setGeometry(10, 10, 150, 30);
    clientButton->setGeometry(10, 50, 150, 30);

    connect(adminButton, SIGNAL(clicked()), this, SLOT(adminWindow()));
    connect(clientButton, SIGNAL(clicked()), this, SLOT(clientWindow()));
}

void MainWindow::clientWindow() {
    auto clientWindow = new ClientWindow;
    this->close();
}

MainWindow::~MainWindow() = default;