//
// Created by Omar Youssif on 8/27/2023.
//

#include "BSTNode.h"

BSTNode::BSTNode() {left = right = nullptr;}
BSTNode::BSTNode(int value, BSTNode *l, BSTNode *r) :data(value) , left(l) , right(r){}

int BSTNode::getData() const {
    return data;
}

void BSTNode::setData(int data) {
    BSTNode::data = data;
}

void BSTNode::setLeft(BSTNode *left) {
    BSTNode::left = left;
}

void BSTNode::setRight(BSTNode *right) {
    BSTNode::right = right;
}

BSTNode *BSTNode::getLeft() const {
    return left;
}

BSTNode *BSTNode::getRight() const {
    return right;
}
