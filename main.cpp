#pragma once
#include "UI.h"
#include "Controller.h"

#include "mainwindow.h"
#include <QApplication>

int ConsoleMain() {
    Controller databaseCtrl, clientCtrl;
    databaseCtrl.loadData("bookDatabase", "/Users/Raul/Documents/School/OOP/Audible/DataFile.json");
    clientCtrl.loadData("client1", "/Users/Raul/Documents/School/OOP/Audible/Client.json");
    UserType type = LoginScreen();
    switch (type) {
        case ADMINISTRATOR :
            AdminScreen(&databaseCtrl);
            break;
        case CLIENT :
            ClientScreen(&clientCtrl, &databaseCtrl);
            break;
        default :
            return 0;
    }
    databaseCtrl.saveData("bookDatabase", "/Users/Raul/Documents/School/OOP/Audible/DataFile.json");
    clientCtrl.saveData("client1", "/Users/Raul/Documents/School/OOP/Audible/Client.json");
    return 0;
}

int main(int argc, char*argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();
}