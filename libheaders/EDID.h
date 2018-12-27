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
		*@Function				GetMonitorName
		*@brief					���Mointor����
		*@author				��˶
		*@param
		*@return
			*@string			Mointor������(������+�ͺ�)
		****************************************************************/
		const std::string GetMonitorName();

		/**************************************************************
		*@Function				GetEDID
		*@brief					���EDID��ֵ
		*@author				��˶
		*@param
		*@return
			*@EDID				EDIDδ������ֵ
		****************************************************************/
		const std::vector<EDID>& GetEDID();

		/**************************************************************
		*@Function				outputfile
		*@brief					��EDID��������Ϣ������ļ���
		*@author				��˶
		*@param
			*@null
		*@return
			*@null	
		*@Other					
								�����ļ�\\HardWare\\EDID\\edid%d.txt	
		****************************************************************/
		void outputfile();

		/**************************************************************
		*@Function				UpdateData
		*@brief					����EDIDֵ
		*@author				��˶
		*@param
			*@null
		*@return
			*@null				����EDID ����Execǰ����ñ�����
		****************************************************************/
		void UpdateData();
	}
}



