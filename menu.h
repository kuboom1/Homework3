#ifndef MENU_H
#define MENU_H

#include <string>
#include "component.h"

class Menu
{
private:
    LinkedList lst;
    int elementsCount = 0;
public:
    Menu();

    int GetElementsCount() {return elementsCount;}

    int start_menu(const std::string inputFile, const std::string outputFile);
    void addUserComponent();
    void editUserComponent();

};

#endif // MENU_H
