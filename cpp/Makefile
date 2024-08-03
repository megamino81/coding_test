# Makefile

# C++ 컴파일러와 플래그
CXX = g++
#CXXFLAGS = -Wall -Wextra -std=c++17
CXXFLAGS = -std=c++17

# 소스 파일과 대상 파일 목록
SOURCES = $(wildcard *.cpp)
BINARY = $(SOURCES:.cpp=)

# 기본 목표: 모든 바이너리 파일을 빌드
all: $(BINARY)

# 각 소스 파일을 컴파일하여 해당 바이너리를 생성
$(BINARY): % : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# clean 목표: 모든 빌드된 바이너리 파일 삭제
clean:
	rm -f $(BINARY)

# .PHONY: makefile에 없는 파일 이름과 같은 목표를 정의하여
# `make clean`과 같은 명령어가 실제 파일이 없어도 실행되도록 합니다.
.PHONY: all clean
