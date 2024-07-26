/*You are working for a computer hardware store and you want to write a program that handles
their price list. You are keeping your data in a dynamically allocated array of structures:

struct Part {
 string partNo;
 string partName;
 double price;
};

Part* parts = new Part[n];
Your program starts by printing a menu (a separate function) in the middle of the screen:
 1. Add a new part
 2. Find the price for a particular part
 3. Exit
If the choice returned to main() is 1), you call another function that inputs a new part and
appends it to the array. If the choice is 2) you call another function that asks the user for a
part number, finds that part in the array, and displays the rest of the information (part name
and price). If the part number entered is not in the array, then the program displays an
appropriate message. This keeps repeating until the user select choice 3).
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Part {       //Global Structre
    string partNo;
    string partName;
    double price;
};

//Function that displays the menu and return the choice entered by the user

int menu() {
    int choice;
    cout << "                        WELCOME TO FUTURE SHOP " << endl << "                                Menu" << endl << endl;
    cout <<"Enter your choice (1 - 2 - 3): " << endl << "1. Add a new part" << endl << "2. Find the price for a particular part" << endl << "3. Exit" << endl;
    cin >> choice;
    return choice;
}
//Function then gets info for a new part from the user and appends it to the array (part: pointer to an array of parts)(size: the size of the array of Parts)

void newpart(Part* parts, int& size) {
    cout << "Enter the part name: ";
    cin >> parts[size].partName; 
    cout << "Enter the part model: ";
    cin >> parts[size].partNo;
    cout << "Enter the part price: ";
    cin >> parts[size].price;
    size++;
}

//Function to ask the user for a part np. and finds the part in the array and return its index. returns -1 if the part is not found

int find(Part* parts, int size) {
    string input;
    cout << "Enter the part no. to find its info: ";
    cin >> input;

    for (int i = 0; i < size; i++) {
        if (parts[i].partNo == input)
        {
            return i;
        }
    }
    return -1;
}

//Function to print info relevant to a particular part
void print(Part* parts, int pos) {
    cout << "Part Number: " << parts[pos].partNo << endl;
    cout << "Part Name: " << parts[pos].partName << endl;
    cout << "Part Price: " << parts[pos].price << endl;
}

int main()
{
    int n = 10;
    Part* parts = new Part[n]; 
    int size = 0;
    int choice;
    do {
        choice = menu();
        switch (choice) {
        case 1: newpart(parts, size); break;
        case 2: {
            int pos = find(parts, size);
            if (pos == -1)cout << "not found !\n" << endl;
            else print(parts, pos); break;
        }
        default: break;
        }
    } while (choice != 3);
}

