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

    
    
Tree& Tree::remove(int i)
{
    if (!contains(i)) //First search the number if it is not found you can not delete it so we will throw an error
       {  
          throw(" error syntax the tree is not contains the number")
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
    else if(num<root->num) root->left=Remove(root->left,num);
    else if(num>root->num) root->right=Remove(root->right,num);
    else //Here we found him
       {
          if(root->left==NULL && root->right==NULL) //vertex whith out child
            {
              root=NULL;
            }
             else if(root->left==NULL) //vertex whith on child
                    {
                       NodeT *cond=root;
                       root=root->right;
                    }
             else if(root->right==NULL) 
                    {
                       NodeT *cond=root;
                       root=root->left;
                    }
           else // vertex whith two child
             {
                NodeT *cond=Min(root->right);
                root->num=cond->num;
                root->right=Remove(root->right,cond->num);
             }
         }
    return root;
}
    
    
 
NodeT *Tree::Min(NodeT * vertex)
{
    while(vertex->left!=NULL)
    {
        vertex=vertex->left;
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
            vertex=vertex->left;
          }
     else
     {
         if(i>vertex->num)
           {
             vertex=vertex->right;
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
                 vertex=vertex->left;
             }
              else
              {
                  vertex=vertex->right;
              }
    }
    return 0;
}

    
int Tree::left(int i) 
{
    NodeT *vertex=getNodeT(i);
    if(vertex->left==NULL)
    {
        throw("no left child");
    }
    else
    {
        return (vertex->left)->num;
    }
}
    
 
NodeT* Tree::getNodeT(int y)
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
            vertex=vertex->left;
        }
        else
        {
            vertex=vertex->right;
        }
    }
   return vertex;
}
  
    
         
int Tree::right(int i)
{
     NodeT *vertex=getNodeT(i);
    if(vertex->right==NULL)
    {
        throw("no right child");
    }
    else
    {
        return (vertex->right)->num;
    }
}
    
    

    
void Tree::destroy(NodeT *i)
{
    if(i!=NULL)
    {
        destroy(i->left);
        destroy(i->right);
        delete(i);
    }
}
    
    
void Tree::In(NodeT * x)
{
    if(x!=NULL)
    {
        In(x->left);
        cout << "--" << x->num;
        In(x->right);
    }
}
    
void Tree::print() 
{
   cout << "In : "; 
    In(rootOfTree);
}

    
};
