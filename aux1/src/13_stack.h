#include <vector>

template<class T>
class Stack
{
public:
    Stack();
    T pop(void);
    void push(T &elem);
    T top(void) const;
    int size(void) const;

private:
    std::vector<T> m_stack;
};

template<class T>
Stack<T>::Stack()
{}

template<class T>
T Stack<T>::pop()
{
    T elem = top();
    m_stack.pop_back();
    return elem;
}

template<class T>
T Stack<T>::top() const
{
    return m_stack.back();
}

template<class T>
void Stack<T>::push(T &elem)
{
    m_stack.push_back(elem);
}

template<class T>
int Stack<T>::size() const
{
    return m_stack.size();
}
