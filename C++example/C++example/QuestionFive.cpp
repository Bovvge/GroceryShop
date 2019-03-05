//
//  QuestionFive.cpp
//  C++example
//
//  Created by 韩金波 on 2019/3/2.
//  Copyright © 2019 韩金波. All rights reserved.
//
#include "QuestionPublic.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;


struct Tree {
    int data;
    Tree *left;
    Tree *right;
};

class BTree {
    
public:
    Tree *root;
    
    BTree(){
        root = NULL;
    }
    
    void insertValue(int value){
        
        Tree * newnode= new Tree;
        
        newnode->data= value;
        
        newnode ->left = NULL;
        
        newnode->right =NULL;
        if(root==NULL){
            root=newnode;
        }else{
            Tree *back = NULL;
            Tree *current= root;
            while(current!=NULL)
            {
                back=current;
                if(current->data> value)
                    current = current->left;
                else
                    current = current->right;
            }
            if(back->data > value){
                back->left = newnode;
            }else{
                back->right = newnode;
            }
        }
        
    }
    void orderByDepth(){
        cout << "逐层打印树的结点:" << endl;
        int k = 0;//深度
        int n = 0;
        Tree ** currList = new Tree * [1];
        if (root != NULL) {
            currList[0] = root;
            n = 1;
        }
        while (true) {
            Tree ** newlist = new Tree* [2^k];
            int newN = 0;
            for (int i = 0; i < n; i ++) {
               Tree* current = currList[i];
                cout << current->data  << "\t";
                if (current->left != NULL) {
                    newlist[newN] = current->left;
                    newN ++;
                }
                if (current->right != NULL) {
                    newlist[newN] = current->right;
                    newN ++;
                }
            }
          
            if (newN == 0) {
                break;
            }else{
                n = newN;
                currList = newlist;
            }
        }
    }

};


void questionFive(){
    
    BTree  btree =  BTree();
    int a[] = {8,6,10,5,7,9,11};
    int k = sizeof(a)/sizeof(a[0]);
    
    
    for (int i = 0; i < k; i++) {
        btree.insertValue(a[i]);
    }
    
    btree.orderByDepth();
}
