#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"
using namespace std;

void menu()
{
    cout << "\n\n\t1.   Integer link list\n";
    cout << "\t2.   Float link list\n";
    cout << "\t3.   Char link list\n";
    cout << "\t4.   String link list\n";
    cout << "\t9.   To quit \n";
    cout << "Enter your choice  ";
}

int main()
{
    int choice;

    LinkedList<int> list0;
    LinkedList<float> list1;
    LinkedList<char> list2;
    LinkedList<string> list3;
    do
    {
        menu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                list0.appendNode(2);
                list0.appendNode(4);
                list0.appendNode(6);
                cout << "Here are the initial values:\n";
                list0.displayList();
                cout << endl;

                cout << "Now inserting the value 5.\n";
                list0.insertNode(5);
                cout << "Here are the values after inserting 5:\n";
                list0.displayList();
                cout << endl;

                cout << "Now deleting the value 6.\n";
                list0.deleteNode(6);
                cout << "Here are the values after deleting 6:\n";
                list0.displayList();
                cout << endl;
                break;
            case 2:
                list1.appendNode(2.5);
                list1.appendNode(4.9);
                list1.appendNode(6.8);
                cout << "Here are the initial values:\n";
                list1.displayList();
                cout << endl;

                cout << "Now inserting the value 5.\n";
                list1.insertNode(5.0);
                cout << "Here are the values after inserting 5:\n";
                list1.displayList();
                cout << endl;

                cout << "Now deleting the value 6.8.\n";
                list1.deleteNode(6.8);
                cout << "Here are the values after deleting 6.8:\n";
                list1.displayList();
                cout << endl;
                break;
            case 3:
                list2.appendNode('b');
                list2.appendNode('f');
                list2.appendNode('k');
                cout << "Here are the initial values:\n";
                list2.displayList();
                cout << endl;

                cout << "Now inserting the value m.\n";
                list2.insertNode('m');
                cout << "Here are the values after inserting 'm':\n";
                list2.displayList();
                cout << endl;

                cout << "Now deleting the value k.\n";
                list2.deleteNode('k');
                cout << "Here are the values after deleting 'k':\n";
                list2.displayList();
                cout << endl;
                break;
            case 4:
                list3.appendNode("Jane Doe");
                list3.appendNode("Mary Garza");
                list3.appendNode("Jane Smith");
                cout << "Here are the initial values:\n";
                list3.displayList();
                cout << endl;

                cout <<"Now inserting the value 'Bobby Luis'.\n";
                list3.insertNode("Bobby Luis");
                cout << "Here are the values after inserting 'Bobby Luis':\n";
                list3.displayList();
                cout << endl;
                
                cout << "Now deleting the value 'Mary Garza'.\n";
                list3.deleteNode("Mary Garza");
                cout << "Here are the values after deleting 'Mary Garza':\n";
                list3.displayList();
                cout << endl;
                break;
        }
    }
    while (choice != 9);
    return 0;
}