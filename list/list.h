#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#define MAX_NUM 10
#define MIN_NUM 1

struct node
{
    int data;
    node * next;
};
int DoList();
int print_list(node *head);