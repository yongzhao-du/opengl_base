#include <Windows.h>
#include <stdio.h>
#include "utils.h"

unsigned char* LoadBMP(const char *path, int &width, int &height)
{
	unsigned char* imageData = NULL;
	FILE* fp = fopen(path, "rb");

	do
	{
		if (!fp) break;

		BITMAPFILEHEADER bfd;
		fread(&bfd, sizeof(BITMAPFILEHEADER), 1, fp);
		if (bfd.bfType != 0x4D42) break;

		BITMAPINFOHEADER bfid;
		fread(&bfid, sizeof(BITMAPINFOHEADER), 1, fp);
		width = bfid.biWidth;
		height = bfid.biHeight;
		imageData = new unsigned char[width * height * 3];
		fseek(fp, bfd.bfOffBits, SEEK_SET);
		fread(imageData, 1, width * height * 3, fp);

	} while (0);

	fclose(fp);
	fp = NULL;

	return imageData;
}