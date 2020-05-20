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
    this->titleLine = new QLineEdit();
    auto deleteButton = new QPushButton("Delete");
    auto backButton = new QPushButton("Back");

    connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(onBookDelete()));

    deleteForm->addWidget(bookList);
    deleteForm->addWidget(labelTitle);
    deleteForm->addWidget(this->titleLine);
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
    auto title = this->titleLine->text();
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

void AdminWindow::addBook() {
    auto Vlayout = new QVBoxLayout();

    auto *labelTitle = new QLabel("Title:");
    this->titleLine = new QLineEdit();
    auto *labelAuthor = new QLabel("Author:");
    this->authorLine = new QLineEdit();
    auto *labelYear = new QLabel("Year:");
    this->yearLine = new QLineEdit();
    auto *labelCover = new QLabel("Cover:");
    this->coverLine = new QLineEdit();
    auto *labelDescription = new QLabel("Description:");
    this->descriptionLine = new QLineEdit();
    auto *labelGenre = new QLabel("Genre:");
    this->genreLine = new QLineEdit();
    auto backButton = new QPushButton("Back");
    auto addButton = new QPushButton("Add");

    connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));
    connect(addButton, SIGNAL(clicked()), this, SLOT(onAddButton()));

    Vlayout->addWidget(labelTitle);
    Vlayout->addWidget(this->titleLine);
    Vlayout->addWidget(labelAuthor);
    Vlayout->addWidget(this->authorLine);
    Vlayout->addWidget(labelYear);
    Vlayout->addWidget(this->yearLine);
    Vlayout->addWidget(labelGenre);
    Vlayout->addWidget(this->genreLine);
    Vlayout->addWidget(labelDescription);
    Vlayout->addWidget(this->descriptionLine);
    Vlayout->addWidget(labelCover);
    Vlayout->addWidget(this->coverLine);
    Vlayout->addWidget(addButton);
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

void AdminWindow::onAddButton() {
    if(
            !(this->yearLine->text().toInt()) ||
            this->titleLine->text().toStdString().empty() ||
            this->authorLine->text().toStdString().empty() ||
            this->genreLine->text().toStdString().empty() ||
            this->descriptionLine->text().toStdString().empty() ||
            this->coverLine->text().toStdString().empty()
            ) {
        auto msg = QMessageBox();
        msg.setText("Sorry...");
        msg.setInformativeText("Some data was invalid!");
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();
    } else {
        auto newBook = Book(
                this->titleLine->text().toStdString(),
                this->authorLine->text().toStdString(),
                this->genreLine->text().toStdString(),
                this->descriptionLine->text().toStdString(),
                this->yearLine->text().toInt(),
                this->coverLine->text().toStdString()
        );

        this->databaseCtrl.addBook(newBook);
        this->databaseCtrl.saveData("bookDatabase", "/home/raulpavel/Documents/Work/Audible/DataFile.json");
        this->addBook();
    }
}

void AdminWindow::editBook() {
    auto *editForm = new QVBoxLayout();

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
    this->titleLine = new QLineEdit();
    auto editButton = new QPushButton("Edit");
    auto backButton = new QPushButton("Back");

    connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(onBookEdit()));

    editForm->addWidget(bookList);
    editForm->addWidget(labelTitle);
    editForm->addWidget(this->titleLine);
    editForm->addWidget(editButton);
    editForm->addWidget(backButton);

    if ( this->mainWidget.layout() != nullptr ) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(editForm);
}

void AdminWindow::onBookEdit() {


    auto title = this->titleLine->text();
    if(!(this->databaseCtrl.getAll().checkByTitle(title.toStdString()))) {
        auto msg = QMessageBox();
        msg.setText("Sorry...");
        msg.setInformativeText("No such book found in the database!");
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();
        this->editBook();
    } else {
        Book bookToEdit = *this->databaseCtrl.findByTitle(this->titleLine->text().toStdString());

        auto Vlayout = new QVBoxLayout();

        auto *labelTitle = new QLabel("Title:");
        this->titleLine = new QLineEdit();
        auto *labelAuthor = new QLabel("Author:");
        this->authorLine = new QLineEdit();
        auto *labelYear = new QLabel("Year:");
        this->yearLine = new QLineEdit();
        auto *labelCover = new QLabel("Cover:");
        this->coverLine = new QLineEdit();
        auto *labelDescription = new QLabel("Description:");
        this->descriptionLine = new QLineEdit();
        auto *labelGenre = new QLabel("Genre:");
        this->genreLine = new QLineEdit();
        auto backButton = new QPushButton("Back");
        auto addButton = new QPushButton("Add");

        connect(backButton, SIGNAL(clicked()), this, SLOT(showOptions()));
        connect(addButton, SIGNAL(clicked()), this, SLOT(onAddButton()));

        Vlayout->addWidget(labelTitle);
        Vlayout->addWidget(this->titleLine);
        Vlayout->addWidget(labelAuthor);
        Vlayout->addWidget(this->authorLine);
        Vlayout->addWidget(labelYear);
        Vlayout->addWidget(this->yearLine);
        Vlayout->addWidget(labelGenre);
        Vlayout->addWidget(this->genreLine);
        Vlayout->addWidget(labelDescription);
        Vlayout->addWidget(this->descriptionLine);
        Vlayout->addWidget(labelCover);
        Vlayout->addWidget(this->coverLine);
        Vlayout->addWidget(addButton);
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

        this->databaseCtrl.saveData("bookDatabase", "/home/raulpavel/Documents/Work/Audible/DataFile.json");
    }
}

AdminWindow::~AdminWindow() = default;