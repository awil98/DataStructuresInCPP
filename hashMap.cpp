#include <iostream>
#include "chains.h"

class hashTable{
  private:
    LinkedList *HT[10];
  public:
    hashTable(){
      for(int i = 0; i < 10; i++){
        HT[i] = NULL;
      }
    }
    int hash(int key){
      return key%10;
    }
    void insert(int key){
      int index = hash(key);
      this->HT[index]->sortedInsert(key);
    }
    void getKey(int key){
      int index = hash(key);
      HT[index]->search(key);
    }
    ~hashTable(){
      std::cout << "Called" << std::endl;
      for(int i=0; i < 10; i++){
        this->HT[i]->~LinkedList();
      }
    }
};

int main(){
  hashTable h1;
  h1.insert(10);
  h1.insert(20);
  return 0;
}
