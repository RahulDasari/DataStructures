#include <cstdlib>
#include<iostream>
using namespace std;

struct Item{
    int i;
    Item *next; 
    Item *prev;
};

Item get_node(int num){
    Item s;
    s.i=num;
    s.next = nullptr;
    s.prev = nullptr;
    return s;
}

struct Stack{
    Item* base;
    Item* top;
    int size;
};

Stack create_stack(){
    Stack s;
    s.base = nullptr;
    s.top = nullptr;
    s.size = 0;
    return s;
}
void add_node(Stack & st , Item & i){
    if(!st.base){
        st.base = &i;
        st.top = &i;
        st.size+=1;
    }
    else{
        st.top->next = &i;
        i.prev = st.top;
        st.top = &i;
        st.size+=1;
    }
}

Item* pop_node(Stack & st){
    if(!st.base){
        return nullptr;
    }
    else{
        Item* ret = st.top;
        st.top = st.top->prev;
        st.size-=1;
        return ret;
    }
}

int main(){
    Stack stack = create_stack();
    Item node1 = get_node(5);
    add_node(stack , node1);
    Item node2 = get_node(10);
    add_node(stack , node2);
    cout<< stack.base->i <<endl;
    cout<< stack.top->i <<endl;
    cout<< pop_node(stack)->i<<endl;
    return 0;
}