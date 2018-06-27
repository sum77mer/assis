#pragma once
#include "UsbDefination.h"

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

