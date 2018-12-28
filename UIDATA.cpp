#include "UIdata.h"
unsigned int majorVersion = 0;
unsigned int minorVersion = 0;
unsigned int revisionVersion = 0;


void getScale(double scaleH,double scaleV,Dialog& theWidget)
{
	int dpiX = theWidget.logicalDpiX();
	int dpiY = theWidget.logicalDpiY();

	switch (dpiX)
	{
	case 96:
	{
		scaleH = 1;
		break;
	}
	case 120:
	{
		scaleH = 1.25;
		break;
	}
	case 144:
	{
		scaleH = 1.5;
		break;
	}
	case 168:
	{
		scaleH = 1.75;
		break;
	}
	case 192:
	{
		scaleH = 2;
		break;
	}
	case 216:
	{
		scaleH = 2.25;
		break;
	}
	case 240:
	{
		scaleH = 2.5;
		break;
	}
	case 288:
	{
		scaleH = 3;
		break;
	}
	default:
	{
		scaleH = 1;
		break;
	}
	}
	switch (dpiY)
	{
	case 96:
	{
		scaleV = 1;
		break;
	}
	case 120:
	{
		scaleV = 1.25;
		break;
	}
	case 144:
	{
		scaleV = 1.5;
		break;
	}
	case 168:
	{
		scaleV = 1.75;
		break;
	}
	case 192:
	{
		scaleV = 2;
		break;
	}
	case 216:
	{
		scaleV = 2.25;
		break;
	}
	case 240:
	{
		scaleV = 2.5;
		break;
	}
	case 288:
	{
		scaleV = 3;
		break;
	}
	default:
	{
		scaleV = 1;
		break;
	}
	}
}