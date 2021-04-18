//#include "list.h"
#include "mainwindow.h"



// Конструктор за замовчуванням
//--------------------------------------------------------------------------------
List::List()
{
    countLists++;
    countElements = 0;

    head = NULL;
    tail = NULL;
}



// Конструктор за значенням
//--------------------------------------------------------------------------------
List::List(int A)
{
    countLists++;
    countElements = 1;

    Node *temp = new Node;
    temp->value = A;
    temp->previous = NULL;
    temp->next = NULL;

    head = temp;
    tail = temp;
}



// Конструктор з копіюванням
//--------------------------------------------------------------------------------
List::List(List &A)
{
    countLists++;
    countElements = A.getCountElements();

    head = A.head;
    tail = A.tail;
}



// Деструктор
//--------------------------------------------------------------------------------
List::~List()
{

}



// Повернути кількість елементів списку
//--------------------------------------------------------------------------------
int List::getCountElements()
{
    return countElements;
}



// Додати елемент в кінець списку
//--------------------------------------------------------------------------------
Node *List::getLeft(List *)
{
    return head;
}



// Додати елемент в кінець списку
//--------------------------------------------------------------------------------
Node *List::getRight(List *)
{
    return tail;
}



// Знаходження середнього арифметичного усіх елементів
//--------------------------------------------------------------------------------
double List::meanValue()
{
    double mean = 0;
    Node *current = head;

    while (current != NULL)
    {
        mean += current->value;
        current = current->next;
    }

    return mean / getCountElements();
}



// Сортування вибіркою
//--------------------------------------------------------------------------------
void List::sortSelection()
{
    Node *current = NULL;
    Node *index = NULL;

    int temp;

    if (head != NULL)
    {
       for (current = head; current->next != NULL; current = current->next)
       {
           for (index = current->next; index != NULL; index = index->next)
           {
               if (current->value < index->value)
               {
                   temp = current->value;
                   current->value = index->value;
                   index->value = temp;
               }
           }
       }
    }
}



// Сортування бульбашкою
//--------------------------------------------------------------------------------
void List::sortBubble()
{
    Node *current, *index = new Node();

    if (head != NULL)
    {

        bool swapped = true;
        while (swapped)
        {
            swapped = false;

            current = head;
            while (current->next != NULL)
            {
                if (current->value > current->next->value)
                {
                    swapped = true;

                    index->value = current->value;
                    current->value = current->next->value;
                    current->next->value = index->value;
                }
                current = current->next;
            }
        }
    }

    delete index;
}



// Налаштування виводу зліва направо (Л-П = true, П-Л = false)
//--------------------------------------------------------------------------------
void List::setOutputLeftToRight(bool way)
{
    outputLeftToRight = way;
}



// Додати елемент в кінець списку
//--------------------------------------------------------------------------------
void List::addNodeRight(int A)
{
    countElements++;

    Node *temp = new Node;
    temp->value = A;
    temp->previous = tail;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}



// Додати елемент на початок списку
//--------------------------------------------------------------------------------
void List::addNodeLeft(int A)
{
    countElements++;

    Node *temp = new Node;
    temp->value = A;
    temp->previous = NULL;
    temp->next = head;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        head->previous = temp;
        head = head->previous;
    }
}



// Видалити елемент з кінця списку
//--------------------------------------------------------------------------------
void List::deleteNodeRight()
{
    countElements--;

    if (head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else if (countElements == 1)
    {
        delete this;
    }
    else
    {
        Node *toDelete = tail;
        tail = tail->previous;
        tail->next = NULL;

        delete toDelete;
    }
}



// Видалити елемент з початку списку
//--------------------------------------------------------------------------------
void List::deleteNodeLeft()
{
    countElements--;

    if (head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else if (countElements == 1)
    {
        delete this;
    }
    else
    {
        Node *toDelete = head;
        head = head->next;
        head->previous = NULL;

        delete toDelete;
    }
}



// Помножити на скаляр усі елементи списку
//--------------------------------------------------------------------------------
void List::timesScalar(int N)
{
    Node *current = head;

    while (current != NULL)
    {
        current->value *= N;
        current = current->next;
    }
}



// Повернути елемент за індексом
//--------------------------------------------------------------------------------
int List::getValueOfElementIndex(int I)
{
    Node *current = head;

    for (int i = 0; i < I; i++)
    {
        current = current->next;
    }

    return current->value;
}



// Перевантаження + (додати елемент в кінець списку)
//--------------------------------------------------------------------------------
void List::operator + (int A)
{
    addNodeRight(A);
}



// Перевантаження - (додати елемент на початок списку)
//--------------------------------------------------------------------------------
void List::operator - (int A)
{
    addNodeLeft(A);
}


// Перевантаження ++ (видалити елемент з кінця списку)
//--------------------------------------------------------------------------------
void List::operator ++ ()
{
    deleteNodeRight();
}



// Перевантаження -- (видалити елемент з початку списку)
//--------------------------------------------------------------------------------
void List::operator -- ()
{
    deleteNodeLeft();
}



// Перевантаження =
//--------------------------------------------------------------------------------
void List::operator = (List &A)
{
    head = A.head;
    tail = A.tail;
    countElements = A.countElements;
}



