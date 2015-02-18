#include <utmp.h>
#include <paths.h>
#include <stdio.h>

void print_entry (int num, struct utmp *up) {
    printf("%d\t", num);
    if (up->ut_type)
       printf("%d\t", up->ut_type);
    if (up->ut_pid)
       printf("%d\t", up->ut_pid);
    if (up->ut_user && up->ut_user != "")
       printf("%s\t", up->ut_user);
    if (up->ut_host)
       printf("%s\t", up->ut_host);
    if (up->ut_time)
       printf("%ld\n", up->ut_time);
}

int main(int argc, char** argv) {
    struct utmp *utmp_data;
    int i = 1;
    setutent();
    printf("#\tut_type\tut_pid\tut_user\t\tut_host\tut_time\n");
    while(utmp_data = getutent()) {
     print_entry(i, utmp_data);
     ++i;
    }
    endutent();
    return 0;
}
