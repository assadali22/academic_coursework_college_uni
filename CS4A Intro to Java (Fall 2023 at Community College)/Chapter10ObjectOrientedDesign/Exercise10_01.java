/*
(The Time class)
Design a class named Time.
The class contains:
- The data fields hour, minute, and second that represent a time.
- A no-arg constructor that creates a Time object for the current time.
(The values of the data fields will represent the current time.)

- A constructor that constructs a Time object with a specified
elapsed time since midnight, January 1, 1970, in milliseconds.
(The values of the data fields will represent this time.)

- A constructor that constructs a Time object with the specified hour, minute, and second.
- Three getter methods for the data fields hour, minute, and second, respectively.


- A method named setTime(long elapseTime)that sets a new time for the object using the
elapsed time. For example, if the elapsed time is 555550000 milliseconds,
the hour is 10, the minute is 19, and the second is 10.


Write a test program that creates two Time objects (using new Time(), new Time(555550000), and new Time(5, 23, 55))
and displays their hour, minute, and second in the format hour:minute:second.
(Hint: The first two constructors will extract the hour, minute, and second from the
elapsed time. For the no-arg constructor, the current time can be obtained
using System.currentTimeMillis(), as shown in LiveExample 2.7, ShowCurrentTime.java.)
*/


public class Exercise10_01
{
    public static void main(String[] args)
    {
        Time time1 = new Time();
        System.out.println(time1.getHour() + ":" + time1.getMinute() + ":" + time1.getSecond());

        Time time2 = new Time(555550000);
        System.out.println(time2.getHour() + ":" + time2.getMinute() + ":" + time2.getSecond());

        Time time3 = new Time(5, 23, 55);
        System.out.println(time3.getHour() + ":" + time3.getMinute() + ":" + time3.getSecond());
    }
}



class Time
{
    private long second;
    private long minute;
    private long hour;


    public Time()
    {
        long totalMilliseconds = System.currentTimeMillis();

        // Obtain the total seconds since midnight, Jan 1, 1970
        long totalSeconds = totalMilliseconds / 1000;

        // Compute the current second in the minute in the hour
        long currentSecond = totalSeconds % 60;

        // Obtain the total minutes
        long totalMinutes = totalSeconds / 60;

        // Compute the current minute in the hour
        long currentMinute = totalMinutes % 60;

        // Obtain the total hours
        long totalHours = totalMinutes / 60;

        // Compute the current hour
        long currentHour = totalHours % 24;


        second = currentSecond;
        minute = currentMinute;
        hour = currentHour;

    }


    public Time(int m)
    {
        long totalSeconds = m / 1000;
        long currentSecond = totalSeconds % 60;

        long totalMinutes = totalSeconds / 60;
        long currentMinute = totalMinutes % 60;

        long totalHours = totalMinutes / 60;
        long currentHour = totalHours % 24;

        second = currentSecond;
        minute = currentMinute;
        hour = currentHour;
    }


    public Time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    public long getHour()
    {
        return hour;
    }

    public long getMinute()
    {
        return minute;
    }

    public long getSecond()
    {
        return second;
    }

    public void setTime(long elapseTime)
    {

        long totalSeconds = elapseTime / 1000;
        long currentSecond = totalSeconds % 60;

        long totalMinutes = totalSeconds / 60;
        long currentMinute = totalMinutes % 60;

        long totalHours = totalMinutes / 60;
        long currentHour = totalHours % 24;


        second = currentSecond;
        minute = currentMinute;
        hour = currentHour;
    }
}
