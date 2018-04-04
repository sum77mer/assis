#pragma once
//**************************************************************
/*
#ifndef CPUID_H
#define CPUID_H

#include <QObject>
#include <qqmlfile.h>
*/
//**************************************************************
#include <tchar.h>
#include "SynQueryData.h"
using namespace std;

typedef unsigned long DWORD;

//CPUID 查询结构

struct CPU_RES{
	vector<string> CPU_MAIN_LEAF_NAME;
	vector<string> CPU_SUB_LEAF_NAME;
    /*
	vector<DWORD> CPU_EAX;
	vector<DWORD> CPU_EBX;
	vector<DWORD> CPU_ECX;
	vector<DWORD> CPU_EDX;
    */
    //*******************************
    vector<unsigned long> CPU_EAX;
    vector<unsigned long> CPU_EBX;
    vector<unsigned long> CPU_ECX;
    vector<unsigned long> CPU_EDX;
    //*************************************
	vector<int> Position;
};

struct FEATURE_INFO{
	BOOL SSE3;
	BOOL PCLMULQDQ;
	BOOL DTES64;
	BOOL MONITOR;
	BOOL DS_CPL;
	BOOL VMX;
	BOOL SMX;
	BOOL EIST;
	BOOL TM2;
	BOOL SSSE3;
	BOOL CNXT_ID;
	BOOL SDBG;
	BOOL FMA;
	BOOL CMPXCHG16B;
	BOOL xTPR_Update_Control;
	BOOL PDCM;
	BOOL PCID;
	BOOL DCA;
	BOOL SSE4_1;
	BOOL SSE4_2;
	BOOL x2APIC;
	BOOL MOVBE;
	BOOL POPCNT;
	BOOL TSC_Deadline;
	BOOL AESNI;
	BOOL XSAVE;
	BOOL OSXSAVE;
	BOOL AVX;
	BOOL F16C;
	BOOL RDRAND;

	BOOL FPU;
	BOOL VME;
	BOOL DE;
	BOOL PSE;
	BOOL TSC;
	BOOL MSR;
	BOOL PAE;
	BOOL MCE;
	BOOL CX8;
	BOOL APIC;
	BOOL SEP;
	BOOL MTRR;
	BOOL PGE;
	BOOL MCA;
	BOOL CMOV;
	BOOL PAT;
	BOOL PSE_36;
	BOOL PSN;
	BOOL CLFSH;
	BOOL DS;
	BOOL ACPI;
	BOOL MMX;
	BOOL FXSR;
	BOOL SSE;
	BOOL SSE2;
	BOOL SS;
	BOOL HTT;
	BOOL TM;
	BOOL PBE;

	BOOL FSGSBASE;
	BOOL IA32_TSC_ADJUST_MSR;
	BOOL SGX;
	BOOL BMI1;
	BOOL HLE;
	BOOL AVX2;
	BOOL FDP_EXCPTN_ONLY;
	BOOL SMEP;
	BOOL BMI2;
	BOOL Enhanced_REP_MOVSB_OR_STOSB;
	BOOL INVPCID;
	BOOL RTM;
	BOOL RDT_M;
	BOOL FPU_CS_DS;
	BOOL MPX;
	BOOL RDT_A;
	BOOL RDSEED;
	BOOL ADX;
	BOOL SMAP;
	BOOL CLFLUSHOPT;
	BOOL CLWB;
	BOOL Intel_Processor_Trace;
	BOOL SHA;

	BOOL PREFETCHWT1;
	BOOL UMIP;
	BOOL PKU;
	BOOL OSPKE;
	BOOL RDPID;
	BOOL SGX_LC;
};
//Cache信息结构
struct Cache_info{
	UINT Cache_level;
	string Cache_type;
	UINT Cache_Ways;
	UINT Cache_line_size;
	UINT Cache_partitions;
	UINT Cache_Set;
	UINT Cache_Size;
};

