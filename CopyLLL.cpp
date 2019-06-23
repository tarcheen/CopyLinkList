/* Hamed Mirlohi
 Copy Linear Link List
 */

#include <iostream>

using namespace std;

struct node
{
    node* next;
    int data;
};

node* copy_LinearLL(node* head)
{
    // empty list
    if(head == nullptr) 
        return nullptr;

    node* newHead = new node;   // generate new LLL
    newHead->data = head->data;
    node* newTmp = newHead;
    head = head -> next;
    //newHead->data = head->data;

    // copy all fields
    while(head != nullptr)
    {
        newTmp->next = new node;
        newTmp = newTmp->next;
        newTmp->next = nullptr;
        newTmp->data = head->data;
        head = head->next;
    }

    return newHead;

}

void display_LLL(node* head)
{
    while(head != nullptr)
    {
        cout<< head << ": "<< head->data <<endl;
        head = head->next;
    }
}

int main()
{

    /*Building the LLL to be copied */
    constexpr int size = 2;
    node* head = new node;
    head->data = 0;
    head->next = nullptr;
    node* tmp = head;

    short count = 1;
    while(count < size)
    {
        tmp->next = new node;
        tmp = tmp->next;
        tmp->data = size * count;
        tmp->next = nullptr;
        tmp->prev = nullptr;
        count++;
    }

    cout<< "Old LLL: " << endl;
    display_LLL(head);

    cout<<"---------------------------------"<<endl;

    node* newNode = copy_LinearLL(head);

    cout<< "New LLL: "<< endl;
    display_LLL(newNode);

}
