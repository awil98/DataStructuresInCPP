#include <iostream>
class Node{
  public:
    int num;
    Node *next;
};

class LinkedList{
  private:
    Node *head;
  public:
    LinkedList(){
      head = NULL;
    }
    void insert(int num){
      Node *temp = head;
      Node *tail = NULL;
      Node *t = new Node;
      if(temp == NULL){
        t->num = num;
        t->next = NULL;
        head = t;
      }else if(temp->num > num){
        t->next = temp;
        t->num = num;
        head = t;
      }else{
        bool br = false;
        while(temp != NULL){
          if(temp->num > num){
            br = true;
            break;
          }
          tail = temp;
          temp = temp->next;
        }
        if(br){
          tail->next = t;
          t->next = temp;
          t->num = num;
        }else{
          tail->next = t;
          t->next = NULL;
          t->num = num;
        }
      }
    }
    void search(int num){
      Node *temp = head;
      while(temp->num <= num && temp !=NULL){
        if(temp->num == num){
          std::cout << num <<" found" << std::endl;
          return;
        }
        temp = temp->next;
      }
      std::cout << num << " not found" << std::endl;
    }
    ~LinkedList(){
      Node *temp = head;
      while(head != NULL){
        temp = head;
        head = head->next;
        std::cout << "Deleting " << temp->num << std::endl;
      }
    }
};

class ArrayADT{
  private:
    LinkedList *HT;
  public:
    ArrayADT(){
      this->HT = new LinkedList[10];
    }
    void insert(int key){
        int index = key % 10;
        HT[index].insert(key);
    }
    void search(int key){
      int index = key % 10;
      HT[index].search(key);
    }
    ~ArrayADT(){
      for(int i = 0; i < 10; i++){
          HT[i].~LinkedList();
      }
      delete[] HT;
    }
};

int main(){
  ArrayADT Ht;
  Ht.insert(10);
  Ht.insert(20);
  Ht.insert(30);
  Ht.search(10);
  return 0;
}
