#include <fstream>
#include "rwFunc.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;


int readFile(LinkedList *lst, string file)
{
    unsigned short int i = 0;
    unsigned short int elementCount = 0;
    string boofer[8];
    string line;
    char* pch = 0;


    ifstream in;
    in.open(file);
    if (in.is_open())
    {
        getline(in, line);
        elementCount = stoi(line);
        while (getline(in, line))
        {
            pch = strtok(line.data(), ";"); // .data() - преобразование string в char, тк strtok() не работает с объектами класса string
            i = 0;
            while (pch != NULL)
            {
                boofer[i] = pch;
                i++;
                pch = strtok(NULL, ";");
            }
            if (boofer[0] == "Videocard")
            {
                VideoCard vc(boofer[0], boofer[1], boofer[2], stoi(boofer[3]), stoi(boofer[4]), stoi(boofer[5]), stoi(boofer[6]));
                lst->push_back(vc);
            }
            else if (boofer[0] == "Processor")
            {
                Processor pc(boofer[0], boofer[1], boofer[2], stoi(boofer[3]), stoi(boofer[4]), stoi(boofer[5]), stoi(boofer[6]));
                lst->push_back(pc);
            }
        }
    }
    in.close();

    return elementCount;
}

int writeFile(Component *comp, int elementCount, std::string file)
{
    ofstream out; // Поток для записи
    out.open(file); // Открытие файла
    if (!out)
    {
        cerr << "\tФайл не открыт!" << endl;
        return EXIT_FAILURE;
    }
    if (!elementCount)
    {
        cerr << "\tДанные не загружены в программу. Нечего записывать в файл." << endl;
        return EXIT_FAILURE;
    }

    out << setiosflags(ios::left) << std::setw(4) << "Id";
    out << setiosflags(ios::left) << std::setw(9) << "Contract";
    out << setiosflags(ios::left) << std::setw(25) << "Name";
    out << setiosflags(ios::left) << std::setw(25) << "Type of work";
    out << setiosflags(ios::left) << std::setw(6) << "Weeks";
    out << setiosflags(ios::left) << std::setw(12) << "Price" << endl;

    for(int i = 0; i < elementCount; i++)
    {

    }
    out.close();

    return EXIT_SUCCESS;
}
