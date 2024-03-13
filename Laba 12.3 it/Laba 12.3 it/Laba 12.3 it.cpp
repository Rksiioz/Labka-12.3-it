#include <iostream>

using namespace std;

typedef int Info;
struct Elem {
    int data;
    Elem* prev;
    Elem* next;
    Elem* link;
    Info info;
};

Elem* createNode(int data) {
    Elem* newNode = new Elem;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    newNode->link = nullptr;
    return newNode;
}

void addToEnd(Elem*& head, int data) {
    Elem* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Elem* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(Elem* head) {
    Elem* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void freeMemory(Elem*& head) {
    Elem* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Input(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void duplicateElements(Elem*& head, Info value) {
    Elem* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            Elem* newNode = createNode(current->data);
            newNode->info = value;
            newNode->next = current->next;
            if (newNode->next != nullptr) {
                newNode->next->prev = newNode;
            }
            newNode->prev = current;
            current->next = newNode;
            current = newNode->next;
        }
        else {
            current = current->next;
        }
    }
}

int main() {
    Elem* myList = nullptr;
    Elem* first = NULL,
        * last = NULL;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value of element " << i + 1 << ": ";
        cin >> value;
        addToEnd(myList, value);
    }

    std::cout << "List: ";
    printList(myList);

    int duplicateValue;
    cout << "Enter value to duplicate: ";
    cin >> duplicateValue;

    duplicateElements(myList, duplicateValue);

    std::cout << "List after duplicating elements: ";
    printList(myList);

    freeMemory(myList);

    return 0;
}
