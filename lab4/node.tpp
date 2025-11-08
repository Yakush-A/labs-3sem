//метод добавления узла
template<typename T>
Node<T>* Node<T>::add_node(T data)
{
    Node<T>* root;
    
    if(this == nullptr)
    {
        root = new Node<T>(data);
        // root->parent = parentPtr;
        return root;
    }

    if(nodeData > data)
    {
        left = left->add_node(data);
        left->update_height();
        left->parent = this;
    }
    else 
    {
        right = right->add_node(data);
        right->update_height();
        right->parent = this;
    }

    root = this->balance();

    return root;
}

//метод удаления узла по значению
template<typename T>
Node<T>* Node<T>::del_node(const T& data)
{
    if(this == nullptr) return this;

    Node<T>* parentPtr = parent;
    Node<T>* root;

    if(nodeData == data)
    {
        Node<T>* tmp;
        if(left != nullptr && right != nullptr)
        {
            tmp = right->get_min();
            nodeData = tmp->nodeData;
            right = right->del_min();
            if(right != nullptr) right->parent = this;

            root = this->balance();
            root->parent = parentPtr;
            return root;
        }
        else if(left != nullptr)
        {
            tmp = left;
            delete this;
            root = tmp->balance();
            return root;
        }
        else if(right != nullptr)
        {
            tmp = right;
            delete this;
            root = tmp->balance();
            return root;
        }
        else 
        {
            delete this;
            return nullptr;
        }
    }

    else if(nodeData > data)
    {
        left = left->del_node(data);
    }
    else 
    {
        right = right->del_node(data);
    }
    
    root = this->balance();
    root->parent = parentPtr;
    return root;
}

//вспомогательный метод удаления минимального узла
template<typename T>
Node<T>* Node<T>::del_min()
{
    if(this == nullptr) return this;

    Node<T>* parentPtr = parent;

    Node<T>* tmp;
    if(left != nullptr)
    {
        left = left->del_min();
        if(left!=nullptr) left->parent = this;
        return this->balance();
    }
    else
    {
        if(right != nullptr)
        {
            tmp = right;
            tmp->parent = this;
        }
        else tmp = nullptr;
        delete this;
        return tmp;
    }
}

//вспомогательный метод поиска максимального узла
template<typename T>
Node<T>* Node<T>::get_max()
{
    if(this == nullptr) return this;

    Node<T>* tmp = this;
    while(tmp->right != nullptr) 
        tmp = tmp->right;

    return tmp;
}

//вспомогательный метод поиска минимального узла
template<typename T>
Node<T>* Node<T>::get_min()
{
    if(this == nullptr) return this;

    Node<T>* tmp = this;
    while(tmp->left != nullptr) 
        tmp = tmp->left;

    return tmp;
}

//метод балансировки конкретного узла
template<typename T>
inline Node<T>* Node<T>::balance()
{
    int balanceFactor = this->get_bf();
    if(balanceFactor >= -1 && balanceFactor <= 1)
    {
        this->update_height();
        return this;
    }
    Node<T>* parentPtr = parent;

    Node<T>* tmp;
    if(balanceFactor>1)
    {
        if(this->right->get_bf() < 0)
            right = right->rotate_right();
        tmp = this->rotate_left();
    }
    else 
    {
        if(this->left->get_bf() > 0)
            left = left->rotate_left();
        tmp = this->rotate_right();
    }

    tmp->parent = parentPtr;
    tmp->update_height();
    return tmp;
}

//метод обновления высоты узла
template<typename T>
inline void Node<T>::update_height()
{
    if(this == nullptr) return;
    else height = ((right->get_height() > left->get_height()) ?
            right->get_height() : left->get_height()) + 1; 
}

