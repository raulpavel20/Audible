#pragma once
#ifndef AUDIBLE_UI_H
#define AUDIBLE_UI_H

#include "Controller.h"

enum UserType {
    ADMINISTRATOR,
    CLIENT,
    UNKNOWN
};

/***
 * Shows the options for user types
 */
UserType LoginScreen();

void adminOptions();
void AdminScreen(Controller *ctrl);

void clientOptions();
void ClientScreen(Controller *clientCtrl, Controller *databaseCtrl);

bool deleteBook(Controller *ctrl);
void browseDatabase(Controller *clientCtrl, Controller *databaseCtrl);
bool updateBook(Controller *databaseCtrl);
bool addBook(Controller *ctrl);

#endif //AUDIBLE_UI_H
