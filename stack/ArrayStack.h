#ifndef ARRAY_STACK_
#define ARRAY_STACK_
#define Stack_Size 100

class stack_fixed
{
    private:
        int stack_f[Stack_Size];
        int top_index;
    public:
        stack_fixed();
        ~stack_fixed();
        void push(int num);
        int pop();
        int top()const;
        bool isEmpty(){return top_index==-1;};
};

#endif