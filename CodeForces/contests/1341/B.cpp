#include <iostream>
#include <vector>
#define MAX 2e5 + 5
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct Info {
  int left, right, peaks;

  void print() {
    dbg(left); dbg(right); dbg(peaks);
  }
};

void print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void CheckPeaks(const vector<int>& mountains, vector<bool>& peak) {
  for (int i = 1; i < peak.size() - 1; i++) {
    if (mountains[i - 1] < mountains[i] && mountains[i] > mountains[i + 1]) {
      peak[i] = true;
    }
  }
}

Info GetBest(const vector<int>&A, int size, int segment_size) {
  Info result{-1,-1,-1};
  vector<bool> peak(size, false);
  CheckPeaks(A, peak);
  vector<int> prefix_sum(size + 1, 0);
  for (int i = 1; i <= size; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + peak[i - 1];
  }
  // print(prefix_sum);
  int l = 0, r = segment_size - 1, best = 0;
  while (r < size) {
    int curr_peaks = prefix_sum[r + 1] - prefix_sum[l] - (peak[r] ? 1 : 0);
    if (curr_peaks > best) {
      best = curr_peaks;
      result.left = l;
      result.right = r;
      result.peaks = curr_peaks;
    }
    l++; r++;
  }
  return result;
}

int main(void) {
  int tc, n, k;
  vector<int> A(MAX);
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    Info info = GetBest(A, n, k);
    // info.print();
    int t = 0;
    if (info.peaks >= 1) {
      t += 2;
      t += (info.peaks - 1);
    }
    if (info.left == -1) {
      cout << 1 << " " << 1 << endl;
    } else {
      cout << t << " " << info.left + 1 << endl;
    }
  }
  return 0;
}