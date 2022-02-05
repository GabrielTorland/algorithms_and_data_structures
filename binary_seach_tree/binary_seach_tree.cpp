//
// Created by MSI Gaming PC on 10/13/2021.
//

#include "binary_seach_tree.h"


Tree CreateBinarySearchTree(){
    Tree t = (Tree)malloc(sizeof(Node));
    t->val = STARTING_VALUE;
    t->right = t->left = nullptr;
    return t;
}

Tree RecursiveInsertBinarySearchTree(int x, Tree t)
{
    if (t == nullptr)
    {  /* Create and return a one-node tree */
        t = (Tree) malloc(sizeof(Node));
        if (t == nullptr){
            printf("Out of memory space!!!");
            std::exit(EXIT_FAILURE);
        }
        else
        {
            t->val = x;
            t->left = t->right = nullptr;
        }
    }
    else
    {
        if (x < t->val)
            t->left = RecursiveInsertBinarySearchTree(x, t->left);
        else if (x > t->val)
            t->right = RecursiveInsertBinarySearchTree(x, t->right);
    }

    /* else x is in the tree already. We'll do nothing */
    return t;
}

/* Here we simply go to the right sub-node until the sub-node is nullptr. Then we return the node(Parent). */
Tree RecursiveFindMaximum(Tree t){
    if (t->right == nullptr){
        return t;
    }
    else{
       return RecursiveFindMaximum(t->right);
    }
}

/* Here we simply go to the left sub-node until the sub-node is nullptr. Then we return the node(Parent). */
Tree RecursiveFindMinimum(Tree t){
    if (t->left == nullptr){
        return t;
    }
    else{
        return RecursiveFindMinimum(t->left);
    }
}

/* Here we can print out the tree in three different orders. */
void PrintTree(Tree t){
    if (t != nullptr){
        // Preorder:
        printf("%d ", t->val);
        PrintTree(t->left);
        // Inorder:
        //printf("%d\n", t->val);
        PrintTree(t->right);
        //Postorder:
        //printf("%d\n", t->val);
    }
}

/* This will print the tree sorted by depth. So it will */
void PrintTreeStructure(Tree t, int depth, std::list<std::tuple<int, int>> *nodes){
    if (t != nullptr){
        std::tuple<int, int> node;
        node = std::make_tuple(t->val, depth);
        nodes->push_back(node);
        PrintTreeStructure(t->left, depth+1, nodes);
        PrintTreeStructure(t->right, depth+1, nodes);
    }
}

/* This will count all the nodes in the tree. */
int CountNodes(Tree t){
    int count = 0;
    if (t != nullptr){
        count += CountNodes(t->left) + CountNodes(t->right);
        count++;
    }
    return count;
}

/* This will count only the leaf nodes in the tree. */
int CountLeaves(Tree t){
    int count = 0;
    if (t != nullptr){
        if ((t->right == nullptr) && (t->left == nullptr)){
            count++;
        }
        else
            count += CountLeaves(t->left) + CountLeaves(t->right);
    }
    return count;
}

/* This return's the height of the tree. The height is the leaf node farthest away from the root. Root node count as zero. */
int TreeHeight(Tree t, int depth){
    if (t != nullptr){
        if ((t->right == nullptr) && (t->left == nullptr)){
            return depth;
        }
        else{
            return std::max(TreeHeight(t->left, depth+1), TreeHeight(t->right, depth+1));
        }
    }
    // Returns INT_MIN when there are no tree.
    return INT_MIN;
}

/* Deletes the node with the value val. */
Tree DeleteNode(Tree t, int val){
    if (t == nullptr){
        return t;
    }

    if (val < t->val){
        t->left = DeleteNode(t->left, val);
    }

    else if (val > t->val){
        t->right = DeleteNode(t->right, val);
    }

    else {
        // Nodes with only one child.
        // This child can be replaced with the deleted node without any complications.
        if (t->left == nullptr){
            Tree temp = t->right;
            free(t);
            return temp;
        }
        else if (t->right == nullptr){
            Tree temp = t->left;
            free(t);
            return temp;
        }

        // Node with two children:
        // Finds the minimum node from the right sub-node of the deleted node.
        // This node will always have a less value than all the other sub-nodes.
        // Hence, we can swap position of the minimum node with the deleted one.
        Tree temp = RecursiveFindMinimum(t->right);
        t->val = temp->val;

        t->right = DeleteNode(t->right, temp->val);
    }
    return t;
}

