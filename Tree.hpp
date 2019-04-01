#include <iostream>
using namespace std;

namespace ariel{
    
class NodeT
{
    
  public:
    
    NodeT* rightChild;
    NodeT* leftChild;
    int num;
    
    
    
    NodeT(int i)
    {   
        num = i;
        rightChild = NULL;
        leftChild = NULL;
    }
    
    NodeT* getRightChild() { return rightChild; }
    void setRightChild(NodeT* n)
    {
      rightChild = n;
    }
    
    
    NodeT* getLeftChild() { return leftChild; }
    void setLeftChild(NodeT* n)
    {
     leftChild = n;
    }
    
    int getNum() { return num; }
};

    
    class Tree{
      
        
    public:
        Tree();
        ~Tree();
        Tree& insert(int i);
        Tree& remove(int i);
        int size();
        bool contains(int i);
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void destroy(NodeT* i);
        void print();
    
     private:
        int value;
        NodeT* rootOfTree;
        NodeT* Min(NodeT* root);
        NodeT* Remove(NodeT *root, int num); //search a delete a value from tree.
        void In(NodeT* x);
        NodeT* getNodeT(int y);
    };
}
