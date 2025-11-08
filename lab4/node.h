#pragma once
#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<iomanip>

template<typename T>
class Node
{
private:
    Node *left, *right, *parent;            //указатели на левое, правое поддеревья и указатель на родительский узел
    int height;                             //высота узла 
    T nodeData;                             //данные узла, его ключ

    /* 
    friend class inOrderIterator;*/

public:
    //конструкторы
    Node() : left(nullptr), right(nullptr), parent(nullptr), height(0), nodeData{} 
    {
    }   
    Node(T data) : left(nullptr), right(nullptr), parent(nullptr), height(0), nodeData(data)
    {
    }

    //деструктор
    ~Node() = default;

    
    Node* del_min();                        //вспомогательный метод удаления минимального узла
    Node* get_min();                        //вспомогательный метод получения минимального узла
    Node* get_max();                        //вспомогательный метод получения максимального узла
    inline unsigned long get_index();       //вспомогательный метод получения "индекса" узла   
    inline int get_height();                //вспомогательный метод получения высоты узла
    inline void update_height();            //вспомогательный метод обновления высоты узла 
    inline int get_bf();                    //вспомогательный метод получения фактора балансировки
    
    //вспомогательный метод для вывода дерева в симметричном обходе
    void inOrderTraversal(std::ostream& os);

    inline Node* balance();                 //метод балансировки узла
    inline Node* rotate_left();             //метод "левого" поворота
    inline Node* rotate_right();            //метод "правого" поворота
    

    Node* add_node(T data);                 //метод добавления узла в дерево
    Node* del_node(const T& data);          //метод удаления узла из дерева по ключу
    void erase_tree();                      //метод очистки дерева
    Node* get_copy(Node* src);              //метод копирования дерева 
    void print_tree(unsigned margin = 0);   //метод "рисования" дерева
    bool is_equal(Node* node);              //метод сравнения деревьев на идентичность
    inline Node* find(const T& data);       //метод поиска узла


};

#include"node.tpp"

#endif