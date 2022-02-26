#include <stdio.h>
#include <sys/statvfs.h>

int main(int argc, const char *argv[])
{

    const unsigned int GB = (1000 * 1000) * 1000;
    struct statvfs buffer;
    int ret = statvfs(argv[1], &buffer);

    if (!ret) {
        const double total = (double)(buffer.f_blocks * buffer.f_frsize) / GB;
        const double available = (double)(buffer.f_bfree * buffer.f_frsize) / GB;
        const double used = total - available;
        const double usedPercentage = (double)(used / total) * (double)100;
        printf("Total: %f --> %.0f\n", total, total);
        printf("Available: %f --> %.0f\n", available, available);
        printf("Used: %f --> %.1f\n", used, used);
        printf("Used Percentage: %f --> %.0f\n", usedPercentage, usedPercentage);
    }
    return ret;
}