#include <iostream>
#include "Package.h"
using namespace std;
Package::Package(int type) {
	this->type = type;
}
int Package::SizeCheck(double size) {
	if (type == 1) {
		for (int i = 0; i < sizeof(yuupakkuSize); i++) {
			if (size < yuupakkuSize[i]) {
				return yuupakkuSize[i];
			}
		}
	}
	else if (type == 2) {
		for (int i = 0; i < sizeof(yamatoSize); i++) {
			if (size < yamatoSize[i]) {
				return yamatoSize[i];
			}
		}
	}

	return 0;
}