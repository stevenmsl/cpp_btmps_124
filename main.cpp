#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol124;

/*
Input: [1,2,3]
       1
      / \
     2   3
Output: 6
*/

tuple<Node *, int>
testFixture1()
{
  auto root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  return make_tuple(root, 6);
}

/*
Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

tuple<Node *, int>
testFixture2()
{
  auto root = new Node(-10);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);
  return make_tuple(root, 42);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  auto val = sol.maxPathSum(get<0>(f));
  cout << "Expect to see : " << get<1>(f) << endl;
  cout << val << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  auto val = sol.maxPathSum(get<0>(f));
  cout << "Expect to see : " << get<1>(f) << endl;
  cout << val << endl;
}

main()
{
  test1();
  test2();
  return 0;
}