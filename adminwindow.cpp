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

void AdminWindow::viewList() {
    this->databaseCtrl.loadData("bookDatabase", "/home/raulpavel/Documents/Work/Audible/DataFile.json");
    auto Vlayout = new QVBoxLayout();

    auto *bookList = new QTableWidget(0, 6);
    QStringList labels;
    labels << tr("Title") << tr("Author") << tr("Year") << tr("Genre") << tr("Description") << tr("Cover");
    bookList->setHorizontalHeaderLabels(labels);
    bookList->horizontalHeader()->setMinimumSectionSize(160);

    std::vector<Book> myBooks = this->databaseCtrl.getAll().getAll();
    for(auto & i : myBooks) {
        int row = bookList->rowCount();
        bookList->insertRow(row);
        auto title = new QTableWidgetItem(QString::fromStdString(i.getTitle()));
        bookList->setItem(row, 0, title);
        auto author = new QTableWidgetItem(QString::fromStdString(i.getAuthor()));
        bookList->setItem(row, 1, author);
        auto year = new QTableWidgetItem(QString::fromStdString(std::to_string(i.getYear())));
        bookList->setItem(row, 2, year);
        auto genre = new QTableWidgetItem(QString::fromStdString(i.getGenre()));
        bookList->setItem(row, 3, genre);
        auto description = new QTableWidgetItem(QString::fromStdString(i.getDescription()));
        bookList->setItem(row, 4, description);
        auto cover = new QTableWidgetItem(QString::fromStdString(i.getCover()));
        bookList->setItem(row, 5, cover);
    }

    auto backButton = new QPushButton("Back");
    connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));

    Vlayout->addWidget(bookList);
    Vlayout->addWidget(backButton);

    if ( this->mainWidget.layout() != nullptr ) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(Vlayout);

}

void AdminWindow::deleteBook() {
    auto *deleteForm = new QVBoxLayout();

    auto *bookList = new QTableWidget(0, 3);
    QStringList labels;
    labels << tr("Title") << tr("Author") << tr("Genre");
    bookList->setHorizontalHeaderLabels(labels);
    bookList->horizontalHeader()->setMinimumSectionSize(260);

    std::vector<Book> myBooks = this->databaseCtrl.getAll().getAll();
    for(auto & i : myBooks) {
        int row = bookList->rowCount();
        bookList->insertRow(row);
        auto title = new QTableWidgetItem(QString::fromStdString(i.getTitle()));
        bookList->setItem(row, 0, title);
        auto author = new QTableWidgetItem(QString::fromStdString(i.getAuthor()));
        bookList->setItem(row, 1, author);
        auto genre = new QTableWidgetItem(QString::fromStdString(i.getGenre()));
        bookList->setItem(row, 2, genre);
    }

    auto *labelTitle = new QLabel("Title:");
    this->title = new QLineEdit();
    auto deleteButton = new QPushButton("Delete");
    auto backButton = new QPushButton("Back");

    connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(onBookDelete()));

    deleteForm->addWidget(bookList);
    deleteForm->addWidget(labelTitle);
    deleteForm->addWidget(this->title);
    deleteForm->addWidget(deleteButton);
    deleteForm->addWidget(backButton);

    if ( this->mainWidget.layout() != nullptr ) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(deleteForm);
}

void AdminWindow::onBookDelete() {
    auto title = this->title->text();
    if(!(this->databaseCtrl.getAll().checkByTitle(title.toStdString()))) {
        auto msg = QMessageBox();
        msg.setText("Sorry...");
        msg.setInformativeText("No such book found in the database!");
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();
    } else {
        this->databaseCtrl.deleteBook(title.toStdString());
        this->databaseCtrl.saveData("bookDatabase", "/home/raulpavel/Documents/Work/Audible/DataFile.json");
        this->deleteBook();
    }
}

AdminWindow::~AdminWindow() = default;