#include "component.h"
#include <iostream>

using namespace std;




// Реализация методов класса Component
Component::Component()
{
    cout << "[INFO] - Вызван базовый конструктор (Component) " << this << endl;
    Name = "";
    Model = "";
    Manufacturer = "";
    Price = 0;
}
Component::Component(string Name, string Model, string Manufacturer, int Price)
{
    cout << "[INFO] - Вызван конструктор с параметрами (Component) " << this << endl;
    this->Name = Name;
    this->Model = Model;
    this->Manufacturer = Manufacturer;
    this->Price = Price;
}
Component::Component(const Component &other)
{
    cout << "[INFO] - Вызван конструктор копирования (Component) " << this << endl;
    Name = other.Name;
    Model = other.Model;
    Manufacturer = other.Manufacturer;
    Price = other.Price;
}
Component::~Component()
{
    cout << "[INFO] - Вызван деструктор (Component) " << this << endl;
}
void Component::operator =(const Component &other)
{
    cout << "[INFO] - Вызвана операция = (Component) " << this << endl;
    Name = other.Name;
    Model = other.Model;
    Manufacturer = other.Manufacturer;
    Price = other.Price;
}
bool Component::operator==(const Component &other)
{
    cout << "[INFO] - Вызвана операция == (Component) " << this << endl;
    return ((Name == other.Name) && (Model == other.Model) && (Manufacturer == other.Manufacturer) && (Price == other.Price));
}
ostream& operator<<(ostream &os, const Component &comp) {
    comp.print(os);  // Вызов виртуальной функции
    return os;
}
void Component::print(std::ostream& os) const
{
    os << "Name: " << Name << endl;
    os << "Model: " << Model << endl;
    os << "Manufacturer: " << Manufacturer << endl;
    os << "Price: " << Price << endl;
}
void Component::print_in_line(std::ostream& os) const
{
    os << Name << " " << Model << " " << Manufacturer << " " << Price <<  " ";
}




// Реализация методов класса VideoCard
VideoCard::VideoCard()
{
    cout << "[INFO] - Вызван базовый конструктор (VideoCard) " << this << endl;
    VideoMemory = 0;
    Frequency = 0;
    LHR = false;
}
VideoCard::VideoCard(string Name, string Model, string Manufacturer, int Price, int VideoMemory, int Frequency, bool LHR): Component(Name, Model, Manufacturer, Price)
{
    cout << "[INFO] - Вызван конструктор с параметрами (VideoCard) " << this << endl;
    this->VideoMemory = VideoMemory;
    this->Frequency = Frequency;
    this->LHR = LHR;
}
VideoCard::VideoCard(const VideoCard &other): Component()
{
    cout << "[INFO] - Вызван конструктор копирования (VideoCard) " << this << endl;
    Name = other.Name;
    Model = other.Model;
    Manufacturer = other.Manufacturer;
    Price = other.Price;
    VideoMemory = other.VideoMemory;
    Frequency = other.Frequency;
    LHR = other.LHR;
}
VideoCard::~VideoCard()
{
    cout << "[INFO] - Вызван деструктор (VideoCard) " << this << endl;
}
void VideoCard::operator =(const VideoCard &other)
{
    cout << "[INFO] - Вызван оператор = (VideoCard) "<< this << endl;
    Name = other.Name;
    Model = other.Model;
    Manufacturer = other.Manufacturer;
    Price = other.Price;
    VideoMemory = other.VideoMemory;
    Frequency = other.Frequency;
    LHR = other.LHR;
}
bool VideoCard::IsEqual(const VideoCard &other)
{
    return ((Name == other.Name) && (Model == other.Model) && (Manufacturer == other.Manufacturer) &&
            (Price == other.Price) && (VideoMemory == other.VideoMemory) && (Frequency == other.Frequency) && (LHR == other.LHR));
}
bool VideoCard::operator==(const Component &other)
{
    const VideoCard* vc = dynamic_cast<const VideoCard*>(&other);
    if (vc == nullptr) return false;
    return IsEqual(*vc);
}
Component* VideoCard::clone() const
{
    return new VideoCard(*this);
}
void VideoCard::print(ostream& os) const
{
    Component::print(os);  // Вывод полей базового класса
    os << "VideoMemory: " << VideoMemory << endl;
    os << "Frequency: " << Frequency << endl;
    os << "LHR: " << LHR << endl;
}
void VideoCard::print_in_line(ostream& os) const
{
    Component::print_in_line(os);  // Вывод полей базового класса
    os << VideoMemory << " " << Frequency << " " << LHR << " " << endl;
}



