#include <stdio.h>
#include <stdlib.h>

#include "fcgi_stdio.h"

int main() {
  while (FCGI_Accept() >= 0) {
    printf("Content-type: text/html\n\nHello World!\n");
  }
  return 0;
}
