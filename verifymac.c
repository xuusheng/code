#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
     char gsFile = "/home/xuusheng/test.txt";
     char MAB[256];
     char fMAC[32];
     memset(MAB, 0, 256);
     fopen("gsFile", "rb");

     while (!feof(fp))
	  for (i = 0; i < 256, !feof(fp); ++i)
	  {
	       MAB[i] ^= fgetc(pf);
	  }

     /* for (i = 0; i < 16; ++i) */
     /* 	  fMac[i] = fgetc(pf); */

     memcpy(MA, MAB, 128);
     memcpy(MB, MAB + 128, 128);

/* GenMac(MAC, MA); */
/* GenMac(MBC, MB); */

/* memcpy(MAC + 4, MBC, 4); */
/* e2f(MAC); */

/* if (memcmp(MAC, pfMAC)) */
/* { */
/*      HtLog(gsLogFile, HT_LOG_MODE_ERROR, __FILE__, __LINE__, "VerifyMac error."); */
/*      return -1; */
/* } */
}
