#include <stdio.h>
#include <stdlib.h>
#include "AVLHeader.h"

void main()
{
    int choice, x;
    node *root = NULL;

    while(1)
    {
        printf("\nAVL TREE IMPLEMENTATIONS\n\t1.Insert\n\t2.Delete\n\t3.Inorder\n\t4.Preorder\n\t5.Postorder\n\t6.Height\n\t7.Exit\nEnter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Inserting...\nEnter Data:");
            scanf("%d",&x);
            root = insert(root, x);
            break;
        case 2:
            printf("Deleting...\nEnter Data:");
            scanf("%d",&x);
            root = delete(root, x);
            break;
        case 3:
            printf("Inorder:");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder:");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder:");
            postorder(root);
            printf("\n");
            break;
        case 6:
            if (root != NULL)
            {
                printf("Root : %d\n", root->data);
                printf("Height of the tree : %d\n", root->height);
            }
            else
            {
                printf("The tree is empty.\n");
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }
}
