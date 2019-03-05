//
//  QuestionSix.cpp
//  C++example
//
//  Created by 韩金波 on 2019/2/28.
//  Copyright © 2019 韩金波. All rights reserved.
//

#include "QuestionPublic.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;

struct Location {
    int row;
    int col;
};

void questionSix(){
    int n ;
    cout << "请输入矩阵维数：\n";
    cin >> n;
    
    int ** matrix = new int *[n];//初始矩阵
    
    int ** spiralMatrix = new int *[n];//螺旋矩阵
    
    
    cout << "随机生成矩阵:\n";
    int count = n * n;//矩阵元素数量
    for (int i = 0; i < n; i++) {
        
        matrix[i] = new int[n];
        
        spiralMatrix[i] = new int[n];
        
        for (int j = 0; j < n; j++) {
            
            int value = rand()%count + 1;//随机数;
            
            cout << value << '\t';
            
            matrix[i][j] = value;
            
        }
        cout << "\n";
    }
    
    Location * locArray = new Location[count];//把矩阵转换成一维的索引
    
    int row = 0;//行
    
    int col = 0;//列
    
    int direction = 0; //旋转方向 0，1，2，3 下 右 上 左 ,deatlut = 0;
    
    int index = 0;//计数器
    
    while (index < count) {
        int cir = direction/4;
        
        Location loc = Location();
        loc.row = row;
        loc.col = col;
        locArray[index] = loc;
        
        index ++;

//        cout << row << '\t' << col << '\t'<< matrix[row][col] << endl;
        
        switch (direction%4) {
            case 0:
            {
                row++;
                if (row == n - cir - 1 ) {
                    direction++;
                }
            }
                break;
            case 1:
            {
                col++;
                if (col == n - cir -1 ) {
                    direction ++;
                }
            }
                break;
            case 2:
            {
                row --;
                if (row ==  cir ) {
                    direction ++;
                }
            }
                break;
            case 3:
            {
                col --;
                if (col == cir + 1) {
                    direction ++;
                }
            }
                break;
                
            default:
                break;
        }
    }
    
  
//排序
    for (int i = 0; i < count-1; i++) {
        for (int j = i+1; j < count; j++) {
            
            Location loc1 = locArray[i];
            
            Location loc2 = locArray[j];
            
            int v1 = matrix[loc1.row][loc1.col];
            
            int v2 = matrix[loc2.row][loc2.col];
            
            if (v1 > v2) {
                
                matrix[loc1.row][loc1.col] = v2;
                
                matrix[loc2.row][loc2.col] = v1;
                
            }
        }
    }
    
    
    cout << "矩阵螺旋输出:\n";
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j <n; j++) {
            
            cout << matrix[i][j] << '\t';
        }
        cout << "\n";
    }
}
