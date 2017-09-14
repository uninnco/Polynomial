#include <iostream>

#define private public
#include "../include/polynomial.h"

#include "/usr/local/include/cpptest.h"

class Polynomialtest:public Test::Suite{
public:
	Polynomialtest(){
		TEST_ADD(Polynomialtest::Init);
		TEST_ADD(Polynomialtest::Add)
	}
private:
	void Init(){
		try{
			Polynomial p("3x^3+4x^2+7x^1+1");
			std::cout <<p<<std::endl;
			std::cout <<p.term_[0]<<std::endl;
			std::cout <<p.term_[1]<<std::endl;
			std::cout <<p.term_[2]<<std::endl;
			std::cout <<p.term_[3]<<std::endl;
			TEST_ASSERT_MSG(p.term_[0] == 1,"p的0次项系数为1");
			TEST_ASSERT_MSG(p.term_[1] == 7,"p的1次项系数为7");
			TEST_ASSERT_MSG(p.term_[2] == 4,"p的2次项系数为4");
			TEST_ASSERT_MSG(p.term_[3] == 3,"p的3次项系数为3");
			TEST_ASSERT_MSG(p.term_.size() == 4,"该多项式只有四项");
			Polynomial p2("1x^5+4x^2+100");
			TEST_ASSERT_MSG(p2.term_[0] == 100,"p2的0次项系数为100");
			TEST_ASSERT_MSG(p2.term_[2] == 4,"p2的2次项系数为4");
			TEST_ASSERT_MSG(p2.term_[5] == 1,"p2的0次项系数为1");
			TEST_ASSERT_MSG(p2.term_.size() == 3,"该多项式只有0项");
			Polynomial p3("1");
			TEST_ASSERT_MSG(p3.term_[0] == 1,"p3的0次项系数为1");
			TEST_ASSERT_MSG(p3.term_.size() ==1,"该多项式只有3项");
			Polynomial p4("0");
			TEST_ASSERT_MSG(p4.term_[0] == 0,"p4的0次项系数为0");
			TEST_ASSERT_MSG(p3.term_.size() ==1,"该多项式只有1项");
		}catch(...){
			TEST_FAIL("unknown exception");
		}
	}
	void Add(){
		try{
			Polynomial p1("3x^2+2x^1+5");
			Polynomial p2("5x^6+4x^2+6x^1+1");
			Polynomial p3;
			p3 = p1+p2;
			
			
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}

};
int main(){
	Polynomialtest polynomial_test;
	Test::HtmlOutput output;
	polynomial_test.run(output,true);
	output.generate(std::cout,true,"Polynomialtest");
}
