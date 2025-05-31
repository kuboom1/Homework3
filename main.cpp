#include "menu.h"
#include <fstream>
using namespace std;

int main()
{
    system("chcp 65001");
    system("cls");

    // ofstream logs;          // Поток для записи логов в файл
    // logs.open("logs.txt");  // Окрываем файл для записи

    const string inputFile = "data.db";
    const string outputFile = "output.txt";
    Menu menu;
    menu.start_menu(inputFile, outputFile);

    // logs.close();
    return 0;
}
