
#include <iostream>
#include <vector>

using namespace std;

template <typename Keys, typename T>
class Node
{
private:
    Keys key;
    T value;
    // Node<Keys, T> *parent;
    Node<Keys, T> *left;
    Node<Keys, T> *right;

public:
    Node(Keys key = 0, T value = 0) : key(key), value(value), left(nullptr), right(nullptr) {}

    Keys getKey() { return key; }
    T getValue() { return value; }
    // Node<Keys, T> *getParent() { return parent; }
    Node<Keys, T> *getLeft() { return left; }
    Node<Keys, T> *getRight() { return right; }

    void setKeys(Keys _key) { key = _key; }
    void setValue(T _value) { value = _value; }
    // void setParent(Node<Keys, T> *p) { parent = p; }
    void setLeft(Node<Keys, T> *p) { left = p; }
    void setRight(Node<Keys, T> *p) { right = p; }

    int hasLeft() { return left != nullptr; }
    int hasRight() { return right != nullptr; }
};

template <class Keys, class T>
class BinarySearchTree
{
private:
    Node<Keys, T> *root = nullptr;
    long long _size = 0;

    Node<Keys, T> *insert(Node<Keys, T> *_root, const Keys &_key, const T &_data)
    {
        if (!_root)
        {
            Node<Keys, T> *_root = new Node<Keys, T>(_key, _data);
            return _root;
        }
        if (_key < _root->getKey())
            _root->setLeft(insert(_root->getLeft(), _key, _data));
        else
            _root->setRight(insert(_root->getRight(), _key, _data));
        return _root;
    }

    void inOrder(Node<Keys, T> *_root)
    {
        if (!_root)
            return;
        inOrder(_root->getLeft());
        cout << _root->getKey() << " - " << _root->getValue() << endl;
        inOrder(_root->getRight());
    }

    Node<Keys, T> *search(Node<Keys, T> *_root, const Keys &_key)
    {
        if (!_root)
            return nullptr;
        if (_root->getKey() == _key)
            return _root;

        if (_key < _root->getKey())
            return search(_root->getLeft(), _key);
        else
            return search(_root->getRight(), _key);
        return nullptr;
    }

    Node<Keys, T> *remove(Node<Keys, T> *_root, const Keys &_key)
    {
        Node<Keys, T> *curr = _root, *prev = nullptr;
        while (curr && curr->getKey() != _key)
        {
            prev = curr;
            if (_key < curr->getKey())
                curr = curr->getLeft();
            else
                curr = curr->getRight();
        }

        // Case 0: Not found
        if (!curr)
            return _root;
        // Case 1 + 2: A leaf node +  Have one child
        if (!curr->getLeft() || !curr->getRight())
        {
            Node<Keys, T> *temp = nullptr;
            if (curr->getLeft())
                temp = curr->getLeft();
            else
                temp = curr->getRight();

            if (prev->getLeft() == curr)
                prev->setLeft(temp);
            else
                prev->setRight(temp);
            delete curr;
        }
        // Case 3: Have two childs
        else
        {
            Node<Keys, T> *parent = nullptr, *temp = curr->getRight();
            while (temp->getLeft())
            {
                parent = temp;
                temp->setLeft(temp->getLeft());
            }

            if (parent)
                parent->setLeft(temp->getRight());
            else
                curr->setRight(temp->getRight());

            curr->setKeys(temp->getKey());
            delete temp;
        }
        return root;
    }

    void deleteRoot(Node<Keys, T> *_root)
    {
        if (!_root)
            return;
        deleteRoot(_root->getLeft());
        deleteRoot(_root->getRight());
        delete _root;
        _size--;
    }

public:
    void insert(const Keys &_key, const T &_data)
    {
        root = insert(root, _key, _data);
        _size++;
    }
    // T search(const Keys &_key) { return search(root, _key); }

    T operator[](const Keys &_key)
    {
        Node<Keys, T> *temp = search(root, _key);
        if (temp)
            return temp->getValue();
        return T();
    }
    void remove(const Keys &_key) { root = remove(root, _key), _size--; }
    void inOrder() { inOrder(root); }
    void clear()
    {
        deleteRoot(root);
        root = nullptr;
    }

    bool empty() { return _size == 0; }
    long long size() { return _size; }

    ~BinarySearchTree() { deleteRoot(root); }
};

main()
{
    BinarySearchTree<string, string> myBST;
    vector<string> english = {"Hard", "Easy", "English", "Japan", "Finger", "Toe", "Daily", "Multiple task"};
    vector<string> vietnamese = {"Kho", "De", "Tieng Anh", "Nhat Ban", "Ngon tay", "Ngon chan", "Hang ngay", "Nhieu nhiem vu"};

    for (int i = 0; i < english.size(); i++)
    {
        myBST.insert(english[i], vietnamese[i]);
    }

    // cout << myBST.size() << endl;
    // myBST.clear();
    // cout << myBST.size() << endl;

    // cout << myBST.search("Toe") << endl;
    // cout << myBST["Toe"] << endl;

    myBST.inOrder();
    cout << endl;

    myBST.remove("Hard");
    myBST.inOrder();

    return 0;
}