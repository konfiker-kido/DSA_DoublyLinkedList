#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};
node *head = NULL;
int count = 0;
void insertAtEnd()
{
    node *val, *temp;
    int x;
    cout << "\nEnter value to add in List: ";
    cin >> x;

    val = new node();
    val->data = x;
    if (head == NULL)
    {
        head = val;
        head->next = NULL;
        head->prev = NULL;
        count++;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        val->prev = temp;
        temp->next = val;
        val->next = NULL;
        count++;
    }
}
void insertAtHead()
{
    node *val;
    int x;
    cout << "\nEnter value to add in List: ";
    cin >> x;
    val = new node();
    val->data = x;
    if (head == NULL)
    {
        head = val;
        head->next = NULL;
        head->prev = NULL;
        count++;
    }
    else
    {
        val->next = head;
        val->prev = NULL;
        head = val;
        count++;
    }
}
void insertAtPos()
{
    node *temp = head, *val, *q = head->next;
    int x, pos;

    cout << "\nEnter position: ";
    cin >> pos;

    val = new node();

    int i = 1;
    if (pos == 1)
        cout << "\nSelect specific function for this";
    else if (pos == count)
        cout << "\nSelect specific function for this";

    else
    {
        cout << "\nEnter value to add in List";
        cin >> x;
        val->data = x;
        while (i < pos - 1)
        {
            temp = temp->next;
            q = q->next;
            i++;
        }

        val->prev = temp;
        val->next = q;
        temp->next = val;
        q->prev = val;
        count++;
        /*
         node *container = temp;
         val->prev = temp;
         val = temp->next;
         temp->next->prev = val;
         container->next = val;    */
    }
}
void deletionAtHead()
{
    node *temp = head;
    if (head == NULL)
        cout << "List is underFlow";
    else
    {
        temp->next->prev = NULL;
        head = temp->next;
        delete temp;
        cout << "\nElement deleted from Head !";
        count--;
    }
}
void deletionAtEnd()
{
    node *temp = head, *temp1;
    if (head == NULL)
        cout << "List is UnderFlow";
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp1 = temp->next->next;
        temp->next = NULL;
        delete temp1;
        count--;
        cout << "\nElement deleted from the End";
    }
}
void deleteAtPos()
{
    int pos;
    node *p = head, *q = head->next;
    cout << "\nEnter Position: ";
    if (pos == 1)
        deletionAtHead();
    else if (pos == count)
        deletionAtEnd();
    else
    {
        int i = 1;
        while (i != pos - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        q->next->prev = p;
        delete q;
        cout << "\nElement Deleted Successfully from " << pos << " postion";
        count--;
    }
}
void display()
{
    node *temp;
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        temp = head;
        cout << "\nNULL ";
        while (temp != 0)
        {
            cout << "<- " << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
}
int main()
{
    int key;
    do
    {
        cout << "\n1.InsertAtHead     2.InsertAtEnd    3.InsertAtPos     4.Display ";
        cout << "\n5.DeleteAtEnd     6.DeleteAtPos    7.DeleteAtHead     8.Count Elements  9.Exit ";
        cout << "\n--------- Choose options to perform task accoradingly   --------" << endl;
        cin >> key;
        switch (key)
        {
        case 1:
            insertAtHead();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPos();
            break;
        case 4:
            display();
            break;
        case 5:
            deletionAtEnd();
            break;
        case 6:
            deleteAtPos();
            break;
        case 7:
            deletionAtHead();
            break;
        case 8:
            cout << "\nThere are " << count << " Element in this List";
            break;
        case 9:
            return 9;

        default:
            cout << "\nChoose valid option";
        }
    } while (9);
    return 0;
}