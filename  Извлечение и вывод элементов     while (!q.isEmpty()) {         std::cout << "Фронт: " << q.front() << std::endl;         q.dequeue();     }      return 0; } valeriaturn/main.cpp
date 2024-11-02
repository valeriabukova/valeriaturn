//
//  main.cpp
//   Извлечение и вывод элементов     while (!q.isEmpty()) {         std::cout << "Фронт: " << q.front() << std::endl;         q.dequeue();     }      return 0; } valeriaturn
//
//  Created by Valeria  Bukova on 02.11.2024.
//

#include <iostream>


template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};


template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
public:
   
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

   
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    
    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Очередь пуста. Нечего удалять.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        --size;
    }

   
    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Очередь пуста. Нет элементов.");
        }
        return head->data;
    }

  
    bool isEmpty() const {
        return size == 0;
    }

  
    size_t getSize() const {
        return size;
    }
};

int main() {
    Queue<int> q;

   
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

   
    while (!q.isEmpty()) {
        std::cout << "Фронт: " << q.front() << std::endl;
        q.dequeue();
    }

    return 0;
}

