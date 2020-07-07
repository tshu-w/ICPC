class Solution {
public:
  vector<int> B;
  long long count_inversion(vector<int>& A, int l, int r) {
    if (l + 1 >= r) return 0;
    int mid = (l + r) / 2; long long res = 0;

    res += count_inversion(A, l, mid);
    res += count_inversion(A, mid, r);

    for (int i = l, j = mid; i < mid; i++) {
      while (j < r and A[i] > 2LL * A[j]) j++;
      res += (j - mid);
    }

    int i = l, j = mid, k = l;
    for (; i < mid and j < r; k++)
      if (A[i] < A[j]) B[k] = A[i++];
      else B[k] = A[j++];

    for (; i < mid; k++) B[k] = A[i++];
    for (; j < r; k++) B[k] = A[j++];
    for (int i = l; i < r; i++) A[i] = B[i];
    return res;

  }
  int reversePairs(vector<int>& nums) {
    B.reserve(nums.size());
    return count_inversion(nums, 0, nums.size());
  }
};
