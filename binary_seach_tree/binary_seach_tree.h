//
// Created by MSI Gaming PC on 10/13/2021.
//

#ifndef BINARY_SEACH_TREE_BINARY_SEACH_TREE_H
#define BINARY_SEACH_TREE_BINARY_SEACH_TREE_H

#include <iostream>
#include <list>
#include <cstdlib>
#include <cstdio>
#include<tuple>

#define STARTING_VALUE 50
#define STACK_CAPACITY 1000

typedef struct TreeNode *Tree;
typedef struct stack *Stack;
struct ListRecord;
typedef struct ListRecord *List;

typedef struct TreeNode
{
    int val;
    Tree left;
    Tree right;
    int depth; // Only using this in task 17. Had to make a queue with TreeNodes.
    struct TreeNode *next; // This I used in the dynamic stack and adt queue.
} Node;

struct stack
{
    size_t capacity;
    int size;
    Tree stack;
};

struct ListRecord{
    Node *head;
    Node *tail;
    int size;
};

Tree CreateBinarySearchTree();

Tree RecursiveInsertBinarySearchTree(int , Tree);

Tree RecursiveFindMaximum(Tree);

Tree RecursiveFindMinimum(Tree);

void PrintTree(Tree t);

void PrintTreeStructure(Tree, int,std::list<std::tuple<int, int>> *);

Tree DeleteNode(Tree, int);

int CountNodes(Tree);

int CountLeaves(Tree);

int TreeHeight(Tree, int);

Tree CopyTree(Tree);

bool IdenticalTrees(Tree, Tree);

void IterativeInsertBinaryTree(Tree, int);

void IterativeTraversal(Tree);

void IterativeTraversalBFS(Tree);

int push(Stack stack, Tree new_node);

Node pop(Stack stack);

Stack create_stack();

List create_list();

void make_empty_list(List);

void sorted_insert(List, Tree, int);

Node remove_last_element(List);

int is_empty(List);

int list_size(List);


#endif //BINARY_SEACH_TREE_BINARY_SEACH_TREE_H
