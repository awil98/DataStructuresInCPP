class Stack{
        private:
                int size;//size of array
                int top;//first element in array
                int *p;//pointer to array in heap
        public:
                Stack(int size){
                        this->top = -1;
                        this->size = size;
                        p = new int[size];
                }

                void push(int n){
                        if(top == size-1){
                                std::cout << "Stack Overflow" << std::endl;
                        }else{
                                top++;
                                p[top] = n;
                        }
                }
                void pop(){
                        if(top == -1){
                                std::cout << "Stack empty" << std::endl;
                        }else{
                                std::cout << "Element removed: " << p[top] << std::endl;
                                top--;
                        }
                }
                void peek(int index){
                        if(top == -1){
                                std::cout << "Stack empty" << std::endl;
                        }else{
                                std::cout << p[top-index+1] << std::endl;
                        }
                }

                void stackTop(){
                        if(top == -1){
                                std::cout << "Stack empty" << std::endl;
                        }else{
                                std::cout << "Top: " << p[top] << std::endl;
                        }
                }
                void isEmpty(){
                        if(top == -1){
                                std::cout << "Stack is empty" << std::endl;
                        }else{
                                std::cout << "No it's not empty" << std::endl;
                        }
                }
                void isFull(){
                        if(top == size-1){
                                std::cout << "Stack is full" << std::endl;
                        }else{
                                std::cout << "Stack isn't full" << std::endl;
                        }
                }
};
int main(){
        Stack s1(5);
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.push(4);
        s1.pop();
        s1.peek(1);
        s1.stackTop();
        s1.isEmpty();
        s1.isFull();
        return 0;
}
