#pragma once
#include <windows.h>
#include <string>
#include <vector>
/*************************************************
Copyright: 2018 Zhaoxin BJ-SV
Author:王硕
Date:2018-7-2
Description: 获取硬件的信息（不包括驱动）
**************************************************/

#include "EDIDdefination.h"
#include "defination.h"
#include "ACPI_Defination.h"
#include "Igpu.h"
#include "UsbDefination.h"

namespace SV_ASSIST
{
	namespace DMI_SMBIOS
	{
		//也可以导出map树

		/**************************************************************
		*@Function				Updatesmbios
		*@brief					更新Smbios信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@null		
		*@Other					存储为文件，文件中大类[],类中信息无特殊标示
		****************************************************************/
		void Updatesmbios();
	}
}

namespace SV_ASSIST
{
	namespace Net
	{
		struct NetStruct
		{
			std::wstring DeviceName;
			std::wstring state;
			std::wstring MediaType;
			std::wstring Name;
		};
		/**************************************************************
		*@Function				Exec
		*@brief					获取网卡信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@null		
		****************************************************************/
		void Exec();
		/**************************************************************
		*@Function				Update
		*@brief					更新网卡信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@null
		****************************************************************/
		void Update();
		/**************************************************************
		*@Function				GetData
		*@brief					获取网卡信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@std::vector<std::wstring>	网卡名		
		****************************************************************/
		const std::vector<NetStruct>& GetData();
	}
}

namespace SV_ASSIST
{
	namespace USB
	{
		/**************************************************************
		*@Function				GetUsbInfo
		*@brief					获取Usb设备树的信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@vector<USB_ROOT_HUB>		Usb设备树信息		
		****************************************************************/
		const vector<USB_ROOT_HUB>& GetUsbInfo();

		/**************************************************************
		*@Function				UpdateData
		*@brief					更新Usb信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@null		
		****************************************************************/
		void UpdateData();
	}
}

namespace SV_ASSIST
{
	namespace GPU
	{
		/**************************************************************
		*@Function				GetGpuInfo
		*@brief					获取显卡信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@IgpuSensor		gpu信息数组
		****************************************************************/
		const std::vector<IgpuSensor>& GetGpuInfo();

		/**************************************************************
		*@Function				UpdateDate
		*@brief					更新显卡信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@null								
		****************************************************************/
		void UpdateDate();
	}
}

namespace SV_ASSIST
{
	namespace Display
	{
		/**************************************************************
		*@Function				GetEDID
		*@brief					获得EDID的值
		*@author				王硕
		*@param
			*@Num				第几个EDID，由GetEDIDNum确定总数
		*@return
			*@EDID				EDID未解析的值
		****************************************************************/
		const EDID& GetEDID(const UINT Num);

		/**************************************************************
		*@Function				Exec
		*@brief					执行获取EDID值
		*@author				王硕
		*@param
			*@null
		*@return
			*@null	
		*@Other					
								生成文件\\HardWare\\EDID\\edid%d.txt	
		****************************************************************/
		
		void Exec();

		/**************************************************************
		*@Function				GetEDIDNum
		*@brief					获取EDID数量
		*@author				王硕
		*@param
			*@null
		*@return
			*@DWORD				EDID个数
		****************************************************************/

		const DWORD GetEDIDNum();

		/**************************************************************
		*@Function				UpdateData
		*@brief					更新EDID值
		*@author				王硕
		*@param
			*@null
		*@return
			*@null				生成文件
		****************************************************************/

		void UpdateData();
	}
}

namespace SV_ASSIST
{
	namespace Storage
	{
		/**************************************************************
		*@Function				updatediskinfo
		*@brief					获取硬盘的信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@null		
		*@Other
								以文件形式保存，文件夹名：硬盘名 文件名：硬盘的特性；文件名为数字，SMART的信息						
		****************************************************************/
		void updatediskinfo();
	}
}

namespace SV_ASSIST
{
	namespace CPU
	{
		/**************************************************************
		*@Function				GetCPUName
		*@brief					获取CPU的名字(Brand Name)
		*@author				王硕
		*@param
			*@					
		*@return
			*@string			CPU名字	
		****************************************************************/
		const std::string& GetCPUName();
		/**************************************************************
		*@Function				GetProcessorID
		*@brief					获取处理器的ID 
		*@author				王硕
		*@param
			*@					
		*@return
			*@string			CPU ID				
		****************************************************************/
		const std::string& GetProcessorID();
		/**************************************************************
		*@Function				GetSocketDesignation
		*@brief					获取处理器的封装形式 
		*@author				王硕
		*@param
			*@x					
		*@return
			*@string							
		****************************************************************/
		const std::string& GetSocketDesignation();

		//可能会废弃 改用MSR形式
		/**************************************************************
		*@Function				GetCurrentClockSpeed
		*@brief					获取处理器最近的频率（WMI 可能不准确） 
		*@author				王硕
		*@param
			*@null
		*@return
			*@UINT				处理器频率				
		****************************************************************/
		const unsigned int GetCurrentClockSpeed();