/* Copying the given tree. */
Tree CopyTree(Tree t){
    if (t == nullptr){
        return nullptr;
    }
    Tree new_node = (Tree)malloc(sizeof(Node));
    new_node->val = t->val;
    new_node->left = CopyTree(t->left);
    new_node->right = CopyTree(t->right);
    return new_node;
}

/* Comparing two trees, returns a boolean. */
bool IdenticalTrees(Tree t_1, Tree t_2){
    if (t_1 == nullptr or t_2 == nullptr)
    {
        return t_1 == t_2;
    }
    else{
        if (t_1->val != t_2->val){
            return false;
        }
        else{
            if (IdenticalTrees(t_1->left, t_2->left) && IdenticalTrees(t_1->right, t_2->right))
                return true;
            else
                return false;
        }
    }
}

/* Iterative insert to the given tree. */
void IterativeInsertBinaryTree(Tree t, int val){
    while (true){
        if (val > t->val){
            t = t->right;
            if (t->right == nullptr){
                t->right = (Tree)malloc(sizeof(Tree));
                if (t->right == nullptr){
                    printf("Out of memory space!!!");
                    std::exit(EXIT_FAILURE);
                }
                t->right->val = val;
                t->right->right = nullptr;
                t->right->left = nullptr;
                break;
            }
        }
        else if (val < t->val){
            t = t->left;
            if (t->left == nullptr){
                t->left = (Tree)malloc(sizeof(Tree));
                if (t->left == nullptr){
                    printf("Out of memory space!!!");
                    std::exit(EXIT_FAILURE);
                }
                t->left->val = val;
                t->left->right = nullptr;
                t->left->left = nullptr;
                break;
            }
        }
        else{
            // pass
            // The value is already in the binary tree
        }
    }
}

/* Iterating through all the nodes in the tree using stack.*/
void IterativeTraversal(Tree t){
    Tree current_node = t;
    Stack stack = create_stack();
    while (true){
        if (current_node != nullptr){
            push(stack, current_node);
            current_node = current_node->left;
        }
        else if (stack->size != 0){
            Node temp = pop(stack);
            current_node = &temp;
            printf("%d ", current_node->val);

            current_node = current_node->right;
        }
        else{
            printf("\n");
            break;
        }
    }
}

/* Iterating through all the nodes in the tree using adt queue. This will look like a bfs. */
/*
void IterativeTraversalDFS(Tree t){
    Tree current_node = t;
    List queue = create_list();
    int depth = 0;
    while (true){
        if (current_node != nullptr){
            // Placing the node in a sorted order.
            sorted_insert(queue, current_node, depth);
            printf("value: %d, depth: %d.\n", current_node->val, depth);
            current_node = current_node->left;
            depth++;
        }
        else if (queue->size != 0){
            Node temp = remove_last_element(queue);
            current_node = &temp;
            depth = current_node->depth+1;
            printf("\n");
            printf("Depth: %d, value: %d.\n", current_node->depth, current_node->val);
            printf("\n");
            current_node = current_node->right;
        }
        else{
            break;
        }
    }
}
*/

/* Iterating through all the nodes in the tree using adt queue. This will look like a bfs. */
void IterativeTraversalBFS(Tree t){
    List queue = create_list();
    int depth = 0;
    // Placing the starting node in a sorted order.
    sorted_insert(queue, t, depth);
    while (list_size(queue) != 0){
        depth++;
        int size = list_size(queue);
        for (int i = 0; i < size; ++i){
            Node temp = remove_last_element(queue);
            printf("%d ", temp.val);
            if (temp.left != nullptr)
                sorted_insert(queue, temp.left, depth);
            if (temp.right != nullptr)
                sorted_insert(queue, temp.right, depth);
        }
        printf("\n");
    }
}

