#include "flipLogic.h"
#include <sstream>
#include <string>
#include <cassert>
#include <climits>
#include <algorithm>
using namespace std;

TreeNode::TreeNode() {
    left = NULL;
    right = NULL;
}

LogicTreeNode::LogicTreeNode(string l) : TreeNode() {
    logic = l;
}

BoolTreeNode::BoolTreeNode(bool v) : TreeNode() {
    val = v;
}


bool LogicTreeNode::get_val() const {
    if (logic == "&&") {
        return ((left -> get_val()) && (right -> get_val()));
    }
    return ((left -> get_val()) || (right -> get_val()));
}

bool BoolTreeNode::get_val() const {
    return val;
}

int LogicTreeNode::flipLogic() {
    if (logic == "&&") {
        // both left and right are true, flip one true to false
        if (left -> get_val() && right -> get_val()) {
            return min(left -> flipLogic(), right -> flipLogic());
        }
        // either left or right is true, flip && to ||
        else if (left -> get_val() || right -> get_val()) {
            return 1;
        }

        // both left and right are false, need to flip && to || and flip left or right subtree 
        else {
            int num = min(left -> flipLogic(), right -> flipLogic());
            return num == INT_MAX ? INT_MAX : num + 1;
        }
    }

    else {
        // both left and right are true, flip || to && and flip left or right subtree
        if (left -> get_val() && right -> get_val()) {
            int num = min(left -> flipLogic(), right -> flipLogic());
            return num == INT_MAX ? INT_MAX : num + 1;
        }
        // either left or right is true, flip || to &&
        else if (left -> get_val() || right -> get_val()) {
            return 1;
        }
        // both left and right are false, flip one false to true
        else {
            return min(left -> flipLogic(), right -> flipLogic());
        }
    }
    assert(false);
}

int BoolTreeNode::flipLogic() {
    return INT_MAX;
}


static TreeNode* construct_logicTree_helper(istringstream& iss) {
    string s;
    iss >> s;
    TreeNode* node;
    if (s == "&&" || s == "||") {
        node = new LogicTreeNode(s);
        node -> left = construct_logicTree_helper(iss);
        node -> right = construct_logicTree_helper(iss);
    }
    else {
        if (s == "True") {
            node = new BoolTreeNode(true);
        }
        else if (s == "False"){
            node = new BoolTreeNode(false);
        }
        else {
            assert(false);
        }
    }
    return node;
}

TreeNode* construct_logicTree(string s) {
    istringstream iss(s);
    return construct_logicTree_helper(iss);
}













