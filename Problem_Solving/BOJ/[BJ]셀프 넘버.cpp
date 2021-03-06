#include <stdio.h>

/* 자리수 무관하게 만든 함수가 주요 */
/*
int d(int n)
{
	int dn;
	
	dn = n + n / 1000 + (n / 100 - (n / 1000) * 10) + (n / 10 - (n / 100) * 10) + (n - (n / 10) * 10);
	//4 자리, 3자리 

	return dn;
}
*/

//n(생성자)가 없는 수 1, 3, 5, 7, 9, 20, 31 ....
// 1 -> 2 4 8 16 23 28 38 49 62 70 .....
// 3 -> 6 12 15 21 24 30 33 39 51 57 
// 5 ->
// 7 -> 14 19 29 40 44 52 59 
// 9 -> 18 27 36 45 54 63 72 
// 

int d(int n) {
	int sum = n;    //자기 자신을 먼저 더해주고

	while (n > 0) {   // 각 자리수의 숫자를 더해야하므로 1의 자리를 계속 더해준다.
		sum += n % 10;  //나머지, 1의 자리 더해주기
		n = n / 10;     //한자리씩 없애기
	}
	return sum;
}


int main()
{
//	int arr[10000] = { 0 };
	int idx[10000] = { 0 }; //0, 1 ~ 9999 //idx[0] == 0, idx[9999] = 9999

	/*
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = i; // 0 , 1 ~ 9999
	}
	*/
	//arr[1] ~ arr[9999] 에 1 ~ 9999까지를 채워 넣는다. <---- 이럴 꺼면 arr배열 따로 만들지 않고, 이후 i를 바로 출력한다. 

	/* 1)
	int j = 0,temp;
	for (int i = 1; i <= 9998; i++)//9998보다 더 적어도 된다.
	{
		if (arr[i] != 0) 
		{
			j = i;
			
			while (j < 10000)
			{
				temp = d(j);
				arr[temp] = 0;//2
				j = temp;
			}
		}
	}
	*/
	int tmp = 0;

	for (int i = 1; i < 10000; i++) {
		int tmp = d(i); //i의 셀프 넘버

		if (tmp < 10000 && idx[tmp] == 0) {
			idx[tmp] = 1;    //셀프넘버 아닌 수 true 로 변경
		}
	}
	/* 1)
	* 첫번째 방법은 하나의 수에 대해 수열을 만들어 해당 수열을 인덱스로 하는 arr 배열을 0으로 만들어 주고
	* 다음 i 값에 대해서도 진행하는 방식이었다. 런타임 에러.
	* 중복이 많았나 보다. if (arr[i] != 0) 조건을 넣어 줌에도 불구하고...
	*/

	/* 2)
	* tmp가 9999를 넘어가는 경우, idx[10000] = {0};에서 idx[tmp]는 다시 
	* 배열 앞부분의 숫자를 건드리는 일이 발생했다. 따라서 tmp<=10000을 추가.
	* idx[tmp] == 0 : 이미 다른 생성자에 의해 idx[tmp] 가 1이 된 경우는 
	* 또, 연산해줄 필요 없다.
	*/
	/* 3) 4) 5)
	* arr[i] = i 해서 arr[i]를 이후 출력 해줘야 하는 경우 for문의 i값을 그대로 출력하자
	* 각 자리수 구하는 방법: a = n%10 ->  n = n/10 반복
	* 배열의 모든 원소를 모두 1로 초기화 해주는 방법은 for문 돌리는 수 밖에 없다. 
	*/

	/*
	for (int i = 1; i <= 9998; i++)//9998보다 더 적어도 된다.
	{
		if(d(i)<10000)
		idx[d(i)] = 1; // 생성자면 1로 한다. 
	}
	*/
	for (int i = 1; i < 10000; i++) //idx[9999]까지 존재
	{
		if(!idx[i]) //생성자가 아니면, idx(i)가 1이 아니면 
		printf("%d\n", i);
	}
	return 0;
}