//метод "левого" поворота узла
template<typename T>
inline Node<T>* Node<T>::rotate_left()
{
    if(this == nullptr) return this;
    
    Node<T>* parentPtr = parent;

    Node<T>* root = right;
    Node<T>* tmp = root->left;

    root->left = this;
    this->parent = root;
    this->right = tmp;
    if(tmp!=nullptr) tmp->parent = this;

    root->left->update_height();
    root->update_height();
    root->parent = parentPtr;

    return root;
}
//метод "правого" поворота узла
template<typename T>
inline Node<T>* Node<T>::rotate_right()
{
    if(this == nullptr) return nullptr;

    Node<T>* parentPtr = parent;

    Node<T>* root = left;
    Node<T>* tmp = root->right;

    root->right = this;
    this->parent = root;
    this->left = tmp;
    if(tmp!=nullptr)tmp->parent = this;

    root->right->update_height();
    root->update_height();
    root->parent = parentPtr;

    return root;
}

//метод очистки дерева
template<typename T>
void Node<T>::erase_tree()
{
    if(this != nullptr)
    {
        left->erase_tree();
        right->erase_tree() ;
        delete this;
    }
}

//вспомогательный метод получения фактора балансировки 
template<typename T>
inline int Node<T>::get_bf()
{
    if(this == nullptr) return 0;
    else return right->get_height() - left->get_height(); 
}

//вспомогательный метод получения высоты узла
template<typename T>
inline int Node<T>::get_height()
{
    if(this == nullptr) return -1;
    else return height;
}


//метод для "рисования" дерева
template<typename T>
void Node<T>::print_tree(unsigned margin)
{   
    if(right != nullptr) right->print_tree(margin+7);
    if(this != nullptr) std::cout<<
    std::setw(margin+7)<<
    // std::bitset<10>(nodeData)<<
    nodeData<<
    // "h="<<get_height()<<
    // " addr="<<this<<
    // " par="<<parent<<
    std::endl;
    if(left != nullptr) left->print_tree(margin+7);
}

//вспомогательный метод для вывода содержимого контейнера
template<typename T>
void Node<T>::inOrderTraversal(std::ostream& os)
{
    if(left != nullptr) left->inOrderTraversal(os);
    os<<nodeData<<std::endl;
    if(right != nullptr) right->inOrderTraversal(os);
}

//метод копирования дерева с определенного корня 
template<typename T>
Node<T>* Node<T>::get_copy(Node<T>* src)
{
    if(src == nullptr) return src;
    else 
    {
        Node<T>* tmp = new Node<T>(src->nodeData); 
        tmp->left = get_copy(src->left);
        if(tmp->left != nullptr) tmp->left->parent = tmp; 
        tmp->right = get_copy(src->right);
        if(tmp->right != nullptr) tmp->right->parent = tmp;
        return tmp; 
    }
}

//метод поиска узла дерева
template<typename T>
inline Node<T>* Node<T>::find(const T& data)
{
    if(this == nullptr) return this;
    Node<T>* tmp = this;
    
    while(tmp != nullptr)
    {
        if(tmp->nodeData == data) break;
        else if(tmp->nodeData > data) tmp = tmp->left;
        else tmp = tmp->right;
    }
    return tmp;
}

//вспомогательный метод получения "индекса" узла
template<typename T>
inline unsigned long Node<T>::get_index()
{
    unsigned long index = 0xffffffffffffffff;

    unsigned long bitmap = 1UL<<(8*sizeof(unsigned long)-1);

    for(Node<T>* tmp = this; tmp->parent!=nullptr; tmp = tmp->parent)
    {
        index >>= 1;
        index += bitmap*(tmp->parent->right == tmp);
    }
    return index;
}

//метод сравнения двух деревьев на идентичность
template<typename T>
bool Node<T>::is_equal(Node<T>* node)
{
    if(node == nullptr && node != nullptr ||
        node != nullptr && node == nullptr) return false; 

    else if(node->nodeData == this->nodeData)
    {
        return (
            this->left->is_equal(node->left) == true &&
                this->right->is_equal(node->right) == true
            );
    }
}
