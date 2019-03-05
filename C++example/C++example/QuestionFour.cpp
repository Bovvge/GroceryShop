//
//  KBFind.cpp
//  C++example
//
//  Created by 韩金波 on 2019/2/27.
//  Copyright © 2019 韩金波. All rights reserved.
//

#include "QuestionPublic.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;

void findWithArray(int *list,int len, int sum);

void questionFour(){
        int list[] = {1,4,7,8,11,15};
        findWithArray(list, 6, 15);
}

struct Couple {
    int a;
    int b;
};
/**
 输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。要求时间复杂度是 O(n)。如果有多对数字的和等于输入的数字，输出乘积较大的一对
 @param list 排好序的数组
 @param len 数组长度
 @param sum 对数和
 */
void findWithArray(int *list,int len, int sum){
    cout << "你输入的数组：" << endl;
    for (int i = 0; i < len; i++) {
        cout << list[i] << "\t";
    }
    cout << "数字和：" << sum << endl;
    Couple * couArr = new Couple[len/2];
    
    int end = len -1;
    
    int index = 0;
    
    for (int start = 0; start < len; start++) {
        
        int a = list[start];
        
        int j = end;
        
        while (j > start) {
            
            int b = list[j];
            
            j--;
            
            if ((a + b) == sum) {
                Couple cou =  Couple();
                cou.a = a;
                cou.b = b;
                
                couArr[index] = cou;//存储对数
                
                end = j;//更新尾坐标
                index ++;//
                
                break;
            }else if( a + b < sum){
                break;
            }
        }
        if (start >= end) {
            break;
        }
    }
    cout << "输出每一对和为"<< sum << "的数"<< endl;
    for (int i = 0; i < index; i++) {
        Couple cou =  couArr[i];
        cout << cou.a << "," << cou.b << endl;
    }
    
    //积最大的一对数
    Couple cou =  couArr[index-1];
    cout << "积最大的一对数：\n" << cou.a << "," << cou.b << endl;

}


