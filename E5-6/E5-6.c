
/*****************************************************************************
*                  ��Ȩ���� (C), 1995-2016, �麣�п����������޹�˾            
*								 All Rights Reserved                         
*@��    ��   : ������
*@�� �� ��   : E5-6.c
*@�� �� ��   : 1.0
*@��������   : 2016��11��23��
*@��������   : 
*****************************************************************************/

/************************************�궨��**********************************/

/***********************************���Ͷ���*********************************/

/***********************************ȫ�ֱ���*********************************/

/*********************************ģ��ȫ�ֱ���*******************************/

/*********************************�ֲ�ȫ�ֱ���*******************************/

/*********************************�ֲ���������*******************************/

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
* @��    ��:peteryang0601
* @������:get_number_digit
* @��������:��ȡ���ֵ�ÿλ�������Լ�λ��
* @�������:digit_buf:���ֻ���,number:����
* @�������:NONE
* @�� �� ֵ:���ֵ�λ��
* @��    ע:
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
* @��    ��:peteryang0601
* @������:power
* @��������:�ݼ���
* @�������:base:����,exp:ָ��
* @�������:NONE
* @�� �� ֵ:�ݼ���ֵ
* @��    ע:
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
* @��    ��:peteryang0601
* @������:narcissistic
* @��������:�ж�number�Ƿ�Ϊˮ�ɻ���
* @�������:number:��������
* @�������:NONE
* @�� �� ֵ:1:�ǣ�0:��
* @��    ע:ˮ�ɻ�����ָһ��NNNλ��������N��3N\ge 3N��3����
*		    ����ÿ��λ�ϵ����ֵ�NNN����֮�͵���������
*****************************************************************************/
int narcissistic( int number )
{
	int digit[10] = {0};
	int number_digits = 0;
	int sum = 0;
	int cnt = 0;
	
	if (number <= 0) return 0;	/*ˮ�ɻ���Ϊ������*/
	
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
* @��    ��:peteryang0601
* @������:PrintN
* @��������:��ӡ�����ڵ�ˮ����
* @�������:��������
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:
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

/***************** (C) COPYRIGHT 2016 �麣�����������޹�˾ *****END OF FILE**/

