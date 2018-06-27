#pragma once

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