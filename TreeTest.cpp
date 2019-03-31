/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
//using std::cout, std::endl;
using namespace std;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  // new tree //
  
  ariel::Tree myTree1;
  ariel::Tree myrTree2;
  ariel::Tree myTree3;
  
  // Fill the first tree //
  
  myTree1.insert(8);
  myTree1.insert(6);
  myTree1.insert(4);
  myTree1.insert(2);
  
  // Fill the second tree //
  
  myTree2.insert(12);
  myTree2.insert(20);
  myTree2.insert(8);
  
  // Fill the third tree //
  
  myTree3.insert(10);
  myTree3.insert(12);
  myTree3.insert(15);
  myTree3.insert(20);
  myTree3.insert(17);
  myTree3.insert(16);
  myTree3.insert(11);
  myTree3.insert(2);
  myTree3.insert(3);
  myTree3.insert(6);
  myTree3.insert(9);
  myTree3.insert(7);
  myTree3.insert(8);
 
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
    
    // myTree1 test //
    
  .CHECK_EQUAL (myTree1.size(), 4)
  .CHECK_EQUAL (myTree1.root(), 8)
  .CHECK_EQUAL (myTree1.parent(4), 6)
  .CHECK_EQUAL (myTree1.parent(6), 8)
  .CHECK_EQUAL (myTree1.left(4), 2)
  .CHECK_THROWS(myTree1.insert(6))
  .CHECK_OK   (myTree1.remove(6))
  .CHECK_EQUAL (myTree1.size(), 3)
  .CHECK_EQUAL (myTree1.left(8), 4)
  .CHECK_OK    (myTree1.print())
    
   
   // myTree2 test //
    
  .CHECK_EQUAL (myTree2.size(), 3)
  .CHECK_EQUAL (myTree2.root(), 12)
  .CHECK_EQUAL (myTree2.parent(8), 12)
  .CHECK_EQUAL (myTree2.parent(20), 12)
  .CHECK_THROWS(myTree2.remove(6))
  .CHECK_OK   (myTree2.remove(12))
  .CHECK_EQUAL (myTree2.root(), 20)
  .CHECK_EQUAL (myTree2.parent(8), 20)
  .CHECK_EQUAL (myTree2.left(20), 8)
  .CHECK_EQUAL (myTree2.size(), 2)
    
    
     // myTree3 test //
    
  .CHECK_EQUAL myTree3.size(), 13)
  .CHECK_EQUAL (myTree3.root(), 10)
  .CHECK_EQUAL (myTree3.parent(2), 10)
  .CHECK_EQUAL (myTree3.parent(12), 10)
  .CHECK_EQUAL (myTree3.parent(11), 12)
  .CHECK_EQUAL (myTree3.parent(15), 12)
  .CHECK_THROWS(myTree3.remove(22))
  .CHECK_OK   (myTree3.remove(6))
  .CHECK_EQUAL (myTree3.size(), 12)
  .CHECK_EQUAL (myTree3.right(3), 9)
  .CHECK_EQUAL (myTree3.right(9), 7)
  .CHECK_OK   (myTree3.remove(10))
  .CHECK_EQUAL (myTree3.size(), 11)
  .CHECK_EQUAL (myTree3.root(), 11)
  .CHECK_EQUAL (myTree3.parent(2), 11)
  .CHECK_EQUAL (myTree3.parent(12), 11)
    
  
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
