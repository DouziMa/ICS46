#include "bstree.h"
#include <iostream>
#include <string>
#include <utility> //for swap()

using namespace std;

BSTree::BSTree() : BST("BSTree"){
    root = nullptr;
}

//Helper function to insert a new node with the given key into the BS tree rooted at t
Node * BSTree::insert_node(Node * t, string key){
    if(t == nullptr){
        t = new Node(key);
    }
    else if(key < t->key){
        t->left = insert_node(t->left,key);
    }
    else{
        t->right = insert_node(t->right,key);
    }
    t->height = compute_height(t);
    return t;
}

//Helper function to search for a node with the given key in the BS tree
Node * BSTree::find_node(Node * t, string key){
    if(t == nullptr) return t;
    if(key < t->key){
        return find_node(t->left,key);
    }
    else if (key > t->key){
        return find_node(t->right,key);
    }
    return t;
}

//Helper function to return a ptr to the node with the smallest key in the BS tree
Node * BSTree::left_most(Node * t)
{
    while (t->left != nullptr) {
        t = t->left;
    }
    return t;
}

//Helper function to delete the node with the given key in the BS tree
Node * BSTree::delete_node(Node * t, string key){
    if(!t) return t;
    if(key < t->key){
        t->left = delete_node(t->left,key);
    }
    else if (key > t->key){
        t->right = delete_node(t->right,key);
    }
    else{
        //CASE 1: Node has one or no child
        if(t->left == nullptr || t->right == nullptr){
            Node *child = t->left ? t->left : t->right;
            //No child case
            if(child == nullptr){
                child = t;
                t = nullptr;
            }else{ // One child case
                *t = *child; // copy data up from child
            }
            delete child;
        }
        //Case 2: Node has two children
        else{
            Node * succ = left_most(t->right);
            swap(t->key, succ->key);
            t->right = delete_node(t->right, key);
        }
    }
    return t;
}

//Helper function to compute the height of the BS tree
int BSTree::compute_height(Node * t){
    if(t == nullptr){
        return -1;
    }
    int left_height = t->left == nullptr ? 0 : t->left->height;
    int right_height = t->right == nullptr ? 0 : t->right->height;
    return 1 + max(left_height, right_height);
}

void BSTree::insert(const string & key){
    root = insert_node(root,key);
    count++;
}

bool BSTree::find(const string & key) const{
    return find_node(root,key) != nullptr;
}

void BSTree::remove(const string & key){
    root = delete_node(root, key);
    count--;
}

bool BSTree::is_empty() const{
    return root == nullptr;
}

int BSTree::get_height() const{
    return compute_height(root);
}