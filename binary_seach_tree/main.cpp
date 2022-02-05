#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include<bits/stdc++.h>
#include "binary_seach_tree.h"

#define NODES_STARTING_COUNT 100

void PrintTreeConsole(Tree t);

int main() {
    srand(time(nullptr));

    Tree t = CreateBinarySearchTree();
    // 1.
    // This will probably not generate 100 nodes because the random range is between 0 and 100. Hence, some nodes will have the same value.
    for (int i = 0; i < NODES_STARTING_COUNT; ++i){
        // Inserting random integer between 0 and 99 into the binary tree.
        RecursiveInsertBinarySearchTree(rand()%100, t);
    }
    // 2.
    printf("Maximum = %d.\n", RecursiveFindMaximum(t)->val);

    // 3.
    printf("Minimum = %d.\n", RecursiveFindMinimum(t)->val);

    PrintTreeConsole(t);
    /* 4.
    printf("Tree: \n");
    PrintTree(t);
    printf("\n");
    */

    // 7.
    DeleteNode(t,  RecursiveFindMinimum(t)->val);
    printf("Minimum = %d.\n", RecursiveFindMinimum(t)->val);
    PrintTreeConsole(t);

    /* 8.
    PrintTreeConsole(t);
    */

    // 9.
    printf("Node count: %d.\n", CountNodes(t));

    // 10.
    printf("Leaf count: %d.\n", CountLeaves(t));

    // 11.
    printf("Height: %d.\n", TreeHeight(t, 0));

    // 12.
    Tree t_2 = CopyTree(t);
    PrintTreeConsole(t_2);

    // 13 & 14.
    if (IdenticalTrees(t, t_2))
        printf("They are equal.\n");
    else
        printf("They are not equal.\n");

    // 15.
    // Iterative insert:
    IterativeInsertBinaryTree(t, 110);

    //Recursive insert:
    RecursiveInsertBinarySearchTree(110, t_2);

    // 16.
    printf("This is traversal using stack and iteration: \n");
    IterativeTraversal(t);

    // 17.
    printf("This is traversal using adt queue and iteration: \n");
    IterativeTraversalBFS(t);

    return 0;
}

void PrintTreeConsole(Tree t){
    auto *nodes = new std::list<std::tuple<int, int>>;
    PrintTreeStructure(t, 0, nodes);
    nodes->sort([](const std::tuple<int, int>& a, const std::tuple<int, int>& b){
        return (std::get<1>(a) < std::get<1>(b));
    });

    int current_depth = 0;
    for (auto const& node: *nodes){
        if (current_depth < std::get<1>(node)){
            current_depth = std::get<1>(node);
            printf("\n");
        }
        printf("%d  ", std::get<0>(node));
    }
    printf("\n");
}