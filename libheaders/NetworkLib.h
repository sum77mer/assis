#pragma once

#include <vector>
#include <string>

namespace SV_ASSIST
{
	namespace Net
	{
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
		const std::vector<std::wstring>& GetData();
	}
}
