#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    string name;
    Node *head;
};
struct Node *head;

void InsertatHead(Node **head, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head != NULL)
    {
        temp->next = *head;
    }
    *head = temp;
}

void InsertAtEnd(Node **head, int x)
{
    Node *temp = new Node();
    temp->data = x;
    Node *last = *head;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    return;
}

void Print(Node *head)
{
    // Node* temp=head;
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

void checkForDups(Node *head)
{
    map<int, bool> checkMap; //create a checkMap
    Node *previous = NULL;   //create a Node pointer
    while (head != NULL)     //goto till last of the list
    {
        if (checkMap[head->data] == true) //if data is already present
        {
            previous->next = head->next; // where the head is pointing point to that data
            // and skip the present data thus deleting it from the list
        }
        else
        {
            checkMap[head->data] = true; //add bool is true
            previous = head; //store head in previous
        }
        head = head->next; //shift head to next
    }
}

int main()
{
    head = NULL; //since this is already pointer to Node
    for (int i = 0; i < 5; i++)
    {
        InsertAtEnd(&head, i); //we will pass the value by reference
    }                          //this will change the value of head;
    // Print(head);
    // head=NULL; //since this is already pointer to Node
    for (int i = 0; i < 5; i++)
    {
        InsertatHead(&head, i); //we will pass the value by reference
    }                           //this will change the value of head;

    InsertatHead(&head, 9);
    InsertatHead(&head, 10);
    Print(head);
    cout << "Before DUPLICATE Check\n";
    // Print(head);
    checkForDups(head);
    Print(head);
}