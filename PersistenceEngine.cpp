#pragma once

#include <QString>
#include <QFile>
#include "PersistenceEngine.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QIODevice>
#include <QJsonArray>

PersistenceEngine::~PersistenceEngine() = default;

std::vector<Book> PersistenceEngine::getData(const std::string& rootKey, const std::string& fileName) {
    std::vector<Book> bookDatabase;
    Book book;
    QFile file(QString::fromStdString(fileName));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    QJsonValue value = object.value(QString::fromStdString(rootKey));
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array) {
        book.setCover(v.toObject().value("cover").toString().toUtf8().constData());
        book.setTitle(v.toObject().value("title").toString().toUtf8().constData());
        book.setAuthor(v.toObject().value("author").toString().toUtf8().constData());
        book.setDescription(v.toObject().value("description").toString().toUtf8().constData());
        book.setGenre(v.toObject().value("genre").toString().toUtf8().constData());
        book.setYear(v.toObject().value("year").toInt());
        bookDatabase.push_back(book);
    }
    return bookDatabase;
}

void PersistenceEngine::saveData(const std::vector<Book>& database, const std::string& rootKey, const std::string& fileName) {
    QJsonArray array;
    QFile file(QString::fromStdString(fileName));
    foreach(Book i, database) {
        QJsonObject bookObject;
        bookObject["title"] = QString::fromStdString(i.getTitle());
        bookObject["author"] = QString::fromStdString(i.getAuthor());
        bookObject["description"] = QString::fromStdString(i.getDescription());
        bookObject["genre"] = QString::fromStdString(i.getGenre());
        bookObject["cover"] = QString::fromStdString(i.getCover());
        bookObject["year"] = i.getYear();
        array.append(bookObject);
    }
    QJsonObject object;
    object[QString::fromStdString(rootKey)] = array;
    QJsonDocument saveDoc(object);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(saveDoc.toJson());
    file.close();
}
