
#include <stdio.h>

int main()
{
   const int row = 2;
   const int col = 4;
   float buffer[row*col] = {0,1,2,4,8,9,7,12};
   // long long int(&output0)[row][col] = *((long long int(*)[row][col])buffer); //强制类型转换的引用会导致单位存储的内存占用的字节数会变化进而导致新数组根据索引取值的错位
   float(*output0)[col] = *((float(*)[row][col])buffer); //向系统申请了新的内存资源用来存储output0的地址，不够高效
   float(&output0_ref)[row][col] = *((float(*)[row][col])buffer);
   float(&output1)[1][col] =*((float(*)[1][col])(buffer + col));
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       {
          printf("output0[%d,%d]: %f; output0_ref[%d,%d]: %f; output1[0,%d]: %f.\n", \
                 i, j, output0[i][j], i, j, output0_ref[i][j], j, output1[0][j]);
       }
   }
   printf("address of the buffer : %p\n", buffer);    // 输出变量buffer的地址
   printf("address of the output0 : %p\n", output0);    // 输出变量output0的地址
   printf("address of the output0_ref : %p\n", output0_ref);    // 输出变量output0的地址
   printf("address of the output1 : %p\n", output1);    // 输出变量output1的地址
   
   printf("buffer=%lx, output0=%lx, output0_ref=%lx, output1=%lx\n", buffer, output0, output0_ref, output1);  //以十六进制形式输出（字母小写）
   printf("buffer=%ld, output0=%ld, output0_ref=%ld, output1=%ld\n", buffer, output0, output0_ref, output1);  //以十进制形式输出
   
   return 0;
}