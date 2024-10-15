#include <stdio.h>
typedef struct AVLNode{
    int data;
    int height;
    struct AVLNode *right;
    struct AVLNode *left;
} node;

node *getnode();
node *insert(node *, int);
node *delete(node *, int);
void inorder(node *);
void preorder(node *);
void postorder(node *);
//int max(node *);
int min(node *);
//int search(node *, int);
int successor(node *);
int max(int, int);
int height_of_Node(node *);
node *SingleRotateL(node*);
node *SingleRotateR(node*);
node *DoubleRotateLR(node*);
node *DoubleRotateRL(node*);
