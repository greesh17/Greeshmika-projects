#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
#include "AvlTree.h"

using namespace std;
 

int main()
{
    int choice, item,element;
    avlTree avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.Display size of AVL Tree"<<endl;
        cout<<"4.Find element in AVL Tree"<<endl;
        cout<<"5.Display height of AVL Tree"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            avl.insert(item);
            break;
        case 2:
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display();
            break;
       case 3:
            
              cout<<"Size of AVL Tree:"<<endl;
              cout << avl.getsize()<< endl; 
              break;
        case 4 :
             cout <<"Enter the value to be found: ";
             cin>>element;
             cout << "find " << element << " returns " << avl.find(element) << endl;
             break;
        case 5:
            cout<<"Height of AVL Tree:"<<endl;
            cout<<avl.height()<<endl;
            break;
        case 6:
            exit(1);    
            break;
        default:
            cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}