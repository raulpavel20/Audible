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
#include <QShortcut>

ClientWindow::ClientWindow(QWidget *parent) : QMainWindow(parent) {
    this->databaseCtrl.loadData("bookDatabase", "/home/raulpavel/Documents/Work/Audible/DataFile.json");
    this->clientCtrl.loadData("client1", "/home/raulpavel/Documents/Work/Audible/Client.json");

    this->mainWidget.setMinimumSize(1000, 400);
    this->showOptions();
    mainWidget.show();
}

void ClientWindow::showOptions() {
    auto *options = new QVBoxLayout();
    auto yourListButton = new QPushButton("View your list");
    auto deleteButton = new QPushButton("Delete a book");
    auto browseButton = new QPushButton("Browse for new books");

    QShortcut *undo = new QShortcut(this);
    undo->setKey(Qt::CTRL+Qt::Key_Z);

    connect(undo, SIGNAL(activated()), this, SLOT(undoF()));
    connect(yourListButton, SIGNAL(clicked()), this, SLOT(viewList()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteBook()));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));

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
    this->clientCtrl.loadData("client1", "/home/raulpavel/Documents/Work/Audible/Client.json");
    auto Vlayout = new QVBoxLayout();

    auto *bookList = new QTableWidget(0, 6);
    QStringList labels;
    labels << tr("Title") << tr("Author") << tr("Year") << tr("Genre") << tr("Description") << tr("Cover");
    bookList->setHorizontalHeaderLabels(labels);
    bookList->horizontalHeader()->setMinimumSectionSize(160);

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

void ClientWindow::deleteBook() {
    auto *deleteForm = new QVBoxLayout();

    auto *bookList = new QTableWidget(0, 3);
    QStringList labels;
    labels << tr("Title") << tr("Author") << tr("Genre");
    bookList->setHorizontalHeaderLabels(labels);
    bookList->horizontalHeader()->setMinimumSectionSize(260);

    std::vector<Book> myBooks = this->clientCtrl.getAll().getAll();
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

void ClientWindow::onBookDelete() {

    auto title = this->title->text();
    if(!(this->clientCtrl.getAll().checkByTitle(title.toStdString()))) {
        auto msg = QMessageBox();
        msg.setText("Sorry...");
        msg.setInformativeText("No such book found in your list!");
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();
    } else {
        this->clientCtrl.deleteBook(title.toStdString());
        this->clientCtrl.saveData("client1", "/home/raulpavel/Documents/Work/Audible/Client.json");
        this->deleteBook();
    }
}

void ClientWindow::browse() {
    auto *browseForm = new QVBoxLayout();

    auto *bookList = new QTableWidget(0, 6);
    QStringList labels;
    labels << tr("Title") << tr("Author") << tr("Year") << tr("Genre") << tr("Description") << tr("Cover");
    bookList->setHorizontalHeaderLabels(labels);
    bookList->horizontalHeader()->setMinimumSectionSize(160);

    std::vector<Book> myBooks = this->databaseCtrl.getAll().getAll();

    auto i = myBooks[this->browseIndex];
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

    auto nextButton = new QPushButton("Next Book");
    auto addAndNextButton = new QPushButton("Add to your list and go to the Next Book");
    auto backButton = new QPushButton("Back");

    connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(onNext()));
    connect(addAndNextButton, SIGNAL(clicked()), this, SLOT(onAddAndNext()));

    browseForm->addWidget(bookList);
    browseForm->addWidget(nextButton);
    browseForm->addWidget(addAndNextButton);
    browseForm->addWidget(backButton);

    if ( this->mainWidget.layout() != nullptr ) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(browseForm);
}

void ClientWindow::onNext() {
    this->browseIndex++;
    if(this->browseIndex == this->databaseCtrl.getAll().getAll().size())
        this->browseIndex = 0;
    this->browse();
}

void ClientWindow::onAddAndNext() {
    auto newBook = this->databaseCtrl.getAll().getAll()[this->browseIndex];
    if(this->clientCtrl.getAll().checkDuplicate(newBook)) {
        auto msg = QMessageBox();
        msg.setText("Sorry...");
        msg.setInformativeText("You already have that book in your list!");
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();
    } else {
        this->clientCtrl.addBook(newBook);
    }
    this->browseIndex++;
    if(this->browseIndex == this->databaseCtrl.getAll().getAll().size())
        this->browseIndex = 0;
    this->clientCtrl.saveData("client1", "/home/raulpavel/Documents/Work/Audible/Client.json");
    this->browse();
}

void ClientWindow::undoF() {
    this->browse();
}

ClientWindow::~ClientWindow() = default;