#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>

using namespace std;

struct Node_query{
    int val;
    node *one;
    node *two;
    node *three;
    vector<int> interval //stores union of x coordinates
};
typedef struct Node_query node;

struct internal_node{
     int *a;  //stores y coordinates;
     int is_child;
     string *lookup; //binary string
};
typedef struct internal_node int_node;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    int leaf;
    int median;
};
typedef struct TreeNode TreeNode;

struct rectangle{
    int a;
    int b;
    int c;
    int d;
};
typedef struct rectangle rectangle;

rectangle r;
TreeNode *root;
node *query;
vector<int> median_y;

int RMA()
{
    int_node *range = query->one;
    // maximum of x coordinates of the y coordinates range->a[i] to range->a[j];
}

int print_ancestor(TreeNode * r, int y2)
{
    if(root==NULL)
        return 0;
    if(root==y2)
        return 1;

    if(print_ancestor(root->left,y2)||print_ancestor(root->right,y2))
    {
        median_y.push_back(r->median);
        return 1;
    }
    else
        return 0;
}

int Range_successor()
{
    int ans;
    // smallest y coordinate in set of points S and rectangle q
    return ans;
}

int rank()
{
    return count_of_an_element
}

int select
{
    return position_of_an_element
}

void after_median_y()
{
    int ym= median_y.pop_back();
    int countm;
    if(ym < y2)
    //compute pymax and pxmax and countm(y2)= number of maximal points from pymax to pxmax
    //compute pnodom is not dominated by pxmax.
    //store it in (countm(y2), pnodom)
    else if(ym>y2)
      //compute pymax and pxmax and countm(y2)= number of maximal points from pymax to pxmax

      return countm;
}
