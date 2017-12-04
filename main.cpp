#include <iostream>

using namespace std;

struct structDate
{
    int day;
    int month;
    int year;
};

structDate nextDay(structDate todaysDate, int nodays)/**< strcutDate nextday is just the name of the function in which the nexday will be assigned*/
{
    structDate tomorrowsDate;/**< strcture for tommorrows date */

    tomorrowsDate.day = todaysDate.day + 1;/**incremen the day by 1 */
    tomorrowsDate.month = todaysDate.month;
    tomorrowsDate.year = todaysDate.year;

    if(tomorrowsDate.day>nodays)/**if the date contians more days then then month contains then enter loop*/
    {
        tomorrowsDate.day=1;
        tomorrowsDate.month++;
    }

    if(tomorrowsDate.month>12)/**if the month is greater then 12 the increment the year*/
    {
        tomorrowsDate.month=1;
        tomorrowsDate.year++;
    }

    return tomorrowsDate;
}

int main(void)
{
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};/**< array for months */
    int nodays;

    char s1, s2;/**< Simply using string to display brackets and comma within user input*/

    structDate today, tomorrow;/**< structure for today and tommorrow */

    cout << "Please enter todays date in the form (day/month/year): ";/**< Getting user input */
    cin >> today.day >> s1 >> today.month >> s2 >> today.year;

    while (today.month < 1 || today.month > 12 || today.day < 1 || today.day > month[today.month-1] || today.year < 1)/**< condition for valid date */
    {
        cout << "\nSorry invalid date entered" << endl;
        cout << "\nPlease renter a valid date in the form (day/month/year): ";
        cin >> today.day >> s1 >> today.month >> s2 >> today.year;
    }

    nodays=month[today.month-1];/**< Leap year  */

    if (today.year%4==0)/**< if the year is divisable by 4 then enter next condition */
    {
       if(today.year%100==0)/**< if the year is divisable by 100 then check is it divisable by 400 if not then skip the year*/
        {
            if(today.year%400==0)
            {
                nodays=29;
            }
        }

        else/**< if it divisible by 100 and 4 its still a leap year */
            nodays=29;/**< Leap year 29 days */
    }

    tomorrow = nextDay(today, nodays);/**< Calling the structure function */

    cout << "Todays date is: " << today.day << s1 << today.month << s2 << today.year <<  endl;/**< Print todays date */
    cout << "Tommorows date is: " << tomorrow.day << s1 << tomorrow.month << s2 << tomorrow.year << endl;/**< Print tommorows date */

    return 0;
}
