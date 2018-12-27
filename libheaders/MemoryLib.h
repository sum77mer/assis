#pragma once
#include "memorydefination.h"

namespace SV_ASSIST
{
	namespace Memory
	{

		/***************************************************
		*@Function					GetMemoryDeviceInfo
		*@brief						�ڴ�Ĳ�ۼ�����
		*@author					��˶
		*@param
		*@return
			*@info					pair.first: SmbusBase pair.second.first: DIMM Slot pair.second.second: DIMM Module
		****************************************************/
		const std::vector<std::pair<ULONG, std::pair<ULONG, DIMMType>>>& GetMemoryDeviceInfo();

		/***************************************************
		*@Function					GetMemoryDDR3Info
		*@brief						��ȡDDR3 SPD����Ϣ
		*@author					��˶
		*@param
		*@return
			*@info					pair.first: DIMM Slot pair.second SPD Infomation
		****************************************************/
		const std::vector<std::pair<ULONG, DDR3_INFO>>&  GetMemoryDDR3SPDInfo();

		/***************************************************
		*@Function					GetMemoryDDR4Info
		*@brief						��ȡDDR4 SPD����Ϣ
		*@author					��˶
		*@param
		*@return
			*@info					pair.first: DIMM Slot pair.second SPD Memory Map
		****************************************************/
		const std::vector<std::pair<ULONG, DDR4_INFO>>&  GetMemoryDDR4SPDInfo();

		/***************************************************
		*@Function					GetMemoryGlobalInfomation
		*@brief						��ȡ��������ڴ���Ϣ
		*@author					��˶
		*@param
		*@return
			*@info					pair.first: DIMM Slot pair.second SPD Infomation
		****************************************************/
		const std::vector<std::pair<ULONG, MemoryData>>& GetMemoryGlobalInfomation();

		void UpdateData();
	}
}

