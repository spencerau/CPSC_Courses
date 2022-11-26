/*
Spencer Au
ID: 002385256
spau@chapman.edu

Partner:
Ben Fellows
bfellows@chapman.edu

CPSC 350 - Section 2
PA5

ScapegoatST() - constructor that intializes the root to null and sets del, depth, and size to 0

virtual ~ScapegoatST() - deletes the root

int getSize(TreeNode<T> *subTreeRoot) - takes a subroot and returns the size of the corresponding subtree

int getSize() - returns size

void insert(T d) - takes a T d and inserts that node into the tree

void remove(T d) - takes a T d and removes that node from the tree

bool contains(T d) - checks if the tree contains the node T d 

void printTreeInOrder() - prints out the contents of the tree in order

void printToFile(ofstream &writer) - prints out the contents of the tree to runLog.txt

T getByID(int id) - takes an int id and returns a T node that has that id

TreeNode<T> *getScapeGoat(TreeNode<T> *newNode) -

void rebuildSubTree(TreeNode<T> *subTreeRoot) -

int buildArray(TreeNode<T> *node, TreeNode<T> *arr[], int i) -

TreeNode<T> *buildBalancedArray(TreeNode<T> **arr, int i, int n) - 

bool containsByID(int id) - takes an int id and checks if the tree contains a node with that id

void removeByID(int id) - takes an int id and removes the node with the corresponding id
*/

#ifndef SCAPEGOATST_H
#define SCAPEGOATST_H

#include "TreeNode.h"
#include <fstream>
#include <cmath>

template <typename T>
class ScapegoatST
{
public:
  ScapegoatST();
  virtual ~ScapegoatST();
  int getSize(TreeNode<T> *subTreeRoot);
  int getSize();
  void insert(T d);
  void remove(T d);
  bool contains(T d);
  void printTreeInOrder();
  void printTreePostOrder();
  T getMin();
  T getMax();
  T getMedian();
  void printToFile(ofstream &writer);
  T getByID(int id);
  TreeNode<T> *getScapeGoat(TreeNode<T> *newNode);
  void rebuildSubTree(TreeNode<T> *subTreeRoot);
  int buildArray(TreeNode<T> *node, TreeNode<T> *arr[], int i);
  TreeNode<T> *buildBalancedArray(TreeNode<T> **arr, int i, int n);
  bool containsByID(int id);
  void removeByID(int id);

private:
  double m_del;
  double m_depth;
  double m_size;
  TreeNode<T> *m_root;
  T getMinHelper(TreeNode<T> *subTreeRoot);
  T getMaxHelper(TreeNode<T> *subTreeRoot);
  void insertHelper(TreeNode<T> *&subTreeRoot, TreeNode<T> *newNode);
  bool containsHelper(TreeNode<T> *subTreeRoot, TreeNode<T> *newNode);
  void printTreeInOrderHelper(TreeNode<T> *subTreeRoot);
  void printTreePostOrderHelper(TreeNode<T> *subTreeRoot);
  void findTarget(T key, TreeNode<T> *&target, TreeNode<T> *&parent);
  TreeNode<T> *getSuccessor(TreeNode<T> *rightChild);
  void printToFileHelper(TreeNode<T> *subTreeRoot, ofstream &writer);
  T getByIDHelper(int id, TreeNode<T> *subTreeRoot);
  bool containsByIDHelper(TreeNode<T> *subTreeRoot, int id);
  void findTargetByID(int id, TreeNode<T> *&target, TreeNode<T> *&parent);
};

template <typename T>
ScapegoatST<T>::ScapegoatST()
{
  m_root = NULL;
  m_size = 0;
  m_del = 0;
  m_depth = 0;
}

template <typename T>
ScapegoatST<T>::~ScapegoatST()
{
  if (m_root != NULL)
  {
    delete m_root;
  }
}

template <typename T>
int ScapegoatST<T>::getSize(TreeNode<T> *subtreeRoot)
{
  if (subtreeRoot == NULL)
  {
    return 0;
  }
  return getSize(subtreeRoot->m_left) + getSize(subtreeRoot->m_right) + 1;
}

template <typename T>
int ScapegoatST<T>::getSize()
{
  return m_size;
}

