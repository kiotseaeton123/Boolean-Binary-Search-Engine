
#include <catch2/catch_all.hpp>
#include <iostream>
#include <string>
#include "../AVLTree.h"
#include <utility>

using namespace std;

TEST_CASE("test case") {
    pair<string, int> temp("hi", 1);
    AVLTree<int, pair<string, int>> tree;
    tree.insert(1, temp);

    std::cout << "Tests can run!" << std::endl;
    CHECK(1);
}

