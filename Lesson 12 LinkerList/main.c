#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
    int data;
    struct list *next;
};

typedef struct list *node;

 node createNote(int value){
    node temp; // dia chi vd: 0x04 co data value
    temp = (node)malloc(sizeof(struct list));
    temp->data = value;
    temp->next = NULL;
    return temp; // 0x04
 }

 node head; 

 void pushBack(int value){
    node temp, p;
    temp = createNote(value); // dia chi 0x04

    if (head == NULL)
    {
        head = temp;
    }else{
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp; 
    }
 }

void popBack(){
    node p = head;
    if (head->next != NULL)
    {
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        //free(p->next);
        p->next->data = 0;
        p->next = NULL;
    }else{
        //free(p);
        p->data = 0;
    }   
}

void clear(){
    node p = head;
    node temp;
    // while (p->next != NULL)
    // {
    //     p->data = 0;
    //     p = p->next;
    // }
    do 
    {
        // p = head;
        // popBack();
        //free(p);
        temp = p->next;
        //free(p);
        p->data = 0;
        p = temp;
    } while(p != NULL);   
}

node front(){
    node p = head;
    return p;
}

node back(){
    node p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
int getData(int index){
    int i = 0;
    node p = head;

    while (p->next != NULL && i != index)
    {
        p = p->next;
        i++;
    }
    return p->data;
}

typedef struct{
    void (*_push_back)(int);
    void (*_pop_back)();
    int (*_get_data)(int);
    void (*_clear)();
    node (*_front)();
    node (*_back)();
}vector;

void vectorInit(vector *p){
    head = NULL;
    p->_push_back = pushBack;
    p->_pop_back = popBack;
    p->_get_data = getData;
    p->_clear = clear;
    p->_front = front;
    p->_back = back;
}

#define Vector(type_name)   \
vector type_name;            \
vectorInit(&type_name);




int main(int argc, char const *argv[])
{
    
    Vector(A);

    A._push_back(10);
    A._push_back(19);
    A._push_back(15);
    //A._pop_back();
    //A._clear();

    // push_back(10);
    // push_back(12);
    // push_back(15);

    printf("Arr[0] = %d\n", A._back()->data);
    printf("Arr[1] = %d\n", A._get_data(1));
    printf("Arr[2] = %d\n", A._get_data(2));
    return 0;
}