template <typename T>
void ScapegoatST<T>::insert(T d)
{
  TreeNode<T> *newNode = new TreeNode<T>(d);
  insertHelper(m_root, newNode);
  ++m_size;
  ++m_del;
  m_depth = 0;
}

template <typename T>
void ScapegoatST<T>::insertHelper(TreeNode<T> *&subTreeRoot, TreeNode<T> *newNode)
{
  if (subTreeRoot == NULL)
  {
    subTreeRoot = newNode;
    if (m_depth > log2(m_size) / log2(1.5))
    { // checking if the node inserted is too deep
    cout << log2(m_size) / log2(1.5) << endl;
      TreeNode<T> *scapeGoat = getScapeGoat(newNode);
      if (scapeGoat->parent != NULL)
      {
        rebuildSubTree(scapeGoat->parent);
      }
      else
      {
        rebuildSubTree(scapeGoat);
      }
    }
  }
  else if (newNode->m_data->getid() < subTreeRoot->m_data->getid())
  {
    m_depth++;
    newNode->parent = subTreeRoot;
    insertHelper(subTreeRoot->m_left, newNode);
  }
  else
  {
    newNode->parent = subTreeRoot;
    m_depth++;
    insertHelper(subTreeRoot->m_right, newNode);
  }
}

template <typename T>
bool ScapegoatST<T>::contains(T d)
{
  TreeNode<T> *newNode = new TreeNode<T>(d);
  return containsHelper(m_root, newNode);
}

template <typename T>
bool ScapegoatST<T>::containsHelper(TreeNode<T> *subTreeRoot, TreeNode<T> *newNode)
{
  if (subTreeRoot == NULL)
  {
    return false;
  }
  else if (newNode->m_data == subTreeRoot->m_data)
  {
    return true;
  }
  else if (newNode->m_data < subTreeRoot->m_data)
  {
    return containsHelper(subTreeRoot->m_left, newNode);
  }
  else
  {
    return containsHelper(subTreeRoot->m_right, newNode);
  }
}

template <typename T>
void ScapegoatST<T>::printTreeInOrder()
{
  printTreeInOrderHelper(m_root);
}

template <typename T>
void ScapegoatST<T>::printTreeInOrderHelper(TreeNode<T> *subTreeRoot)
{
  if (subTreeRoot != NULL)
  {
    printTreeInOrderHelper(subTreeRoot->m_left);
    subTreeRoot->getData()->printInfo();
    printTreeInOrderHelper(subTreeRoot->m_right);
  }
}

template <typename T>
void ScapegoatST<T>::printTreePostOrder()
{
  printTreePostOrderHelper(m_root);
}

template <typename T>
void ScapegoatST<T>::printTreePostOrderHelper(TreeNode<T> *subTreeRoot)
{
  if (subTreeRoot != NULL)
  {
    printTreeInOrderHelper(subTreeRoot->m_left);
    printTreeInOrderHelper(subTreeRoot->m_right);
    cout << subTreeRoot->m_data << endl;
  }
}

template <typename T>
T ScapegoatST<T>::getMin()
{
  // check if empty
  return getMinHelper(m_root);
}

template <typename T>
T ScapegoatST<T>::getMinHelper(TreeNode<T> *subTreeRoot)
{
  if (subTreeRoot->m_left == NULL)
  {
    return subTreeRoot->m_data;
  }
  else
  {
    return getMinHelper(subTreeRoot->m_left);
  }
}

template <typename T>
T ScapegoatST<T>::getMax()
{
  // check if empty
  return getMaxHelper(m_root);
}

template <typename T>
T ScapegoatST<T>::getMaxHelper(TreeNode<T> *subTreeRoot)
{
  if (subTreeRoot->m_right == NULL)
  {
    return subTreeRoot->m_data;
  }
  else
  {
    return getMaxHelper(subTreeRoot->m_right);
  }
}

template <typename T>
T ScapegoatST<T>::getMedian()
{
  // check if empty
  return m_root->m_data;
}

template <typename T>
void ScapegoatST<T>::findTarget(T key, TreeNode<T> *&target, TreeNode<T> *&parent)
{
  while (target != NULL && target->m_data != key)
  {
    parent = target;
    if (key < target->m_data)
    {
      target = target->m_left;
    }
    else
    {
      target = target->m_right;
    }
  }
}

