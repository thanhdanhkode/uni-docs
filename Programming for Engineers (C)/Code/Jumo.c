#include <stdio.h>
#include <windows.h>

void gotoXY(int x, int y)
{
  printf("\033[%d;%dH", y, x);
}

void clearScreen()
{
  printf("\033[H\033[J");
}

int main()
{
  clearScreen();

  // Vẽ Header cố định
  printf("=========================================\n");
  printf("      APP NAME: QUAN LY SINH VIEN        \n");
  printf("=========================================\n");
  printf("\n"); // Khoảng trống cho nội dung thay đổi

  int count = 0;
  while (count < 10)
  {
    // Di chuyển con trỏ đến dòng thứ 5 để ghi nội dung mới
    gotoXY(1, 5);
    printf("Dang xu ly buoc: %d/10...\n", count + 1);
    printf("Du lieu nhan duoc: [Data %d]       ", count * 10); // Thêm khoảng trắng để xóa đè chữ cũ

    fflush(stdout); // Đảm bảo nội dung được in ra ngay lập tức
    Sleep(1000);    // Tạm dừng 1 giây (Windows dùng Sleep(1000))
    count++;
  }

  gotoXY(1, 8);
  printf("Hoan thanh!\n");
  return 0;
}
