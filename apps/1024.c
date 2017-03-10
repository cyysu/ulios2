/*	1024.c for ulios application
	���ߣ�����
	���ܣ�������С��Ϸ
	����޸����ڣ�2014-08-08
*/

#include "../lib/malloc.h"
#include "../lib/gclient.h"

#define BLOCK_WIDTH	32	/*���С*/
#define LINE_WIDTH	2	/*���߿��*/

#define KEY_UP		0x4800
#define KEY_LEFT	0x4B00
#define KEY_RIGHT	0x4D00
#define KEY_DOWN	0x5000

DWORD GamDat[4][4];
DWORD MaxDat = 0;			/*��¼�������*/
BOOL isDatChange = FALSE;	/*��¼�����Ƿ�仯*/
CTRL_WND *wnd = NULL;

/*˫��ת��Ϊ����*/
char *Itoa(char *buf, DWORD n)
{
	char *p, *q;
	
	q = p = buf;
	do
	{
		*p++ = '0' + (char)(n % 10);
		n /= 10;
	}
	while (n);
	buf = p;	/*ȷ���ַ���β��*/
	*p-- = '\0';
	while (p > q)	/*��ת�ַ���*/
	{
		char c = *q;
		*q++ = *p;
		*p-- = c;
	}
	return buf;
}

void DrawScene()	/*������ͼ*/
{
	long x, y;

	for (y = 0; y < 4; y++)
		for (x = 0; x < 4; x++)
		{
			char buf[8];
			GCFillRect(&wnd->client, x * (BLOCK_WIDTH + LINE_WIDTH), y * (BLOCK_WIDTH + LINE_WIDTH), BLOCK_WIDTH, BLOCK_WIDTH, 0xFFFFFFFF);
			if (GamDat[x][y])
			{
				Itoa(buf, GamDat[x][y]);
				GCDrawStr(&wnd->client, x * (BLOCK_WIDTH + LINE_WIDTH) + (BLOCK_WIDTH - (long)strlen(buf) * (long)GCCharWidth) / 2, y * (BLOCK_WIDTH + LINE_WIDTH) + (BLOCK_WIDTH - (long)GCCharHeight) / 2, buf, 0);
			}
		}
	for (x = 0; x < 3; x++)
	{
		GCFillRect(&wnd->client, 0, x * (BLOCK_WIDTH + LINE_WIDTH) + BLOCK_WIDTH, BLOCK_WIDTH * 4 + LINE_WIDTH * 3, LINE_WIDTH, 0);
		GCFillRect(&wnd->client, x * (BLOCK_WIDTH + LINE_WIDTH) + BLOCK_WIDTH, 0, LINE_WIDTH, BLOCK_WIDTH * 4 + LINE_WIDTH * 3, 0);
	}
	GCWndGetClientLoca(wnd, &x, &y);
	GUIpaint(wnd->obj.gid, x, y, BLOCK_WIDTH * 4 + LINE_WIDTH * 3, BLOCK_WIDTH * 4 + LINE_WIDTH * 3);
}

void LogicLeft()	/*�����߼�����*/
{
	long x, y, i;

	for (y = 0; y < 4; y++)
		for (x = 0; x < 4; x++)
			if (GamDat[x][y])	/*��������*/
			{
				for (i = x + 1; i < 4; i++)	/*���Ҳ��������*/
				{
					if (GamDat[i][y] == GamDat[x][y])	/*�ҵ������*/
					{
						GamDat[x][y] += GamDat[i][y];	/*�ۼӽ��*/
						GamDat[i][y] = 0;
						if (MaxDat < GamDat[x][y])
							MaxDat = GamDat[x][y];
						isDatChange = TRUE;
						break;
					}
					else if (GamDat[i][y])
						break;
				}
				for (i = x - 1; i >= 0; i--)	/*������ҿ�λ*/
					if (GamDat[i][y])
						break;
				if (++i != x)
				{
					GamDat[i][y] = GamDat[x][y];	/*���·�������*/
					GamDat[x][y] = 0;
					isDatChange = TRUE;
				}
			}
}

void LogicRight()	/*�����߼�����*/
{
	long x, y, i;

	for (y = 0; y < 4; y++)
		for (x = 3; x >= 0; x--)
			if (GamDat[x][y])	/*��������*/
			{
				for (i = x - 1; i >= 0; i--)	/*������������*/
				{
					if (GamDat[i][y] == GamDat[x][y])	/*�ҵ������*/
					{
						GamDat[x][y] += GamDat[i][y];	/*�ۼӽ��*/
						GamDat[i][y] = 0;
						if (MaxDat < GamDat[x][y])
							MaxDat = GamDat[x][y];
						isDatChange = TRUE;
						break;
					}
					else if (GamDat[i][y])
						break;
				}
				for (i = x + 1; i < 4; i++)	/*���Ҳ��ҿ�λ*/
					if (GamDat[i][y])
						break;
				if (--i != x)
				{
					GamDat[i][y] = GamDat[x][y];	/*���·�������*/
					GamDat[x][y] = 0;
					isDatChange = TRUE;
				}
			}
}

