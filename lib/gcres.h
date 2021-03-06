/*	gcres.h for ulios graphical user interface
作者：孙亮
功能：GUI客户端公用资源
最后修改日期：2011-08-15
*/

#ifndef	_GCRES_H_
#define	_GCRES_H_

#include "gclient.h"

UDI_IMAGE WndCloseImg =	/*窗口关闭按钮*/
{
	0x0000000A, 0x0000000A,{
	0xFFFFFFFF, 0xFFC51C18, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFC51C17, 0xFFFFFFFF,
	0xFFBE0E0A, 0xFFBB0400, 0xFFBF130F, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFBE110D, 0xFFBB0400, 0xFFBE100C,
	0xFFFFFFFF, 0xFFB8100C, 0xFFB50400, 0xFFBA130F, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFB9110D, 0xFFB60300, 0xFFB9110E, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFB3100C, 0xFFAF0300, 0xFFB41512, 0xFFB41411, 0xFFAF0300, 0xFFB3110D, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFAE1815, 0xFFA70300, 0xFFA70300, 0xFFAF1816, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFA81916, 0xFFA00200, 0xFFA00300, 0xFFA81A18, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF9D0F0D, 0xFF980200, 0xFF9E1210, 0xFF9D110F, 0xFF970100, 0xFF9E100F, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFF970E0D, 0xFF910100, 0xFF960F0E, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF960D0C, 0xFF900100, 0xFF97100F, 0xFFFFFFFF,
	0xFF8E0B0B, 0xFF8A0100, 0xFF900E0D, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF8F0B0B, 0xFF890100, 0xFF900E0D,
	0xFFFFFFFF, 0xFF8E1515, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF8E1515, 0xFFFFFFFF,
}};
UDI_IMAGE WndMinImg =	/*窗口最小化按钮*/
{
	0x00000004, 0x00000002,{
	0xFF7C0000, 0xFF7C0000, 0xFF7C0000, 0xFF7C0000,
	0xFFB70C0C, 0xFFB70C0C, 0xFFB70C0C, 0xFFB70C0C,
}};
UDI_IMAGE WndMaxImg =	/*窗口最大化按钮*/
{
	0x0000000C, 0x0000000C,{
	0xFFFFFFFF, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFB10000, 0xFFFFFFFF,
	0xFFAE0000, 0xFFAE0000, 0xFFAE0000, 0xFFAE0000, 0xFFAE0000, 0xFFAE0000, 0xFFAE0000, 0xFFAE0000, 0xFFAF0000, 0xFFAE0000, 0xFFAF0000, 0xFFAE0000,
	0xFFAA0000, 0xFFAB0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFAA0000, 0xFFAA0000,
	0xFFA60000, 0xFFA60000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFA50000, 0xFFA60000,
	0xFFA10000, 0xFFA10000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFA10000, 0xFFA00000,
	0xFF9B0000, 0xFF9C0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF9C0000, 0xFF9C0000,
	0xFF950000, 0xFF960000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF960000, 0xFF960000,
	0xFF900000, 0xFF900000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF910000, 0xFF900000,
	0xFF8B0000, 0xFF8B0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF8B0000, 0xFF8B0000,
	0xFF870000, 0xFF860000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF870000, 0xFF870000,
	0xFF820000, 0xFF830000, 0xFF820000, 0xFF830000, 0xFF830000, 0xFF820000, 0xFF820000, 0xFF830000, 0xFF830000, 0xFF830000, 0xFF830000, 0xFF830000,
	0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF,
}};
UDI_IMAGE WndSizeImg =	/*窗口缩放按钮*/
{
	0x00000008, 0x00000008,{
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF9E3C3C,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF9E3C3C, 0xFFFFFFFF, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF9E3C3C, 0xFF9E3C3C, 0xFFFFFFFF, 0xFF800101,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF9E3C3C, 0xFF9E3C3C, 0xFF9E3C3C, 0xFFFFFFFF, 0xFF820505,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF9E3C3C, 0xFF9E3C3C, 0xFF9E3C3C, 0xFF9E3C3C, 0xFFFFFFFF, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF820505,
	0xFF9E3C3C, 0xFF800000, 0xFF800000, 0xFF800101, 0xFF830606, 0xFF800000, 0xFF820505, 0xFF810202,
}};
UDI_IMAGE ScrlVSubImg =	/*纵向滚动条减小按钮*/
{
	0x0000000A, 0x00000006,{
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
}};
UDI_IMAGE ScrlVAddImg =	/*纵向滚动条增大按钮*/
{
	0x0000000A, 0x00000006,{
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
}};
UDI_IMAGE ScrlVDragImg =	/*纵向滚动条拖动按钮*/
{
	0x00000008, 0x00000006,{
	0xFF6D0000, 0xFF700000, 0xFF750000, 0xFF7A0000, 0xFF800000, 0xFF850000, 0xFF890000, 0xFF8D0000,
	0xFF6D0000, 0xFF700000, 0xFFD16B6B, 0xFF7A0000, 0xFFD16B6B, 0xFF850000, 0xFFD16B6B, 0xFF8D0000,
	0xFF6D0000, 0xFF700000, 0xFF750000, 0xFF7A0000, 0xFF800000, 0xFF850000, 0xFF890000, 0xFF8D0000,
	0xFF6D0000, 0xFF700000, 0xFF750000, 0xFF7A0000, 0xFF800000, 0xFF850000, 0xFF890000, 0xFF8D0000,
	0xFF6D0000, 0xFF700000, 0xFFD16B6B, 0xFF7A0000, 0xFFD16B6B, 0xFF850000, 0xFFD16B6B, 0xFF8D0000,
	0xFF6D0000, 0xFF700000, 0xFF750000, 0xFF7A0000, 0xFF800000, 0xFF850000, 0xFF890000, 0xFF8D0000,
}};
UDI_IMAGE ScrlHSubImg =	/*横向滚动条减小按钮*/
{
	0x00000006, 0x0000000A,{
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000, 0xFF800000,
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF800000,
}};
UDI_IMAGE ScrlHAddImg =	/*横向滚动条增大按钮*/
{
	0x00000006, 0x0000000A,{
	0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFF800000, 0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	0xFF800000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
}};
UDI_IMAGE ScrlHDragImg =	/*横向滚动条拖动按钮*/
{
	0x00000006, 0x00000008,{
	0xFF900000, 0xFF900000, 0xFF900000, 0xFF900000, 0xFF900000, 0xFF900000,
	0xFF8D0000, 0xFFD16B6B, 0xFF8D0000, 0xFF8D0000, 0xFFD16B6B, 0xFF8D0000,
	0xFF890000, 0xFF890000, 0xFF890000, 0xFF890000, 0xFF890000, 0xFF890000,
	0xFF850000, 0xFFD16B6B, 0xFF850000, 0xFF850000, 0xFFD16B6B, 0xFF850000,
	0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000,
	0xFF7A0000, 0xFFD16B6B, 0xFF7A0000, 0xFF7A0000, 0xFFD16B6B, 0xFF7A0000,
	0xFF750000, 0xFF750000, 0xFF750000, 0xFF750000, 0xFF750000, 0xFF750000,
	0xFF700000, 0xFF700000, 0xFF700000, 0xFF700000, 0xFF700000, 0xFF700000,
}};

#endif
