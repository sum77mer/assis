#pragma once
#include "SynQueryData.h"

typedef struct{
	string Name;
	string _Language;
	string SerialNumber;
	string Manufacturer;
}BIOS_Data;
class BIOS
{
public:
	BOOL excute();
	int find_location(vector<string> vecIntegerArray, string search_string);
	BIOS_Data Return_BIOS_info();
private:
	BIOS_Data info;
};