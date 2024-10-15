#include "AVLHeader.h"
#include <stdlib.h>
node *getnode()

{
    node *a = (node *)malloc(sizeof(node));
    if (a == NULL)
    {
        printf("Error...");
        return NULL;
    }
    a->right = NULL;
    a->left = NULL;
    a->height = 0;
    return a;
}

node *SingleRotateL(node *root)
{
    if (root != NULL && root->right != NULL)
    {
        node *k = root->right;
        root->right = k->left;
        k->left = root;

        k->height = max(height_of_Node(k->left), height_of_Node(k->right)) + 1;
        root->height = max(height_of_Node(root->left), height_of_Node(root->right)) + 1;

        return k;
    }

    else
    {
        return root;
    }
}

node *SingleRotateR(node *root)
{
    if (root != NULL && root->left != NULL)
    {

    node *k = root->left;
    root->left = k->right;
    k->right = root;

    k->height = max(height_of_Node(k->left), height_of_Node(k->right)) + 1;
    root->height = max(height_of_Node(root->left), height_of_Node(root->right)) + 1;

    return k;

    }

    else
    {
        return root;
    }
}

node *DoubleRotateLR(node *root)
{
    if (root -> left != NULL && root != NULL)
    {
        root->left = SingleRotateL(root->left);
        return SingleRotateR(root);
    }
    else
    {
        return root;
    }
}

node *DoubleRotateRL(node *root)
{

    if (root->right != NULL && root != NULL)
    {
        root->right = SingleRotateR(root->right);
        return SingleRotateL(root);
    }

    else
    {
        return root;
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int height_of_Node(node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    return root->height;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        node *t = getnode();
        if (t == NULL)
        {
            printf("Malloc failed.\n");
            return root;
        }

        t->data = data;
        return t;
    }

    if (root->data < data)
    {
        root->right = insert(root->right, data);

        if (height_of_Node(root->right) - height_of_Node(root->left) == 2)
        {
            node *t = root->right;
            node *p = root->left;
            if (data > t->data)
            {
                root = SingleRotateL(root);
            }
            else
            {
                root = DoubleRotateRL(root);
            }
        }
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
        if (height_of_Node(root->left) - height_of_Node(root->right) == 2)
        {
            node *t = root->right;
            node *p = root->left;
            if (data < p->data)
            {
                root = SingleRotateR(root);
            }
            else
            {
                root = DoubleRotateLR(root);
            }
        }
    }
    if (root != NULL)
    {
        root->height = max(height_of_Node(root->left), height_of_Node(root->right)) + 1;
    }
    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node *delete(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;  
    }


    if (data < root->data)
    {
        root->left = delete(root->left, data);  

     
        if (height_of_Node(root->right) - height_of_Node(root->left) == 2)
        {
            if (height_of_Node(root->right->right) >= height_of_Node(root->right->left))
            {
                root = SingleRotateL(root);  
            }
            else
            {
                root->right = SingleRotateR(root->right);  
                root = SingleRotateL(root);
            }
        }
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);  

       
        if (height_of_Node(root->left) - height_of_Node(root->right) == 2)
        {
            if (height_of_Node(root->left->left) >= height_of_Node(root->left->right))
            {
                root = SingleRotateR(root);  
            }
            else
            {
                root->left = SingleRotateL(root->left); 
                root = SingleRotateR(root);
            }
        }
    }
    else
    {
     
        if (root->left == NULL || root->right == NULL) 
        {
            node *temp = root->left ? root->left : root->right;

            if (temp == NULL)  
            {
                temp = root;
                root = NULL;
            }
            else 
            {
                *root = *temp;  
            }
            free(temp);
        }
        else
        {

            int temp = successor(root);
            root->data = temp;  
            root->right = delete(root->right, temp);

            
            if (height_of_Node(root->left) - height_of_Node(root->right) == 2)
            {
                if (height_of_Node(root->left->left) >= height_of_Node(root->left->right))
                {
                    root = SingleRotateR(root); 
                }
                else
                {
                    root->left = SingleRotateL(root->left);  
                    root = SingleRotateR(root);
                }
            }
        }
    }

 
    if (root == NULL)
        return root;

   
    root->height = max(height_of_Node(root->left), height_of_Node(root->right)) + 1;

    return root;
}

int min(node *root)
{
    node *current = root;

    
    while (current->left != NULL)
        current = current->left;

    return current->data;
}


int successor(node *root)
{
    return min(root->right);
}
