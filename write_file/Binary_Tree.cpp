#include <iostream>
using namespace std;

template<typename T>
class Node{
    public:
        T data;
        Node<T> *left;
        Node<T> *right;
        Node(T d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

template<typename T>
class BinarySearchTree {
    public:
        Node<T> *insert(Node<T> *root, T data) {
            if(root == NULL){
                return new Node<T>(data);
            }
            else {
                Node<T> *cur = new Node<T>(data);
                if(data <= root->data){
                    cur = insert(root->left,data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
                }
                return root;
            }
        }

        void inorder(Node<T>* root){
            if(root != NULL){
                inorder(root->left);
                cout << root->data << " ";
                inorder(root->right);  
            }
            
        }


        void preorder(Node<T>* root){
            if(root != NULL){
                cout << root->data << " ";
                inorder(root->left);
                inorder(root->right);
            }
        }

        void printGivenLevel(Node<T> *root,T level){
            if(root == NULL){
                return;
            }
            else if(level == 1){
                cout << root->data << " ";
            }
            else {
                printGivenLevel(Node->left);
                printGivenLevel(Node->right);
            }
            


        }

};


int main(){
    int n,data;
    cin >> n;
    BinarySearchTree<int> BST;
    Node<int> *root = NULL;
    while(n-- > 0){
        cin >> data;
        root = BST.insert(root,data);
    }
    // cout << root->data;
    BST.inorder(root);

}