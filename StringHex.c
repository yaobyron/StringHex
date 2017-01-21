/*
 * =====================================================================================
 *
 *       Filename:  StringHex.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/20/2017 06:40:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/*
// C prototype : void StrToHex(char *pbDest, char *pbSrc, int nLen)
// parameter(s): [OUT] pbDest - 输出缓冲区
//	 [IN] pbSrc - 字符串
//	 [IN] nLen - 16进制数的字节数(字符串的长度/2)
// return value: 
// remarks : 将字符串转化为16进制数
*/
void StrToHex(char *pbDest, char *pbSrc, int nLen)
{
	char h1,h2;
	char s1,s2;
	int i;

	for (i=0; i<nLen; i++)
	{
		h1 = pbSrc[2*i];
		h2 = pbSrc[2*i+1];

		s1 = toupper(h1) - 0x30;
		if (s1 > 9) 
		s1 -= 7;

		s2 = toupper(h2) - 0x30;
		if (s2 > 9) 
		s2 -= 7;

		pbDest[i] = s1*16 + s2;
	}
}

/*
// C prototype : void HexToStr(char *pbDest, char *pbSrc, int nLen)
// parameter(s): [OUT] pbDest - 存放目标字符串
//	 [IN] pbSrc - 输入16进制数的起始地址
//	 [IN] nLen - 16进制数的字节数
// return value: 
// remarks : 将16进制数转化为字符串
*/
void HexToStr(char *pbDest, unsigned char *pbSrc, int nLen)
{
	char ddl,ddh;
	int i;
	
	for( i = 0; i < nLen; i++ )
	{
		printf("pbSrc[%d] = %x\n", i, pbSrc[i]);
	}

	for (i=0; i<nLen; i++)
	{		
		ddh = 48 + pbSrc[i] / 16;
		ddl = 48 + pbSrc[i] % 16;


		/* 大写字母 */
		if (ddh > 57 && ddh < 96) 
			ddh = ddh + 7;
		if (ddl > 57 && ddl < 96) 
			ddl = ddl + 7;

		pbDest[i*2] = ddh;
		pbDest[i*2+1] = ddl;
	}

	pbDest[nLen*2] = '\0';
}

void main()
{
	char TestString[]= "00aaabac";
	printf("TestString = %s\n", TestString);
	int TestStingLen = 4;
	unsigned char TestHex[4] = {0};

	StrToHex(TestHex, TestString, TestStingLen);

	printf("StrToHex: ");
	int i = 0;
	for( i = 0; i < TestStingLen; i++ )
	{
		printf("TestHex[%d] = %x ", i, TestHex[i]);
	}
	printf("\n");

	int HexToStringLen = 4;
	int MaxLen= 128;
	char *HexToString = (char *)malloc(MaxLen);
	unsigned char TestHexData[] = {0xab, 0xab, 0xac, 0xad};

	HexToStr(HexToString, TestHexData, HexToStringLen);
	printf("HexToString: %s\n", HexToString);

	return ;
}
