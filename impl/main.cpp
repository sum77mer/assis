
#include "cpuid.h"
#include "BIOS.h"

int main()
{

	info_out CPUID_info;
	CPUID_Data Save_CPU_Data;
	CPUID_info.excute_CPUID();
	Save_CPU_Data = CPUID_info.RES_DATA;

	BIOS bios_info;
	bios_info.excute();
	BIOS_Data Save_BIOS_Data = bios_info.Return_BIOS_info();
	
	return 0;
}
