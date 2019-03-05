//
//  QuestionThree.cpp
//  C++example
//
//  Created by 韩金波 on 2019/3/2.
//  Copyright © 2019 韩金波. All rights reserved.
//
#include "QuestionPublic.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;

void questionThree(){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << "上排十个数：" << endl;
    for (int i = 0 ; i < 10; i++) {
        cout << a[i] <<"\t";
    }
    //0,1,2,3,4,5,6,7,8,9,必须上面的出现数字加起来之和为1
    int b[10]= {6,2,1,0,0,0,0,0,1,0};
    cout << "\n\n下排排十个数：" << endl;
    for (int i = 0 ; i < 10; i++) {
        cout << b[i] << "\t";
    }
    cout << "\n"<< endl;
}
