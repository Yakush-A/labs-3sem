/*
template<typename T>
typename Tree<T>::inOrderIterator Tree<T>::find(const T& data)
{
    return inOrderIterator(root->find(data));
}
*/

//перегрузка вывода дерева
template<typename T>
std::ostream& operator << (std::ostream& os, const Tree<T>& container)
{
    if(!container.empty()) container.root->inOrderTraversal(os);

    return os;
}


//метод вставки узла
template<typename T>
void Tree<T>::insert(T data)
{
    root = root->add_node(data);
}

//метод удаления узла
template<typename T>
void Tree<T>::erase(const T& data)
{
    root = root->del_node(data);

}

//метод "рисоваия" дерева
template<typename T>
void Tree<T>::print() const
{
    if(root != nullptr) root->print_tree(0);
}

//метод сравнения деревьев на идентичность
template<typename T>
inline bool Tree<T>::operator == (const Tree<T>& other) const
{
    return root->is_equal(other.root);
}

//перегрузка присваивания
template<typename T>
inline Tree<T>& Tree<T>::operator = (const Tree<T>& src)
{
    root->erase_tree();
    root = src.root->get_copy(src.root);
    return *this;
}

//метод проверки дерева на отсутствие узлов
template<typename T>
inline bool Tree<T>::empty() const
{
    return root == nullptr;
}

//метод определения, есть ли узел в дереве
template<typename T>
inline bool Tree<T>::contains(const T& data) const
{
    return root->find(data) != nullptr;   
}



// template<typename T>
// inline void Tree<T>::shitterface()
// {
//     while(true)
//     {
//         this->print();
//         T buffer;
//         char option;
//         std::cin>>option;  
//         switch (option)
//         {
//         case 'a':
//             std::cout<<"enter new node: ";
//             std::cin>>buffer;
//             this->insert(buffer);
//             break;
//         case 'd':
//             std::cout<<"enter node to erase: ";
//             std::cin>>buffer;
//             this->erase(buffer);
//             break;
//         case 'x':
//             return;
//         default:
//             break;
//         }
//     }
// }


/*
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
inline typename Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator++(int)
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
inline typename Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator++()
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
inline typename Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator--(int)
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
inline typename Tree<T>::inOrderIterator Tree<T>::inOrderIterator::operator--()
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
*/      

/*
template <typename T>
inline typename Tree<T>::inOrdedIterator Tree<T>::begin()
{
    if(root == nullptr) return inOrdedIterator(root); 
    
    Tree<T>::Node* tmp = root;
    while(tmp->left != nullptr) tmp = tmp->left;

    return inOrdedIterator(tmp);
}
template <typename T>
inline typename Tree<T>::inOrdedIterator Tree<T>::end()
{
    return inOrdedIterator(nullptr);
}
*/
