#pragma once
#ifndef TREE_H
#define TREE_H

#include<bitset>
#include"node.h"


template <typename T>
class Tree
{
private:
    Node<T>* root;                                 //корень дерева

public:
    //конструкторы
    Tree() : root(nullptr)
    {
    }
    Tree(const T& src) : root(nullptr)
    {
        insert(src);
    }
    Tree(std::initializer_list<T> initList) : root(nullptr)
    {
        auto it = initList.begin();
        for(it; it<initList.end(); it++) insert(*it);
    }

    //конструктор копирования
    Tree(const Tree<T>& src) : root(nullptr)
    {
        root = src.root->get_copy(src.root);
    }

    //деструктор
    ~Tree()
    {
        if(root != nullptr) root->erase_tree();
    }

    
    inline void insert(T data);                 //метод вставки узла
    inline void erase(const T& data);           //метод удаления узла
    inline bool empty() const;                  //метод проверки дерева на отсутствие узлов
    inline bool contains(const T& data) const;  //метод определения, есть ли в дереве узел

    void print() const;                         //метод "рисования" дерева

    //перегрузка вывода контейнера
    template<typename U>
    friend std::ostream& operator << (std::ostream& os, const Tree<U>& container);  

    //перегрузка сравнения деревьев на идентичность
    inline bool operator == (const Tree<T>& other) const;
    
    //перегрузка присваивания
    inline Tree<T>& operator = (const Tree<T>& src);

/*
    class inOrderIterator
    {
    private:
        Node* currNode;

    public:
        inOrderIterator() : currNode(nullptr)
        {
        }
        inOrderIterator(Node* startNode) : currNode(startNode)
        {
        }
        inOrderIterator(inOrderIterator& src) = default;
        ~inOrderIterator() = default;

        inline const T& operator *();

        inline bool operator == (const inOrderIterator& other);
        inline bool operator != (const inOrderIterator& other);

        inline inOrderIterator operator++(int);
        inline inOrderIterator operator++();
        inline inOrderIterator operator--(int);
        inline inOrderIterator operator--();

        inline bool operator > (const inOrderIterator& other);
        inline bool operator >= (const inOrderIterator& other);
        inline bool operator < (const inOrderIterator& other);
        inline bool operator <= (const inOrderIterator& other);  
    };

    inOrderIterator find(const T& data);

    inline inOrderIterator begin();
    inline inOrderIterator end();
*/

};

#include"tree.tpp"

#endif //TREE_H
