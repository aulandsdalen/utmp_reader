#include <utmp.h>
#include <paths.h>
#include <stdio.h>

void print_entry (int num, struct utmp *up) {
    printf("%d\t", num);
    if (up->ut_type)
       printf("%d\t", up->ut_type);
    else
       printf("x\t");
    if (up->ut_pid)
       printf("%d\t", up->ut_pid);
    else
       printf("xxxx\t");
    if (up->ut_user)
       printf("%s\t\t", up->ut_user);
    else
       printf("system\t\t");
    if (up->ut_host)
       printf("%s\t\t", up->ut_host);
    else
       printf("hostname\t\t");
    if (up->ut_time)
       printf("%ld\n", up->ut_time);
    else
       printf("0000000000\n");
}

int main(int argc, char** argv) {
    struct utmp *utmp_data;
    int i = 1;
    setutent();
    printf("#\tut_type\tut_pid\tut_user\t\tut_host\t\tut_time\n");
    while(utmp_data = getutent()) {
     print_entry(i, utmp_data);
     ++i;
    }
    endutent();
    return 0;
}