		//可能会废弃，改用MSR形式
		/**************************************************************
		*@Function				GetExtClock
		*@brief					获取处理器的Bus Speed 
		*@author				王硕
		*@param
			*@null
		*@return
			*@uint				处理器外频				
		****************************************************************/
		const unsigned int GetExtClock();

		/**************************************************************
		*@Function				GetCore
		*@brief					获取处理器的物理核心数 
		*@author				王硕
		*@param
			*@null
		*@return
			*@uint				物理核心数				
		****************************************************************/
		const unsigned int GetCore();

		/**************************************************************
		*@Function				GetThread
		*@brief					获取处理器的线程数 
		*@author				王硕
		*@param
			*@null
		*@return
			*@uint				处理器线程数				
		****************************************************************/
		const unsigned int GetThread();

		//采用MSR形式 未做
		/**************************************************************
		*@Function				GetRevision
		*@brief					获取处理器的修订版本 
		*@author				王硕
		*@param
			*@null
		*@return
			*@uint				处理器的修订版本				
		****************************************************************/
		const unsigned int GetRevision(); //未做

		//可能会废弃 采用msr形式
		/**************************************************************
		*@Function				GetMaxClockSpeed
		*@brief					获取处理器的最大时钟 
		*@author				王硕
		*@param
			*@null
		*@return
			*@uint				最大时钟				
		****************************************************************/
		const unsigned int GetMaxClockSpeed();


		/**************************************************************
		*@Function				GetUpgradeMethod
		*@brief					获取处理器的封装形式 
		*@author				王硕
		*@param
			*@null					
		*@return
			*@uint							
		****************************************************************/
		const unsigned int GetUpgradeMethod();

		/**************************************************************
		*@Function				GetManufacturer
		*@brief					获取处理器的厂商ID 
		*@author				王硕
		*@param
			*@null				
		*@return
			*@string			处理器厂商				
		****************************************************************/
		const std::string& GetManufacturer();

		/**************************************************************
		*@Function				GetFamily
		*@brief					获取处理器的Family
		*@author				王硕
		*@param
			*@null
		*@return
			*@short				处理器家族				
		****************************************************************/
		const short GetFamily();

		/**************************************************************
		*@Function				GetModel
		*@brief					获取处理器的Model 
		*@author				王硕
		*@param
			*@
		*@return
			*@short				Model				
		****************************************************************/
		const short GetModel();
		/**************************************************************
		*@Function				GetSocketDesignation
		*@brief					获取处理器的封装形式 
		*@author				王硕
		*@param
			*@x					OUT 自己分配好的数组大小空间一般来讲至少要求16字节
		*@return
			*@Null				
		****************************************************************/
		const short GetStepping();
		/**************************************************************
		*@Function				GetExtFamily
		*@brief					获取处理器的Ext.Family 
		*@author				王硕
		*@param
			*@null
		*@return
			*@short				Ext.Family				
		****************************************************************/
		const short GetExtFamily();
		/**************************************************************
		*@Function				GetExtModel
		*@brief					获取处理器的Ext.Model
		*@author				王硕
		*@param
			*@null
		*@return
			*@short				Ext.Model				
		****************************************************************/
		const short GetExtModel();
		/**************************************************************
		*@Function				GetFeature
		*@brief					获取处理器的特性 
		*@author				王硕
		*@param
			*@null
		*@return
			*@CPUFeature		处理器支持的特性			
		****************************************************************/
		const CPUFeature& GetFeature();

		/**************************************************************
		*@Function				GetCache
		*@brief					获取处理器的Cache
		*@author				王硕
		*@param
			*@
		*@return
			*@Cache_info		一、二、三级Cache(若没3级需要自己判断)		
		****************************************************************/
		const Cache_info* GetCache();

		//以下仅支持Inte部分cpu
		/**************************************************************
		*@Function				GetCodeName
		*@brief					获取处理器的代号
		*@author				王硕
		*@param
		*@
		*@return
		*@string				Intel未知代号返回Unknown，其他未知代号返回空
		****************************************************************/
		const std::string& GetCodeName();

		/**************************************************************
		*@Function				GetTechnology
		*@brief					获取处理器的工艺
		*@author				王硕
		*@param
		*@
		*@return
		*@Cache_info			未知返回0
		****************************************************************/
		const unsigned int GetTechnology();
	}
}

namespace SV_ASSIST
{
	namespace AUDIO
	{
		struct AudioStruct
		{
			std::wstring id;
			std::wstring state;
			std::wstring name;
			std::wstring desc;
			std::wstring audioif;
		};

		void Exec();

		void UpdateData();

		const std::vector<AudioStruct>& GetOutputAudio();
	}
}

namespace SV_ASSIST 
{
	namespace ACPI
	{
		BOOL Excute();

		const ACPI_MCFG_STRUCTURE& GetMCFG();

		const ACPI_RSDT_STRUCTURE& GetRSDT();
		/**************************************************************
		*@Function				GetPCIEBaseAddress
		*@brief					获取PCIE在Memory映射中的地址
		*@author				王硕
		*@param
			*@PCIE_BaseAddress	OUT 输出PCIE Configuration Space 在内存中的基地址
		*@return
			*@BOOL				获取PCIE基地址是否成功
		****************************************************************/
		const DWORD64 GetPCIEBaseAddress();
	}
}
