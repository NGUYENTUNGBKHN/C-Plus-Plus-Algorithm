/******************************************************************************/
/*! @addtogroup Group2
    @file       main.cpp
    @brief      
    @date       2024/11/08
    @author     Development Dept at Tokyo (nguyen-thanh-tung@jcm-hq.co.jp)
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
/* Problem :  Given N pairs of parentheses, write a fucntion to generate all 
*           combinations of well-formed parentheses
*      Example : 
*           Input : N = 3
*           Output : ["((()))","(()())","(())()","()(())","()()()"]
*       Constraints : 
*           1 <= n <= 8
*https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/794/
*/

#include <cassert>
#include <iostream>
#include <vector>

namespace backTracking{

class generate_parentheses
{
    public:
        std::vector<std::string> generate(int n);
    private:
        std::vector<std::string> res; // contains all possible valid patterns

        void makeString(std::string str, int n, int closed, int open);

    protected:
};

std::vector<std::string> generate_parentheses::generate(int n)
{
    backTracking::generate_parentheses::res.clear();
    std::string str = "(";

    backTracking::generate_parentheses::makeString(str, n, 0, 1);

    return res;
}

void generate_parentheses::makeString(std::string str, int n, int closed, int open)
{
    if (closed > open)
    {
        return ;
    }
    
    if ((str.length() == 2 * n) && (closed != open))
    {
        return ;
    }

    if (str.length() == 2 * n)
    {
        res.push_back(str);
        return;
    }

    makeString(str + ')', n, closed + 1, open);
    makeString(str + '(', n, closed, open + 1);
}

}

static void test()
{
    int n = 0;
    std::vector<std::string> pattern;
    backTracking::generate_parentheses p;

    /* Case test 1 */
    n = 1;
    pattern = {{"()"}};
    assert(p.generate(n) == pattern);

    /* Case test 2 */
    n = 3;
    pattern = {{"()()()"}, {"()(())"}, {"(())()"}, {"(()())"}, {"((()))"}};
    assert(p.generate(n) == pattern);

    /* Case test 3 */
    n = 4;
    pattern = {{"()()()()"}, {"()()(())"}, {"()(())()"}, {"()(()())"},
                {"()((()))"}, {"(())()()"}, {"(())(())"}, {"(()())()"},
                {"(()()())"}, {"(()(()))"}, {"((()))()"}, {"((())())"},
                {"((()()))"}, {"(((())))"}};
    assert(p.generate(n) == pattern);

    std::cout << "All tests passed !!" << std::endl;
}


int main()
{

    std::cout << "Generate parentheses problem \n" << std::endl;

    test();
    
    return 0;
}

