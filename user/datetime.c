#include <unistd.h>
#include <stdio.h>

int main(int argc, const char** argv) {
    printf("%02d:%02d:%02d %02d/%02d/%04d\n", get_hour(), get_minute(), get_second(), get_day(), get_month(), get_year());
    return 0;
}