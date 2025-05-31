#include "menu.h"
#include <string>
#include <iostream>
#include "component.h"
#include "rwFunc.h"
#include "cstring"

using namespace std;

Menu::Menu()
{
    cout << "[INFO] - Вызван конструктор (Menu)" << endl;

}

int Menu::start_menu(const string inputFile, const string outputFile)
{
    int input;
    cout << "Выберите действие:" << endl;
    cout << "\t(1) Загрузить данные в программу из файла " << inputFile << endl;
    cout << "\t(2) Сохранить данные в файл " << outputFile << endl;
    cout << "\t(3) Распечатать данные" << endl;
    cout << "\t(4) Добавить элемент в список" << endl;
    cout << "\t(5) Удалить элемент из списка" << endl;
    cout << "\t(6) Отредактировать элемент списка" << endl;
    cout << "\t(7) Просмотреть информацию о программе" << endl;
    cout << "\t(8) Выход" << endl;
    do
    {
        cout << "Ввод: ";
        cin >> input;
        cin.ignore();
        switch (input)
        {
        case 1:
            if (elementsCount)
                cout << "\tДанные успешно загружены!" << endl;
            else if ((elementsCount = readFile(&lst, inputFile)))
                cout << "\tДанные успешно загружены!" << endl;
            break;
        case 2:
            if (!writeFile(&lst, elementsCount, outputFile)) // !writeFile потому что EXIT_SUCCESS почему-то 0, а не 1
                cout << "\tДанные успешно записаны в файл!" << endl;
            break;
        case 3:
            if (!lst.is_empty())
                lst.print_list();
            else cout << "\tДанные не были загружены, список пуст." << endl;
            break;
        case 4:
            addUserComponent();
            break;
        case 5:
            if (!lst.is_empty())
            {
                int x;
                cout << "Введите номер элемента, который хотите удалить: ";
                cin >> x;
                if ((x > 0) && (x < elementsCount + 1))
                {
                    lst.erase(x - 1);
                    cout << "Элемент был успешно удалён!" << endl;
                }
                else cout << "\tНомер должен быть от 1 до " << elementsCount << endl;
            }
            else cout << "\tДанные не были загружены, список пуст." << endl;
            break;
        case 6:
            editUserComponent();
            break;
        case 7:
            cout << "\tПрограмма подготовлена студентом:" << endl;
            cout << "\tВорончихин Иван Юрьевич, ИЦТМС 2-5" << endl;
            cout << "\tДата компиляции: " << __DATE__ << endl;
            cout << "\tВремя компиляции: " << __TIME__ << endl;
            break;
        default:
            break;
        }
    } while (1 <= input  && input <= 7);

    return EXIT_SUCCESS;
}

void Menu::addUserComponent() // Этот метод можно упростить до варианта, в котором пользователю предлагается только ввести номер для вставки
{
    int i, input;
    string boofer[8];
    char* pch = 0;
    string userString = "";
    Component* cp;

    cout << "\tВведите данные для элемента через знак точка с запятой [;]: " << endl;
    cout << "\t[название];[модель];[производитель];[цена];[видеопамять/ядра];[частота/потоки];[LHR/L2Cash];" << endl;
    cout << "Ввод данных элемента: ";
    getline(cin, userString);
    pch = strtok(userString.data(), ";"); // .data() - преобразование string в char, тк strtok() не работает с объектами класса string
    i = 0;
    while (pch != NULL)
    {
        boofer[i] = pch;
        i++;
        pch = strtok(NULL, ";");
    }
    if (boofer[0] == "Videocard")
        cp = new VideoCard(boofer[0], boofer[1], boofer[2], stoi(boofer[3]), stoi(boofer[4]), stoi(boofer[5]), stoi(boofer[6]));
    else if (boofer[0] == "Processor")
        cp = new Processor(boofer[0], boofer[1], boofer[2], stoi(boofer[3]), stoi(boofer[4]), stoi(boofer[5]), stoi(boofer[6]));
    else
    {
        cout << "\tНеверное название, можно добавить только Videocard и Processor" << endl;
        return;
    }
    cout << "\t(1) Добавить в начало списка" << endl;
    cout << "\t(2) Добавить в конец списка" << endl;
    cout << "\t(3) Определить место по номеру от 2 до " << elementsCount - 1 << endl;
    cout << "Ввод: ";
    cin >> input;
    switch(input)
    {
    case 1:
        lst.push_front(*cp);
        cout << "\tЭлемент успешно вставлен в начало списка!" << endl;
        delete cp;
        break;
    case 2:
        lst.push_back(*cp);
        cout << "\tЭлемент успешно вставлен в конец списка!" << endl;
        delete cp;
        break;
    case 3:
        int x;
        cout << "Позиция в списке, куда нужно вставить элемент: ";
        cin >> x;
        cin.ignore();
        if ((x > 1) && (x < elementsCount))
        {
            lst.insert(x - 1, *cp);
            cout << "\tЭлемент успешно вставлен в список по номеру " << x << "!" << endl;
        }
        else
        {
            cout << "\tНомер должен быть от 2 до " << elementsCount - 1 << endl;
            delete cp;
            return;
        }
        delete cp;
        break;
    default:
        delete cp;
        break;
    }
}

void Menu::editUserComponent()
{
    int i, x;
    string boofer[8];
    char* pch = 0;
    string userString = "";
    Component* cp;

    cout << "Введите номер элемента, который хотите отредактировать: ";
    cin >> x;
    cin.ignore();
    if ((x < 0) || (x > elementsCount + 1))
    {
        cout << "\tНомер должен быть от 1 до " << elementsCount << endl;
        return;
    }
    cout << "\tВведите данные для элемента через знак точка с запятой [;]: " << endl;
    cout << "\t[название];[модель];[производитель];[цена];[видеопамять/ядра];[частота/потоки];[LHR/L2Cash];" << endl;
    cout << "Ввод данных элемента: ";
    getline(cin, userString);
    pch = strtok(userString.data(), ";"); // .data() - преобразование string в char, тк strtok() не работает с объектами класса string
    i = 0;
    while (pch != NULL)
    {
        boofer[i] = pch;
        i++;
        pch = strtok(NULL, ";");
    }
    if (boofer[0] == "Videocard")
        cp = new VideoCard(boofer[0], boofer[1], boofer[2], stoi(boofer[3]), stoi(boofer[4]), stoi(boofer[5]), stoi(boofer[6]));
    else if (boofer[0] == "Processor")
        cp = new Processor(boofer[0], boofer[1], boofer[2], stoi(boofer[3]), stoi(boofer[4]), stoi(boofer[5]), stoi(boofer[6]));
    else
    {
        cout << "\tНеверное название, можно написать только Videocard и Processor" << endl;
        return;
    }
    lst.edit(x - 1, *cp);
    cout << "Элемент был успешно изменён!" << endl;
    delete cp;
}
