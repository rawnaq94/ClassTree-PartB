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
          throw(" error syntax the tree contains the number");
       }

    NodeT *newNodeT=new NodeT(i); //Creates a vertex
    bool flag=false;
    
    if (rootOfTree==NULL) 
       {
           rootOfTree=newNodeT;
           newNodeT->rightChild=NULL;
           newNodeT->leftChild=NULL;
       }
     else // current vertex is a root of the tree
       {
           NodeT *vertex=rootOfTree;
           while(vertex !=NULL && !flag)
                {
                     if(i<vertex->num)
                       {
                          if(vertex->leftChild==NULL)
                            {
                                vertex->leftChild=newNodeT;
                                flag=true;
                            }
                         vertex=vertex->leftChild;
                       }
                     else
                       {
                          if(i>vertex->num)
                            {
                               if(vertex->rightChild==NULL)
                                 {
                                    vertex->rightChild=newNodeT;
                                    flag=true;
                                 }
                              vretex=vertex->rightChild;
                             }
                        }
                  }
     }
    value++;
    return *this;
}

    
    
Tree& Tree::remove(int i)
{
    if (!contains(i)) //First search the number if it is not found you can not delete it so we will throw an error
       {  
          throw(" error syntax the tree is not contains the number");
       }
    Remove(rootOfTree, i);
    value--;
    return *this;
}
    
 
NodeT* Tree::Remove(NodeT *root, int num)
{
    if(root==NULL) 
      {
         return root;
      }
    else if(num<root->num) root->leftChild=Remove(root->leftChild,num);
    else if(num>root->num) root->rightChild=Remove(root->rightChild,num);
    else //Here we found him
       {
          if(root->leftChild==NULL && root->rightChild==NULL) //vertex whith out child
            {
              root=NULL;
            }
             else if(root->leftChild==NULL) //vertex whith on child
                    {
                       NodeT *cond=root;
                       root=root->rightChild;
                    }
             else if(root->rightChild==NULL) 
                    {
                       NodeT *cond=root;
                       root=root->leftChild;
                    }
           else // vertex whith two child
             {
                NodeT *cond=Min(root->rightChild);
                root->num=cond->num;
                root->rightChild=Remove(root->rightChild,cond->num);
             }
         }
    return root;
}
    
    
 
NodeT *Tree::Min(NodeT * vertex)
{
    while(vertex->leftChild!=NULL)
    {
        vertex=vertex->leftChild;
        return vertex;
    }
}
             

int Tree::size()
{
    return value;
}
    
    
bool Tree::contains(int i) 
{
    NodeT *vertex=rootOfTree;
    while(vertex!=NULL)
    {
        if(vertex->num==i)
          {
            return true;
          }
        if(i<vertex->num)
          {
            vertex=vertex->leftChild;
          }
     else
     {
         if(i>vertex->num)
           {
             vertex=vertex->rightChild;
           }
     }
    }
    return false;
}
    
    
   
int Tree::root()
{
    if(rootOfTree==NULL)
      {
        throw("this root is null");
      }
   return rootOfTree->num;
}
    
    
int Tree::parent(int i)
{
    if(rootOfTree==NULL)
      {
        throw("this tree is null");
      }
    if(rootOfTree->num==i)
      {
        throw("no parent");
      }
    if(!contains(i))
      {
        throw("error syntax the tree is not contains the number");
      }
  NodeT *vertex=rootOfTree;
    while(vertex!=NULL)
         {
             if(left(vretex->num)==i || right(vertex->num)==i)
               {
                 return vertex->num;
               }
             if(i<left(vertex->num))
             {
                 vertex=vertex->leftChild;
             }
              else
              {
                  vertex=vertex->rightChild;
              }
    }
    return 0;
}

    
int Tree::left(int i) 
{
    NodeT *vertex=getNodeT(i);
    if(vertex->leftChild==NULL)
    {
        throw("no left child");
    }
    else
    {
        return (vertex->leftChild)->num;
    }
}
    
 
NodeT* Tree::getNodeT(int i)
{
     if(rootOfTree==NULL)
     {
         throw("no vertex the tree is empty");
     }
    if(!contains(i))
    {
        throw("the tree is not exist this number");
    }
 NodeT *vertex=rootOfTree;
    while(vertex!=NULL)
    {
        if(vertex->num==i)
        {
            return vertex;
        }
        if(i<vertex->num)
        {
            vertex=vertex->leftChild;
        }
        else
        {
            vertex=vertex->rightChild;
        }
    }
   return vertex;
}
  
    
         
int Tree::right(int i)
{
     NodeT *vertex=getNodeT(i);
    if(vertex->rightChild==NULL)
    {
        throw("no right child");
    }
    else
    {
        return (vertex->rightChild)->num;
    }
}
    
    

    
void Tree::destroy(NodeT *i)
{
    if(i!=NULL)
    {
        destroy(i->leftChild);
        destroy(i->rightChild);
        delete(i);
    }
}
    
    
void Tree::In(NodeT * x)
{
    if(x!=NULL)
    {
        In(x->leftChild);
        cout << "--" << x->num;
        In(x->rightChild);
    }
}
    
void Tree::print() 
{
   cout << "In : "; 
    In(rootOfTree);
}

    
};
