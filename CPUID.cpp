#include "cpuid.h"


//利用CPUID指令获取CPU的信息
void Get_CPUIDinfo::Read_CPUID(UINT IN_EAX,UINT IN_ECX)	
{
    /*
	DWORD CPUinfo_a, CPUinfo_b, CPUinfo_c, CPUinfo_d;
    _asm{
            pushad
                mov eax,IN_EAX
                mov ecx,IN_ECX
                cpuid
                mov dword ptr CPUinfo_a,eax
                mov dword ptr CPUinfo_b,ebx
                mov dword ptr CPUinfo_c,ecx
                mov dword ptr CPUinfo_d,edx
                popad
        }
        */
    unsigned long CPUinfo_a, CPUinfo_b, CPUinfo_c, CPUinfo_d;
    _asm{
            pushad
                mov eax,IN_EAX
                mov ecx,IN_ECX
                cpuid
                mov dword ptr CPUinfo_a,eax
                mov dword ptr CPUinfo_b,ebx
                mov dword ptr CPUinfo_c,ecx
                mov dword ptr CPUinfo_d,edx
                popad
        }
/*
    _asm("pushad\\n\\t"
            "movw IN_EAX,%eax\\n\\t"
            "movw IN_ECX,%ecx\\n\\t"
            "cpuid\\n\\t"
            "movl %eax,$ CPUinfo_a\\n\\t"
            "movl %ebx,$ CPUinfo_b\\n\\t"
            "movl %ecx,$ CPUinfo_c\\n\\t"
            "movl %edx,$ CPUinfo_d\\n\\t"
            "popad");
*/
	m_eax = CPUinfo_a;
	m_ebx = CPUinfo_b;
	m_ecx = CPUinfo_c;
	m_edx = CPUinfo_d;
}

