#include "EDIDdefination.h"

namespace SV_ASSIST
{
	namespace Display
	{
		/**************************************************************
		*@Function				GetEDID
		*@brief					获取EDID原始信息
		*@author				王硕
		*@param
			*@Num				第几个显示器的EDID
		*@return
			*@EDID				EDID原始信息	
		****************************************************************/
		const EDID& GetEDID(const UINT Num);

		/**************************************************************
		*@Function				Exec
		*@brief					获取EDID信息
		*@author				王硕
		*@param
			*@null
		*@return
			*@null	
		*@Other					
								将解析后数据保存到文件中	
		****************************************************************/
		
		void Exec();

		/**************************************************************
		*@Function				GetEDIDNum
		*@brief					获取显示器的数量
		*@author				王硕
		*@param
			*@null
		*@return
			*@DWORD				显示器数量
		****************************************************************/

		const DWORD GetEDIDNum();
	}
}