int push(Stack stack, Tree node){
    if (stack->size == stack->capacity){
        printf("Stack is full!");
        return INT_MIN;
    }
    Tree new_node = (Tree)malloc(sizeof(Node));
    if (new_node == nullptr){
        printf("Out of memory!\n");
        return INT_MIN;
    }
    else{
        // Set up new node.
        new_node->val = node->val;
        new_node->right = node->right;
        new_node->left = node->left;
        new_node->next = stack->stack;

        stack->stack = new_node;
        stack->size++;
        return 1;
    }
}


Node pop(Stack stack){
    if (stack->size > 0){
        Tree temp = stack->stack;
        stack->stack = stack->stack->next;
        Node temp_1 = *temp;
        free(temp);
        stack->size--;
        return temp_1;
    }
    else
    {
        printf("Super stack is empty! HO! HA!\n");
        Node node;
        node.right = nullptr;
        node.left = nullptr;
        node.val = INT_MIN;
        return node;
    }

}

Stack create_stack()
{
    auto stack = (Stack)malloc(sizeof(struct stack));
    if (stack == nullptr){
        return nullptr;
    }
    else{
        stack->capacity = STACK_CAPACITY;
        // Dummy node.
        Tree new_node = (Tree)malloc(sizeof(Node));
        stack->stack = new_node;
        stack->stack->next = nullptr;
        stack->size = 0;
    }
    return stack;
}


List create_list(){
    // Allocate a list
    List list = (List) malloc(sizeof (struct ListRecord));

    if (list == nullptr){
        printf("Error. Unable to allocate space for list.\n");
    }

    // Call make empty list
    make_empty_list(list);

    return list;
}

void make_empty_list(List list){
    // Allocate a dummy node
    Node *dummy = (Node*) malloc(sizeof (Node));

    if (dummy == nullptr){
        printf("Error. Unable to allocate space for dummy element.\n");
    }
    else{

        dummy->next = nullptr;
        dummy->val = INT_MAX;
        dummy->depth = INT_MAX;

        // Set list tail to dummy
        list->tail = nullptr;

        // Set list head to dummy
        list->head = dummy;

        // Set list size to 0
        list->size = 0;
    }
}

void sorted_insert(List list, Tree node, int depth){
    // Allocate insert node
    Tree insert, temp_node;
    insert = (Tree) malloc(sizeof (Node));
    if (insert == nullptr){
        printf("Error. Unable to allocate space for new element.\n");
    }
    insert->next = nullptr;

    // Set val to value
    insert->val = node->val;
    insert->right = node->right;
    insert->left = node->left;
    insert->depth = depth;

    temp_node = list->head;
    Tree previous_node = temp_node;
    temp_node = temp_node->next;
    for (int i = 0; i < list_size(list) && insert->depth < temp_node->depth; ++i) {
        previous_node = temp_node;
        temp_node = temp_node->next;
    }
    // Setting tail when element is added to the end of the queue.
    if (temp_node == nullptr){
        list->tail = insert;
    }

    insert->next = temp_node;
    previous_node->next = insert;


    // Increment size
    list->size++;
}

Node remove_last_element(List list){
    if (!is_empty(list)) {
        // Define a temp node to head
        Node *temp_node = list->head;

        // Loop temp next is not null and temp next val is not value.
        //  set temp to temp next
        for (int i = 0; temp_node->next != nullptr; ++i) {
            if (temp_node->next->next == nullptr){
                // Set delete node to current->next
                Tree delete_node = temp_node->next;
                // Set current->next to current->next->next
                temp_node->next = temp_node->next->next; // Same as nullptr.
                list->tail = temp_node;
                // delete the delete node
                Node temp = *delete_node;
                free(delete_node);
                list->size--;
                return temp;
            }
            temp_node = temp_node->next;
        }
    }
    else{
        printf("Error. Can not delete from empty list.\n");
        Node temp;
        temp.right = nullptr;
        temp.left = nullptr;
        temp.val = INT_MIN;
        return temp;
    }

}

int is_empty(List list){
    return list->size == 0;
}

int list_size(List list){
    return list->size;
}