// Реализация методов класса Processor
Processor::Processor()
{
    cout << "[INFO] - Вызван базовый конструктор (Processor) " << this << endl;
    Cores = 0;
    Threads = 0;
    L2Cash = 0;
}
Processor::Processor(string Name, string Model, string Manufacturer, int Price, int Cores, int Threads, int L2Cash): Component(Name, Model, Manufacturer, Price)
{
    cout << "[INFO] - Вызван конструктор c параметрами (Processor) " << this << endl;
    this->Cores = Cores;
    this->Threads = Threads;
    this->L2Cash = L2Cash;
}
Processor::Processor(const Processor &other): Component()
{
    cout << "[INFO] - Вызван конструктор копирования (Processor) " << this << endl;
    Name = other.Name;
    Model = other.Model;
    Manufacturer = other.Manufacturer;
    Price = other.Price;
    Cores = other.Cores;
    Threads = other.Threads;
    L2Cash = other.L2Cash;
}
Processor::~Processor()
{
    cout << "[INFO] - Вызван деструктор (Processor) " << this << endl;
}
void Processor::operator =(const Processor &other)
{
    cout << "[INFO] - Вызван оператор = (Processor) " << this << endl;
    Name = other.Name;
    Model = other.Model;
    Manufacturer = other.Manufacturer;
    Price = other.Price;
    Cores = other.Cores;
    Threads = other.Threads;
    L2Cash = other.L2Cash;
}
bool Processor::IsEqual(const Processor &other)
{
    return ((Name == other.Name) && (Model == other.Model) && (Manufacturer == other.Manufacturer) &&
            (Price == other.Price) && (Cores == other.Cores) && (Threads == other.Threads) && (L2Cash == other.L2Cash));
}
bool Processor::operator==(const Component &other)
{
    const Processor* proc = dynamic_cast<const Processor*>(&other);
    if (proc == nullptr) return false;
    return IsEqual(*proc);
}
Component* Processor::clone() const
{
    return new Processor(*this);
}
void Processor::print(ostream& os) const {
    Component::print(os);  // Вывод полей базового класса
    os << "Cores: " << Cores << endl;
    os << "Threads: " << Threads << endl;
    os << "L2Cash: " << L2Cash << endl;
}
void Processor::print_in_line(ostream& os) const
{
    Component::print_in_line(os);  // Вывод полей базового класса
    os << Cores << " " << Threads << " " << L2Cash << " " << endl;
}



// Методы класса LinkedList

Node* LinkedList::push_front(Component &comp)
{
    Node* ptr = new Node(comp);
    ptr->next = head;
    if (head != NULL)
        head->prev = ptr;
    if (tail == NULL)
        tail = ptr;

    head = ptr;
    return ptr;
}
Node* LinkedList::push_back(Component &comp)
{
    Node* ptr = new Node(comp);
    ptr->prev = tail;
    if (tail != NULL)
        tail->next = ptr;
    if (head == NULL)
        head = ptr;

    tail = ptr;

    return ptr;
}
void LinkedList::pop_front()
{
    if (head == NULL) return;

    Node *ptr = head->next;
    if (ptr != NULL)
        ptr->prev = NULL;
    else
        tail = NULL;

    delete head;
    head = ptr;
}
void LinkedList::pop_back()
{
    if (tail == NULL) return;

    Node *ptr = tail->prev;
    if (ptr != NULL)
        ptr->next = NULL;
    else
        head = NULL;

    delete tail;
    tail = ptr;
}
Node* LinkedList::get_at(int index)
{
    Node* ptr = head;
    int n = 0;
    while (n != index)
    {
        if (ptr == NULL)
            return NULL;
        ptr = ptr->next;
        n++;
    }
    return ptr;
}
Node* LinkedList::operator [](int index)
{
    return get_at(index);
}
Node* LinkedList::insert(int index, Component &comp)
{
    Node* right = get_at(index);
    if (right == NULL)
        return push_back(comp);
    Node* left = right->prev;
    if (left == NULL)
        return push_front(comp);

    Node* ptr = new Node(comp);

    ptr->next = right;
    ptr->prev = left;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
}
void LinkedList::erase(int index)
{
    Node* ptr = get_at(index);
    if (ptr == NULL)
        return;

    if (ptr->prev == NULL)
    {
        pop_front();
        return;
    }

    if (ptr->next == NULL)
    {
        pop_back();
        return;
    }

    Node* left = ptr->prev;
    Node* right = ptr->next;
    left->next = right;
    right->prev = left;

    delete ptr;
}
int LinkedList::find(const Component &other)
{
    int index = 0;
    Node* ptr = head;
    while (ptr != nullptr)
    {
        if (*(ptr->component) == other)
        {
            return index;
        }
        ptr = ptr->next;
        index++;
    }
    return -1;
}
void LinkedList::edit(int index, const Component &other)
{
    Node* ptr = this->get_at(index);
    *(ptr->component) = other;
}
void LinkedList::print_list() {
    Node* ptr = head;
    int count = 1;
    while(ptr != nullptr) {
        cout << "Компонент " << count++ << ":\n";
        if (ptr->component) {
            cout << *ptr->component << endl;
        }
        ptr = ptr->next;
    }
}
bool LinkedList::is_empty()
{
    return head == nullptr;
}
void LinkedList::clear()
{
    while (head != NULL)
        pop_front();
}
