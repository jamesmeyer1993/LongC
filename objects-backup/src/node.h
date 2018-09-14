
struct Node
// Data
{
  struct Node next*;
};

struct Node newNode(struct Node **next_node)
// Constructor
{
  // Create and actual structure rather than allocating and reallocating space
  // all around.
  struct Node n;
  n->next=next_node;
  return n;
}
