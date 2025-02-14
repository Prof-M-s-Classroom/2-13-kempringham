#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    ~LinkedList() {
        Node<T> *current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }
    Node<T>* get(int index) {
        if (index < 0 || index>=length)
            return nullptr;
        Node<T>* temp=head;
        for (int i = 0; i < index; i++) {
            temp=temp->next;
        }
        return temp;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index < 0 || index >= length) { // no need to delete an index of the LL that does not exist
            cout << "Index is invalid" << endl;
            return;
        }
        if (index == 0) { // index 0 is the first index of the LL, so delete first
            delfirst();
        }
        if (index == length - 1) { // index length - 1 is the last index of the LL, so delete last
            dellast();
        }
        else {
            Node<T> *temp = get(index - 1);
            Node<T> *newNode = temp->next;
            temp->next = newNode->next;
            delete newNode;
            length--;
        }
    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        if (index < 0 || index > length) { // can't add at index that is not included in LL
            cout << "Index is invalid" << endl;
            return;
        }
        if (index == 0) { // index zero is the head
            addhead(value);
        }
        if (index == length) { // index length is the one after last index, so adding at tail
            add(value);
        }
        else {
            Node<T> *newNode = new Node<T>(value);
            Node<T> *temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return;
        }
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* prev;
        Node<T>* curr;
        Node<T>* next;
        prev = NULL;
        curr = head;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    student *s4 = new student("D", 23);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();
    //ll->dellast();
    //ll->print();
    ll->reverselist();
    ll->print();
    ll->insert(2,s4);
    ll->print();
    //ll->deleteNode(2);
    //ll->print();
}