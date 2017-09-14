# 头文件
INCLUDE =include/

# 源文件
SRC     =src/

# 测试文件
TEST    =test/

# 说明文档
DOC     =doc/

# 编译选项
CXXFLAGS= -Wall -g

# 头文件
INC_FLAGS = -I $(INCLUDE)

# 连接选项
LDFLAGS = -lcpptest

# 目标文件
OBJ     =$(TEST)polynomial_test.o $(TEST)polynomial.o 

all:polynomial.o  polynomial_test.o polynomial_test cpptest astyle doxygen

# 编译
polynomial.o:$(SRC)polynomial.cpp
	g++ -c -std=c++11 $(CXXFLAGS)  -o $(TEST)$@ $<
polynomial_test.o:$(TEST)polynomial_test.cpp
	g++ -c -std=c++11 $(CXXFLAGS) -o $(TEST)$@ $<
polynomial_test:$(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST)$@ $(OBJ) $(LDFLAGS)



##:.$(SRC)bignum.cpp
##	g++ $(CXXFLAGS) -c -o $(TEST)$@ $<

# 静态代码检测
cppcheck:
	cppcheck --enable=all $(SRC) $(INCLUDE)

# 测试
cpptest:
	$(TEST)polynomial_test > $(TEST)test.html

# TODO 覆盖率测试

# TODO 代码统计

# 清空
clean:
	rm -f $(TEST)polynomial_test.o
	rm -f $(TEST)polynomial_test
	rm -f $(TEST)*.html
	rm -f $(DOC)html/*.*

# 格式化
astyle:
	astyle -A8 $(INCLUDE)*.h $(SRC)*.cpp

# 生成文档
doxygen:
	doxygen