//CPU解析后的信息结构 未完成……
struct CPUID_Data{
	UINT Family;
	UINT Model;
	UINT Stepping;
	UINT Ext_Family;
	UINT Ext_Model;
	string Name;
	string CurrentClockSpeed;
	string ExtClock;
	string Manufacturer;
	string Core;
	string Thread;
	string ProcessorID;
	string Revision;
	string MaxClockSpeed;
	string SocketDesignation;
	string UpgradeMethod;
	FEATURE_INFO Feature_info;
	string CPU_Type;
	string Architecture;
	string Code_Name;
	string Socket_Packeage;
	vector<string> Cache_TLB;
	Cache_info cache[4];
	vector<UINT> C_STATE_info;
};
/************
INTEL的信息
************/
//Instruction SIMD (x86) when EAX=1 CPUID
//EAX
#define CPUID_Stepping						0x0000000F
#define CPUID_Model							0x000000F0
#define CPUID_Family						0x00000F00
#define CPUID_Processor_Type				0x00003000
#define CPUID_Extended_Model				0x000F0000
#define CPUID_Extended_Family				0x0FF00000
//EBX
#define CPUID_BRANDID						0x000000FF

//ECX
#define SSE3_FLAGS							0x00000001
#define PCLMULQDQ_FLAGS						0x00000002
#define DTES64_FLAGS						0x00000004
#define MONITOR_FLAGS						0x00000008
#define DS_CPL_FLAGS						0x00000010
#define VMX_FLAGS							0x00000020
#define SMX_FLAGS							0x00000040
#define EIST_FLAGS							0x00000080
#define TM2_FLAGS							0x00000100
#define SSSE3_FLAGS							0x00000200
#define CNXT_ID_FLAGS						0x00000400
#define SDBG_FLAGS							0x00000800
#define FMA_FLAGS							0x00001000
#define CMPXCHG16B_FLAGS					0x00002000
#define xTPR_Update_Control_FLAGS			0x00004000
#define PDCM_FLAGS							0x00008000
#define PCID_FLAGS							0x00020000
#define DCA_FLAGS							0x00040000
#define SSE4_1_FLAGS						0x00080000
#define SSE4_2_FLAGS						0x00100000
#define X2APIC_FLAGS						0x00200000
#define MOVBE_FLAGS							0x00400000
#define POPCNT_FLAGS						0x00800000
#define TSC_Deadline_FLAGS					0x01000000
#define AESNI_FLAGS							0x02000000
#define XSAVE_FLAGS							0x04000000
#define OSXSAVE_FLAGS						0x08000000
#define AVX_FLAGS							0x10000000
#define F16C_FLAGS							0x20000000
#define RDRAND_FLAGS						0x40000000
//EDX
#define FPU_FLAGS							0x00000001
#define VME_FLAGS							0x00000002
#define DE_FLAGS							0x00000004
#define PSE_FLAGS							0x00000008
#define TSC_FLAGS							0x00000010
#define MSR_FLAGS							0x00000020
#define PAE_FLAGS							0x00000040
#define MCE_FLAGS							0x00000080
#define CX8_FLAGS							0x00000100
#define APIC_FLAGS							0x00000200

#define SEP_FLAGS							0x00000800
#define MTRR_FLAGS							0x00001000
#define PGE_FLAGS							0x00002000
#define MCA_FLAGS							0x00004000
#define CMOV_FLAGS							0x00008000
#define PAT_FLAGS							0x00010000
#define PSE_36_FLAGS						0x00020000
#define PSN_FLAGS							0x00040000
#define CLFSH_FLAGS							0x00080000

#define DS_FLAGS							0x00200000
#define ACPI_FLAGS							0x00400000
#define MMX_FLAGS							0x00800000
#define FXSR_FLAGS							0x01000000
#define SSE_FLAGS							0x02000000
#define SSE2_FLAGS							0x04000000
#define SS_FLAGS							0x08000000
#define HTT_FLAGS							0x10000000
#define TM_FLAGS							0x20000000
#define PBE_FLAGS							0x80000000

//E-Feature info when EAX=7 CPUID
//EBX
#define FSGSBASE_FLAGS						0x00000001
#define IA32_TSC_ADJUST_MSR_FLAGS			0x00000002
#define SGX_FLAGS							0x00000004
#define BMI1_FLAGS							0x00000008
#define HLE_FLAGS							0x00000010
#define AVX2_FLAGS							0x00000020
#define FDP_EXCPTN_ONLY_FLAGS				0x00000040
#define SMEP_FLAGS							0x00000080
#define BMI2_FLAGS							0x00000100
#define Enhanced_REP_MOVSB_OR_STOSB_FLAGS	0x00000200
#define CNXT_ID_FLAGS						0x00000400
#define INVPCID_FLAGS						0x00000800
#define RTM_FLAGS							0x00001000
#define RDT_M_FLAGS							0x00002000
#define FPU_CS_DS_FLAGS						0x00004000
#define MPX_FLAGS							0x00008000
#define RDT_A_FLAGS							0x00010000

