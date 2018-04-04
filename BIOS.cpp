#include "BIOS.h"
#include <tchar.h>

BOOL BIOS::excute()
{
    BSTR bstring1=::SysAllocString(L"root\\CIMV2");
    BSTR bstring2=::SysAllocString(L"SELECT Name,CurrentLanguage,Manufacturer,SerialNumber FROM Win32_BIOS");
    CSynQueryData recvnotify( bstring1,bstring2);
    recvnotify.ExcuteFun();
    vector<string> out_put_data = recvnotify.ClassData();
    vector<string> out_put_name = recvnotify.ClassName();
    int myPosition = -1;
    string str = "Name";
    myPosition = this->find_location(out_put_name, str);
	if (myPosition != -1)
	{
		info.Name = out_put_data[myPosition];
	}
	else return FALSE;
    str = "CurrentLanguage";
	myPosition = this->find_location(out_put_name,str);
	if (myPosition != -1)
	{
		info._Language = out_put_data[myPosition];
	}
	else return FALSE;
    str = "Manufacturer";
	myPosition = this->find_location(out_put_name,str);
	if (myPosition != -1)
	{
		info.Manufacturer = out_put_data[myPosition];
	}
	else return FALSE;
    str = "SerialNumber";
	myPosition = this->find_location(out_put_name,str);
	if (myPosition != -1)
	{
		info.SerialNumber = out_put_data[myPosition];
	}
	else return FALSE;
	return TRUE;
}

BIOS_Data BIOS::Return_BIOS_info()
{
	return info;
}

int BIOS::find_location(vector<string> vecIntegerArray, string search_string)
{
	vector <string>::iterator iElement = find(vecIntegerArray.begin(),  
		vecIntegerArray.end(),search_string);  
	if( iElement != vecIntegerArray.end() )  
	{  
		int nPosition = distance(vecIntegerArray.begin(),iElement);  
		return nPosition;
	}  
	return -1;
}

