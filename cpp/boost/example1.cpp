#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <vector>
#include "iostream"
using namespace std;
using namespace boost;

// 全局测试夹具类
struct global_fixture {
    global_fixture() { cout << "global setup" << endl;}
    ~global_fixture() { cout << "global teardown" << endl;}
};

// 定义全局夹具
BOOST_GLOBAL_FIXTURE(global_fixture);
// using namespace boost::assign;
// boost::assign::BOOST_CHECK_EQUAL(m,4);;
// 测试套件夹具类
struct assign_fixture {
    assign_fixture() {cout << "suit setup" << endl;}
    ~assign_fixture() {cout << "suit teardown" << endl;}

    std::vector<int> v;
};

// 定义测试套件级别的夹具
//前面说测试夹具就好比c++的构造函数和析构函数，也可以理解为在执行测试之前设置一个环境，在测试完成时清除它。
BOOST_FIXTURE_TEST_SUITE(s_assign, assign_fixture)  //使用该夹具的测试放在里面

BOOST_AUTO_TEST_CASE(fff) {
    using namespace boost::assign;
    v += 1, 2, 3, 4;
    BOOST_CHECK_EQUAL(v.size(), 4);
    BOOST_CHECK_EQUAL(v[2], 3);
    
}

BOOST_AUTO_TEST_CASE(t_assign2) {
    using namespace boost::assign;

    push_back(v)(11)(22)(33);
    BOOST_CHECK_EQUAL(v.empty(), true);
    BOOST_CHECK_LT(v[0], v[1]);
}

BOOST_AUTO_TEST_SUITE_END()