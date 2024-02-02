//
// Created by Omar Youssif on 8/27/2023.
//

#ifndef BST_BSTNODE_H
#define BST_BSTNODE_H


class BSTNode {
private:
    int data;
    BSTNode *left , *right;
public:
    BSTNode();
    BSTNode(int value , BSTNode* l= nullptr , BSTNode*r = nullptr);

    int getData() const;

    BSTNode *getLeft() const;

    BSTNode *getRight() const;

    void setData(int data);

    void setLeft(BSTNode *left);

    void setRight(BSTNode *right);


};


#endif //BST_BSTNODE_H
