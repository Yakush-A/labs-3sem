#include"tree.h"

template<typename T>
inline const T& Tree<T>::inOrderIterator::operator *()
{
    if(currNode != nullptr) return currNode->nodeData;
    else
    {
        static T buffer;
        return buffer;
    }
}

template<typename T>
inline bool Tree<T>::inOrderIterator::operator == (const Tree<T>::inOrderIterator& other)
{
    return currNode == other.currNode;
}

template<typename T>
inline bool Tree<T>::inOrderIterator::operator != (const Tree<T>::inOrderIterator& other)
{
    return currNode != other.currNode;
} 

template<typename T>
inline Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator++(int)
{
    inOrderIterator buffer(currNode);
    if(currNode == nullptr) return *this;

    else if(currNode->right != nullptr)
        currNode = currNode->right->get_min();
    else if(currNode->parent!=nullptr)
    {
        Tree<T>::Node* tmp = currNode;
        while(tmp = tmp->parent)
        {
            if(tmp == nullptr) break;
            
            if(currNode != tmp->right) break;
            currNode = tmp;
        }

        currNode = tmp;
    } 
    return *this;

    return buffer;   
}
template<typename T>
inline Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator++()
{
    if(currNode == nullptr) return *this;

    else if(currNode->right != nullptr)
        currNode = currNode->right->get_min();
    else if(currNode->parent!=nullptr)
    {
        Tree<T>::Node* tmp = currNode;
        while(tmp = tmp->parent)
        {
            if(tmp == nullptr) break;
            
            if(currNode != tmp->right) break;
            currNode = tmp;
        }

        currNode = tmp;
    } 
    return *this;
}
template<typename T>
inline Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator--(int)
{
    inOrderIterator buffer(currNode);

    if(currNode == nullptr) return *this;

    else if(currNode->left != nullptr)
        currNode = currNode->left->get_max();
    else if(currNode->parent!=nullptr)
    {
        Tree<T>::Node* tmp = currNode;
        while(tmp = tmp->parent)
        {
            if(tmp == nullptr) break;
            
            if(currNode != tmp->left) break;
            currNode = tmp;
        }

        currNode = tmp;
    } 
    return buffer;
}
template<typename T>
inline Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator--()
{
    if(currNode == nullptr) return *this;

    else if(currNode->left != nullptr)
        currNode = currNode->left->get_max();
    else if(currNode->parent!=nullptr)
    {
        Tree<T>::Node* tmp = currNode;
        while(tmp = tmp->parent)
        {
            if(tmp == nullptr) break;
            
            if(currNode != tmp->left) break;
            currNode = tmp;
        }

        currNode = tmp;
    } 
    return *this;
}

template<typename T>
inline bool Tree<T>::inOrderIterator::operator > (const Tree<T>::inOrderIterator& other)
{
    if(currNode == nullptr) return true;
    else if(other.currNode == nullptr) return false;

    if(this->currNode == other.currNode) return false;

    if(this->currNode->nodeData == other.currNode->nodeData)
        return this->currNode->get_index() > other.currNode->get_index();

    else return this->currNode->nodeData > other.currNode->nodeData;
}

template<typename T>
inline bool Tree<T>::inOrderIterator::operator >= (const Tree<T>::inOrderIterator& other)
{
    if(this->currNode == other.currNode) return true;

    if(this->currNode->nodeData == other.currNode->nodeData)
        return this->currNode->get_index() > other.currNode->get_index();

    else return this->currNode->nodeData > other.currNode->nodeData;
}

template<typename T>
inline bool Tree<T>::inOrderIterator::operator < (const Tree<T>::inOrderIterator& other)
{
    if(this->currNode == other.currNode) return false;

    if(this->currNode->nodeData == other.currNode->nodeData)
        return this->currNode->get_index() < other.currNode->get_index();

    else return this->currNode->nodeData < other.currNode->nodeData;
}

template<typename T>
inline bool Tree<T>::inOrderIterator::operator <= (const Tree<T>::inOrderIterator& other)
{
    if(this->currNode == other.currNode) return true;

    if(this->currNode->nodeData == other.currNode->nodeData)
        return this->currNode->get_index() < other.currNode->get_index();

    else return this->currNode->nodeData < other.currNode->nodeData;
}
        