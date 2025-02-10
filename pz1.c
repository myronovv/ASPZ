#include <stdio.h>

typedef enum {
    GREGORIAN,
    JULIAN
} CalendarType;

typedef struct {
    int year;
    int month;
    int day;
} Date;

int is_leap_year_gregorian(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int is_leap_year_julian(int year) {
    return year % 4 == 0;
}

Date get_tomorrow_date(Date current_date, CalendarType calendar_type) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int is_leap_year = (calendar_type == GREGORIAN) ? is_leap_year_gregorian(current_date.year) : is_leap_year_julian(current_date.year);

    if (is_leap_year) {
        days_in_month[1] = 29;
    }

    current_date.day++;

    if (current_date.day > days_in_month[current_date.month - 1]) {
        current_date.day = 1;
        current_date.month++;

        if (current_date.month > 12) {
            current_date.month = 1;
            current_date.year++;
        }
    }

    return current_date;
}

int main() {
    Date date;
    int calendar_choice;

    printf("Input date : YYYY MM DD: ");
    scanf("%d %d %d", &date.year, &date.month, &date.day);

    printf("Choose calendar (0 - grygorian, 1 - ulian): ");
    scanf("%d", &calendar_choice);

    CalendarType calendar_type = (calendar_choice == 0) ? GREGORIAN : JULIAN;

    Date tomorrow_date = get_tomorrow_date(date, calendar_type);

    printf("Tomorrow`s date in %s calendar: %04d-%02d-%02d\n",
           (calendar_type == GREGORIAN) ? "grygorian" : "ulian",
           tomorrow_date.year, tomorrow_date.month, tomorrow_date.day);

    return 0;
}