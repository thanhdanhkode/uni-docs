#include <stdio.h>
#include <stdlib.h>

/**
 * Đọc nội dung file vào buffer có sẵn.
 * @param filename: Tên file cần đọc
 * @param buffer: Con trỏ tới vùng nhớ đã cấp phát
 * @param buffer_size: Kích thước tối đa của buffer
 * @return: Số byte đã đọc, hoặc -1 nếu thất bại
 */
long read_file(const char *filename, char *buffer, size_t buffer_size)
{
  FILE *file = fopen(filename, "rb"); // Mở ở chế độ binary để an toàn cho mọi loại file
  if (file == NULL)
  {
    perror("Lỗi mở file");
    return -1;
  }

  // Đọc dữ liệu vào buffer
  // fread trả về số lượng phần tử đọc được thành công
  size_t bytes_read = fread(buffer, 1, buffer_size - 1, file);

  // Thêm ký tự kết thúc chuỗi nếu bạn dùng để đọc file văn bản
  buffer[bytes_read] = '\0';

  fclose(file);
  return (long)bytes_read;
}

int main()
{
  const char *path = "Hanu.txt";

  // 1. Mở file tạm để đo kích thước (size)
  FILE *f = fopen(path, "rb");
  if (!f)
    return 1;
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  rewind(f);
  fclose(f);

  // 2. Cấp phát bộ nhớ dựa trên kích thước thực tế (+1 cho ký tự '\0')
  char *my_buffer = malloc(fsize + 1);
  if (my_buffer == NULL)
    return 1;

  // 3. Gọi hàm đã tạo
  long result = read_file(path, my_buffer, fsize + 1);

  if (result >= 0)
  {
    printf("Noi dung file:\n%s\n", my_buffer);
    printf("Da doc: %ld bytes\n", result);
  }

  // Luôn nhớ giải phóng bộ nhớ sau khi dùng xong
  free(my_buffer);
  return 0;
}