#define RDSEED_FLAGS						0x00080000
#define ADX_FLAGS							0x00100000
#define SMAP_FLAGS							0x00200000

#define CLFLUSHOPT_FLAGS					0x01000000
#define CLWB_FLAGS							0x02000000
#define Intel_Processor_Trace_FLAGS			0x04000000
#define OSXSAVE_FLAGS						0x08000000

#define SHA_FLAGS							0x40000000
//ECX
#define PREFETCHWT1_FLAGS					0x00000001
#define UMIP_FLAGS							0x00000004
#define PKU_FLAGS							0x00000008
#define OSPKE_FLAGS							0x00000010
#define RDPID_FLAGS							0x00400000
#define SGX_LC_FLAGS						0x40000000

//Cache and TLB EAX = 2
#define CACHE_AVAILABLE						0x80000000
#define	CACHE_SHIELD						0x000000FF
//Cache Type and Size EAX = 4
//EAX
#define CACHE_TYPE							0x0000001F
#define CACHE_LEVEL							0x000000E0
//EBX
#define CACHE_WAYS							0xFFC00000
#define CACHE_PARTITIONS					0x003FF000
#define CACHE_LINE_SIZE						0x00000FFF

//MONITOR/MWAIT EAX = 5
//EDX
#define C_STATE_0							0x0000000F
#define C_STATE_1							0x000000F0	
#define C_STATE_2							0x00000F00	
#define C_STATE_3							0x0000F000	
#define C_STATE_4							0x000F0000	
#define C_STATE_5							0x00F00000	
#define C_STATE_6							0x0F000000	
#define C_STATE_7							0xF0000000	

/*********
AMD的信息
**********/
//Instruction SIMD (x86) when EAX=0x80000001 CPUID(Only AMD)
//EDX
#define E_3DNOW_FLAGS						0x40000000
#define _3DNOW_FLAGS						0x80000000
//ECX
#define SSE4A_FLAGS							0x00000040
#define XOP_FLAGS							0x00000800
#define FMA4_FLAGS							0x00010000
class Get_CPUIDinfo
{
    //original
public:
	void Read_CPUID(UINT IN_EAX = 0,UINT IN_ECX = 0);		//读取CPUID中信息
protected:
    //DWORD m_eax, m_ebx, m_ecx, m_edx;
    unsigned long m_eax, m_ebx, m_ecx, m_edx;
private:
};
class get_info: public Get_CPUIDinfo
{
public:
	void CPUID_MAIN_LEAF_1();
	void CPUID_MAIN_LEAF_2();
	void CPUID_MAIN_LEAF_4();
	void CPUID_MAIN_LEAF_5();
	void CPUID_MAIN_LEAF_7();
protected:
	int find_location(vector<int> vecIntegerArray, int search_num);
	int find_location(vector<string> vecIntegerArray, string search_string);
	CPU_RES RES_info;
private:
};
/*
class info_out: public get_info
{
	public:
        BOOL excute_CPUID(); // 解析信息
		CPUID_Data RES_DATA; //CPU信息的返回结构
        info_out();

    //private:
        void save_cache(unsigned char cacheinfo);	//cache中的信息
        BOOL DF_DM_info(UINT DF_DM);
        void GET_FEATURE_INFO(DWORD ECX, DWORD EDX);
        void GET_E_FEATURE_INFO(DWORD EBX, DWORD ECX);
		int location;
		
};
*/



class Info_out : public get_info//, public QObject
{
//*************************************************************
    /*
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
public:
    //explicit Info_out(QObject *parent = nullptr);
    Info_out();
    QString userName();
    void setUserName(const QString &userName);
signals:
    void userNameChanged();
private:
    QString m_userName;
    */
//**************************************************************below is original code
    public:
        BOOL excute_CPUID(); // 解析信息
        CPUID_Data RES_DATA; //CPU信息的返回结构
        Info_out();

    //private:
        void save_cache(unsigned char cacheinfo);	//cache中的信息
        BOOL DF_DM_info(UINT DF_DM);
        //void GET_FEATURE_INFO(DWORD ECX, DWORD EDX);
        //void GET_E_FEATURE_INFO(DWORD EBX, DWORD ECX);
        void GET_FEATURE_INFO(unsigned long ECX, unsigned long EDX);
        void GET_E_FEATURE_INFO(unsigned long EBX, unsigned long ECX);
        int location;

};
//#endif
