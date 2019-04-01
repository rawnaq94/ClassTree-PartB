// Part Two with full exercise //

#include <iostream>
#include "Tree.hpp"
using namespace std;

namespace ariel{
    

Tree::Tree() // copy constructor
{
  rootOfTree = NULL;
  value = 0;
}
    
    
    
Tree::~Tree() //Deletes a vertex if it is Null
{
    if (rootOfTree==NULL) 
       {
           delete rootOfTree;
       }
    else 
       {
           destroy(rootOfTree); 
       }
}     
Tree& Tree::insert(int i) 
{ 
    if (contains(i)) //First search the number if found to throw error
       {  
          throw(" error syntax the tree contains the number")
       }

    NodeT *newNodeT=new NodeT(i); //Creates a vertex
    bool flag=false;
    
    if (rootOfTree==NULL) 
       {
           rootOfTree=newNodeT;
           newNodeT->right=NULL;
           newNodeT->left=NULL;
       }
     else // current vertex is a root of the tree
       {
           NodeT *vertex=rootOfTree;
           while(vertex !NULL && !flag)
                {
                     if(i<vertex->num)
                       {
                          if(vertex->left==NULL)
                            {
                                vertex->left=newNodeT;
                                flag=true;
                            }
                         vertex=vertex->left;
                       }
                     else
                       {
                          if(i>vertex->num)
                            {
                               if(vertex->right==NULL)
                                 {
                                    vertex->right=newNodeT;
                                    flag=true;
                                 }
                              vretex=vertex->right;
                             }
                        }
                  }
     }
    value++;
    return *this;
}

    
    
Tree Tree::remove(int i) { return *this; }

int Tree::size() { return 0; }
    
bool Tree::contains(int i) { return false; }

int Tree::root(){ return 0; }
    
int Tree::parent(int i){ return 0; }
    
int Tree::left(int i) { return 0; }
    
int Tree::right(int i){ return 0; }
    
void Tree::print() { }

    
};
