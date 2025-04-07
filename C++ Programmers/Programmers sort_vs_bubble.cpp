#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
//문제 이걸 sort를 안쓰고 그리고 쓰고의 시간차이를 구하라
using std::vector;
using std::cout;
using std::swap;
using std::endl;
void bubblesort(vector<int>& v) {
   for (size_t i = 0; i < v.size(); i++) {
      for (size_t j = 0; j < v.size() - i - 1; j++) {
         if (v[j] > v[j + 1])
            swap(v[j], v[j + 1]);
      }
   }
}


int main() {
   vector<int>vt(3000);
   for (int i = 0; i < 3000; i++) {
      vt[i] = i + 1;
   }
   vector<int>v2 = vt;
   clock_t startvt2 = clock(); //vt2 버블정렬 시작 시간
   bubblesort(v2);
   clock_t endvt2 = clock();  //vt2  버블정렬 끝나는 시간
   double bubbleclock = (double)(endvt2 - startvt2) / CLOCKS_PER_SEC;
   cout << "sort를 안쓴경우는 " << bubbleclock << endl;


   vector<int>v3 = vt;
   clock_t sortstart = clock(); //v3 sort 시작 시간
   sort(v3.begin(), v3.end());
   clock_t endsort = clock();
   double sorttime = (double)(endsort - sortstart) / CLOCKS_PER_SEC;

   cout << "sort를 쓴 경우는" << sorttime;

   return 0;
}