// Copyright [2018] <mituh>
// 1037. 在霍格沃茨找零钱(20).cpp    07:56 -> 8:16 = 20min
/*
1037 在霍格沃茨找零钱（20 point(s)）

如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 [0, 10
​7] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例 1：

10.16.27 14.1.28
输出样例 1：

3.2.1
输入样例 2：

14.1.28 10.16.27
输出样例 2：

-3.2.1
*/


#include <cstdio>

char str_p[100];
char str_a[100];

int main() {
  scanf("%s %s", str_p, str_a);
  int g, s, k;
  sscanf(str_p, "%d.%d.%d", &g, &s, &k);
  int P = 17*29*g + 29*s + k;
  sscanf(str_a, "%d.%d.%d", &g, &s, &k);
  int A = 17*29*g + 29*s + k;

  int delta = A-P, flag;
  if (delta >= 0) {
    flag = 1;
  } else {
    flag = -1; delta *= -1;
  }

  int gg, ss, kk;
  gg = delta / (17*29); delta -= 17*29*gg;     // bug1
  ss = delta / 29;      delta -= 29*ss;
  kk = delta;
  printf("%d.%d.%d\n", flag*gg, ss, kk);

  return 0;
}
