#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct T
{
   int h;
   int m;
};

int32_t main()
{

   vector<pair<T, T>> intervals;

   int n;
   cin >> n;

   auto cmp = [&](pair<T, T> t1, pair<T, T> t2)
   {
      if (t1.first.h == t2.first.h)
         return t1.first.m < t2.first.m;
      else
         return t1.first.h < t2.first.h;
   };

   for (int i = 0; i < n; i++)
   {
      string s;
      cin >> s;

      T t1, t2;


      t1.h = (s[0] - '0') * 10 + (s[1] - '0');
      t1.m = (s[3] - '0') * 10 + (s[4] - '0');
      if (s[5] == 'P')
      { 
         t1.h%=12;
         t1.h += 12;
      }


      t2.h = (s[0 + 8] - '0') * 10 + (s[1 + 8] - '0');
      t2.m = (s[3 + 8] - '0') * 10 + (s[4 + 8] - '0');
      // t2.AM = (s[5+8] == 'A' ? true:false);
      if (s[5 + 8] == 'P')
         t2.h += 12;

      intervals.push_back({t1, t2});
   }
   sort(intervals.begin(), intervals.end(), cmp);



   auto calcDif = [&](T t1, T t2)
   {
      if (t1.h > t2.h || (t1.h == t2.h && t1.m > t2.m))
      {
         T res;
         res.h = 0, res.m = 0;
         return res;
      }

      T res;

      if (t1.m > t2.m)
      {
         t2.h -= 1;
         t2.m += 60;
      }

      res.m = t2.m - t1.m;
      res.h = t2.h - t1.h;

      return res;
   };

   T res = {0, 0};

   auto Max = [&](T t1, T t2)
   {
      if (t1.h != t2.h)
      {
         if (t1.h < t2.h)
            return t2;
         return t1;
      }
      {
         if (t1.m < t2.m)
            return t2;
         return t1;
      }
   };

   for (int i = 1; i < n; i++)
   {
      auto t1 = intervals[i - 1].second;
      auto t2 = intervals[i].first;

      T d = calcDif(t1, t2);
      res = Max(res, d);
   }
  
   cout << res.h << " " << res.m << "\n";
}