#include "EDIDdefination.h"

namespace SV_ASSIST
{
	namespace Display
	{
		/**************************************************************
		*@Function				GetEDID
		*@brief					��ȡEDIDԭʼ��Ϣ
		*@author				��˶
		*@param
			*@Num				�ڼ�����ʾ����EDID
		*@return
			*@EDID				EDIDԭʼ��Ϣ	
		****************************************************************/
		const EDID& GetEDID(const UINT Num);

		/**************************************************************
		*@Function				Exec
		*@brief					��ȡEDID��Ϣ
		*@author				��˶
		*@param
			*@null
		*@return
			*@null	
		*@Other					
								�����������ݱ��浽�ļ���	
		****************************************************************/
		
		void Exec();

		/**************************************************************
		*@Function				GetEDIDNum
		*@brief					��ȡ��ʾ��������
		*@author				��˶
		*@param
			*@null
		*@return
			*@DWORD				��ʾ������
		****************************************************************/

		const DWORD GetEDIDNum();
	}
}



