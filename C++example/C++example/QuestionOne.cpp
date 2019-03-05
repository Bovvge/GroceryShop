// MyFirstProgram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "QuestionPublic.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;
//函数声明
void calculateFibonacciSequence(int num);

void questionOne(){
    calculateFibonacciSequence(20);
}

void calculateFibonacciSequence(int num) {

    cout << "计算出斐波那契数列前20位:"<<endl;
	int *fib = new int[num];//斐波那契数列
    
	int index = 0;//计数器
	int next = 0;
	int pre = 0;
	while (index < num)//生成斐波那契数列
	{
		if (index == 0)
		{
			next = 1;
		}
		else
		{
			int temp = next + pre;
			pre = next;
			next = temp;
		}
		fib[index] = next;
		cout << index + 1 << ":    " << next << endl;//输出每一位的斐波那契数列
		index++;
	}
	//计算斐波那契数列的和
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum = fib[i] * (num - i) + sum;
	}

	cout << "计算和：" << sum << endl;
}



