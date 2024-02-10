#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    string phone_number;
    Node* prev;
    Node* next;

    Node(string n, string num) : name(n), phone_number(num), prev(nullptr), next(nullptr) {}
};

class PhoneDirectory {
private:
    Node* head;
    Node* tail;

public:
    PhoneDirectory() : head(nullptr), tail(nullptr) {}

    void addContact(string name, string phone_number) {
        Node* new_node = new Node(name, phone_number);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void deleteContact(string name) {
        Node* current = head;
        while (current) {
            if (current->name == name) {
                if (current == head) {
                    head = current->next;
                    if (head)
                        head->prev = nullptr;
                    else
                        tail = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Contact " << name << " deleted." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found." << endl;
    }

    void displayContacts() {
        Node* current = head;
        cout << "Phone Directory:" << endl;
        while (current) {
            cout << "Name: " << current->name << ", Phone Number: " << current->phone_number << endl;
            current = current->next;
        }
    }

    ~PhoneDirectory() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    PhoneDirectory phoneDir;
    phoneDir.addContact("Aman", "9852297226");
    phoneDir.addContact("Akash", "9852369741");
    phoneDir.addContact("Arun", "7852146985");
    phoneDir.addContact("Animesh", "8523697412");
    
    

    phoneDir.displayContacts();
    cout<<"Enter Name to delete the contact : ";
    string name;
    cin>>name;
    cout << "\nDeleting " <<name<< " from the directory..." << endl;
    phoneDir.deleteContact(name);
    cout << "\nAfter deletion:" << endl;
    phoneDir.displayContacts();

    return 0;
}
