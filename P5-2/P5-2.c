
/*****************************************************************************
*                  版权所有 (C), 1995-2016, 珠海市科荟电器有限公司            
*								 All Rights Reserved                         
*@作    者   : 阳永锋
*@文 件 名   : P5-1.c
*@版 本 号   : 1.0
*@创建日期   : 2016年11月14日
*@功能描述   : 
*****************************************************************************/

/************************************宏定义**********************************/

/***********************************类型定义*********************************/

/***********************************全局变量*********************************/

/*********************************模块全局变量*******************************/

/*********************************局部全局变量*******************************/

/*********************************局部函数声明*******************************/


#include <stdio.h>

int max( int a, int b );

int main()
{    
    int a, b;

    scanf("%d %d", &a, &b);
    printf("max = %d\n", max(a, b));

    return 0;
}


/*****************************************************************************
* @作    者:阳永锋
* @函数名:max
* @功能描述:比较值大小
* @输入参数:a,b
* @输出参数:NONE
* @返 回 值:和
* @备    注:
*****************************************************************************/
int max( int a, int b )
{
	return ((a >= b)?a:b);
}

/***************** (C) COPYRIGHT 2016 珠海科荟电器有限公司 *****END OF FILE**/

