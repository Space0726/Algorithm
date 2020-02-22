#include <cstdio>

using namespace std;

int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char day_str[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main() {
    int y, m, d;
    bool is_normal = true;
    while (true) {
        scanf("%d %d %d", &y, &m, &d);
        if (y < 2000 || y > 2010 || m < 1 || m > 12 || d < 1 || d > 31) {
            printf("INPUT ERROR!\n");
            continue;
        }
        if (y%400 == 0 || (y%4 == 0 && y%100 != 0))
            is_normal = false;
        if (m == 2) {
            if (!is_normal && d > 29) {
                printf("INPUT ERROR!\n");
                continue;
            } else if (is_normal && d > 28) {
                printf("INPUT ERROR!\n");
                continue;
            }
        }

        int start_day = 6;
        for (int i = 2000; i < y; i++) {
            for (int j = 0; j < 12; j++) {
                start_day += day[j];
                if ((i%400 == 0 || (i%4 == 0 && i%100 != 0)) && j == 1)
                    ++start_day;
            }
        }
        for (int i = 0; i < m - 1; i++) {
            start_day += day[i];
            if (!is_normal && i == 1)
                ++start_day;
        }
        start_day = start_day % 7;

        printf("%d. %d\nsun mon tue wed thu fri sat\n", y, m);
        for (int i = 0; i < start_day; i++)
            printf("    ");
        for (int i = 1; i <= day[m-1]; i++) {
            printf("%3d ", i);
            if ((i + start_day) % 7 == 0)
                putchar('\n');
            if (i == 28 && !is_normal && m == 2)
                printf("%3d ", i+1);
        }
        printf("\n%s\n", day_str[(start_day + d - 1) % 7]);
        break;
    }

    return 0;
}
