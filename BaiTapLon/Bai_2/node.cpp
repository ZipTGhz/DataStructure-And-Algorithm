template<class T>
class node
{
private:
    T data;
    node<T> *left;
    node<T> *right;

public:
    node(T __data) : data(__data), left(nullptr), right(nullptr) {}
    void setData(T __data) { data = __data; }
    void setLeft(node<T> *_left) { left = _left; }
    void setRight(node<T> *_right) { right = _right; }

    T getData() { return data; }
    node<T> *getLeft() { return left; }
    node<T> *getRight() { return right; }
};