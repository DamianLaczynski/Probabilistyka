// Probabilistyka.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <list> 

#define N 3
#define TYPE int


struct node
{
    TYPE value;
    node* childs = nullptr;
} root;

void genPermutation(node* parent, std::list<TYPE> values)
{
    if (values.size() == 1)
    {
        parent->childs = new node[values.size()];
        parent->childs[0].value = values.back();
        std::cout << parent->childs[0].value<<"\n";
        return;
    }
    else
    {
        parent->childs = new node[values.size()];
        for (int i = 0; i < values.size(); i++)
        {
            parent->childs[i].value = values.back();
            std::cout << parent->childs[i].value;
            values.pop_back();
            genPermutation(&(parent->childs[i]), values);
            values.push_front(parent->childs[i].value);
        }
    }
}


int main()
{
    std::list<TYPE> values = { 1,2,3 };
    genPermutation(&root, values);
    std::cout << "end";
}
