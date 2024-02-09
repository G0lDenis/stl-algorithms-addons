#include "algo/py_algo.h"

#include <gtest/gtest.h>
#include <vector>


TEST(AlgoTestSuit, AllOfTest) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    ASSERT_FALSE(py_algo::all_of(v.begin(), v.end(), [](int a) { return a == 1; }));

    std::vector<std::string> v2(5, "Nice");
    ASSERT_TRUE(py_algo::all_of(v2.begin(), v2.end(), [](const std::string& a) { return a == "Nice"; }));

    std::vector<int> v3 = {};
    ASSERT_TRUE(py_algo::all_of(v3.begin(), v3.end(), [](int a) { return a == 0; }));
}

TEST(AlgoTestSuit, AnyOfTest) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(py_algo::any_of(v.begin(), v.end(), [](int a) { return a == 1; }));
    ASSERT_FALSE(py_algo::any_of(v.begin(), v.end(), [](int a) { return a == 0; }));

    std::vector<int> v2 = {};
    ASSERT_FALSE(py_algo::any_of(v2.begin(), v2.end(), [](int a) { return a == 0; }));
}

TEST(AlgoTestSuit, NoneOfTest) {
    std::vector<float> v = {1.2, 2.2, 3.4, 4.5, 5.6, 6.7, 7.8};
    ASSERT_TRUE(py_algo::none_of(v.begin(), v.end(), [](float a) { return a == 1.1f; }));
    ASSERT_FALSE(py_algo::none_of(v.begin(), v.end(), [](float a) { return a == 6.7f; }));

    std::vector<int> v2 = {};
    ASSERT_TRUE(py_algo::none_of(v2.begin(), v2.end(), [](int a) { return a == 0; }));
}

TEST(AlgoTestSuit, OneOfTest) {
    std::vector<float> v = {1.2, 2.2, 3.4, 4.5, 5.6, 6.7, 4.5, 7.8, 8.8};
    ASSERT_FALSE(py_algo::one_of(v.begin(), v.end(), [](float a) { return a == 1.1f; }));
    ASSERT_TRUE(py_algo::one_of(v.begin(), v.end(), [](float a) { return a == 6.7f; }));
    ASSERT_FALSE(py_algo::one_of(v.begin(), v.end(), [](float a) { return a == 4.5f; }));

    std::vector<int> v2 = {};
    ASSERT_FALSE(py_algo::one_of(v2.begin(), v2.end(), [](int a) { return a == 0; }));
}

TEST(AlgoTestSuit, IsSortedTest) {
    std::vector<float> v = {1.2, 2.2, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9};
    ASSERT_TRUE(py_algo::is_sorted(v.begin(), v.end()));

    std::vector<int> v2 = {};
    ASSERT_TRUE(py_algo::is_sorted(v2.begin(), v2.end()));

    std::vector<float> v3 = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9};
    std::reverse(v3.begin(), v3.end());
    ASSERT_TRUE(py_algo::is_sorted(v3.begin(), v3.end(), [](float a, float b) { return a > b; }));

    std::vector<float> v4 = {1.2, 2.3, 3.4, 4.5, 5.7, 5.6, 6.7, 7.8, 8.9};
    ASSERT_FALSE(py_algo::is_sorted(v4.begin(), v4.end()));
}

TEST(AlgoTestSuit, IsPartitionedTest) {
    std::vector<float> v = {1.2, 2.2, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9};
    ASSERT_TRUE(py_algo::is_partitioned(v.begin(), v.end(), [](float a) { return a <= 4.5f; }));
    ASSERT_TRUE(py_algo::is_partitioned(v.begin(), v.end(), [](float a) { return a < 0.f; }));

    std::vector<int> v2 = {1, 3, 5, 7, 8, 10, 12, 14};
    ASSERT_TRUE(py_algo::is_partitioned(v2.begin(), v2.end(), [](int a) { return a % 2 == 1; }));
    ASSERT_FALSE(py_algo::is_partitioned(v2.begin(), v2.end(), [](int a) { return a % 3 == 0; }));
}


TEST(AlgoTestSuit, FindNotTest) {
    std::vector<float> v = {1.2, 1.2, 1.2, 1.3, 1.2, 1.4, 1.7, 1.2};
    ASSERT_EQ(v.begin() + 3, py_algo::find_not(v.begin(), v.end(), 1.2f));

    std::vector<int> v2(10, 1);
    ASSERT_EQ(v2.end(), py_algo::find_not(v2.begin(), v2.end(), 1));
}

TEST(AlgoTestSuit, FindBackwardTest) {
    std::vector<float> v = {1.2, 1.2, 1.2, 1.3, 1.2, 1.4, 1.7, 1.2};
    ASSERT_EQ(v.begin() + 5, py_algo::find_backward(v.begin(), v.end(), 1.4f));

    std::vector<int> v2(10, 1);
    ASSERT_EQ(v2.end(), py_algo::find_backward(v2.begin(), v2.end(), 2));
}

TEST(AlgoTestSuit, IsPalindromeTest) {
    std::vector<int> v = {1, 2, 2, 2, 3, 2, 2, 2, 1};
    ASSERT_TRUE(py_algo::is_palindrome(v.begin(), v.end()));

    std::vector<int> v2 = {1, 2, 2, 2, 2, 2, 2, 1};
    ASSERT_TRUE(py_algo::is_palindrome(v2.begin(), v2.end()));

    std::vector<int> v3 = {1, 2, 3, 2, 2, 4, 2, 1};
    ASSERT_FALSE(py_algo::is_palindrome(v3.begin(), v3.end()));
}

TEST(XrangeTestSuit, ConstructorsTest) {
    auto range1 = py_algo::xrange<int>(1, 7, 2);
    std::vector<int> result1 = {1, 3, 5};
    auto p1 = result1.begin();
    for (auto i: range1) {
        ASSERT_EQ(*p1, i);
        p1++;
    }
    ASSERT_EQ(p1, result1.end());

    auto range2 = py_algo::xrange<int>(1, 7);
    std::vector<int> result2 = {1, 2, 3, 4, 5, 6};
    auto p2 = result2.begin();
    for (auto i: range2) {
        ASSERT_EQ(*p2, i);
        p2++;
    }
    ASSERT_EQ(p2, result2.end());

    auto range3 = py_algo::xrange(1.2, 7.3);
    std::vector<double> result3 = {1.2, 2.2, 3.2, 4.2, 5.2, 6.2, 7.2};
    auto p3 = result3.begin();
    for (auto i: range3) {
        ASSERT_EQ(*p3, i);
        p3++;
    }
    ASSERT_EQ(p3, result3.end());
}

TEST(ZipTestSuit, ConstructorTest) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<std::string> v2 = {"Hey,", "bro!", "Awesome", "test", ")", "))"};
    auto zip1 = py_algo::zip(v, v2);
    std::vector<std::pair<int, std::string>> result = {{1, "Hey,"},
                                                       {2, "bro!"},
                                                       {3, "Awesome"},
                                                       {4, "test"},
                                                       {5, ")"}};
    auto p1 = result.begin();
    for (auto i: zip1) {
        ASSERT_EQ(p1->first, i.first);
        ASSERT_EQ(p1->second, i.second);
        p1++;
    }
    ASSERT_EQ(p1, result.end());
}
