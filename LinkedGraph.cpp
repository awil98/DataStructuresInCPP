#include <iostream>

class Node{
  public:
    int num;
    Node *next;
    int weight;
};

class LinkedList{
  private:
    Node *head;
  public:
    LinkedList(){
      this->head = NULL;
    }
    void insert(int num, int weight){
      Node *temp = head;
      Node *t = new Node;
      if(head == NULL){
        std::cout << num << std::endl;
        head = t;
        head->num = num;
        head->weight = weight;
        head->next = NULL;
      }else{
        while(temp->next != NULL){
          temp = temp->next;
        }
        temp->next = t;
        t->num = num;
        t->weight = weight;
        t->next = NULL;
      }
    }
    ~LinkedList(){
      Node *temp = NULL;
      while(head != NULL){
        temp = head;
        head = head->next;
        std::cout << temp->num << " Deleted" << std::endl;
        delete temp;
      }
    }
};

class Graph{
private:
  LinkedList arr[5];
public:
  void insert(int index, int num, int weight){
    arr[index].insert(num, weight);
  }
  ~Graph(){
    for(int i = 0; i < 5; i++){
      arr[i].~LinkedList();
    }
  }
};

int main(){
  Graph g1;
  g1.insert(0, 1, 5);
  g1.insert(0, 2, 3);
  return 0;
}
