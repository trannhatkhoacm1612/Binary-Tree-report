#include<bits/stdc++.h>
#include<fstream>
#include<string>
using namespace std;
 
// Một nút trong cây AVL
class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};
 
// Hàm trả về chiều cao của cây con bắt đầu từ nút N
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// Hàm trả về giá trị lớn nhất của hai số nguyên
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Hàm tạo một nút mới với giá trị key cho trước và các con trỏ left, right trỏ đến NULL */
Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // nút mới được thêm vào ở vị trí lá
    return(node);
}
 
// Hàm xoay phải cây con bắt đầu từ nút y
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Thực hiện xoay phải
    x->right = y;
    y->left = T2;
 
    // Cập nhật chiều cao
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Trả về nút gốc mới
    return x;
}
 
// Hàm xoay trái cây con bắt đầu từ nút x
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Thực hiện xoay trái
    y->left = x;
    x->right = T2;
 
    // Cập nhật chiều cao
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Trả về nút gốc mới
    return y;
}
 
// Lấy giá trị Balance factor của nút N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Hàm đệ quy để chèn một giá trị key vào cây con bắt đầu từ nút node và trả về nút gốc mới của cây
Node* insert(Node* node, int key)
{
    /* 1. Thực hiện chèn giá trị key vào cây */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Không cho phép chèn giá trị trùng lặp vào cây
        return node;
 
    /* 2. Cập nhật chiều cao của nút cha */
    node->height = 1 + max(height(node->left),
                        height(node->right));
 
    /* 3. Lấy giá trị Balance factor của nút cha để kiểm tra xem cây có trở nên mất cân bằng hay không */
    int balance = getBalance(node);
 
    // Nếu cây bị mất cân bằng, có 4 trường hợp để xử lý
 
    // Trường hợp Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Trường hợp Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Trường hợp Left Right
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp Right Left
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* Trả về con trỏ đến nút gốc (không thay đổi) */
    return node;
}