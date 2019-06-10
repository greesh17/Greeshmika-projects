#pragma once
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))

using namespace std;
 
struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}*root;
 
class avlTree
{
   
   public:
        int height();
        int getsize();
        bool insert(int);
        void display();
        bool find(int);  
        
        avlTree()   // constructor
           {
            root = NULL;
          }
       ~avlTree()  // destructor
        {
         if(root) delete root;  
        }
    
        
   private:
        int height(avl_node *);
        int diff(avl_node *);
        int getsize(avl_node *);
        avl_node *doubleright_rotation(avl_node *);
        avl_node *doubleleft_rotation(avl_node *);
        avl_node *leftright_rotation(avl_node *);
        avl_node *rightleft_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, int );
        void display(avl_node *, int);
        bool find(avl_node *, int);
        
        avl_node* root;
};
 

int avlTree::height()
{
    return height(root);
}
int avlTree::height(avl_node *temp)  // to find height of tree
{
    int total_height = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        total_height = max_height + 1;
    }
    return total_height;
}
int avlTree::getsize()
 {
  return getsize(root);   
 }
int avlTree::getsize(avl_node *temp)  // to find size of tree
{  
    if (temp == NULL)  
        return 0;  
    else
        return(getsize(temp->left) + 1 + getsize(temp->right));  
} 

bool avlTree::find(int item)
{
    return find(root, item);
}

bool avlTree::find(avl_node *temp, int value) // find the desired value in AVL tree
{
	if (temp == NULL)
	{
        return false;
	}
	else if (value == temp->data)
	{
        return true;
    }
    else if (value < temp->data)
	{
		return find(temp->left, value);
	}
	else
	{
		return find(temp->right, value);
	}
}
int avlTree::diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 

avl_node *avlTree::doubleright_rotation(avl_node *parent) // right-right rotation
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avlTree::doubleleft_rotation(avl_node *parent) //left-left rotation
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 

avl_node *avlTree::leftright_rotation(avl_node *parent) //left-right rotation
{
    avl_node *temp;
    temp = parent->left;
    parent->left = doubleright_rotation (temp);
    return doubleleft_rotation (parent);
}
 

avl_node *avlTree::rightleft_rotation(avl_node *parent) // right- left rotation
{
    avl_node *temp;
    temp = parent->right;
    parent->right = doubleleft_rotation (temp);
    return doubleright_rotation (parent);
}
 

avl_node *avlTree::balance(avl_node *temp) //to find balance of the left and right of AVL tree
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = doubleleft_rotation (temp);
        else
            temp = leftright_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rightleft_rotation (temp);
        else
            temp = doubleright_rotation (temp);
    }
    return temp;
}
 
bool avlTree::insert(int value)
{
    if (find(value))
            {
                cout<<"value already exists"<<endl;
         return false;
            }
    else
    {
   root = insert(root, value);
   return true;
    }
}

avl_node *avlTree::insert(avl_node *root, int value) // inserting unique values into AVL tree
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

void avlTree::display()
{
    if (root == NULL)
    {
        cout<<"Tree is Empty"<<endl;
    }
    else
    {
        int level = 0;
        display(root,level);
    }
}
 

void avlTree::display(avl_node *ptr, int level) // To Display AVL tree
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"                      ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}