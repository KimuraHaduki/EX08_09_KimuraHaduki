#pragma once
class Package {
private:
	int type;
	int yuupakkuSize[8] = { 60,80,100,120,140,160,170,0 };
	int yamatoSize[9] = { 60,80,100,120,140,160,180,200,0 };

public:
	Package(int type);
	int SizeCheck(double size);
};