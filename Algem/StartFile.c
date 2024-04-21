
#include "stdio.h"
#include "stdlib.h"
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

#include "iso646.h"

#define CMP_EQ(a, b) ((a) == (b))

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} node;

node *get_free_node(int value, node *parent) {
    node *tmp = (node *) malloc(sizeof(node));
    tmp->left = tmp->left = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insert(node **head, int value) {
    node *tmp = NULL;
    if (*head == NULL) {
        *head = get_free_node(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp != NULL) {
        if (CMP_GT(value, tmp->data)) {
            if (tmp->right != NULL) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = get_free_node(value, tmp);
                return;
            }
        } else if (CMP_LT(value, tmp->data)) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = get_free_node(value, tmp);
                return;
            }
        } else return;
    }
}

node *get_min_node(node *root) {
    while (root->left)
        root = root->left;
    return root;
}

node *get_max_node(node *root) {
    while (root->right)
        root = root->right;
    return root;
}

void pre_order_traver(node *root) {
    if (root) {
        printf("%d ", root->data);
        pre_order_traver(root->left);
        pre_order_traver(root->right);
    }
}

void post_order_traver(node *root) {
    if (root!= NULL) {
        post_order_traver(root->left);
        post_order_traver(root->right);
        printf("%d ", root->data);
    }
}

void in_order_traver(node *root) {
    if (root) {
        in_order_traver(root->left);
        printf("%d ", root->data);
        in_order_traver(root->right);

    }
}
void deleteTree(node **root) {
    if (*root) {
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        free(*root);
    }
}
int main() {
    freopen("/Users/555tery/CLionProjects/my_university_c/Algem/input.txt", "r", stdin);
    freopen("/Users/555tery/CLionProjects/my_university_c/Algem/output.txt", "w", stdout);
    int val = 0;
    scanf("%d", &val);
    node *head = get_free_node(val, NULL);
    while (scanf("%d", &val) != EOF) {
        insert(&head, val);
    }
    node *tmp = head;
    pre_order_traver(head);
    printf("\n");
    post_order_traver(tmp);
    printf("\n");
//    in_order_traver(head);
//    printf("\n");
    deleteTree(&head);
    fclose(stdin);
    fclose(stdout);
}