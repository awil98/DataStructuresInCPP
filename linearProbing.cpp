#include <iostream>

class HT{
  private:
    int Ht[10] = {0};
  public:
    int hash(int key){
      return key%10;
    }
    int probe(int key){
      int index = hash(key);
      int i = 0;
      while(Ht[(index+i)%10] != 0){
        i++;
      }
      return (index+i)%10;
    }
    void insert(int key){
      int index = hash(key);

      if(Ht[index] != 0){
        index=probe(key);
      }
      Ht[index] = key;
    }
    void search(int key){
      int index = hash(key);
      int i = 0;
      while(Ht[(index+i)%10] != key ){
        if(Ht[index+i] == 0){
          std::cout << "Key not found" << std::endl;
          return;
        }
        i++;
      }
       std::cout << (index+i)%10 << std::endl;
    }
};

int main(){
  HT ht;
  ht.insert(12);
  ht.insert(25);
  ht.insert(35);
  ht.insert(26);
  ht.search(30);
  return 0;
}
