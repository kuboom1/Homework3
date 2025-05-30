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
    os << "Name: " << comp.Name << endl;
    os << "Model: " << comp.Model << endl;
    os << "Manufacturer: " << comp.Manufacturer << endl;
    os << "Price: " << comp.Price << endl;
    return os;
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
ostream& operator<<(ostream &os, const VideoCard &vc) {
    os << static_cast<const Component&>(vc);
    os << "VideoMemory: " << vc.GetVideoMemory() << endl;
    os << "Frequency: " << vc.GetFrequency() << endl;
    os << "LHR: " << vc.GetLHR() << endl;
    return os;
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
ostream& operator<<(ostream &os, const Processor &pc) {
    os << static_cast<const Component&>(pc);
    os << "Cores: " << pc.GetCores() << endl;
    os << "Threads: " << pc.GetThreads() << endl;
    os << "L2Cash: " << pc.GetL2Cash() << endl;
    return os;
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