template <typename T>
TreeNode<T> *ScapegoatST<T>::getSuccessor(TreeNode<T> *rightChild)
{
  while (rightChild->m_left != NULL)
  {
    rightChild = rightChild->m_left;
  }
  return rightChild;
}

template <typename T>
void ScapegoatST<T>::remove(T d)
{
  // check if empty
  TreeNode<T> *target = NULL;
  TreeNode<T> *parent = NULL;
  target = m_root;
  findTarget(d, target, parent);
  if (target == NULL)
  { // value wasn't in tree, othing to do
    return;
  }
  // check if leaf (including the root)
  if (target->m_left == NULL && target->m_right == NULL)
  { // no children, it's a leaf
    if (target == m_root)
    { // leaf is the root of tree
      m_root = NULL;
    }
    else
    { // it's not the root
      if (target == parent->m_left)
      {
        parent->m_left = NULL;
      }
      else
      {
        parent->m_right = NULL;
      }
    }
    // delete target; //free the memory
  }
  else if (target->m_left != NULL && target->m_right != NULL)
  { // 2 child case
    TreeNode<T> *suc = getSuccessor(target->m_right);
    T value = suc->m_data;
    remove(value); // remove successor treenode
    target->m_data = value;
  }
  else
  { // 1 child
    TreeNode<T> *child;
    if (target->m_left != NULL)
    {
      child = target->m_left;
    }
    else
    {
      child = target->m_right;
    }
    if (target == m_root)
    {
      m_root = child;
    }
    else
    {
      if (target == parent->m_left)
      {
        parent->m_left = child;
      }
      else
      {
        parent->m_right = child;
      }
    }
    --m_size;
    delete target;
    delete parent;
    if (m_del > 2 * m_size)
    {
      rebuildSubTree(m_root);
    }
  }
}

template <typename T>
void ScapegoatST<T>::printToFile(ofstream &writer)
{
  printToFileHelper(m_root, writer);
}

template <typename T>
void ScapegoatST<T>::printToFileHelper(TreeNode<T> *subTreeRoot, ofstream &writer)
{
  if (subTreeRoot != NULL)
  {
    printToFileHelper(subTreeRoot->m_left, writer);
    subTreeRoot->getData()->printToFile(writer);
    printToFileHelper(subTreeRoot->m_right, writer);
  }
}

// need to implement these three
template <typename T>
T ScapegoatST<T>::getByID(int id)
{
  return getByIDHelper(id, m_root);
}

template <typename T>
T ScapegoatST<T>::getByIDHelper(int id, TreeNode<T> *subTreeRoot)
{
  if (subTreeRoot == NULL)
  {
    return NULL;
  }
  else if (subTreeRoot->getData()->getid() == id)
  {
    return subTreeRoot->getData();
  }
  else if (subTreeRoot->getData()->getid() < id)
  {
    return getByIDHelper(id, subTreeRoot->m_right);
  }
  else
  {
    return getByIDHelper(id, subTreeRoot->m_left);
  }
}

template <typename T>
bool ScapegoatST<T>::containsByID(int id)
{
  // if (m_root == NULL) return false;
  return containsByIDHelper(m_root, id);
}

template <typename T>
bool ScapegoatST<T>::containsByIDHelper(TreeNode<T> *subTreeRoot, int id)
{
  if (subTreeRoot == NULL)
  {
    return false;
  }
  else if (id == subTreeRoot->m_data->getid())
  {
    return true;
  }
  else if (id < subTreeRoot->m_data->getid())
  {
    return containsByIDHelper(subTreeRoot->m_left, id);
  }
  else
  {
    return containsByIDHelper(subTreeRoot->m_right, id);
  }
}