//EAX= 2时 CPUID返回值中代表的信息。
void Info_out::save_cache(unsigned char cacheinfo)
{
	switch  (cacheinfo)
	{
    case 0x00:
		break;
    case 0x01: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4-KBPages, 4-way set associative, 32 entries");
		break;
    case 0x02: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4-MB Pages, fully associative, 2 entries");
		break;
    case 0x03: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-KB Pages, 4-way set associative, 64 entries");
		break;
    case 0x04: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-MB Pages, 4-way set associative, 8 entries");
		break;
    case 0x05: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-MB Pages, 4-way set associative, 32 entries");
		break;
    case 0x06: RES_DATA.Cache_TLB.emplace_back( "1st-level instruction cache: 8-KB, 4-way set associative, 32-byte line size");
		break;
    case 0x08: RES_DATA.Cache_TLB.emplace_back( "1st-level instruction cache: 16-KB, 4-way set associative, 32-byte line size");
		break;
    case 0x09: RES_DATA.Cache_TLB.emplace_back( "1st-level instruction cache: 32-KBytes, 4-way set associative, 64 byte line size");
		break;
    case 0x0A: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 8-KB, 2-way set associative, 32-byte line size");
		break;
    case 0x0B: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4-MByte pages, 4-way set associative, 4 entries");
		break;
    case 0x0C: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 16-KB, 4-way set associative, 32-byte line size");
		break;
    case 0x0D: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 16 KBytes, 4-way set associative, 64 byte line size");
		break;
    case 0x0E: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 24 KBytes, 6-way set associative, 64 byte line size");
		break;
    case 0x1D: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 128 KBytes, 2-way set associative, 64 byte line size");
		break;
    case 0x21: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 256 KBytes, 8-way set associative, 64 byte line size");
		break;
    case 0x22: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 512 KB, 4-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x23: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 1-MB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x24: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 1 MBytes, 16-way set associative, 64 byte line size");
		break;
    case 0x25: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 2-MB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x29: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 4-MB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x2C: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 32-KB, 8-way set associative, 64-byte line size");
		break;
    case 0x30: RES_DATA.Cache_TLB.emplace_back( "1st-level instruction cache: 32-KB, 8-way set associative, 64-byte line size");
		break;
    case 0x39: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 128-KB, 4-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x3A: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 192-KB, 6-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x3B: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 128-KB, 2-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x3C: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 256-KB, 4-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x3D: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 384-KB, 6-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x3E: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 512-KB, 4-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x40: RES_DATA.Cache_TLB.emplace_back( "No 2nd-level cache or, if processor contains a valid 2nd-level cache, no 3rd-level cache");
		break;
    case 0x41: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 128-KB, 4-way set associative, 32-byte line size");
		break;
    case 0x42: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 256-KB, 4-way set associative, 32-byte line size");
		break;
    case 0x43: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 512-KB, 4-way set associative, 32-byte line size");
		break;
    case 0x44: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 1-MB, 4-way set associative, 32-byte line size");
		break;
    case 0x45: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 2-MB, 4-way set associative, 32-byte line size");
		break;
    case 0x46: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 4MB, 4-way set associative, 64-byte line size");
		break;
    case 0x47: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 8MB, 8-way set associative, 64-byte line size");
		break;
    case 0x48: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 3MByte, 12-way set associative, 64 byte line size");
		break;
    case 0x49: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 4MB, 16-way set associative, 64-byte line size (Intel Xeon processor MP,Family 0Fh, Model 06h \n 2nd-level cache: 4MB, 16-way set associative, 64-byte line size");
		break;
    case 0x4A: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 6MB, 12-way set associative, 64-byte line size");
		break;
    case 0x4B: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 8MB, 16-way set associative, 64-byte line size");
		break;
    case 0x4C: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 12MB, 12-way set associative, 64-byte line size");
		break;
    case 0x4D: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 16MB, 16-way set associative, 64-byte line size");
		break;
    case 0x4E: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 6MB, 24-way set associative, 64-byte line size");
		break;
    case 0x4F: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4 KByte pages, 32 entries");
		break;
    case 0x50: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4-KB, 2-MB or 4-MB pages, fully associative, 64 entries");
		break;
    case 0x51: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4-KB, 2-MB or 4-MB pages, fully associative, 128 entries");
		break;
    case 0x52: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4-KB, 2-MB or 4-MB pages, fully associative, 256 entries");
		break;
    case 0x55: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 2-MByte or 4-MByte pages, fully associative, 7 entries");
		break;
    case 0x56: RES_DATA.Cache_TLB.emplace_back( "Data TLB0: 4 MByte pages, 4-way set associative, 16 entries");
		break;
    case 0x57: RES_DATA.Cache_TLB.emplace_back( "Data TLB0: 4 KByte pages, 4-way associative, 16 entries");
		break;
    case 0x59: RES_DATA.Cache_TLB.emplace_back( "Data TLB0: 4 KByte pages, fully associative, 16 entries");
		break;
    case 0x5A: RES_DATA.Cache_TLB.emplace_back( "Data TLB0: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries");
		break;
    case 0x5B: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-KB or 4-MB pages, fully associative, 64 entries");
		break;
    case 0x5C: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-KB or 4-MB pages, fully associative, 128 entries");
		break;
    case 0x5D: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-KB or 4-MB pages, fully associative, 256 entries");
		break;
    case 0x60: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 16-KB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x61: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4 KByte pages, fully associative, 48 entries");
		break;
    case 0x63: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries and a separate array with 1 GByte pages, 4-way set associative, 4 entries");
		break;
    case 0x64: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4 KByte pages, 4-way set associative, 512 entries");
		break;
    case 0x66: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 8-KB, 4-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x67: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 16-KB, 4-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x68: RES_DATA.Cache_TLB.emplace_back( "1st-level data cache: 32-KB, 4 way set associative, sectored cache, 64-byte line size");
		break;
    case 0x6A: RES_DATA.Cache_TLB.emplace_back( "uTLB: 4 KByte pages, 8-way set associative, 64 entries");
		break;
    case 0x6B: RES_DATA.Cache_TLB.emplace_back( "DTLB: 4 KByte pages, 8-way set associative, 256 entries");
		break;
    case 0x6C: RES_DATA.Cache_TLB.emplace_back( "DTLB: 2M/4M pages, 8-way set associative, 128 entries");
		break;
    case 0x6D: RES_DATA.Cache_TLB.emplace_back( "DTLB: 1 GByte pages, fully associative, 16 entries");
		break;
    case 0x70: RES_DATA.Cache_TLB.emplace_back( "Trace cache: 12K-uops, 8-way set associative");
		break;
    case 0x71: RES_DATA.Cache_TLB.emplace_back( "Trace cache: 16K-uops, 8-way set associative");
		break;
    case 0x72: RES_DATA.Cache_TLB.emplace_back( "Trace cache: 32K-uops, 8-way set associative");
		break;
    case 0x76: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 2M/4M pages, fully associative, 8 entries");
		break;
    case 0x78: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 1-MB, 4-way set associative, 64-byte line size");
		break;
    case 0x79: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 128-KB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x7A: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 256-KB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x7B: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 512-KB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x7C: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 1-MB, 8-way set associative, sectored cache, 64-byte line size");
		break;
    case 0x7D: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 2-MB, 8-way set associative, 64-byte line size");
		break;
    case 0x7F: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 512-KB, 2-way set associative, 64-byte line size");
		break;
    case 0x80: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 512 KByte, 8-way set associative, 64-byte line size");
		break;
    case 0x82: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 256-KB, 8-way set associative, 32-byte line size");
		break;
    case 0x83: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 512-KB, 8-way set associative, 32-byte line size");
		break;
    case 0x84: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 1-MB, 8-way set associative, 32-byte line size");
		break;
    case 0x85: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 2-MB, 8-way set associative, 32-byte line size");
		break;
    case 0x86: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 512-KB, 4-way set associative, 64-byte line size");
		break;
    case 0x87: RES_DATA.Cache_TLB.emplace_back( "2nd-level cache: 1-MB, 8-way set associative, 64-byte line size");
		break;
    case 0xA0: RES_DATA.Cache_TLB.emplace_back( "DTLB: 4k pages, fully associative, 32 entries");
		break;
    case 0xB0: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4-KB Pages, 4-way set associative, 128 entries");
		break;
    case 0xB1: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 2M pages, 4-way, 8 entries or 4M pages, 4-way, 4 entries");
		break;
    case 0xB2: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4KByte pages, 4-way set associative, 64 entries");
		break;
    case 0xB3: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-KB Pages, 4-way set associative, 128 entries");
		break;
    case 0xB4: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4-KB Pages, 4-way set associative, 256 entries");
		break;
    case 0xB5: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4KByte pages, 8-way set associative, 64 entries");
		break;
    case 0xB6: RES_DATA.Cache_TLB.emplace_back( "Instruction TLB: 4KByte pages, 8-way set associative, 128 entries");
		break;
    case 0xBA: RES_DATA.Cache_TLB.emplace_back( "Data TLB1: 4 KByte pages, 4-way associative, 64 entries");
		break;
    case 0xC0: RES_DATA.Cache_TLB.emplace_back( "Data TLB: 4 KByte and 4 MByte pages, 4-way associative, 8 entries");
		break;
    case 0xC1: RES_DATA.Cache_TLB.emplace_back( "Shared 2nd-Level TLB: 4 KByte/2MByte pages, 8-way associative, 1024 entries");
		break;
    case 0xC2: RES_DATA.Cache_TLB.emplace_back( "DTLB: 4 KByte/2 MByte pages, 4-way associative, 16 entries");
		break;
    case 0xC3: RES_DATA.Cache_TLB.emplace_back( "Shared 2nd-Level TLB: 4 KByte /2 MByte pages, 6-way associative, 1536 entries. Also 1GBbyte pages, 4-way, 16 entries.");
		break;
    case 0xC4: RES_DATA.Cache_TLB.emplace_back( "DTLB: 2M/4M Byte pages, 4-way associative, 32 entries");
		break;
    case 0xCA: RES_DATA.Cache_TLB.emplace_back( "Shared 2nd-Level TLB: 4 KByte pages, 4-way associative, 512 entries");
		break;
    case 0xD0: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 512 KByte, 4-way set associative, 64 byte line size");
		break;
    case 0xD1: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 1 MByte, 4-way set associative, 64 byte line size");
		break;
    case 0xD2: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 2 MByte, 4-way set associative, 64 byte line size");
		break;
    case 0xD6: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 1 MByte, 8-way set associative, 64 byte line size");
		break;
    case 0xD7: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 2 MByte, 8-way set associative, 64 byte line size");
		break;
    case 0xD8: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 4 MByte, 8-way set associative, 64 byte line size");
		break;
    case 0xDC: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 1.5 MByte, 12-way set associative, 64 byte line size");
		break;
    case 0xDD: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 3 MByte, 12-way set associative, 64 byte line size");
		break;
    case 0xDE: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 6 MByte, 12-way set associative, 64 byte line size");
		break;
    case 0xE2: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 2 MByte, 16-way set associative, 64 byte line size");
		break;
    case 0xE3: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 4 MByte, 16-way set associative, 64 byte line size");
		break;
    case 0xE4: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 8 MByte, 16-way set associative, 64 byte line size");
		break;
    case 0xEA: RES_DATA.Cache_TLB.emplace_back( "3rd-level cache: 12MByte, 24-way set associative, 64 byte line size");
		break;
    case 0xEB: RES_DATA.Cache_TLB.emplace_back("3rd-level cache: 18MByte, 24-way set associative, 64 byte line size");
		break;
    case 0xEC: RES_DATA.Cache_TLB.emplace_back("3rd-level cache: 24MByte, 24-way set associative, 64 byte line size");
        break;

    case 0xF0: RES_DATA.Cache_TLB.emplace_back("64-byte Prefetching");
		break;
    case 0xF1: RES_DATA.Cache_TLB.emplace_back("128-byte Prefetching");
		break;
	default:
		break;
	}
}

//EAX= 1 时 CPUID中的信息（CPU）
void get_info::CPUID_MAIN_LEAF_1()
{
	this->Read_CPUID(1,0);
	this->RES_info.CPU_MAIN_LEAF_NAME.emplace_back( "Main Leaf 1");
	RES_info.CPU_SUB_LEAF_NAME.emplace_back( "Sub Leaf 0");
	RES_info.CPU_EAX.emplace_back(m_eax);
	RES_info.CPU_EBX.emplace_back(m_ebx);
	RES_info.CPU_ECX.emplace_back(m_ecx);
	RES_info.CPU_EDX.emplace_back(m_edx);
	RES_info.Position.emplace_back(100);
}

//EAX= 2 时 CPUID中的信息 （Cache）
void get_info::CPUID_MAIN_LEAF_2()
{
	this->Read_CPUID(2,0);
	RES_info.CPU_MAIN_LEAF_NAME.emplace_back( "Main Leaf 2");
	RES_info.CPU_SUB_LEAF_NAME.emplace_back( "Sub Leaf 0");
	RES_info.CPU_EAX.emplace_back(m_eax);
	RES_info.CPU_EBX.emplace_back(m_ebx);
	RES_info.CPU_ECX.emplace_back(m_ecx);
	RES_info.CPU_EDX.emplace_back(m_edx);
	RES_info.Position.emplace_back(200);
}

//EAX= 4 时 CPUID中的信息（Cache）
void get_info::CPUID_MAIN_LEAF_4()
{
	do 
	{
		static int i = 0;
		this->Read_CPUID(4,i);
		if ((m_eax & CACHE_TYPE) == 0x00)	break;
		RES_info.CPU_MAIN_LEAF_NAME.emplace_back( "Main Leaf 4");
		RES_info.CPU_SUB_LEAF_NAME.emplace_back( "Sub Leaf " + i);
		RES_info.CPU_EAX.emplace_back(m_eax);
		RES_info.CPU_EBX.emplace_back(m_ebx);
		RES_info.CPU_ECX.emplace_back(m_ecx);
		RES_info.CPU_EDX.emplace_back(m_edx);
		RES_info.Position.emplace_back(400 + i);
		i++;
	} while ((m_eax & CACHE_TYPE) != 0x00);
}

//EAX= 5 时 CPUID中的信息（Mointor/Mwait）
void get_info::CPUID_MAIN_LEAF_5()
{
	this->Read_CPUID(5,0);
	RES_info.CPU_MAIN_LEAF_NAME.emplace_back( "Main Leaf 5");
	RES_info.CPU_SUB_LEAF_NAME.emplace_back( "Sub Leaf 0");
	RES_info.CPU_EAX.emplace_back(m_eax);
	RES_info.CPU_EBX.emplace_back(m_ebx);
	RES_info.CPU_ECX.emplace_back(m_ecx);
	RES_info.CPU_EDX.emplace_back(m_edx);
	RES_info.Position.emplace_back(500);
}
//EAX= 7 时 CPUID中的信息（Mointor/Mwait）
void get_info::CPUID_MAIN_LEAF_7()
{
	this->Read_CPUID(7,0);
	RES_info.CPU_MAIN_LEAF_NAME.emplace_back( "Main Leaf 7");
	RES_info.CPU_SUB_LEAF_NAME.emplace_back( "Sub Leaf 0");
	RES_info.CPU_EAX.emplace_back(m_eax);
	RES_info.CPU_EBX.emplace_back(m_ebx);
	RES_info.CPU_ECX.emplace_back(m_ecx);
	RES_info.CPU_EDX.emplace_back(m_edx);
	RES_info.Position.emplace_back(700);
}
//查找信息，确定EAX= n时的位置
int get_info::find_location(vector<int> vecIntegerArray, int search_num)
{
	vector <int>::iterator iElement = find(vecIntegerArray.begin(),  
		vecIntegerArray.end(),search_num);  
	if( iElement != vecIntegerArray.end() )  
	{  
		int nPosition = distance(vecIntegerArray.begin(),iElement);  
		return nPosition;
	}  
	return -1;
}
//void Info_out::GET_E_FEATURE_INFO(DWORD EBX, DWORD ECX)
void Info_out::GET_E_FEATURE_INFO(unsigned long EBX, unsigned long ECX)
{
	(EBX & FSGSBASE_FLAGS) ? RES_DATA.Feature_info.FSGSBASE = TRUE : RES_DATA.Feature_info.FSGSBASE = FALSE;
	(EBX & IA32_TSC_ADJUST_MSR_FLAGS) ? RES_DATA.Feature_info.IA32_TSC_ADJUST_MSR = TRUE : RES_DATA.Feature_info.IA32_TSC_ADJUST_MSR = FALSE;
	(EBX & SGX_FLAGS) ? RES_DATA.Feature_info.SGX = TRUE : RES_DATA.Feature_info.SGX = FALSE;
	(EBX & BMI1_FLAGS) ? RES_DATA.Feature_info.BMI1 = TRUE : RES_DATA.Feature_info.BMI1 = FALSE;
	(EBX & HLE_FLAGS) ? RES_DATA.Feature_info.HLE = TRUE : RES_DATA.Feature_info.HLE = FALSE;
	(EBX & AVX2_FLAGS) ? RES_DATA.Feature_info.AVX2 = TRUE : RES_DATA.Feature_info.AVX2 = FALSE;
	(EBX & FDP_EXCPTN_ONLY_FLAGS) ? RES_DATA.Feature_info.FDP_EXCPTN_ONLY = TRUE : RES_DATA.Feature_info.FDP_EXCPTN_ONLY = FALSE;
	(EBX & SMEP_FLAGS) ? RES_DATA.Feature_info.SMEP = TRUE : RES_DATA.Feature_info.SMEP = FALSE;
	(EBX & BMI2_FLAGS) ? RES_DATA.Feature_info.BMI2 = TRUE : RES_DATA.Feature_info.BMI2 = FALSE;
	(EBX & Enhanced_REP_MOVSB_OR_STOSB_FLAGS) ? RES_DATA.Feature_info.Enhanced_REP_MOVSB_OR_STOSB = TRUE : RES_DATA.Feature_info.Enhanced_REP_MOVSB_OR_STOSB = FALSE;
	(EBX & INVPCID_FLAGS) ? RES_DATA.Feature_info.INVPCID = TRUE : RES_DATA.Feature_info.INVPCID = FALSE;
	(EBX & RTM_FLAGS) ? RES_DATA.Feature_info.RTM = TRUE : RES_DATA.Feature_info.RTM = FALSE;
	(EBX & RDT_M_FLAGS) ? RES_DATA.Feature_info.RDT_M = TRUE : RES_DATA.Feature_info.RDT_M = FALSE;
	(EBX & FPU_CS_DS_FLAGS) ? RES_DATA.Feature_info.FPU_CS_DS = TRUE : RES_DATA.Feature_info.FPU_CS_DS = FALSE;
	(EBX & MPX_FLAGS) ? RES_DATA.Feature_info.MPX = TRUE : RES_DATA.Feature_info.MPX = FALSE;
	(EBX & RDT_A_FLAGS) ? RES_DATA.Feature_info.RDT_A = TRUE : RES_DATA.Feature_info.RDT_A = FALSE;
	(EBX & RDSEED_FLAGS) ? RES_DATA.Feature_info.RDSEED = TRUE : RES_DATA.Feature_info.RDSEED = FALSE;
	(EBX & ADX_FLAGS) ? RES_DATA.Feature_info.ADX = TRUE : RES_DATA.Feature_info.ADX = FALSE;
	(EBX & SMAP_FLAGS) ? RES_DATA.Feature_info.SMAP = TRUE : RES_DATA.Feature_info.SMAP = FALSE;
	(EBX & CLFLUSHOPT_FLAGS) ? RES_DATA.Feature_info.CLFLUSHOPT = TRUE : RES_DATA.Feature_info.CLFLUSHOPT = FALSE;
	(EBX & CLWB_FLAGS) ? RES_DATA.Feature_info.CLWB = TRUE : RES_DATA.Feature_info.CLWB = FALSE;
	(EBX & Intel_Processor_Trace_FLAGS) ? RES_DATA.Feature_info.Intel_Processor_Trace = TRUE : RES_DATA.Feature_info.Intel_Processor_Trace = FALSE;
	(EBX & SHA_FLAGS) ? RES_DATA.Feature_info.SHA = TRUE : RES_DATA.Feature_info.SHA = FALSE;
	(ECX & PREFETCHWT1_FLAGS) ? RES_DATA.Feature_info.PREFETCHWT1 = TRUE : RES_DATA.Feature_info.PREFETCHWT1 = FALSE;
	(ECX & UMIP_FLAGS) ? RES_DATA.Feature_info.UMIP = TRUE : RES_DATA.Feature_info.UMIP = FALSE;
	(ECX & PKU_FLAGS) ? RES_DATA.Feature_info.PKU = TRUE : RES_DATA.Feature_info.PKU = FALSE;
	(ECX & OSPKE_FLAGS) ? RES_DATA.Feature_info.OSPKE = TRUE : RES_DATA.Feature_info.OSPKE = FALSE;
	(ECX & RDPID_FLAGS) ? RES_DATA.Feature_info.RDPID = TRUE : RES_DATA.Feature_info.RDPID = FALSE;
	(ECX & SGX_LC_FLAGS) ? RES_DATA.Feature_info.SGX_LC = TRUE : RES_DATA.Feature_info.SGX_LC = FALSE;
}
int get_info::find_location(vector<string> vecIntegerArray, string search_string)
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
Info_out::Info_out()
{
    location = 0;
}
//displayfamily_displaymodel中的信息 来源intel
BOOL Info_out::DF_DM_info(UINT DF_DM)
{
	switch(DF_DM)
	{
	case 0x0685:	RES_DATA.Architecture = "Future Intel(R) Xeon Phi(TM) Processor based on Knights Mill microarchitecture";
					RES_DATA.Code_Name = "Knight's Corner";
		break;
	case 0x0657:	RES_DATA.Architecture = "Intel(R) Xeon Phi(TM) Processor 3200, 5200, 7200 Series based on Knights Landing microarchitecture";
					RES_DATA.Code_Name = "Knight's Corner";
		break;
	case 0x0666:	RES_DATA.Architecture = "Future Intel(R) Core(TM) processors based on Cannon Lake microarchitecture";
					RES_DATA.Code_Name = "Cannon Lake";
		break;
	case 0x068E:	RES_DATA.Architecture = "7th generation Intel(R) Core(TM) processors based on Kaby Lake microarchitecture";
					RES_DATA.Code_Name = "Kaby Lake";
		break;
	case 0x069E:	RES_DATA.Architecture = "7th generation Intel(R) Core(TM) processors based on Kaby Lake microarchitecture";
					RES_DATA.Code_Name = "Kaby Lake";
		break;
	case 0x0655:	RES_DATA.Architecture = "Intel(R) Xeon(R) Processor Scalable Family based on Skylake microarchitecture";
					RES_DATA.Code_Name = "Skylake";
		break;
	case 0x064E:	RES_DATA.Architecture = "6th generation Intel Core processors and Intel Xeon processor E3-1500m v5 product family and E3-1200 v5 product family based on Skylake microarchitecture";
					RES_DATA.Code_Name = "Skylake";
		break;
	case 0x065E:	RES_DATA.Architecture = "6th generation Intel Core processors and Intel Xeon processor E3-1500m v5 product family and E3-1200 v5 product family based on Skylake microarchitecture";
					RES_DATA.Code_Name = "Skylake";
		break;
	case 0x0656:	RES_DATA.Architecture = "Intel Xeon processor D-1500 product family based on Broadwell microarchitecture";
					RES_DATA.Code_Name = "Broadwell";
		break;
	case 0x064F:	RES_DATA.Architecture = "Intel Xeon processor E5 v4 Family based on Broadwell microarchitecture, Intel Xeon processor E7 v4 Family, Intel Core i7-69xx Processor Extreme Edition";
					RES_DATA.Code_Name = "Broadwell";
		break;
	case 0x0647:	RES_DATA.Architecture = "5th generation Intel Core processors, Intel Xeon processor E3-1200 v4 product family based on Broadwell microarchitecture";
					RES_DATA.Code_Name ="Broadwell";
		break;
	case 0x063D:	RES_DATA.Architecture = "Intel Core M-5xxx Processor, 5th generation Intel Core processors based on Broadwell microarchitecture";
					RES_DATA.Code_Name = "Broadwell";
		break;
	case 0x063F:	RES_DATA.Architecture = "Intel Xeon processor E5-4600/2600/1600 v3 product families, Intel Xeon processor E7 v3 product families based on Haswell-E microarchitecture, Intel Core i7-59xx Processor Extreme Edition";
					RES_DATA.Code_Name = "Haswell-E";
		break;
	case 0x063C:	RES_DATA.Architecture = "4th Generation Intel Core processor and Intel Xeon processor E3-1200 v3 product family based on Haswell microarchitecture";
					RES_DATA.Code_Name = "Haswell";
		break;
	case 0x0645:	RES_DATA.Architecture = "4th Generation Intel Core processor and Intel Xeon processor E3-1200 v3 product family based on Haswell microarchitecture";
					RES_DATA.Code_Name = "Haswell";
		break;
	case 0x0646:	RES_DATA.Architecture = "4th Generation Intel Core processor and Intel Xeon processor E3-1200 v3 product family based on Haswell microarchitecture";
					RES_DATA.Code_Name = "Haswell";
		break;
	case 0x063E:	RES_DATA.Architecture = "Intel Xeon processor E7-8800/4800/2800 v2 product families based on Ivy Bridge-E microarchitecture \n Intel Xeon processor E5-2600/1600 v2 product families and Intel Xeon processor E5-2400 v2 product family based on Ivy Bridge-E microarchitecture, Intel Core i7-49xx Processor Extreme Edition";
		break;
	case 0x063A:	RES_DATA.Architecture = "3rd Generation Intel Core Processor and Intel Xeon processor E3-1200 v2 product family based on Ivy	Bridge microarchitecture";
					RES_DATA.Code_Name = "Ivy Bridge";
		break;
	case 0x062D:	RES_DATA.Architecture = "Intel Xeon processor E5 Family based on Intel microarchitecture code name Sandy Bridge, Intel Core i7-39xx Processor Extreme Edition";
					RES_DATA.Code_Name = "Sandy Bridge";
		break;
	case 0x062F:	RES_DATA.Architecture = "Intel Xeon Processor E7 Family";
		break;
	case 0x062A:	RES_DATA.Architecture = "Intel Xeon processor E3-1200 product family; 2nd Generation Intel Core i7, i5, i3 Processors 2xxx Series";
		break;
	case 0x062E:	RES_DATA.Architecture = "Intel Xeon processor 7500, 6500 series";
		break;
	case 0x0625:	RES_DATA.Architecture = "Intel Xeon processors 3600, 5600 series, Intel Core i7, i5 and i3 Processors";
		break;
	case 0x062C:	RES_DATA.Architecture = "Intel Xeon processors 3600, 5600 series, Intel Core i7, i5 and i3 Processors";
		break;
	case 0x061E:	RES_DATA.Architecture = "Intel Core i7 and i5 Processors";
		break;
	case 0x061F:	RES_DATA.Architecture = "Intel Core i7 and i5 Processors";
		break;
	case 0x061A:	RES_DATA.Architecture = "Intel Core i7 Processor, Intel Xeon processor 3400, 3500, 5500 series";
		break;
	case 0x061D:	RES_DATA.Architecture = "Intel Xeon processor MP 7400 series";
		break;
	case 0x0617:	RES_DATA.Architecture = "Intel Xeon processor 3100, 3300, 5200, 5400 series, Intel Core 2 Quad processors 8000, 9000 series";
		break;
	case 0x060F:	RES_DATA.Architecture = "Intel Xeon processor 3000, 3200, 5100, 5300, 7300 series, Intel Core 2 Quad processor 6000 series, Intel Core 2 Extreme 6000 series, Intel Core 2 Duo 4000, 5000, 6000, 7000 series processors, Intel Pentium dual-core processors";
		break;
	case 0x060E:	RES_DATA.Architecture = "Intel Core Duo, Intel Core Solo processors";
		break;
	case 0x060D:	RES_DATA.Architecture =  "Intel Pentium M processor";
		break;
	case 0x067A:	RES_DATA.Architecture =  "Future Intel(R) Atom(TM) processors based on Goldmont Plus Microarchitecture";
					RES_DATA.Code_Name =  "Goldmont Plus";
		break;
	case 0x065F:	RES_DATA.Architecture =  "Intel Atom processors based on Goldmont Microarchitecture (code name Denverton)";
					RES_DATA.Code_Name =  "Denverton";
		break;
	case 0x065C:	RES_DATA.Architecture =  "Intel Atom processors based on Goldmont Microarchitecture";
					RES_DATA.Code_Name =  "Denverton";
		break;
	case 0x064C:	RES_DATA.Architecture =  "Intel Atom processor X7-Z8000 and X5-Z8000 series based on Airmont Microarchitecture";
					RES_DATA.Code_Name =  "Airmont";
		break;
	case 0x065D:	RES_DATA.Architecture =  "Intel Atom processor X3-C3000 based on Silvermont Microarchitecture";
					RES_DATA.Code_Name =  "Silvermont";
		break;
	case 0x065A:	RES_DATA.Architecture =  "Intel Atom processor Z3500 series";
		break;
	case 0x064A:	RES_DATA.Architecture = "Intel Atom processor Z3400 series";
		break;
	case 0x0637:	RES_DATA.Architecture =  "Intel Atom processor E3000 series, Z3600 series, Z3700 series";
		break;
	case 0x064D:	RES_DATA.Architecture =  "Intel Atom processor C2000 series";
		break;
	case 0x0636:	RES_DATA.Architecture =  "Intel Atom processor S1000 Series";
		break;
	case 0x061C:	RES_DATA.Architecture =  "Intel Atom processor family, Intel Atom processor D2000, N2000, E2000, Z2000, C1000 series";
		break;
	case 0x0626:	RES_DATA.Architecture =  "Intel Atom processor family, Intel Atom processor D2000, N2000, E2000, Z2000, C1000 series";
		break;
	case 0x0627:	RES_DATA.Architecture =  "Intel Atom processor family, Intel Atom processor D2000, N2000, E2000, Z2000, C1000 series";
		break;
	case 0x0635:	RES_DATA.Architecture =  "Intel Atom processor family, Intel Atom processor D2000, N2000, E2000, Z2000, C1000 series";
		break;
	case 0x0F06:	RES_DATA.Architecture =  "Intel Xeon processor 7100, 5000 Series, Intel Xeon Processor MP, Intel Pentium 4, Pentium D	processors";
		break;
	case 0x0F03:	RES_DATA.Architecture =  "Intel Xeon processor, Intel Xeon processor MP, Intel Pentium 4, Pentium D processors";
		break;
	case 0x0F04:	RES_DATA.Architecture =  "Intel Xeon processor, Intel Xeon processor MP, Intel Pentium 4, Pentium D processors";
		break;
	case 0x0609:	RES_DATA.Architecture =  "Intel Pentium M processor";
		break;
	case 0x0F02:	RES_DATA.Architecture =  "Intel Xeon Processor, Intel Xeon processor MP, Intel Pentium 4 processors";
		break;
	case 0x0F00:	RES_DATA.Architecture =  "Intel Xeon Processor, Intel Xeon processor MP, Intel Pentium 4 processors";
		break;
	case 0x0F01:	RES_DATA.Architecture =  "Intel Xeon Processor, Intel Xeon processor MP, Intel Pentium 4 processors";
		break;
	case 0x0607:	RES_DATA.Architecture =  "Intel Pentium III Xeon processor, Intel Pentium III processor";
		break;
	case 0x0608:	RES_DATA.Architecture =  "Intel Pentium III Xeon processor, Intel Pentium III processor";
		break;
	case 0x060A:	RES_DATA.Architecture =  "Intel Pentium III Xeon processor, Intel Pentium III processor";
		break;
	case 0x060B:	RES_DATA.Architecture =  "Intel Pentium III Xeon processor, Intel Pentium III processor";
		break;
	case 0x0603:	RES_DATA.Architecture =  "Intel Pentium II Xeon processor, Intel Pentium II processor";
		break;
	case 0x0605:	RES_DATA.Architecture =  "Intel Pentium II Xeon processor, Intel Pentium II processor";
		break;
	case 0x0601:	RES_DATA.Architecture =  "Intel Pentium Pro processor";
		break;
	case 0x0501:	RES_DATA.Architecture =  "Intel Pentium processor, Intel Pentium processor with MMX Technology";
		break;
	case 0x0502:	RES_DATA.Architecture =  "Intel Pentium processor, Intel Pentium processor with MMX Technology";
		break;
	case 0x0504:	RES_DATA.Architecture =  "Intel Pentium processor, Intel Pentium processor with MMX Technology";
		break;
	case 0x0509:	RES_DATA.Architecture =  "The Intel(R) Quark(TM) SoC X1000 processor";
		break;
	default:
		RES_DATA.Architecture =  "";
		break;
	}
	return TRUE;
}
//void Info_out::GET_FEATURE_INFO(DWORD ECX, DWORD EDX)
void Info_out::GET_FEATURE_INFO(unsigned long ECX, unsigned long EDX)
{
	//ECX
	(ECX & SSE3_FLAGS) ? RES_DATA.Feature_info.SSE3 = TRUE : RES_DATA.Feature_info.SSE3 = FALSE;
	(ECX & PCLMULQDQ_FLAGS) ? RES_DATA.Feature_info.PCLMULQDQ = TRUE : RES_DATA.Feature_info.PCLMULQDQ = FALSE;
	(ECX & DTES64_FLAGS) ? RES_DATA.Feature_info.DTES64 = TRUE : RES_DATA.Feature_info.DTES64 = FALSE;
	(ECX & MONITOR_FLAGS) ? RES_DATA.Feature_info.MONITOR = TRUE : RES_DATA.Feature_info.MONITOR = FALSE;
	(ECX & DS_CPL_FLAGS) ? RES_DATA.Feature_info.DS_CPL = TRUE : RES_DATA.Feature_info.DS_CPL = FALSE;
	(ECX & VMX_FLAGS) ? RES_DATA.Feature_info.VMX = TRUE : RES_DATA.Feature_info.VMX = FALSE;
	(ECX & SMX_FLAGS) ? RES_DATA.Feature_info.SMX = TRUE : RES_DATA.Feature_info.SMX = FALSE;
	(ECX & EIST_FLAGS) ? RES_DATA.Feature_info.EIST = TRUE : RES_DATA.Feature_info.EIST = FALSE;
	(ECX & TM2_FLAGS) ? RES_DATA.Feature_info.TM2 = TRUE : RES_DATA.Feature_info.TM2 = FALSE;
	(ECX & SSSE3_FLAGS) ? RES_DATA.Feature_info.SSSE3 = TRUE : RES_DATA.Feature_info.SSSE3 = FALSE;
	(ECX & CNXT_ID_FLAGS) ? RES_DATA.Feature_info.CNXT_ID = TRUE : RES_DATA.Feature_info.CNXT_ID = FALSE;
	(ECX & SDBG_FLAGS) ? RES_DATA.Feature_info.SDBG = TRUE : RES_DATA.Feature_info.SDBG = FALSE;
	(ECX & FMA_FLAGS) ? RES_DATA.Feature_info.FMA = TRUE : RES_DATA.Feature_info.FMA = FALSE;
	(ECX & CMPXCHG16B_FLAGS) ? RES_DATA.Feature_info.CMPXCHG16B = TRUE : RES_DATA.Feature_info.CMPXCHG16B = FALSE;
	(ECX & xTPR_Update_Control_FLAGS) ? RES_DATA.Feature_info.xTPR_Update_Control = TRUE : RES_DATA.Feature_info.xTPR_Update_Control = FALSE;
	(ECX & PDCM_FLAGS) ? RES_DATA.Feature_info.PDCM = TRUE : RES_DATA.Feature_info.PDCM = FALSE;
	(ECX & PCID_FLAGS) ? RES_DATA.Feature_info.PCID = TRUE : RES_DATA.Feature_info.PCID = FALSE;
	(ECX & DCA_FLAGS) ? RES_DATA.Feature_info.DCA = TRUE : RES_DATA.Feature_info.DCA = FALSE;
	(ECX & SSE4_1_FLAGS) ? RES_DATA.Feature_info.SSE4_1 = TRUE : RES_DATA.Feature_info.SSE4_1 = FALSE;
	(ECX & SSE4_2_FLAGS) ? RES_DATA.Feature_info.SSE4_2 = TRUE : RES_DATA.Feature_info.SSE4_2 = FALSE;
	(ECX & X2APIC_FLAGS) ? RES_DATA.Feature_info.x2APIC = TRUE : RES_DATA.Feature_info.x2APIC = FALSE;
	(ECX & MOVBE_FLAGS) ? RES_DATA.Feature_info.MOVBE = TRUE : RES_DATA.Feature_info.MOVBE = FALSE;
	(ECX & POPCNT_FLAGS) ? RES_DATA.Feature_info.POPCNT = TRUE : RES_DATA.Feature_info.POPCNT = FALSE;
	(ECX & TSC_Deadline_FLAGS) ? RES_DATA.Feature_info.TSC_Deadline = TRUE : RES_DATA.Feature_info.TSC_Deadline = FALSE;
	(ECX & AESNI_FLAGS) ? RES_DATA.Feature_info.AESNI = TRUE : RES_DATA.Feature_info.AESNI = FALSE;
	(ECX & XSAVE_FLAGS) ? RES_DATA.Feature_info.XSAVE = TRUE : RES_DATA.Feature_info.XSAVE = FALSE;
	(ECX & OSXSAVE_FLAGS) ? RES_DATA.Feature_info.OSXSAVE = TRUE : RES_DATA.Feature_info.OSXSAVE = FALSE;
	(ECX & AVX_FLAGS) ? RES_DATA.Feature_info.AVX = TRUE : RES_DATA.Feature_info.AVX = FALSE;
	(ECX & F16C_FLAGS) ? RES_DATA.Feature_info.F16C = TRUE : RES_DATA.Feature_info.F16C = FALSE;
	(ECX & RDRAND_FLAGS) ? RES_DATA.Feature_info.RDRAND = TRUE : RES_DATA.Feature_info.RDRAND = FALSE;
	//EDX
	(EDX & FPU_FLAGS) ? RES_DATA.Feature_info.FPU = TRUE : RES_DATA.Feature_info.FPU = FALSE;
	(EDX & VME_FLAGS) ? RES_DATA.Feature_info.VME = TRUE : RES_DATA.Feature_info.VME = FALSE;
	(EDX & DE_FLAGS) ? RES_DATA.Feature_info.DE = TRUE : RES_DATA.Feature_info.DE = FALSE;
	(EDX & PSE_FLAGS) ? RES_DATA.Feature_info.PSE = TRUE : RES_DATA.Feature_info.PSE = FALSE;
	(EDX & TSC_FLAGS) ? RES_DATA.Feature_info.TSC = TRUE : RES_DATA.Feature_info.TSC = FALSE;
	(EDX & MSR_FLAGS) ? RES_DATA.Feature_info.MSR = TRUE : RES_DATA.Feature_info.MSR = FALSE;
	(EDX & PAE_FLAGS) ? RES_DATA.Feature_info.PAE = TRUE : RES_DATA.Feature_info.PAE = FALSE;
	(EDX & MCE_FLAGS) ? RES_DATA.Feature_info.MCE = TRUE : RES_DATA.Feature_info.MCE = FALSE;
	(EDX & CX8_FLAGS) ? RES_DATA.Feature_info.CX8 = TRUE : RES_DATA.Feature_info.CX8 = FALSE;
	(EDX & APIC_FLAGS) ? RES_DATA.Feature_info.APIC = TRUE : RES_DATA.Feature_info.APIC = FALSE;
	(EDX & SEP_FLAGS) ? RES_DATA.Feature_info.SEP = TRUE : RES_DATA.Feature_info.SEP = FALSE;
	(EDX & MTRR_FLAGS) ? RES_DATA.Feature_info.MTRR = TRUE : RES_DATA.Feature_info.MTRR = FALSE;
	(EDX & PGE_FLAGS) ? RES_DATA.Feature_info.PGE = TRUE : RES_DATA.Feature_info.PGE = FALSE;
	(EDX & MCA_FLAGS) ? RES_DATA.Feature_info.MCA = TRUE : RES_DATA.Feature_info.MCA = FALSE;
	(EDX & CMOV_FLAGS) ? RES_DATA.Feature_info.CMOV = TRUE : RES_DATA.Feature_info.CMOV = FALSE;
	(EDX & PAT_FLAGS) ? RES_DATA.Feature_info.PAT = TRUE : RES_DATA.Feature_info.PAT = FALSE;
	(EDX & PSE_36_FLAGS) ? RES_DATA.Feature_info.PSE_36 = TRUE : RES_DATA.Feature_info.PSE_36 = FALSE;
	(EDX & PSN_FLAGS) ? RES_DATA.Feature_info.PSN = TRUE : RES_DATA.Feature_info.PSN = FALSE;
	(EDX & CLFSH_FLAGS) ? RES_DATA.Feature_info.CLFSH = TRUE : RES_DATA.Feature_info.CLFSH = FALSE;
	(EDX & DS_FLAGS) ? RES_DATA.Feature_info.DS = TRUE : RES_DATA.Feature_info.DS = FALSE;
	(EDX & ACPI_FLAGS) ? RES_DATA.Feature_info.ACPI = TRUE : RES_DATA.Feature_info.ACPI = FALSE;
	(EDX & MMX_FLAGS) ? RES_DATA.Feature_info.MMX = TRUE : RES_DATA.Feature_info.MMX = FALSE;
	(EDX & FXSR_FLAGS) ? RES_DATA.Feature_info.FXSR = TRUE : RES_DATA.Feature_info.FXSR = FALSE;
	(EDX & SSE_FLAGS) ? RES_DATA.Feature_info.SSE = TRUE : RES_DATA.Feature_info.SSE = FALSE;
	(EDX & SSE2_FLAGS) ? RES_DATA.Feature_info.SSE2 = TRUE : RES_DATA.Feature_info.SSE2 = FALSE;
	(EDX & SS_FLAGS) ? RES_DATA.Feature_info.SS = TRUE : RES_DATA.Feature_info.SS = FALSE;
	(EDX & HTT_FLAGS) ? RES_DATA.Feature_info.HTT = TRUE : RES_DATA.Feature_info.HTT = FALSE;
	(EDX & TM_FLAGS) ? RES_DATA.Feature_info.TM = TRUE : RES_DATA.Feature_info.TM = FALSE;
	(EDX & PBE_FLAGS) ? RES_DATA.Feature_info.PBE = TRUE : RES_DATA.Feature_info.PBE = FALSE;



}
//解析CPUID返回值中的信息
BOOL Info_out::excute_CPUID()
{
    //从WMI中获取信息   _bstr_t(""),
    BSTR bstring1=::SysAllocString( L"root\\CIMV2" );
    BSTR bstring2=::SysAllocString(L"SELECT Name,CurrentClockSpeed ,MaxClockSpeed,ExtClock,Manufacturer,MaxClockSpeed,NumberOfCores,ProcessorId,Revision,SocketDesignation,UpgradeMethod,NumberOfLogicalProcessors FROM Win32_Processor");
    CSynQueryData recvnotify(bstring1,bstring2);
	recvnotify.ExcuteFun(); 
	int myPosition = -1;
	vector<string> out_put_data = recvnotify.ClassData();
	vector<string> out_put_name = recvnotify.ClassName();
	myPosition = this->find_location(out_put_name,  "Name");
	if (myPosition != -1)	RES_DATA.Name = out_put_data[myPosition];
	else RES_DATA.Name =  "Unknown";
	myPosition = this->find_location(out_put_name,  "CurrentClockSpeed");
	if (myPosition != -1)	RES_DATA.CurrentClockSpeed = out_put_data[myPosition];
	else RES_DATA.CurrentClockSpeed =  "Unknown";
	myPosition = this->find_location(out_put_name,  "ExtClock");
	if (myPosition != -1)	RES_DATA.ExtClock = out_put_data[myPosition];
	else RES_DATA.ExtClock =  "Unknown";
	myPosition = this->find_location(out_put_name,  "Manufacturer");
	if (myPosition != -1)	RES_DATA.Manufacturer = out_put_data[myPosition];
	else RES_DATA.Manufacturer =  "Unknown";
	myPosition = this->find_location(out_put_name,  "NumberOfCores");
	if (myPosition != -1)	RES_DATA.Core = out_put_data[myPosition];	
	else RES_DATA.Core =  "Unknown";
	myPosition = this->find_location(out_put_name,  "ProcessorId");
	if (myPosition != -1)	RES_DATA.ProcessorID = out_put_data[myPosition];
	else RES_DATA.ProcessorID =  "Unknown";
	myPosition = this->find_location(out_put_name,  "Revision");
	if (myPosition != -1)	RES_DATA.Revision = out_put_data[myPosition];
	else RES_DATA.Revision =  "Unknown";
	myPosition = this->find_location(out_put_name,  "SocketDesignation");
	if (myPosition != -1)	RES_DATA.SocketDesignation = out_put_data[myPosition];	
	else RES_DATA.SocketDesignation =  "Unknown";
	myPosition = this->find_location(out_put_name,  "UpgradeMethod");
	if (myPosition != -1)	RES_DATA.UpgradeMethod = out_put_data[myPosition];
	else RES_DATA.UpgradeMethod =  "Unknown";
	myPosition = this->find_location(out_put_name,  "MaxClockSpeed");
	if (myPosition != -1)	RES_DATA.MaxClockSpeed = out_put_data[myPosition];
	else RES_DATA.MaxClockSpeed =  "Unknown";
	myPosition = this->find_location(out_put_name,  "NumberOfLogicalProcessors");
	if (myPosition != -1)	RES_DATA.Thread = out_put_data[myPosition];
	else RES_DATA.Thread =  "Unknown"; 
	//从CPUID中获取信息
	this->CPUID_MAIN_LEAF_1();
	this->CPUID_MAIN_LEAF_2();
	this->CPUID_MAIN_LEAF_4();
	this->CPUID_MAIN_LEAF_5();
	this->CPUID_MAIN_LEAF_7();
	int DisplayFamily, DisplayModel;
	int DF_DM;
	//对CPUID MAIN LEAF 1 进行数据处理
	
	//对EAX数据进行处理.
	location = this->find_location(RES_info.Position, 100);
	if(location != -1)
	{//对EAX数据进行处理.

		RES_DATA.Family = (this -> RES_info.CPU_EAX[location] & CPUID_Family) >> 8;
		RES_DATA.Model = (RES_info.CPU_EAX[location] & CPUID_Model) >> 4;
		RES_DATA.Stepping = RES_info.CPU_EAX[location] & CPUID_Stepping;
		switch((RES_info.CPU_EAX[location] & CPUID_Processor_Type) >> 12)
		{
		case 0x00:	RES_DATA.CPU_Type =  "Original OEM Processor";
			break;
		case 0x01:	RES_DATA.CPU_Type =  "Intel OverDrive(R) Processor";
			break;
		case 0x02:	RES_DATA.CPU_Type =  "Dual processor (not applicable to Intel486 processors)";
			break;
		case 0x03:	RES_DATA.CPU_Type =  "Intel reserved";
			break;
		default:
			RES_DATA.CPU_Type =  "";
			break;
		}
		RES_DATA.Ext_Family = ((RES_info.CPU_EAX[location] & CPUID_Extended_Family) >> 20)  + ((RES_info.CPU_EAX[location] & CPUID_Family) >> 8);
		RES_DATA.Ext_Model = (((RES_info.CPU_EAX[location] & CPUID_Extended_Model) >> 16) << 4) + ((RES_info.CPU_EAX[location] & CPUID_Model) >> 4);

		//对ECX and EDX数据进行处理
		this->GET_FEATURE_INFO(RES_info.CPU_ECX[location], RES_info.CPU_EDX[location]);
	}
	else
	{
		return FALSE;
	}
	//进行DisplayFamily_DisplayModel数据处理
	if (RES_DATA.Family != 0x0F)		DisplayFamily = RES_DATA.Family;
	else	DisplayFamily = RES_DATA.Ext_Family;
	if (RES_DATA.Family == 0x06 || RES_DATA.Family == 0x0F)	DisplayModel = RES_DATA.Ext_Model;
	else	DisplayModel = RES_DATA.Model;
	DF_DM = (DisplayFamily << 8) + DisplayModel;
	this->DF_DM_info(DF_DM);
	//对CPUID MAIN LEAF 2 进行数据处理
	location = this->find_location(RES_info.Position, 200);
	if(location != -1)
	{
		if((RES_info.CPU_EAX[location] & CACHE_AVAILABLE) == 0)
		{
			this->save_cache((RES_info.CPU_EAX[location] >> 24) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EAX[location] >> 16) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EAX[location] >> 8) & CACHE_SHIELD);
		}
		if((RES_info.CPU_EBX[location] & CACHE_AVAILABLE) == 0)
		{
			this->save_cache((RES_info.CPU_EBX[location] >> 24) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EBX[location] >> 16) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EBX[location] >> 8) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EDX[location] >> 0) & CACHE_SHIELD);
		}
		if((RES_info.CPU_ECX[location] & CACHE_AVAILABLE) == 0)
		{
			this->save_cache((RES_info.CPU_ECX[location] >> 24) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_ECX[location] >> 16) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_ECX[location] >> 8) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EDX[location] >> 0) & CACHE_SHIELD);
		}
		if((RES_info.CPU_EDX[location] & CACHE_AVAILABLE) == 0)
		{
			this->save_cache((RES_info.CPU_EDX[location] >> 24) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EDX[location] >> 16) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EDX[location] >> 8) & CACHE_SHIELD);
			this->save_cache((RES_info.CPU_EDX[location] >> 0) & CACHE_SHIELD);
		}
	}
	else	return FALSE;
	//对CPUID MAIN LEAF 4 进行数据处理
	//遍历寻找Cache信息
	for(UINT j = 0; j < 10; ++j)
	{
		location = this->find_location(RES_info.Position, 400 + j);
		if(location != -1)
		{
			RES_DATA.cache[j].Cache_level = ((RES_info.CPU_EAX[location] & CACHE_LEVEL) >> 5);
			RES_DATA.cache[j].Cache_Ways = (((RES_info.CPU_EBX[location] & CACHE_WAYS) >> 22) + 1);
			RES_DATA.cache[j].Cache_partitions = (((RES_info.CPU_EBX[location] & CACHE_PARTITIONS) >> 12) + 1);
			RES_DATA.cache[j].Cache_line_size = ((RES_info.CPU_EBX[location] & CACHE_LINE_SIZE) + 1);
			RES_DATA.cache[j].Cache_Set = (RES_info.CPU_ECX[location] + 1 );
			RES_DATA.cache[j].Cache_Size = ((((RES_info.CPU_EBX[location] & CACHE_WAYS) >> 22) + 1) * (((RES_info.CPU_EBX[location] & CACHE_PARTITIONS) >> 12) + 1) * ((RES_info.CPU_EBX[location] & CACHE_LINE_SIZE) + 1) * (RES_info.CPU_ECX[location] + 1));

			switch(RES_info.CPU_EAX[location] & CACHE_TYPE)
			{
			case 0x00:
				break;
			case 0x01: RES_DATA.cache[j].Cache_type =  "DATA CACHE";
				break;
			case 0x02: RES_DATA.cache[j].Cache_type =  "Instruction Cache";
				break;
			case 0x03: RES_DATA.cache[j].Cache_type =  "Unified Cache";
				break;
			default:
				break;
			}
		}
		else	
		{
			if(j == 0)	return FALSE;
			else break;
		}
	}
	//对CPUID MAIN LEAF 5 进行数据处理
	location = this->find_location(RES_info.Position, 500);
	if(location != -1)
	{
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_0) >> 0));
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_1) >> 4));
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_2) >> 8));
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_3) >> 12));
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_4) >> 16));
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_5) >> 20));
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_6) >> 24));
		RES_DATA.C_STATE_info.emplace_back(((RES_info.CPU_EDX[location] & C_STATE_7) >> 28));
	}
	else	return FALSE;

	//对CPUID MAIN LEAF 7 进行数据处理
	location = this->find_location(RES_info.Position, 700);
	if(location != -1)
	{
		this->GET_E_FEATURE_INFO(RES_info.CPU_EBX[location], RES_info.CPU_ECX[location]);
	}
	else	return FALSE;
	return TRUE;
}
/*
 * below is changed part
 *
*/

/*

Info_out::Info_out()
{
    location = 0;
}
QString Info_out::userName()
{
    //Info_out CPUID_info;
    //CPUID_Data Save_Data;
    //CPUID_info.excute_CPUID();
    //Info_out.excute_CPUID();
    //Save_Data = CPUID_info.RES_DATA;
    m_userName="Intel kabylake";
    return m_userName;
}

void Info_out::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}

*/
