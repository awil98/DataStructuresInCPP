#ifndef chains
#define chains
#include <iostream>
class Node{
  public:
      int num;
      Node* next;
};
class LinkedList{
  private:
    Node* head;
  public:
    LinkedList(){
      this->head = NULL;
    }
    void sortedInsert(int num){
      Node *t = new Node;
      Node *temp = this->head;
      Node *tail = NULL;
      t->num = num;
      if(head == NULL){
        head = t;
        head->next = NULL;
        return;
      }
      if(temp->num > num){
        t->next = temp;
        head = t;
        return;
      }
      while(temp != NULL){
        if(temp->num > num){
          tail->next = t;
          t->next = temp;
          return;
        }else{
          tail = temp;
          temp = temp->next;
        }
      }
      tail->next = t;
      t->next = NULL;
    }
    void search(int num){
      Node *p = head;
      while(p!=NULL){
        if(num==p->num){
          std::cout << "Key Found" << std::endl;
        }
      }
      std::cout << "Key Not Found" << std::endl;
    }
    ~LinkedList(){
      Node *temp = NULL;
      while(head != NULL){
        temp = head;
        head = head->next;
        std::cout << "Deleting " << temp->num << std::endl;
        delete temp;
      }
    }
};
#endif
