/*	logo.c for ulios application
	���ߣ����߻�
	���ܣ�����LOGO
	����޸����ڣ�2013-02-03
*/

#include "../fs/fsapi.h"
#include "../lib/malloc.h"
#include "../lib/gdi.h"
#include "../lib/math.h"

/*����BMPͼ���ļ�*/
long LoadBmp(char *path, DWORD *buf, DWORD len, DWORD *width, DWORD *height)
{
	BYTE BmpHead[32];
	DWORD bmpw, bmph;
	long file;

	if ((file = FSopen(path, FS_OPEN_READ)) < 0)	/*��ȡBMP�ļ�*/
		return file;
	if (FSread(file, &BmpHead[2], 30) < 30 || *((WORD*)&BmpHead[2]) != 0x4D42 || *((WORD*)&BmpHead[30]) != 24)	/*��֤32λ�������*/
	{
		FSclose(file);
		return -1;
	}
	bmpw = *((DWORD*)&BmpHead[20]);
	bmph = *((DWORD*)&BmpHead[24]);
	if (width)
		*width = bmpw;
	if (height)
		*height = bmph;
	if (bmpw * bmph > len)
	{
		FSclose(file);
		return -1;
	}
	FSseek(file, 54, FS_SEEK_SET);
	len = (bmpw * 3 + 3) & 0xFFFFFFFC;
	for (buf += bmpw * (bmph - 1); bmph > 0; bmph--, buf -= bmpw)
	{
		BYTE *src, *dst;

		if (FSread(file, buf, len) < len)
		{
			FSclose(file);
			return -1;
		}
		src = (BYTE*)buf + bmpw * 3;
		dst = (BYTE*)buf + bmpw * 4;
		while (src > (BYTE*)buf)
		{
			*(--dst) = 0xFF;
			*(--dst) = *(--src);
			*(--dst) = *(--src);
			*(--dst) = *(--src);
		}
	}
	FSclose(file);
	return NO_ERROR;
}

/*24λͼ����������ת,����:Դ����,Դ�ߴ�,Ŀ�Ļ���,Ŀ�ĳߴ�,��ת�Ƕ�*/
void RotateImage(DWORD *src, DWORD sw, DWORD sh, DWORD *dst, DWORD dw, DWORD dh, float radian)
{
	DWORD x, y, sx, sy;
	long dx, dy;
	float sinr, cosr;

	sinr = sin(radian);
	cosr = cos(radian);
	for (y = 0, dy = -(long)(dh >> 1); y < dh; y++, dy++)
		for (x = 0, dx = -(long)(dw >> 1); x < dw; x++, dx++)
		{
			sx = (sw >> 1) + (DWORD)(dx * cosr + dy * sinr);
			sy = (sh >> 1) + (DWORD)(dy * cosr - dx * sinr);
			*dst++ = (sx < sw && sy < sh) ? src[sx + sy * sw] : 0;
		}
}

int main()
{
	DWORD *img, *bmp, BmpWidth, BmpHeight, ImgWidth;
	float radian;
	long i, res;

	if ((res = InitMallocTab(0x1000000)) != NO_ERROR)	/*����16MB���ڴ�*/
		return res;
	LoadBmp("logo.bmp", NULL, 0, &BmpWidth, &BmpHeight);
	bmp = (DWORD*)malloc(BmpWidth * BmpHeight * sizeof(DWORD));
	LoadBmp("logo.bmp", bmp, BmpWidth * BmpHeight, NULL, NULL);
	ImgWidth = (DWORD)sqrt(BmpWidth * BmpWidth + BmpHeight * BmpHeight);
	img = (DWORD*)malloc(ImgWidth * ImgWidth * sizeof(DWORD));
	if ((res = GDIinit()) != NO_ERROR)
		return res;
	radian = 0.0f;
	for (i = 0; i < 1000; i++)
	{
		radian += 0.02f;
		RotateImage(bmp, BmpWidth, BmpHeight, img, ImgWidth, ImgWidth, radian);
		GDIPutImage(100, 100, img, ImgWidth, ImgWidth);
		KSleep(10);
	}
	GDIrelease();
	return NO_ERROR;
}
