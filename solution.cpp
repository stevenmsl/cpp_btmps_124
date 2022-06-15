#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol124;
using namespace std;

/*takeaways
  - two cases
    - the path includes the root, the left, and the right
      - we evaluate the sum right away as we don't need
        to include the parent hence have enough information
    - the path includes the root and one child
      - we return either root + left or root + right
      - this is to allow us to include the parent in
        the path
  - time complexity is O(n) as you need to visit
    every node.
*/
int Solution::maxPathSum(Node *root)
{
  if (root == nullptr)
    return 0;
  auto sum = INT_MIN;
  _maxPathSum(root, sum);
  return sum;
}

int Solution::_maxPathSum(Node *root, int &sum)
{
  if (root == nullptr)
    return 0;

  /* ignore the sum of the children if it comes
     up as a negative number as it won't increase
     the sum
  */
  auto ls = max(0, _maxPathSum(root->left, sum));
  auto rs = max(0, _maxPathSum(root->right, sum));
  auto ps = ls + rs + root->val;
  /* evaluate the sum
     - the path doesn't include the parent since you evaluate
       the root, the left, and the right
     - there are 3 different paths
     - root alone (both the left and the right chidlren's sum is negative)
     - root + left (only the left is positive)
     - root + right (only the right is positive)
  */
  sum = max(sum, ps);

  /* report which path will contribute to the sum more
     - we report back either root + left or
       root + right
     - this is the case where the path includes the
       root and one of its child
     - this allows the root's parent to be included
       as part of the path once we return from
       this call
  */
  return max(ls, rs) + root->val;
}
