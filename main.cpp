#include <iostream>
#include "component.h"
#include "rwFunc.h"

using namespace std;

int main()
{
    system("chcp 65001");
    system("cls");

    LinkedList lst;
    int COUNT;
    const string FILE = "data.db";
    COUNT = readFile(&lst, FILE);
    lst.print_list();
    writeFile(&lst, COUNT, "output.txt");
    return 0;
}
