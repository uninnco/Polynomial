#pragma once
#include <iostream>
#include <map>
#include <string>
//////////////////////////////////////////////////////////////////
/////  按照次幂的由高到低的输入多项式
//////////////////////////////////////////////////////////////////
/**
 * @file Polynomial.h
 * @brief 多项式运算
 * @details 用于多项式的加减乘及输出值
 * @version 1.0
 * @author 荣立飞
 * @date 2017-8-23
 */
using std::string;
using std::map;
using std::ostream;
/**
 * @brief 多项式类实现
 */

class Polynomial
{
public:
    /**
     * @brief 默认构造函数
     */
    Polynomial();
    /**
     * @brief 构造函数 请按照次幂由大到小的输入，并且系数为1时不要省略 没有那么智能TAT
     * @prama p 输入的字符串形式多项式
     */
    Polynomial(string const& p);
    /**
     * @brief 复制构造
     * @prama p 多项式对象
     */
    Polynomial(Polynomial const& p);
    /**
     * @brief 重载运算符=
     * @prama p 多项式对象
     */
    Polynomial& operator=(Polynomial const& p);
    /**
     * @brief 重载运算符+
     * @prama p 多项式对象
     * return 一个新的多项式对象
     */
    Polynomial operator+(Polynomial const& p);
    /**
     * @brief 重载运算符-
     * @prama p 多项式对象
     * return 一个新的多项式对象
     */
    Polynomial operator-(Polynomial const& p);
    /**
     * @brief 重载运算符*
     * @prama p 多项式对象
     * return 一个新的多项式对象
     */
    Polynomial operator*(Polynomial const& p);
    /**
     * @brief 输入x值，给出结果
     * @prama x int类型变量
     * return 一个int类型的结果
     */
    int compute(int x);
    /**
     * @brief 重载运算符<<
     */
    friend ostream& operator<<(ostream& os,Polynomial const& p);
private:
    map<size_t,int> term_;
    ///map将次幂作为键
    ///将系数作为值
};
