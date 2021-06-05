#pragma once
#include <string>

struct  Node {
    char str; // City
    Node* pnext;
    Node(char str, Node* pnext = nullptr) {
        this->str = str;
        this->pnext = pnext;
    }
};


class Set {
public:
    Set();
    ~Set();
    void Pop_Front();
    void Clear();
    void Insert(char str);
    size_t GetSize();
    bool IsEmpty();    
    bool Find(char str);
    char operator[] (size_t index);
    void Erase(size_t index);
private:   
    size_t Size;
    Node* head;
};


Set::Set() {
    Size = 0;
    head = nullptr;
}

Set::~Set() {
    Clear();
}

bool Set::Find(char str) {
    if (head == nullptr) return false;
    else {        
        Node* cur = head;
        while (cur != nullptr) {
            if (str == cur->str) return true;
            cur = cur->pnext;
        }
        return false;
    }
}

void Set::Pop_Front()
{
    Node* cur = head;
    head = head->pnext;
    delete cur;
    Size--;
}




void Set::Clear()
{
    while (Size > 0) {
        Pop_Front();
    }
}




void Set::Insert(char str)
{
    if (!Find(str)) {
        if (head == nullptr) {
            head = new Node(str);
        }
        else {
            Node* cur = head;
            while (cur->pnext != nullptr) {
                cur = cur->pnext;
            }
            cur->pnext = new Node(str);
        }
        Size++;
        //Sort();
    }

}


size_t Set::GetSize()
{
    return Size;
}


char Set::operator[](size_t index)
{
    int count = 0;
    Node* cur = head;
    while (cur != nullptr) {
        if (count == index) {
            return cur->str;
        } cur = cur->pnext;
        count++;
    }
}


bool Set::IsEmpty() {

    return Size == 0;
}



void Set::Erase(size_t index) {
    if (index > Size - 1) {
        throw std::out_of_range("Wrong index\n");
    }
    if (index == 0) {
        Pop_Front();
    }
    else {
        Node* cur = head;
        size_t i = 0;
        while (cur != nullptr) {
            if (index == i - 1) {
                Node* tmp = cur->pnext;
                cur->pnext = tmp->pnext;
                delete tmp;
                break;
            }
            i++;
            cur = cur->pnext;
        }
    }
}

