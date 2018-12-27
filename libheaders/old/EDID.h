#include "EDIDdefination.h"

/*************************************************
Copyright: 2017 Zhaoxin BJ-SV
Author:��˶
Date:2017-12-13
Description: ��ȡEDID����Ϣ
**************************************************/

namespace SV_ASSIST
{
	namespace Display
	{
		/**************************************************************
		*@Function				GetEDID
		*@brief					���EDID��ֵ
		*@author				��˶
		*@param
			*@Num				�ڼ���EDID����GetEDIDNumȷ������
		*@return
			*@EDID				EDIDδ������ֵ
		****************************************************************/
		const EDID& GetEDID(const UINT Num);

		/**************************************************************
		*@Function				Exec
		*@brief					ִ�л�ȡEDIDֵ
		*@author				��˶
		*@param
			*@null
		*@return
			*@null	
		*@Other					
								�����ļ�\\HardWare\\EDID\\edid%d.txt	
		****************************************************************/
		
		void Exec();

		/**************************************************************
		*@Function				GetEDIDNum
		*@brief					��ȡEDID����
		*@author				��˶
		*@param
			*@null
		*@return
			*@DWORD				EDID����
		****************************************************************/

		const DWORD GetEDIDNum();

		/**************************************************************
		*@Function				UpdateData
		*@brief					����EDIDֵ
		*@author				��˶
		*@param
			*@null
		*@return
			*@null				�����ļ�
		****************************************************************/

		void UpdateData();
	}
}



