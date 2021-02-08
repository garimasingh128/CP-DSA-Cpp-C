// This example elaborates implementation of segment trees.

// Let us consider the following problem to understand Segment Trees.

// We have an array arr[0 . . . n-1]. We should be able to
// 1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1

// 2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.

#include<bits/stdc++.h>
using namespace std;

void buildTree(int *a, int start, int end, int *tree, int index)
{
    if(start==end)
    {
        tree[index]=a[start];
        return;
    }

    int mid= (start+end)/2;
    buildTree(a,start,mid,tree,2*index);
    buildTree(a,mid+1,end,tree,2*index+1);

    tree[index]= tree[2*index]+tree[2*index+1];
    return;
}

void updateTree(int *a, int start, int end, int *tree, int treeIndex, int idx, int value)
{
    if(start==end)
    {
        a[idx]=value;
        tree[treeIndex]=value;
        return;
    }

    int mid= (start+end)/2;

    if(mid<idx)
    {
        updateTree(a,mid+1,end,tree,2*treeIndex+1,idx,value);
    }
    else
    {
        updateTree(a,start,mid,tree,2*treeIndex,idx,value);
    }
    
    tree[treeIndex]= tree[treeIndex *2] + tree[treeIndex * 2+1];
    return;
}

int rangeQuery(int *tree, int start, int end, int treeNode ,int l, int r)
{
    // Completely outside of the tree.
    if(r<start || l>end)
    return 0;

    // Completely inside the tree
    if(l<=start && r>=end)
    {
        return tree[treeNode];
    }

    // Partial on both side of the tree.
    int mid = (start + end)/2;
    int ans1= rangeQuery(tree, start, mid, 2*treeNode, l, r);
    int ans2= rangeQuery(tree, mid+1, end, 2*treeNode+1, l, r);

    return ans1+ans2;
}

int main(){
    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    int *tree = new int[4*n];

    buildTree(a,0,n-1,tree,1);

    for(int i=1;i<4*n;i++)
    cout<<tree[i]<<" ";

    //updateTree(a,0,n-1,tree,1,2,10);
    cout<<endl;

    for(int i=1;i<4*n;i++)
    cout<<tree[i]<<" ";

    cout<<endl;

    cout<<rangeQuery(tree,0, n-1, 1, 2, 4);

}
