//
//  KBReversion.cpp
//  C++example
//
//  Created by 韩金波 on 2019/2/27.
//  Copyright © 2019 韩金波. All rights reserved.
//

#include "QuestionPublic.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;

void reversionStatement();
void reversionReadWrite(char * str ,char * reverStr, int index, int start, int len );

void questionTwo(){
    reversionStatement();
}
void reversionStatement(){
    char * str = new char [1000];//输入字符串
    cout << "请输入一段英语句子:\n" ;
    cin.getline(str, 1000);//改方法可以输入空格
    
    int size = (int)strlen(str);
    cout << "你输入的英语句子：\n" << str << "\nsize:" << size ;
    
    char * reversionStr = new char[size + 1];//反转字符串初始化
    reversionStr[size] = '\0';//字符串以'\0'结尾
    
    int index = 0;//单词的开始位置
    int len = 0;//单词的长度
    //逆序查到空格，就认为是单词
    for (int i = size - 1; i >=0; i--) {
        char c = str[i];
        len++;
        if(c == ' ' ){
            reversionReadWrite(str, reversionStr, index, i, len);
            index  += len;
            len = 0;
        }else if(i == 0  ){
            reversionReadWrite(str, reversionStr, index, 0, len);
        }
    }
    int newSize = (int)strlen(reversionStr);
    cout << "\n翻转后的字符串：\n"<< reversionStr <<"\nsize:" << newSize << endl;
}

//翻转写入，一个单词一个单词的写
void reversionReadWrite(char * str ,char * reverStr, int index, int start, int len ){
    int i = 0;
    bool hasUpper = false;//首字母是不是已经大写了
    while (i< len) {
        char c = str[start + i];
        if (c >= 'A' && c <= 'Z') {
            hasUpper = true;
        }else if ( !hasUpper &&c >= 'a'&& c <= 'z') {
            c -= 32;//转换大小写
            hasUpper = true;
        }
        if (c == ' ') {
            reverStr[index + len - 1] = c;//当第一个是空格
        }else{
            reverStr[index] = c;
            index ++;
        }
        i++;
    }
}
