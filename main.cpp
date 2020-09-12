#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t readNetworkFile(char* file) {
  FILE* fp = fopen(file, "rb");  // 인자로 입력된 파일명을 가진 파일 포인터
  fseek(fp, 0, SEEK_END);
  int sz = ftell(fp); // file의 크기 
  rewind(fp);
  uint8_t network_buffer[sz];
  fread(network_buffer, sizeof(uint8_t), sz, fp);
  fclose(fp);
  uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
  return ntohl(*p); // network byte to host byte
}


int main(int argc, char** argv){
    if (argc == 3) {
        int a=readNetworkFile(argv[1]);
        int b=readNetworkFile(argv[2]);
        int res=a+b;
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, res, res);
    }
    else printf("input error\n");
    return 0;
}
