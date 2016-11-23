
/*****************************************************************************
*                  版权所有 (C), 1995-2016, 珠海市科荟电器有限公司            
*								 All Rights Reserved                         
*@作    者   : 阳永锋
*@文 件 名   : E5-6.c
*@版 本 号   : 1.0
*@创建日期   : 2016年11月23日
*@功能描述   : 
*****************************************************************************/

/************************************宏定义**********************************/

/***********************************类型定义*********************************/

/***********************************全局变量*********************************/

/*********************************模块全局变量*******************************/

/*********************************局部全局变量*******************************/

/*********************************局部函数声明*******************************/

#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

static int print_array(int array[], int array_size)
{
	int cnt = 0;

	for (cnt = 0; cnt < array_size;)
	{
		printf("%2d",array[cnt]);
		if(++cnt % 5 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
}

/*****************************************************************************
* @作    者:peteryang0601
* @函数名:get_number_digit
* @功能描述:获取数字的每位的数字以及位数
* @输入参数:digit_buf:数字缓存,number:数字
* @输出参数:NONE
* @返 回 值:数字的位数
* @备    注:
*****************************************************************************/
static int get_number_digit(int digit_buf[], int number)
{
	int number_digits = 0;

	while(number != 0)
	{
		digit_buf[number_digits++] = number%10;
		number /= 10;
	}
	//print_array(digit_buf,number_digits);
	return number_digits;
}

/*****************************************************************************
* @作    者:peteryang0601
* @函数名:power
* @功能描述:幂计算
* @输入参数:base:底数,exp:指数
* @输出参数:NONE
* @返 回 值:幂计算值
* @备    注:
*****************************************************************************/
static int power(int base, int exp)
{
	int result = 1;
	int cnt = 0;
	
	while(exp-- > 0)
	{
		result *= base;
	}
	return result;
}

/*****************************************************************************
* @作    者:peteryang0601
* @函数名:narcissistic
* @功能描述:判断number是否为水仙花数
* @输入参数:number:输入数字
* @输出参数:NONE
* @返 回 值:1:是，0:否
* @备    注:水仙花数是指一个NNN位正整数（N≥3N\ge 3N≥3），
*		    它的每个位上的数字的NNN次幂之和等于它本身
*****************************************************************************/
int narcissistic( int number )
{
	int digit[10] = {0};
	int number_digits = 0;
	int sum = 0;
	int cnt = 0;
	
	if (number <= 0) return 0;	/*水仙花数为正整数*/
	
	number_digits = get_number_digit(digit,number);
	if (number_digits > 0)
	{
		for (cnt = 0; cnt < number_digits; cnt++)
		{
			sum += power(digit[cnt],number_digits);
		}
		if (sum == number)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

/*****************************************************************************
* @作    者:peteryang0601
* @函数名:PrintN
* @功能描述:打印区间内的水仙数
* @输入参数:数据区间
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:
*****************************************************************************/
void PrintN( int m, int n )
{
	int number = m;

	for (number = m + 1; number < n; number++)
	{
		if (narcissistic(number) != 0)
		{
			if (m != n)
			{
				printf("%d\n",number);
			}
			else
			{
				printf("%d\n",m);
				printf("%d\n",n);
			}
		}
	}
}

/***************** (C) COPYRIGHT 2016 珠海科荟电器有限公司 *****END OF FILE**/

