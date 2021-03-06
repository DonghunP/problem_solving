//#include <iostream>
//#include <string>
//using namespace std;
//
//int recur(string s)
//{
//    if (s.size() == 2)
//    {
//        if (s[0] == '0')
//            return 0;
//        else if (s[1] == '0') {
//            if (stoi(s) > 40)
//                return 0;
//            else
//                return 1;
//        }
//        else
//            return 2;
//    }
//    if (s.size() == 1)
//    {
//        if (s[0] == '0')
//            return 0;
//        else
//            return 1;
//    }
//
//
//    if (stoi(s.substr(0, 2)) > 40 && s[1] != '0') //경우의 수를 못 나는 경우 -> 0번째 숫자 무시
//    {
//        return recur(s.substr(1, s.size()));
//    }
//    else if (s[1] == '0') //두번째 자리가 0이면 못나눈다
//    {
//        return recur(s.substr(2, s.size()));
//    }
//    else
//    {
//        return recur(s.substr(1, s.size())) + recur(s.substr(2, s.size()));
//    }
//}
//
//int main() {
//    string s;
//    getline(cin, s);
//
//    cout << recur(s);
//    return 0;
//}

//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	char n[45];
//	int num[45] = { 0 };
//	int dp[45] = { 0 };
//	cin >> n;
//	for (int i = 0; i < strlen(n); i++) {
//		num[i] = n[i] - '0';
//	}
//
//	dp[0] = 1;
//	for (int i = 0; i < strlen(n); i++) {
//		if (num[i] != 0) {
//			dp[i + 1] += dp[i];
//			if (10 <= num[i] * 10 + num[i + 1] && num[i] * 10 + num[i + 1] <= 34) {
//				dp[i + 2] += dp[i];
//			}
//		}
//	}
//
//	cout << dp[strlen(n)];
//
//}

#include <stdio.h>
int i, arr[44], dp[44];
int main() {
	dp[1] = 1;
	for (i = 2; scanf("%1d", &arr[i]) != -1; i++) {
		if (arr[i]) 
			dp[i] += dp[i - 1];

		if ( (arr[i] + arr[i - 1] * 10 >= 10) && (arr[i] + arr[i - 1] * 10 <= 34) )
			dp[i] += dp[i - 2];
	}
	printf("%d", dp[i - 1]);
	return 0;
}

//#include<cstdio>
//int a[41], dp[41] = { 1 }, i;
//int main() {
//    for (i = 1; scanf("%1d", a + i) != -1; i++)
//        dp[i] = dp[i - 1] * (a[i] > 0) + dp[i - 2] * (a[i - 1] * 10 + a[i] > 9 && a[i - 1] * 10 + a[i] <= 34);
//    printf("%d", dp[i - 1]);
//    return 0;
//}