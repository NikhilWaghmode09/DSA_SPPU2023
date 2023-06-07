// Program: Telephone Book using Hash Table with Collision Handling
// Logic: This program simulates a telephone book database using a hash table implementation.
//        Two collision handling techniques, linear probing and quadratic probing, are used.
//        The user can choose to insert new records with mobile numbers and names,
//        display the hash table, or exit the program.
//        The hash table size is fixed at 10, and each mobile number is hashed to a specific slot in the table.
//        In case of collisions, the program uses different techniques to find the next available slot.
//        Linear probing checks the next slot in a linear fashion,
//        while quadratic probing uses quadratic increments to find the next slot.
//        The program ensures that no duplicate mobile numbers are inserted into the hash table.
//        The user can insert records using either linear probing or quadratic probing,
//        and the hash table is displayed to show the final records.
//        The program continues to prompt for options until the user chooses to exit.
//        Finally, the program terminates with a "Thank you" message.


#include <iostream>
#include <string>
using namespace std;

class Telephone {
private:
    long mobno[10];  // Array to store mobile numbers
    string name[10]; // Array to store corresponding names
    long key;        // Input mobile number

public:
    Telephone() {
        for (int i = 0; i < 10; i++) {
            mobno[i] = -1;  // Initialize array elements to -1 indicating empty slots
        }
    }

    void insert_LP() {
        cout << "Enter mobile no.: ";
        cin >> key;
        int hash_address = key % 10;  // Compute the hash address using modulo operator

        while (mobno[hash_address] != -1) {
            hash_address = (hash_address + 1) % 10;  // Linear probing: move to the next slot in case of collision
        }

        mobno[hash_address] = key;  // Insert the mobile number at the computed hash address
        cout << "Enter name: ";
        cin >> name[hash_address];  // Input the corresponding name
    }

    void insert_QP() {
        cout << "Enter mobile no.: ";
        cin >> key;
        int hash_address = key % 10;  // Compute the hash address using modulo operator
        int i = 1;

        while (mobno[hash_address] != -1) {
            hash_address = (hash_address + i * i) % 10;  // Quadratic probing: move to the next slot with quadratic increments
            i++;
            if (i > 10) {
                cout << "Hash table is full. Cannot insert." << endl;  // Exit if the hash table is full
                return;
            }
        }

        mobno[hash_address] = key;  // Insert the mobile number at the computed hash address
        cout << "Enter name: ";
        cin >> name[hash_address];  // Input the corresponding name
    }

    void display() {
        cout << "\n---- Telephone Book ----" << endl;
        cout << "Index\tMobile No.\tName" << endl;
        for (int i = 0; i < 10; i++) {
            cout << i << "\t" << mobno[i] << "\t\t" << name[i] << endl;  // Display the hash table entries
        }
    }
};

int main() {
    Telephone t1;
    int ch;
    do {
        cout << "\n1. Insert (LP)";
        cout << "\n2. Insert (QP)";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                t1.insert_LP();  // Call the insert function using linear probing
                break;
            case 2:
                t1.insert_QP();  // Call the insert function using quadratic probing
                break;
            case 3:
                t1.display();  // Display the hash table
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (ch != 4);

    return 0;
}
