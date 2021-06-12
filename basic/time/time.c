//
// Created by xzh on 2021/6/10.
//

#include "../basic.h"
#include <sys/time.h>
int main() {

   // time_t *during = 0;

    // time_t t= time(during);
    //printf("time=%d\n",t);

    // struct tm *localtime=localtime_r(&during,localtime);
    // printf("y=%d %d %d",localtime->tm_year+1900,localtime->tm_mon+1,localtime->tm_mday);

    time_t timep;
    int seconds = time(&timep);//获取当前时间的秒数值，并把值赋给变量，这里timep和seconds的值是一样的
    printf("seconds=%d\n", seconds);
    printf("timep=%ld\n", timep);
    printf("%s", ctime(&timep));//将秒数值转为字符串时间

    struct tm *tm_prt;
    char *wdays[]={"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
    tm_prt = localtime(&timep);//获取一个本地时间封装struct tm *tm_prt对象，通过这个tm_prt指针，可以获取到时间的所有内容。
    printf("date=%d年%d月%d日", tm_prt->tm_year + 1900, tm_prt->tm_mon + 1, tm_prt->tm_mday);
    printf(" %02d:%02d:%02d %s\n", tm_prt->tm_hour, tm_prt->tm_min, tm_prt->tm_sec,wdays[tm_prt->tm_wday]);//%02d表示前补零

    tm_prt=gmtime(&timep);//GreenwichMeanTime，GMT 返回的是格林尼治天文台的时间，也就是没有计算时区的时间，只有在计算别的国家时间这种不常用功能的时候才有用
    printf("date=%d年%d月%d日", tm_prt->tm_year + 1900, tm_prt->tm_mon + 1, tm_prt->tm_mday);
    printf(" %02d:%02d:%02d %s\n", tm_prt->tm_hour, tm_prt->tm_min, tm_prt->tm_sec,wdays[tm_prt->tm_wday]);//%02d表示前补零


    //asctime其实就是将秒数转化为string的工具，自带换行，其实用处不大，因为不能输出中文
    printf("%s",asctime(localtime(&timep)));
    printf("%s\n",asctime(gmtime(&timep)));

    //将struct tm 输出为秒数，是不是使用utc时间是取决于tm_ptr本身是经过localtime()还是gmtime()得到的。
    time_t time_len=mktime(tm_prt);
    printf("time_len=%ld\n",time_len);
    tm_prt = localtime(&timep);
    time_t time_len2=mktime(tm_prt);
    printf("time_len2=%ld\n",time_len2);
    printf("%ld\n",time_len2-time_len);//28800秒=8小时，也就是时区差。


    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv,&tz);//废弃的方法，tz感觉是有bug的。用localtime替代。
    printf("tv_sec=%ld\n",tv.tv_sec);
    printf("tv_usec=%ld\n",tv.tv_usec);//6位的微秒数
    printf("tz_dsttime=%d\n",tz.tz_dsttime);//0
    printf("tz_minuteswest=%d\n",tz.tz_minuteswest);//和gmt差了多少分钟,不过实践为0


 }