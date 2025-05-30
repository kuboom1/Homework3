#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>


class Component
{
protected:
    std::string Name;
    std::string Model;
    std::string Manufacturer;
    int Price;

public:
    Component();
    Component(std::string Name, std::string Model, std::string Manufacturer, int Price);
    Component(const Component &);
    virtual ~Component();

    std::string GetName() const {return Name;}
    void SetName(std::string Name) {this->Name = Name;}
    std::string GetModel() const {return Model;}
    void SetModel(std::string Model) {this->Model = Model;}
    std::string GetManufacturer() const {return Manufacturer;}
    void SetManufacturer(std::string Manufacturer) {this->Manufacturer = Manufacturer;}
    int GetPrice() const {return Price;}
    void SetPrice(int Price) {this->Price = Price;}

    void operator=(const Component &other);
    virtual bool operator==(const Component &other);
    virtual Component* clone() const = 0;
    friend std::ostream& operator<<(std::ostream &os, const Component &comp);
};


class VideoCard: public Component
{
private:
    int VideoMemory;
    int Frequency;
    bool LHR;

public:
    VideoCard();
    VideoCard(std::string Name, std::string Model, std::string Manufacturer, int Price, int VideoMemory, int Frequency, bool LHR);
    VideoCard(const VideoCard &);
    ~VideoCard();

    int GetVideoMemory() const {return VideoMemory;}
    void SetVideoMemory(int VideoMemory) {this->VideoMemory = VideoMemory;}
    int GetFrequency() const {return Frequency;}
    void SetFrequency(int Frequency) {this->Frequency = Frequency;}
    bool GetLHR() const {return LHR;}
    void SetLHR(bool LHR) {this->LHR = LHR;}

    void operator=(const VideoCard &);
    virtual bool operator==(const Component &other) override;
    bool IsEqual(const VideoCard &other);
    Component* clone() const override;
    friend std::ostream& operator<<(std::ostream &os, VideoCard &vc);
};


class Processor: public Component
{
private:
    int Cores;
    int Threads;
    int L2Cash;

public:
    Processor();
    Processor(std::string Name, std::string Model, std::string Manufacturer, int Price, int Cores, int Threads, int L2Cash);
    Processor(const Processor &);
    ~Processor();

    int GetCores() const {return Cores;}
    void SetCores(int Cores) {this->Cores = Cores;}
    int GetThreads() const {return Threads;}
    void SetThreads(int Threads) {this->Threads = Threads;}
    int GetL2Cash() const {return L2Cash;}
    void SetL2Cash(int L2Cash) {this->L2Cash = L2Cash;}

    void operator=(const Processor &);
    virtual bool operator==(const Component &other) override;
    bool IsEqual(const Processor &other);
    Component* clone() const override;
    friend std::ostream& operator<<(std::ostream &os, Processor &pc);
};


class Node
{
public:
    Component *component;
    Node *prev, *next;

    Node(Component &comp)
    {
        this->component = comp.clone();
        this->prev = this->next = nullptr;
    }

    ~Node()
    {
        delete component;
    }

private:
    Node(const Node &) = delete;
};


class LinkedList
{
public:
    Node *head, *tail;

    LinkedList()
    {
        head = tail = NULL;
    }

    ~LinkedList()
    {
        while (head != NULL)
            pop_front();
    }

    Node* push_front(Component &comp);
    Node* push_back(Component &comp);
    void pop_front();
    void pop_back();
    Node* get_at(int index);
    Node* operator [](int index);
    Node* insert(int index, Component &comp);
    void erase(int index);
    int find(const Component &other);
    void edit(int index, const Component &other); //TODO other будет создаваться пользователем в меню
    void print_list();
    bool is_empty();
    void clear();
};



#endif // COMPONENT_H