void LogicUp()	/*�����߼�����*/
{
	long x, y, i;

	for (x = 0; x < 4; x++)
		for (y = 0; y < 4; y++)
			if (GamDat[x][y])	/*��������*/
			{
				for (i = y + 1; i < 4; i++)	/*���²��������*/
				{
					if (GamDat[x][i] == GamDat[x][y])	/*�ҵ������*/
					{
						GamDat[x][y] += GamDat[x][i];	/*�ۼӽ��*/
						GamDat[x][i] = 0;
						if (MaxDat < GamDat[x][y])
							MaxDat = GamDat[x][y];
						isDatChange = TRUE;
						break;
					}
					else if (GamDat[x][i])
						break;
				}
				for (i = y - 1; i >= 0; i--)	/*���ϲ��ҿ�λ*/
					if (GamDat[x][i])
						break;
				if (++i != y)
				{
					GamDat[x][i] = GamDat[x][y];	/*���·�������*/
					GamDat[x][y] = 0;
					isDatChange = TRUE;
				}
			}
}

void LogicDown()	/*�����߼�����*/
{
	long x, y, i;

	for (x = 0; x < 4; x++)
		for (y = 3; y >= 0; y--)
			if (GamDat[x][y])	/*��������*/
			{
				for (i = y - 1; i >= 0; i--)	/*���ϲ��������*/
				{
					if (GamDat[x][i] == GamDat[x][y])	/*�ҵ������*/
					{
						GamDat[x][y] += GamDat[x][i];	/*�ۼӽ��*/
						GamDat[x][i] = 0;
						if (MaxDat < GamDat[x][y])
							MaxDat = GamDat[x][y];
						isDatChange = TRUE;
						break;
					}
					else if (GamDat[x][i])
						break;
				}
				for (i = y + 1; i < 4; i++)	/*���²��ҿ�λ*/
					if (GamDat[x][i])
						break;
				if (--i != y)
				{
					GamDat[x][i] = GamDat[x][y];	/*���·�������*/
					GamDat[x][y] = 0;
					isDatChange = TRUE;
				}
			}
}

void LogicResult()	/*����߼�*/
{
	if (isDatChange)
	{
		if (MaxDat >= 1024)
			GCWndSetCaption(wnd, "��ϲ�㣬��ʤ�ˣ�");
		else
		for (;;)	/*����һ������*/
		{
			DWORD i = TMGetRand();
			if (GamDat[i & 3][(i >> 2) & 3] == 0)
			{
				GamDat[i & 3][(i >> 2) & 3] = 1;
				break;
			}
		}
		isDatChange = FALSE;
	}
}

long MainMsgProc(THREAD_ID ptid, DWORD data[MSG_DATA_LEN])
{
	CTRL_WND *wnd = (CTRL_WND*)data[GUIMSG_GOBJ_ID];
	switch (data[MSG_API_ID] & MSG_API_MASK)
	{
	case GM_SETFOCUS:
		if (data[1])
			wnd->obj.style |= WND_STATE_FOCUS;
		else
			wnd->obj.style &= (~WND_STATE_FOCUS);
		break;
	case GM_LBUTTONDOWN:	/*��갴��*/
		if (!(wnd->obj.style & WND_STATE_FOCUS))
			GUISetFocus(wnd->obj.gid);
		break;
	case GM_KEY:	/*������Ϣ*/
		switch (data[1] & 0xFFFF)
		{
		case KEY_LEFT:
			LogicLeft();
			break;
		case KEY_RIGHT:
			LogicRight();
			break;
		case KEY_UP:
			LogicUp();
			break;
		case KEY_DOWN:
			LogicDown();
			break;
		}
		LogicResult();
		DrawScene();
		break;
	}
	return GCWndDefMsgProc(ptid, data);
}

int main()
{
	THREAD_ID ptid;
	DWORD data[MSG_DATA_LEN];
	CTRL_ARGS args;
	long res;

	GamDat[0][0] = 1;
	if ((res = InitMallocTab(0x1000000)) != NO_ERROR)	/*����16MB���ڴ�*/
		return res;
	if ((res = GCinit()) != NO_ERROR)
		return res;
	args.width = BLOCK_WIDTH * 4 + LINE_WIDTH * 3 + 2;
	args.height = BLOCK_WIDTH * 4 + LINE_WIDTH * 3 + 21;
	args.x = 300;
	args.y = 200;
	args.style = WND_STYLE_CAPTION | WND_STYLE_BORDER | WND_STYLE_CLOSEBTN;
	args.MsgProc = MainMsgProc;
	GCWndCreate(&wnd, &args, 0, NULL, "�ϲ�����ﵽ1024��");
	ptid.ProcID = SRV_GUI_PORT;
	ptid.ThedID = INVALID;
	if ((res = KRecvProcMsg(&ptid, data, INVALID)) != NO_ERROR)	/*�ȴ����������Ϣ*/
		return res;
	GCDispatchMsg(ptid, data);	/*������ɺ�������*/
	DrawScene();

	for (;;)
	{
		if ((res = KRecvMsg(&ptid, data, INVALID)) != NO_ERROR)	/*�ȴ���Ϣ*/
			break;
		if (GCDispatchMsg(ptid, data) == NO_ERROR)	/*����GUI��Ϣ*/
		{
			if ((data[MSG_API_ID] & MSG_API_MASK) == GM_DESTROY && data[GUIMSG_GOBJ_ID] == (DWORD)wnd)	/*����������,�˳�����*/
				break;
		}
	}
	return NO_ERROR;
}
