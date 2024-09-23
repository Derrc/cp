#include <iostream>
#include <vector>
using namespace std;

/*
  Segment Trees
  - updates and range min queries in O(logn) time
  - when n is a power of 2: 2n-1 space is needed
  - when n is not a power of 2: 2*2^(ceil(log2n))-1 is needed -> approx 2^(ceil(log2n)+1) < O(4n)
  - extra nodes are not needed in array rep -> can just use 2n space
  - original array is stored from n -> 2n-1, root is stored in index 1
  - can build in O(2n) time
*/

class MinSegmentTree {
  private:
    vector<int> segtree;
    int n;
  
  public:
    MinSegmentTree(int n) : n(n), segtree(n*2, INT32_MAX) {}

    // sets value at ind to val
    void set(int ind, int val) {
      ind += n;
      segtree[ind] = val;
      for (; ind > 1; ind /= 2) {
        // segtree[ind^1] gets ind+1 if even or ind-1 if odd
        // gets sibling node in bt
        segtree[ind/2] = min(segtree[ind], segtree[ind^1]);
        // ind = odd -> ind^1 subtracts 1
        // ind = even -> ind^1 adds 1
        // root node is 1
      }
    }

    // computes min query for [start, end]
    int range_min(int start, int end) {
      int cur = INT32_MAX;
      // parent of segtree[i] = segtree[floor(i/2)]
      for (start += n, end += n; start <= end; start /= 2, end /= 2) {
        // include only right subtree and move to subtree to right
        if (start % 2 == 1) { cur = min(cur, segtree[start++]); }
        // include only left subtree and move to subtree to left
        if (end % 2 == 0) { cur = min(cur, segtree[end--]); }
      }

      return cur;
    }
};

int main() {
  int n, q;
  cin >> n >> q;

  MinSegmentTree mst(n);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    mst.set(i, nums[i]);
  }

  for (int i = 0; i < q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      mst.set(a-1, b);
    } else {
      cout << mst.range_min(a-1, b-1) << "\n";
    }
  }
}