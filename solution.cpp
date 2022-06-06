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
    - paths include the root (parent) node
    - paths don't include the root (parent) node
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
  /* see if the path sum will increase by including the root
     - this is the case where the path doesn't include the
       parent node
  */
  sum = max(sum, ps);

  /* report which child will contribute to the sum more
     - this is the case where the path includes the
       root and one of its child
     - this allows the root's parent to be included
       as part of the path once we return from
       this call
  */
  return max(ls, rs) + root->val;
}
