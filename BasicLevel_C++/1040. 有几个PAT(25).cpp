// Copyright [2018] <mituh>
// 1040. 有几个PAT(25).cpp   06:23
/*
1040 有几个PAT(25)

字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？
输入格式：

输入只有一行，包含一个字符串，长度不超过10^5 ，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT

输出样例：
2
*/

/*
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  int n = s.length(), cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      for (int j = i+1; j < n; j++) {
        if (s[j] == 'A') {
          for (int k = j+1; k < n; k++) {
            if (s[k] == 'T') {
              cnt++;
            }
          }
        }
      }
    }
  }
  printf("%d\n", cnt ? cnt % 1000000007 : 0);
  return 0;
}

// 1,2AC, 后三个超时, 15分
// 如何解决3sum问题?

*/

// 计算每个A左边有几个P, 右边有几个T, 相乘

#include <cstdio>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  int sum = 0, n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      int left_P = 0, right_T = 0;
      int p = i-1, q = i+1;
      while (p >= 0) {
        if (s[p] == 'P') left_P++;
        p++;
      }
      while (q < n) {
        if (s[q] == 'T') right_T++;
        q++;
      }
      sum += left_P * right_T;
    }
  }
  printf("%d\n", sum);
  return 0;
}


/*
// 计算每个A左边有几个P, 右边有几个T, 相乘
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  int sum = 0, n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      int left_P = 0, right_T = 0;
      int p = i-1, q = i+1;
      while (p >= 0) {
        if (s[p] == 'P') left_P++;
        p--;
      }
      while (q < n) {
        if (s[q] == 'T') right_T++;
        q++;
      }
      sum += left_P * right_T;
    }
  }
  printf("%d\n", sum);
  return 0;
}
// case3, 4, wrong
*/

// 优化递推的做法,
// Time: O(n)


#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; getline(cin, s);
  int sum = 0, cnt_p = 0, cnt_t = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'T') cnt_t++;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      cnt_p++;
    } else if (s[i] == 'T') {
      cnt_t--;
    } else if (s[i] == 'A') {
      // printf("p = %d, t = %d\n", cnt_p, cnt_t);
      sum = (sum + cnt_p * cnt_t) % 1000000007;
      // sum += cnt_p * cnt_t;
    }
  }
  cout << sum << endl;
  return 0;
}



