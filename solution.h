
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol124
{

  class Solution
  {
  private:
    int _maxPathSum(Node *root, int &sum);

  public:
    int maxPathSum(Node *root);
  };
}
#endif