
/*****************************************************************************
*                  版权所有 (C), 1995-2016, 珠海市科荟电器有限公司            
*								 All Rights Reserved                         
*@作    者   : 阳永锋
*@文 件 名   : E5-4.c
*@版 本 号   : 1.0
*@创建日期   : 2016年11月22日
*@功能描述   : 
*****************************************************************************/

/************************************宏定义**********************************/

/***********************************类型定义*********************************/

/***********************************全局变量*********************************/

/*********************************模块全局变量*******************************/

/*********************************局部全局变量*******************************/

/*********************************局部函数声明*******************************/
#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

/*****************************************************************************
* @作    者:peteryang0601
* @函数名:prime
* @功能描述:判断输入数是否为素数
* @输入参数:p:输入整数
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。
*****************************************************************************/
int prime( int p )
{
	int temp = 0;
	int div = 3;
	
	if (p < 1)			/*素数 > 1*/
	{
		return 0;
	}
	else if (p == 1)	/*1不是素数*/
	{
		return 0;
	}
	else if (p == 2)	/*2 是素数*/
	{
		return 1;
	}
	else if (p % 2 == 0) /*偶数除2外都不是素数*/
	{
		return 0;
	}
	else
	{
		temp = sqrt(p);						/*如非素数，必有一个因素<=开方根植*/
		for (div = 3; div <= temp; div++)	
		{
			if (p % div == 0) return 0;
		}
		return 1;
	}
}

/*****************************************************************************
* @作    者:peteryang0601
* @函数名:PrimeSum
* @功能描述:计算区间内素数和
* @输入参数:m:区间起始值,n区间结束值
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:
*****************************************************************************/
int PrimeSum( int m, int n )
{
	int temp = m ;
	int sum = 0;
	
	for (temp = m; temp <= n; temp++)
	{
		if (prime(temp) != 0)
		{
			sum += temp;
		}
	}
	return sum;
}

/***************** (C) COPYRIGHT 2016 珠海科荟电器有限公司 *****END OF FILE**/

