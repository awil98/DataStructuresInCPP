#include <iostream>

class Ht{
  private:
    int HT[10] = {0};
    int elements = 5;
  public:
    int hash(int key){
      return key%10;
    }
    int hash2(int key){
      return (7-(key%7));
    }
    void insert(int key){
      int index = hash(key);
      if(HT[index] == 0){
          HT[index] = key;
          return;
      }
      int i = 1;
      while(HT[index] != 0){
        index = (hash(key) + i++ * hash2(key))%10;
      }
      HT[index] = key;
    }
    void search(int key){
      int index = hash(key);
      if(HT[index] == key){
        std::cout << key << " found." << std::endl;
        return;
      }
      int i = 1;
      bool br = false;
      while(HT[index] != key){
        if(i > elements){
          br = true;
          break;
        }
        index = (hash(key) + i++ * hash2(key))%10;
      }
      if(br){
        std::cout << key << " not found." << std::endl;
        return;
      }
      std::cout << key << " found." << std::endl;
    }
};

int main(){
  Ht ht;
  ht.insert(5);
  ht.insert(25);
  ht.insert(15);
  ht.insert(35);
  ht.insert(95);
  ht.search(15);
  ht.search(10);
  return 0;
}
