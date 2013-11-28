#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int key_value;
  struct node *left;
  struct node *right;
} Node;

int binary_search(int num_to_find, Node tree_node){
  if(num_to_find == tree_node.key_value){
    printf("Found %d in the tree", num_to_find);
    return 0;
  } else if (num_to_find < tree_node.key_value){
    binary_search(num_to_find, *tree_node.left);
  } else if (num_to_find >= tree_node.key_value){
    binary_search(num_to_find, *tree_node.right);
  } else if (tree_node.left == NULL && tree_node.right == NULL){
    printf("ERROR, value not found");
  } else {
    printf("G DANG");
  }
  return 1;
}

void insert_into_binary_tree(int number_to_insert, Node tree_node){
  if(number_to_insert < tree_node.key_value){
    if(tree_node.left){
      insert_into_binary_tree(number_to_insert, *tree_node.left);
    } else {
      Node insert_node;
      insert_node.key_value = number_to_insert;
      tree_node.left = &insert_node;
    }
  } else if(number_to_insert >= tree_node.key_value){
    if(tree_node.right){
      insert_into_binary_tree(number_to_insert, *tree_node.right);
    } else {
      Node insert_node;
      insert_node.key_value = number_to_insert;
      tree_node.right = &insert_node;
    }
  }
  else {
    printf("Houston, we have a problem");
  }
}

void test_insert_into(int number_to_insert, Node tree_node){
  if(number_to_insert < tree_node.key_value){
    //    Node new_node;
    //    new_node.key_value = number_to_insert;
    //    tree_node.left = &new_node;
    printf("Ok it is less than the key_value\n");
  } else {
    printf("HMMM, this is weird\n");
  }
}

void double_check_myself(int num_to_find, Node tree_node) {
  if(num_to_find == tree_node.key_value){
    printf("Found that thing\n");
  }
}


int main(void){

  Node root;
  Node new_node;
  Node newer_node;
  Node newest_node;

  root.key_value = 12;
  //  new_node.key_value = 10;
  //  newer_node.key_value = 8;
  //  newest_node.key_value = 14;

  
  //  new_node.left = &newer_node;
  //  root.left = &new_node;
  //  root.right = &newest_node;

  //  printf("The root node value is %d\n", root.key_value);
  //  printf("The value of the root's left node is %d\n", root.left->key_value);
  //  printf("The value of the left node's left is %d\n", root.left->left->key_value);

  int search_param = 8;
  //  insert_into_binary_tree(8, root);
  binary_search(search_param, root);
  test_insert_into(8, root);
  printf("Inserted %d into the root node", root.left->key_value);
  //  double_check_myself(search_param, newer_node);

  return 0;

}
