#include "clientwindow.h"
#include "Controller.h"
#include "Book.h"
#include <vector>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
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
    auto *bookList = new QVBoxLayout();

    std::vector<Book> myBooks = this->clientCtrl.getAll().getAll();
    for(auto & i : myBooks) {
        auto title = new QLabel(QString::fromStdString(i.getTitle()));
        auto author = new QLabel(QString::fromStdString(i.getAuthor()));
        auto cover = new QLabel(QString::fromStdString(i.getCover()));
        auto description = new QLabel(QString::fromStdString(i.getDescription()));
        auto genre = new QLabel(QString::fromStdString(i.getGenre()));
        auto year = new QLabel(QString::fromStdString(std::to_string(i.getYear())));
        bookList->addWidget(title);
        bookList->addWidget(author);
        bookList->addWidget(description);
        bookList->addWidget(genre);
        bookList->addWidget(year);
        bookList->addWidget(cover);
        QWidget *lineB = new QWidget;
        lineB->setFixedHeight(2);
        lineB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        lineB->setStyleSheet(QString("background-color: #c0c0c0;"));
        bookList->addWidget(lineB);
    }

    auto backButton = new QPushButton("Back");
    connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));
    bookList->addWidget(backButton);

    if ( this->mainWidget.layout() != nullptr ) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(bookList);
}

ClientWindow::~ClientWindow() = default;