#include "clientwindow.h"
#include "Controller.h"
#include "Book.h"
#include <vector>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QIcon>
#include <QWidget>

ClientWindow::ClientWindow(QWidget *parent) : QMainWindow(parent) {
    this->databaseCtrl.loadData("bookDatabase", "/home/raulpavel/Documents/Work/Audible/DataFile.json");
    this->clientCtrl.loadData("client1", "/home/raulpavel/Documents/Work/Audible/Client.json");

    this->mainWidget.setMinimumSize(700, 300);
    this->showOptions();
    mainWidget.show();
}

void ClientWindow::showOptions() {
    auto *options = new QVBoxLayout();
    auto yourListButton = new QPushButton("View your list");
    auto deleteButton = new QPushButton("Delete a book");
    auto browseButton = new QPushButton("Browse for new books");

    connect(yourListButton, SIGNAL(clicked()), this, SLOT(viewList()));

    options->addWidget(yourListButton);
    options->addWidget(deleteButton);
    options->addWidget(browseButton);

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

void ClientWindow::viewList() {
    auto Vlayout = new QVBoxLayout();

    auto *bookList = new QTableWidget(0, 6);
    QStringList labels;
    labels << tr("Title") << tr("Author") << tr("Year") << tr("Genre") << tr("Description") << tr("Cover");
    bookList->setHorizontalHeaderLabels(labels);

    std::vector<Book> myBooks = this->clientCtrl.getAll().getAll();
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

ClientWindow::~ClientWindow() = default;