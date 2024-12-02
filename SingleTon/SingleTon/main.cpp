//main.cpp

#include <iostream>
#include "Singleton.h"

int main() {
	Singleton::Instance().Log("test");
	SingletonD::Instance().Log("test");
}
