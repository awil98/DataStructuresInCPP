#include <iostream>

class Node{
  public:
    Node *lchild;
    int num;
    int height;
    Node *rchild;
};

class Stack{
  private:
    Node *st[10];
    int index = -1;
  public:
    Stack(){
    }
    void push(Node* pointer){
      st[++index] = pointer;
    }
    Node* pop(){
      if(index == -1){
          std::cout << "Stack empty" << std::endl;
          return nullptr;
      }
      std::cout << st[index]->num << " popped." << std::endl;
      return st[index--];
    }
    bool isEmpty(){
      return index == -1;
    }
    ~Stack(){
      delete[] st;
    }
};


class AVL{
  private:
    Node *root;
  public:
    AVL(int num){
      root = new Node;
      root->num = num;
      root->lchild =  NULL;
      root->rchild =  NULL;
      root->height = 1;
    }
    int NodeHeight(Node *p){
      int hl, hr;
      hl= p && p->lchild?p->lchild->height:0;
      hr= p && p->rchild?p->rchild->height:0;
      return hl>hr?hl+1:hr+1;
    }
    void insert(int num){
      Node *temp = root;
      Node *tail = NULL;
      Node *t = new Node;
      Stack s1;
      while(temp != NULL){
        s1.push(temp);
        if(temp->num > num){
          tail = temp;
          temp = temp->lchild;
        }else{
          tail = temp;
          temp = temp->rchild;
        }
      }
      if(tail->num > num){
        tail->lchild = t;
        t->height = 1;
        t->num = num;
        t->lchild = t->rchild = NULL;
      }else{
        tail->rchild = t;
        t->num = num;
        t->height = 1;
        t->lchild = t->rchild = NULL;
      }
      while(!s1.isEmpty()){
        temp = s1.pop();
        temp->height=NodeHeight(temp);
        if(balanceFactor(temp) == 2 && balanceFactor(p->lchild)==1){
          LL
        }
      }
    }
    
    int balanceFactor(Node *p){
      int hl, hr;
      hl= p && p->lchild?p->lchild->height:0;
      hr= p && p->rchild?p->rchild->height:0;
      return hl-hr;
    }
    ~AVL(){
      Stack s1;
      Node *temp = NULL;
      while(root != NULL || !s1.isEmpty()){
        if(root != NULL){
          s1.push(root);
          root = root->lchild;
        }else{
          root = s1.pop();
          temp = root;
          std::cout << "Deleting " << temp->num << std::endl;
          std::cout << "With height " << temp->height << std::endl;
          delete temp;
          root = root->rchild;
        }
      }
    }
};
int main(){
  AVL a1(5);
  a1.insert(10);
  a1.insert(15);
  a1.insert(2);
  return 0;
}
