#include "flipLogic.h"
#include <iostream>
#include <string>
#include <cassert>
#include <climits>

void test_basic1();
void test_basic2();
void test_basic3();
void test_cannot_flip();

using namespace std;
int main() {
    test_basic1();
    test_basic2();
    test_basic3();
    test_cannot_flip();
}

static void test_template(string logicStr, int min_num) {
    TreeNode* root = construct_logicTree(logicStr);
    int actual_num = root -> flipLogic();
    cout << "Expected flip times: " << min_num << endl;
    cout << "Actual flip times: " << actual_num << endl;
    delete root;
    assert(min_num == actual_num);
    cout << "PASS" << endl;
}

void test_basic1() {
    test_template("|| && True False || True False", 1);
}

void test_basic2() {
    test_template("&& && True False && False False", 2);
}

void test_basic3() {
    test_template("&& || && True False False && False False", 2);
}

void test_cannot_flip() {
    test_template("&& || && False False False && False False", INT_MAX);
}

