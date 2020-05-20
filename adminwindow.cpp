#include "adminwindow.h"
#include "clientwindow.h"
#include "Controller.h"
#include "Book.h"
#include <vector>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTableWidget>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>

AdminWindow::AdminWindow(QWidget *parent) : QMainWindow(parent) {
    this->databaseCtrl.loadData("bookDatabase", "/home/raulpavel/Documents/Work/Audible/DataFile.json");

    this->mainWidget.setMinimumSize(1000, 400);
    this->showOptions();
    mainWidget.show();
}

void AdminWindow::showOptions() {
    auto *options = new QVBoxLayout();
    auto databaseButton = new QPushButton("View database");
    auto deleteButton = new QPushButton("Delete a book");
    auto addButton = new QPushButton("Add a book");
    auto editButton = new QPushButton("Edit a book");

    connect(databaseButton, SIGNAL(clicked()), this, SLOT(viewList()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteBook()));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addBook()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(editBook()));

    options->addWidget(databaseButton);
    options->addWidget(deleteButton);
    options->addWidget(addButton);
    options->addWidget(editButton);

    if ( this->mainWidget.layout() != nullptr ) {
        QLayoutItem* item;
        while ( ( item = this->mainWidget.layout()->takeAt( 0 ) ) != nullptr ) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(options);
}

AdminWindow::~AdminWindow() = default;