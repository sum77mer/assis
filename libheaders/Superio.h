#pragma once
#include "SuperIOStruct.h"

namespace SV_ASSIST
{
	namespace SUPERIO
	{
		/***************************************************
		*@Function					GetSuperIoChipId
		*@brief						����SioоƬ����
		*@author					��˶
		*@param
		*@return
		*@SIO_Model				SioоƬ���ţ�0Ϊ��Sio
		****************************************************/
		SIO_Model GetSuperIoChipId();

		/***************************************************
		*@Function					ReadSioPage
		*@brief						��ȡSuperIo������Page��Ϣ(SuperIoChipId=0ʱ���ɵ���)
		*@author					��˶
		*@param
		*@Siodata				�������ڻ�ȡ��Ϣ������
		*@Pages					������GetSuperIoChipId��ȷ��оƬ��Pages
		*@return
		*@BOOL						�Ƿ�ɹ�
		****************************************************/
		BOOL ReadSioPage(std::vector<Super_IO_Data>& Siodata, const std::vector<USHORT>& Pages);


		/***************************************************
		*@Function					GetSioSensor
		*@brief						��ȡSio��Sensor��Ϣ(SuperIoChipId=0ʱ���ɵ���)
		*@author					��˶
		*@param
		*@return
			*@SioSensor				Sio��Sensor��Ϣ
		****************************************************/
		const SioSensor& GetSioSensor();

		/***************************************************
		*@Function					GetSioPage
		*@brief						��ȡSio��Page��Ϣ(SuperIoChipId=0ʱ���ɵ���)
		*@author					��˶
		*@param
		*@return
			*@std::vector<USHORT>		Sio��Page��Ϣ
		****************************************************/
		const std::vector<USHORT>& GetSioPage(IN int Chipid);

		/***************************************************
		*@Function					UpdateData
		*@brief						����Sio��Ϣ ÿ�θ����й�Sio��Ϣǰ����ñ�����ˢ��Sio��Ϣ
		*@author					��˶
		*@param
		*@return
			*@null
		****************************************************/
		void UpdateData();
	}

	namespace CPU
	{
		/***************************************************
		*@Function					GetCpuVCore
		*@brief						��ȡcpu�ĺ��ĵ�ѹ ��Sio����ȡ��Ϣ
		*@author					��˶
		*@param
			*@VendorID				����PCI�����VendorId 0x8080 0x1106 0x1022��
		*@return
			*@float					cpu���ĵ�ѹֵ ��λV
		****************************************************/
		float GetCpuVCore(IN DWORD VendorID);
	}
}


