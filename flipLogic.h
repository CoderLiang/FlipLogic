#ifndef FLIPLOGIC_H
#define FLIPLOGIC_H
#include <string>

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    TreeNode();
    virtual bool get_val() const = 0;
    virtual int flipLogic() = 0;
    virtual ~TreeNode(){};
};

class LogicTreeNode: public TreeNode {
    // logic can only be && or ||
    std::string logic;
public:
    LogicTreeNode(std::string l);
    ~LogicTreeNode();
    bool get_val() const;
    // return the least amount of operations to flip a logic algebra
    // if not able to flip, return INT_MAX
    int flipLogic();
};

class BoolTreeNode : public TreeNode {
    // val can only be true or false
    bool val;
public:
    BoolTreeNode(bool v);
    ~BoolTreeNode();
    bool get_val() const;
    // because we can only flip logical operator, always return INT_MAX here
    int flipLogic();
};

// construct the logic tree from a string
// example: "|| && True False || True False" will be constructed as:
//                   ||
//         &&                  ||
//   True      False    True         False
TreeNode* construct_logicTree(std::string s);

#endif
