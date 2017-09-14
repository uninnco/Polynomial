#include "../include/polynomial.h" //主头文件
#include <algorithm>
#include <sstream>
//////////////////////////////////////////////////////////////////
/////  按照次幂的由高到低的输入多项式
//////////////////////////////////////////////////////////////////
using std::istringstream;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::find;
using std::ostream;


Polynomial::Polynomial() {}
Polynomial::Polynomial(string const& p)
{
    istringstream iss(p);
    while(!iss.eof()) {
        int item_num(0); //项的系数
        char x('0');  //识别'x'  三种情况  x^2  x  1的时候会被item_num读到
        char index_symbool('0'); //识别'^'
        size_t power(0);  //幂次
        iss >> item_num;
        iss >> x;
        iss >> index_symbool;
        if(item_num != 0 && x != 'x'&& index_symbool != '^') {  //防止该项只有一个数字,并且数字项必须在最后
            term_[0] = item_num;
            return ;
        }
#ifdef DEBUG
        cout<<"项数: " << item_num<<endl;
        cout<<"x: "<< x<<endl;
        cout<<"^: " <<index_symbool<<endl;
#endif
        if(index_symbool != '^') {
            term_[1] = item_num;
            if(index_symbool != '0') { //这时次幂读取到的是下个多项式的正负号
                //后面的power读取到了后面项的系数
                if(index_symbool == '-') {
                    iss >> power;
                    term_[0] = power*(-1);
                }
                if(index_symbool == '+') {
                    iss >> power;
                    term_[0] = power;
                }

            }
            continue;
        }
        iss >> power;
        term_[power] =item_num;
    }
}
Polynomial::Polynomial(Polynomial const& p)
{
    this->term_ = p.term_;
}
Polynomial& Polynomial::operator=(Polynomial const& p)
{
    this-> term_ = p.term_;
    return *this;
}
Polynomial Polynomial::operator+(Polynomial const& p)
{
    Polynomial res(*this);
    for(auto m:(p.term_)) {
        auto it = term_.find(m.first);
        if(it != term_.end()) {
            res.term_[it->first] = it->second + m.second;  //如果找到就相同的项的系数相加
        } else {
            res.term_[m.first] = m.second;  //没找到就把该项添上
        }
    }
    return res;
}
Polynomial Polynomial::operator-(Polynomial const& p)
{
    Polynomial res(*this);
    for(auto m:(p.term_)) {
        auto it = term_.find(m.first);
        if(it != term_.end()) {
            res.term_[it->first] = it->second - m.second;  //如果找到就相同的项的系数相加
        } else {
            res.term_[m.first] =(-1)* m.second;  //没找到就把该项添上
        }
    }
    return res;
}
Polynomial Polynomial::operator*(Polynomial const& p)
{
    Polynomial res;
    for(auto l:term_) {
        for(auto r:(p.term_)) {
            res.term_[l.first+r.first] += l.second* r.second;  //如果找到就相同的项的系数相加
        }
    }
    return res;
}
int Polynomial::compute(int x)
{
    int res(0);
    for(auto m:term_) {
        res += m.second*(int)pow(x,m.first);
    }
    return res;
}
/*friend*/ostream& operator<<(ostream& os,Polynomial const& p)
{
    size_t i = 0;
    bool loop_first_flag = 1;
    for(auto m:p.term_) {
        if(m.first == 0&&m.second != 0) {
            if(m.second > 0 ) {
                if(loop_first_flag != 1) {
                    os << "+"<<m.second;
                } else {
                    os<<m.second;
                    loop_first_flag = 0;
                }
            } else if(m.second < 0) {
                os <<m.second;
            }
            continue;
        }
        if(m.second > 0) {
            if(loop_first_flag == 1) {
                os << m.second << "x^"<<m.first;
                loop_first_flag = 0;
                continue;
            }
            os<<"+"<<m.second<<"x^"<<m.first;
        }
        if(m.second < 0) {
            os<<m.second<<"x^"<<m.first;
        }
        if(m.second == 0) {  //判断该项系数是否为零
            i++;
        }
    }
    if(i == p.term_.size()) {
        os<<"0" ;
    }
    return os;
}
