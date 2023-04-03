//test_gprof.cpp

#include <stdio.h>

void func4(void)
{
    printf("\n Inside func4() \n");
    for (int i=0; i<=0XFFFF;i++);
}

void func3(void)
{
    printf("\n Inside func3() \n");
    for(int i=0;i<=0XFFFFFFF;i++);
}

void func2(void)
{
    printf("\n Inside func2() \n");

    for(int i=0;i<=0XFFF;i++);

    func3();
}

void func1(void)
{
    printf("\n Inside func1() \n");
    for(int i=0;i<=0XFFFFFF;i++);

    func2();
}

int main()
{
    printf("\n main() starts...\n");
    for(int i=0;i<=0XFFFFF;i++);

    func1();
    func4();
    printf("\n main() ends...\n");

    return 0;
}