template <typename T>
void ScapegoatST<T>::removeByID(int id)
{
  if (m_root == NULL)
    return;
  if (m_root->getData()->getid() == id)
    remove(m_root->getData());
  // recursive call

  // check if empty
  TreeNode<T> *target = NULL;
  TreeNode<T> *parent = NULL;
  target = m_root;
  findTargetByID(id, target, parent);
  if (target == NULL)
  { // value wasn't in tree, othing to do
    return;
  }
  // check if leaf (including the root)
  if (target->m_left == NULL && target->m_right == NULL)
  { // no children, it's a leaf
    if (target == m_root)
    { // leaf is the root of tree
      m_root = NULL;
    }
    else
    { // it's not the root
      if (target == parent->m_left)
      {
        parent->m_left = NULL;
      }
      else
      {
        parent->m_right = NULL;
      }
    }
    // delete target; //free the memory
  }
  else if (target->m_left != NULL && target->m_right != NULL)
  { // 2 child case
    TreeNode<T> *suc = getSuccessor(target->m_right);
    T value = suc->m_data;
    remove(value); // remove successor treenode
    target->m_data = value;
  }
  else
  { // 1 child
    TreeNode<T> *child;
    if (target->m_left != NULL)
    {
      child = target->m_left;
    }
    else
    {
      child = target->m_right;
    }
    if (target == m_root)
    {
      m_root = child;
    }
    else
    {
      if (target == parent->m_left)
      {
        parent->m_left = child;
      }
      else
      {
        parent->m_right = child;
      }
    }
    delete target;
    delete parent;
    if (m_del > 2 * m_size)
    {
      rebuildSubTree(m_root);
    }
  }
  --m_size;
}

template <typename T>
void ScapegoatST<T>::findTargetByID(int id, TreeNode<T> *&target, TreeNode<T> *&parent)
{
  while (target != NULL && target->m_data->getid() != id)
  {
    parent = target;
    if (id < target->m_data->getid())
    {
      target = target->m_left;
    }
    else
    {
      target = target->m_right;
    }
  }
}

template <typename T>
TreeNode<T> *ScapegoatST<T>::getScapeGoat(TreeNode<T> *newNode)
{
  if (newNode->parent != NULL)
  {
    TreeNode<T> *parentNode = newNode->parent;
    while (3 * getSize(parentNode) <= 2 * getSize(parentNode->parent))
    {
      parentNode = parentNode->parent;
    }
    return parentNode;
  }
  return newNode;
}
//method to rebuild a subtree using buildarray and buildbalanced array
template <typename T>
void ScapegoatST<T>::rebuildSubTree(TreeNode<T> *subTreeRoot)
{
  TreeNode<T> *parentNode = subTreeRoot->parent;
  int size = getSize(subTreeRoot);
  TreeNode<T> **tempArr= new TreeNode<T> *[size];
  buildArray(subTreeRoot, tempArr, 0);
  if (parentNode == NULL)
  {
    m_root = buildBalancedArray(tempArr, 0, size);
    m_root->parent = NULL;
  }
  else if (parentNode->m_right == subTreeRoot)
  {
    parentNode->m_right = buildBalancedArray(tempArr, 0, size);
    parentNode->m_right->parent = parentNode;
  }
  else
  {
    parentNode->m_left = buildBalancedArray(tempArr, 0, size);
    parentNode->m_left->parent = parentNode;
  }
}
//method to build array from inorder traversal of tree
template <typename T>
int ScapegoatST<T>::buildArray(TreeNode<T> *node, TreeNode<T> *arr[], int i)
{
  if (node == NULL)
  //check if node passed is null and return i if it is
  {
    return i;
  }
  else
  {
    //preform inorder treversal and copy to array
    i = buildArray(node->m_left, arr, i);
    arr[i++] = node;
    return buildArray(node->m_right, arr, i);
  }
}
//method to build balanced array representation of an array from an array
template <typename T>
TreeNode<T> *ScapegoatST<T>::buildBalancedArray(TreeNode<T> **arr, int i, int j)
{
  if (j == 0)
  {
    return NULL;
  }
  //find median index of array
  int k = j / 2;
  arr[i + k]->m_left = buildBalancedArray(arr, i, k);
  if (arr[i + k]->m_left != NULL)
  {
    arr[i + k]->m_left->parent = arr[i + k];
  }
  arr[i + k]->m_right = buildBalancedArray(arr, i + k + 1, j - k - 1);
  if (arr[i + k]->m_right != NULL)
  {
    arr[i + k]->m_right->parent = arr[i + k];
  }
  return arr[i + k];
}

#endif
