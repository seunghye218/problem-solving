#include <stdio.h>
#include <time.h>

int main() {
  struct tm now;
  time_t t = time(NULL);
  localtime_r(&t, &now);
  char date[11];
  sprintf(date, "%04d-%02d-%02d", now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
  printf("%s\n", date);
}