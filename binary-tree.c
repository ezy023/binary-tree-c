#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int key_value;
  struct node *left;
  struct node *right;
} Node;

void test_insert_into(Node node_to_add, Node tree_node){
  if(node_to_add.key_value < tree_node.key_value){
    if(tree_node.left){
      test_insert_into(node_to_add, *tree_node.left);
    } else {
      tree_node.left = &node_to_add;
    }
    printf("The value of the new node is %d\n", tree_node.left->key_value);
  } else if(node_to_add.key_value >= tree_node.key_value) {
    if(tree_node.right){
      test_insert_into(node_to_add, *tree_node.right);
    } else {
      tree_node.right = &node_to_add;
    }
    printf("The value of the new node is %d\n", tree_node.right->key_value);
  } else {
    printf("HMMM, this is weird\n");
  }
}

void double_check_myself(int num_to_find, Node tree_node) {
  if(num_to_find == tree_node.key_value){
    printf("Found that thing\n");
  } else if(num_to_find < tree_node.key_value){
    printf("Ok so we hit the else\n");
    double_check_myself(num_to_find, *tree_node.left);
  } else if(num_to_find >= tree_node.key_value){
    double_check_myself(num_to_find, *tree_node.right);
  } else {
    printf("We got a weird one, a between case\n");
  }
}

Node create_new_node(int value){
  Node *gen_node = malloc(sizeof(Node));
  gen_node->key_value = value;
  return *gen_node;
}

void create_and_add_node(int value, Node *root_node)
{
  Node node_to_add = create_new_node(value);
  test_insert_into(node_to_add, *root_node);
}

int main(void){

  Node *root_node = malloc(sizeof(Node));
  root_node->key_value = 10;

  Node pointer_node = create_new_node(9);
  printf("Node Value: %d\n", pointer_node.key_value);

  int numbers[] = {12, 21, 30, 4, 3, 1, 6, 2, 0, 36, 13, 8, 26, 39, 34, 19, 39, 10, 28, 9};
  int array_size = sizeof(numbers)/sizeof(int);
  int i = 0;

  for(i; i < array_size; i++){
    create_and_add_node(numbers[i], root_node);
  }

  /* if(root_node->left){ */
  /*   printf("hmmmm\n"); */
  /* } else { */
  /*   printf("ok cool\n"); */
  /* } */

  /* test_insert_into(pointer_node, *root_node); */

  return 0;

}
