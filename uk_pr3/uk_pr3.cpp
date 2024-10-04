
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value) 
    {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = tail = node; 
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void push_back(int value)
    {
        Node* node = new Node(value);
        if (tail == nullptr) {
            tail = head = node;
        }
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    void pop_back()
    {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
    }
    void pop_front()
    {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    void display()
    {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
       
    }
    void sort() {
       
        Node* left = head;
        Node* right = head->next;
        bool pr;

        Node* temp = new Node(0);

        if (left->next) {
            do {
                pr = false;
                while (right != nullptr)
                {
                    if (left->data > right->data)
                    {
                        temp->data = left->data;
                        left->data = right->data;
                        right->data = temp->data;
                        pr = true;
                    }
                    left = left->next;
                    right = left->next;
                }
            } while (pr);
        }delete temp;

    }
    void remove_duplicate()
    {
        Node* temp = head;

        while (temp != nullptr) {
            Node* num = temp;
            while (temp->next != nullptr) {
                if (temp->next->data == num->data) {
                    temp->next = temp->next->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = temp;
                    }
                }
                else {
                    temp = temp->next;
                }
            }
            temp = num->next;
        }
    }

};

int main()
{
    DoublyLinkedList a;
    setlocale(0, "rus");
    int proverka;
    do {
        std::cout << "\n1 - Добавить элемент в начало.\n2 - Добавить элемент в конец.\n3 - Удалить элемент с начала.\n4 - Удалить элемент с конца.\n5 - Отобразить список.\n6 - Сортировать список\n7 - Удалить дубликаты.\n8 - Выйти.\n";
        std::cin >> proverka;

        switch (proverka)
        {
        case 1:
            int value;
            std::cout << "Введите значение: ";
            std::cin >> value;
            a.push_front(value);
            break;
        case 2:
            std::cout << "Введите значение: ";
            std::cin >> value;
            a.push_back(value);
            break;
        case 3:
            a.pop_front();
            break;
        case 4:
            a.pop_back();
            break;
        case 5:
            a.display();
            break;
        case 6:
            a.sort();
            break;
        case 7:
            a.remove_duplicate();
            break;
        case 8:
            std::cout << "Выход\n";
            exit(0);
            break;
        default:
            std::cout << "Попробуйте снова.\n";
            break;
        }
    } while (proverka != 8);

    return 0;
}

