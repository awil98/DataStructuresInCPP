#include <iostream>
#define INT_MAX 2000000000
#define INT_MIN -2000000000
using namespace std;

struct BSTNode{
        int number;
        BSTNode* left;
        BSTNode* right;
};

BSTNode* createNode(int value);
BSTNode* insert(BSTNode* root, int value);
bool found(BSTNode* root, int value);
int findMax(BSTNode* root);
int findMin(BSTNode* root);
int findHeight(BSTNode* root);
bool isBST(BSTNode* root, int min, int max);

int main(){
        BSTNode* root = NULL;
        root = insert(root, 15);
        root = insert(root, 20);
        root = insert(root, 10);
        root = insert(root, 9);
        if(found(root, 9) == true){
                cout << "Found" << endl;
        }else{
                cout << "Error" << endl;
        }
        cout << INT_MIN << endl;
        cout << findMax(root) << endl;
        cout << findHeight(root) << endl;
        cout << isBST(root, INT_MIN, INT_MAX) << endl;
        return 0;
}
BSTNode* createNode(int value){
        /*I need to create a new node object and set its
         *number field equal to value and I also need to
         *set its left and right values equal to null and return the node
         * */
        BSTNode* newNode = new BSTNode();
        newNode->number = value;
        newNode->left = newNode->right = NULL;
        return newNode;
}
BSTNode* insert(BSTNode* root, int value){
        /*I need to check if the pointer root is null
         * if it is I need to create a new node and set it equal to root
         * If root isn't null I have to get it to this base case by continually
         * calling insert and once i hit base case I need to return that root
         * value to root->left if it's smaller than root and right otherwise
         * */
        if(root == NULL){
                root = createNode(value);
        }else if(root->number > value){
                /*So if my value is less than the number stored in the node
                 * that im currently pointing to I need go down the left side
                 * of the tree until I'm pointing at a node that has a null
                 * left pointer value I can do this by sending in the root->left
                 * as my my new root and the same value
                 * */
                root->left = insert(root->left, value);
        }else{
                /*Else I need to traverse the right side of the tree
                 * */
                root->right = insert(root->right, value);
        }


        return root;
}
bool found(BSTNode* root, int value){
        /*I need to traverse the tree until i find the value
         * if the value is less than I need to go down the left side
         * otherwise I need to go down the right side
         * */
        if(root->number == value){
                return true;//this is the base case

        }
        else if(root->number > value){
                /*If the value is less than I need to traverse the left side
                 * */
                found(root->left, value);
        }else if(root->number < value){
                /*IF the value is greater than I need to traverse the right side
                 * */
                found(root->right, value);
        }else{
                return false;
        }
}
int findMax(BSTNode* root){
        if(root == NULL){
                cout << "There isn't any data in the tree" << endl;
                return -10;
        }
        else if(root->right == NULL){
                return root->number;//if I've gone the farthest right i can go i've reached my max
        }
        return findMax(root->right);
}

int findHeight(BSTNode* root){
        if(root == NULL){
                return -1;
        }
        int left = findHeight(root->left);
        int right = findHeight(root->right);

        if(left >= right){
                return left + 1;
        }else{
                return right + 1;
        }
}
bool isBST(BSTNode* root, int min, int max){
        if(root == NULL) return true;
        else if(root->number < min || root->number > max){
                return false;
        }else{
                return isBST(root->left, min, root->number) && isBST(root->right, root->number, max);
        }
}
