//
// Created by kiots on 11/20/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_AVLTREE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_AVLTREE_H

#include <utility>

using namespace std;

//key(node): word, value: vector<article_number>
template<typename K, typename V>
class AVLTree {

private:
    class AVLNode {
    public:
        K key;//string word
        V value;//vector<article,
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode(const K &the_key, const V &the_value, AVLNode *_left, AVLNode *_right, int _height = 0)
                : key(the_key), value(the_value), left(_left), right(_right), height(_height) {}
    };

    AVLNode *root;

    V &insert(const K &x, const V &y, AVLNode *&node) {//pass function in parameter: function object
        //...overloads parentheses operator
        if (node == nullptr) {
            node = new AVLNode(x, y, nullptr, nullptr);
            return node->value;
        } else if (x < node->key)//std strings can be compared with <
            return insert(x, y, node->left);
        else if (node->key < x)//only < operator overloaded
            return insert(x, y, node->right);
        else if (x == node->key)
            return node->value;
        balance(node);
    }

    void balance(AVLNode *&node) {
        if (node == nullptr)
            return;
        if (height(node->left) - height(node->right) > 1) {
            if (height(node->left->left) >= height(node->left->right))
                rotate_left_child(node);
            else
                double_rotate_left_child(node);
        } else if (height(node->right) - height(node->left) > 1)
            if (height(node->right->right) >= height(node->right->left))
                rotate_right_child(node);
            else
                double_rotate_right_child(node);

        node->height = max(height(node->left), height(node->right)) + 1;
    }

    void rotate_left_child(AVLNode *&node) {
        AVLNode *key_node = node->left;
        node->left = key_node->right;
        key_node->right = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        key_node->height = max(height(key_node->left), node->height) + 1;
        node = key_node;
    }

    void double_rotate_left_child(AVLNode *&node) {
        rotate_right_child(node->left);
        rotate_left_child(node);
    }

    void rotate_right_child(AVLNode *&node) {
        AVLNode *key_node = node->right;
        node->right = key_node->left;
        key_node->left = node;
        node->height = max(height(node->right), height(node->left)) + 1;
        key_node->height = max(height(key_node->right), node->height) + 1;
        node = key_node;
    }

    void double_rotate_right_child(AVLNode *&node) {
        rotate_left_child(node->right);
        rotate_right_child(node);
    }

    AVLNode* find(AVLNode *&node, K key) {
        if (node == nullptr || node->key == key) return node;

        if(key < node->key)
            return find(node->left, key);
        if(key > node->key)
            return find(node->right, key);
    }

    void makeEmpty(AVLNode *&node) {
        if (node == nullptr) return;
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
    }

    int max(int x, int y) {
        if (x > y) return x;
        else return y;
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() { makeEmpty(root); }

    V &insert(const K &x, const V &y) {
        return insert(x, y, root);
    }

    V& find(K key) {
        return find(root, key)->value;
    }

    int height(AVLNode *node) {
        return (node == nullptr ? -1 : node->height);
    }
};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_AVLTREE_H
