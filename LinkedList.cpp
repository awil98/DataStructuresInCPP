#include <iostream>
#include <limits>
#define INT_MIN std::numeric_limits<int>::min()

class Node{
        public:
                int num;//A number
                Node *next;//A pointer the next Node
};
class LinkedList{
        Node *first;//pointer to first Node
        public:
                LinkedList(int num){
                        //create first node in constructor and set it as my first Node for this linked list
                        this->first = new Node;
                        this->first->num = num;
                        this->first->next = NULL;
                }
                void createNodeIT(int num){
                        Node *p = new Node;//create new node
                        p->num = num;//assign num value
                        p->next = NULL;//set its next value to null
                        Node *temp = this->first;
                        while(temp->next != NULL){
                                temp = temp->next;//loop through to the last node
                        }
                        temp->next = p;//set the current node to next node
                }
                void display(){
                        Node *temp = this->first;//creating a pointer copy to the first element
                        while(temp != NULL){
                                std::cout << temp->num << std::endl;
                                temp = temp->next;
                        }
                }
                void countOfElements(){
                         int count = 0;
                         Node *temp = this->first;
                         while(temp != NULL){
                                 count++;
                                 temp = temp->next;
                         }
                         std::cout << "The count: " << count << std::endl;
                 }
                 void findElement(int key){
                       Node *temp = this->first;
                       bool found = false;
                       while(temp != NULL){
                               if(temp->num == key){
                                       std::cout << "Element found" << "\n";
                                       found = true;
                                       break;
                               }
                               temp = temp->next;
                       }
                       if(found == false){
                               std::cout << "Element not found" << "\n";
                       }

               }
               void insertAsFirst(int num){
                       Node *temp = new Node;
                       temp->num = num;
                       temp->next = this->first;
                       this->first = temp;
               }
               ~LinkedList(){
                       Node *temp = NULL;
                       while(this->first != NULL){
                               temp = this->first;
                               this->first = this->first->next;
                               std::cout << "Deleting Node with value " << temp->num << std::endl;
                               delete temp;
                       }
              }
};

int main(){
        LinkedList l1(5);
        l1.createNodeIT(8);
        l1.createNodeIT(10);
        l1.countOfElements();
        l1.findElement(10);
        l1.display();

}
