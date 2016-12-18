//The points in the axes are: (1,1), (2,2), (3,3), (4,5), (5,6), (6,4), (7,8), (8,9)
//The query rectangle is [a,b] x [c,d] = [3,7] x [3,8]
//The maximal points are (5,6) and (6,4)
//The point (4,5) is dominated by the point (5,6)
//Ongoing Code
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <math>
#include <string.h>

using namespace std;

int a[10];
vector<int> arr;

int p=3,q=7, r=3, s=8; //a, b, c, d

struct node{
    int val;
    struct Treenode *left, *right;
    struct LinkedList *A;
    int mark; //canonical nodes
    int B[100];
    int x;
    int y;
    node(int data): val(data), left(NULL), right(NULL), A(NULL), mark(0), B[100]={0}, x(-1), y(-1){}
};

node head=NULL;

struct LinkedList{
    int val;
    struct LinkedList *next;
    struct Linkedlist *next1;
    struct Linkedlist *next2;
    struct Linkedlist *next3;
    LinkedList(int x): v(x), next(NULL), next1(NULL), next2(NULL), next3(NULL){}
};

struct store_range{
    int *B1;
    int *B2;
};

void range_maximum(int *c)
{
   int n= c.size();                                  //0<=r<=log n
   int r= log(n);
   for(int i=0; i<n; i++)
   {
       struct store_range store=(struct store_range)malloc(sizeof(struct store_range));
       store[i]->B1=(int *)malloc(r*sizeof(int));
       store[i]->B2=(int *)malloc(r*sizeof(int));
       for(int r1=0; r1<=r; r1++)
       {
       int x=i+pow(2, r1)-1;
       int y=i-pow(2, r1)+1;
       int maxi=-1;
       int t1, t2;
       for(int j=i; j<=x; j++)
       {
           if(maxi<c[j])
           {
               maxi=c[j];
               t1=j;
           }
       }
       maxi=-1;
       for(int j=y; j<=i; j++)
       {
           if(maxi<c[j])
           {
               maxi=c[j];
               t2=j;
           }
       }
       B1[r1]=t1;
       B2[r1]=t2;
       }
   }
}

void canonical_points(node *temp)
{
    if(temp->val!=0)
        return;
    if(temp->x!=-1 && temp->y !=-1) // Not a leaf node
    {
        if((temp->x < p && temp->y < q)||(temp->x > p && temp->y > q))
        {
            if(temp->x >= p && temp->y <= q)
                temp->mark=1;
        }
    }
    canonical_points(temp->left);
    canonical_points(temp->right);

}

int process_range_max(int i, int j, int *arr)
{
    int r= log(j-i);
    int x=store[j]->B[r];
    int y=store[i]->B[r];
    return arr[x]>arr[y]?x:y;
}

int fractional_cascading(node *temp)
{
    node temp3=temp->A;
    node *temp1= temp->left->A;
    node *temp2=temp->right->A;

    while(temp3!=NULL)
    {
        node *prev= NULL;
        while(temp1!=NULL)
        {
            if(temp1->val < temp3->val)
            {
                    temp3->next1= prev;
                    break;
            }
            if(temp1->val == temp3->val)
                temp3->next3= temp1;

                prev= temp1;
                temp1=temp1->next;
        }
        node *prev= NULL;
        while(temp2!=NULL)
        {
            if(temp2->val < temp3->val)
            {
                    temp3->next2= prev;
                    break;
            }
            if(temp2->val == temp3->val)
                temp3->next3= temp1;

                prev= temp1;
                temp1=temp1->next;
        }
    temp3=temp3->next;
    }
}

void internal(node *n)
{
    if(n==NULL)
        return;

    if(n->val!=0)
        arr.push_back(n->val);

    internal(n->left);
    internal(n->right);
}

void assign_internal_nodes(node *temp)
{
    if(temp->val!=0)
        return;

    internal(temp);
    int i=0;
    sort(arr.begin(), arr.end(), greater());
    while(!arr.empty())
    {
        int k= arr.top();
        for(int j=1; j<=8; j++)
        {
            if(k==a[j])
                break;
        }
        temp->B[i]=j;
        i++;
        temp->A= new LinkedList(k);
        arr.pop_back();
        temp->A=temp->A->next;
    }
    temp->x= max(temp->B.begin(), temp->end());
    temp->y= min(temp->B.begin(), temp->end());

    assign_internal_nodes(temp->left);
    assign_internal_nodes(temp->right);
}

int main()
{
    head= new node(0);
    head->left= new node(0);
    head->right= new node(0);
    head->left->left= new node(0);
    head->left->right= new node(0);
    head->right->left= new node(0);
    head->right->right= new node(0);
    head->left->left->left= new node(1);
    head->left->left->right= new node(2);
    head->left->right->left= new node(3);
    head->left->right->right= new node(4);
    head->right->left->left= new node(5);
    head->right->left->right= new node(6);
    head->right->right->left= new node(7);
    head->right->right->right= new node(8);
// We can use map
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=5;
    a[5]=6;
    a[6]=4;
    a[7]=8;
    a[8]=9;

    return 0;
}
