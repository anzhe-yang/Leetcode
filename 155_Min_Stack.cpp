/** 问题描述：
 *  设计一个栈结构，使它支持 push pop top getMin 操作。
 *  getMin 是在 O(N) 时间复杂度内返回最小的值。
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:

    MinStack() 
    {}
    
    void push(int x) 
    {
        real_stack.push(x);
        if (min_stack.empty() || min_stack.top() >= x)//这个语句很关键
        //其一：必须先判断最小栈是否为空，如果为空就直接开始下一步，如果先判断最小值是否大于x，则会造成内存溢出，即最小栈没有top元素
        //其二：当x小于等于最小栈栈顶时，就压入x。这个等于很关键，如果x和当前最小值相等时也要压入栈，因为弹出一个最小值之后，应还有一个最小值
        {
            min_stack.push(x);
        }
    }
    
    void pop() 
    {
        if (min_stack.top() == real_stack.top())
        {
            min_stack.pop();
        }
        real_stack.pop();  
    }
    
    int top() 
    {
        return real_stack.top();
    }
    
    int getMin() 
    {
        return min_stack.top();
    }

private:
    stack<int> real_stack;
    stack<int> min_stack;
};

int main(int argc, char const *argv[])
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    assert(obj->getMin() == -3);
    obj->pop();
    assert(obj->top() == 0);
    assert(obj->getMin() == -2);

    return 0;
}
