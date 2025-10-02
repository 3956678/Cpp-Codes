#include<iostream>
using namespace std;
struct node {
    int val;
    node* next;
    node* bef;
};
node* head = NULL;
void insertatbeginning(int v) {
    node* t = new node();
    t->val = v;
    if (head == NULL) {
        t->next = t;
        t->bef = t;
        head = t;
    } else {
        node* tail = head;
        while (tail->next != head)
            tail = tail->next;

        t->next = head;
        t->bef = tail;
        head->bef = t;
        tail->next = t;
        head = t;
    }
}
void insertatend(int v) {
    if (head == NULL) {
        insertatbeginning(v);
        return;
    }
    node* t = new node();
    t->val = v;
    node* tail = head;
    while (tail->next != head)
        tail = tail->next;
    t->next = head;
    t->bef = tail;
    tail->next = t;
    head->bef = t;
}
void insertati(int i, int v) {
    if (i <= 1 || head == NULL) {
        insertatbeginning(v);
        return;
    }
    node* temp = head;
    int pos = 1;
    do {
        if (pos == i - 1) {
            node* t = new node();
            t->val = v;
            t->next = temp->next;
            t->bef = temp;
            temp->next->bef = t;
            temp->next = t;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    insertatend(v);
}
void deletion(int i) {
    if (head == NULL) {
        cout << "There is no element to delete.\n";
        return;
    }
    if (i == 1) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        node* tail = head;
        while (tail->next != head)
            tail = tail->next;
        node* temp = head;
        head = head->next;
        head->bef = tail;
        tail->next = head;
        delete temp;
        return;
    }
    node* temp = head;
    int pos = 1;
    do {
        if (pos == i) {
            temp->bef->next = temp->next;
            temp->next->bef = temp->bef;
            delete temp;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Invalid position.\n";
}
void displayfromfront() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node* t = head;
    cout << "The values are: ";
    do {
        cout << t->val << " ";
        t = t->next;
    } while (t != head);
    cout << "\n";
}
void displayfromback() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node* t = head;
    while (t->next != head)
        t = t->next;

    node* start = t;
    cout << "The values from back are: ";
    do {
        cout << t->val << " ";
        t = t->bef;
    } while (t != start);
    cout << "\n";
}
int main() {
    int choice, value, pos;
    do {
        cout << "\nMenu:\n";
        cout << "1) Insert at beginning\n";
        cout << "2) Display from front\n";
        cout << "3) Insert at end\n";
        cout << "4) Insert at specific position\n";
        cout << "5) Delete at specific index\n";
        cout << "6) Display from back\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertatbeginning(value);
                break;
            case 2:
                displayfromfront();
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                insertatend(value);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> pos;
                insertati(pos, value);
                break;
            case 5:
                cout << "Enter index to delete: ";
                cin >> pos;
                deletion(pos);
                break;
            case 6:
                displayfromback();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);
    cout << "Final list from back:\n";
    displayfromback();
    return 0;
}
