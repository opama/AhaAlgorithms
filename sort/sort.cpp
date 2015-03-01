#include "sort.h"
#include "stdlib.h"

int* genlist(int len)
{
    if(len<0)
    {
        std::cerr << "len <0"<<std::endl;
        return 0;
    }
    int *p=new int[len];
    for(std::size_t n=0;n<len;++n)
    {
        //generate [MIN_NUM,MAX_NUM]
        p[n]= rand()%(MAX_NUM-MIN_NUM+1)+ MIN_NUM;
    }
    return p;
    //return 0;
}
int test()
{
    std::cout<<"this is test"<<std::endl;
    return 0;
}

int printlist(int *p,int len)
{
    std::cout<<"arrary: "<<std::endl;
    for(std::size_t n=0;n<len;++n)
    {
        std::cout<<p[n]<<" ";
    }
    std::cout<<std::endl;
}

int clearlist(int *p)
{
    if (p!=0)
    {delete [] p;}
    return 0;
}

int simple_bucket_sort(int *p,int len)
{
    //generate bucket
    int * bucket= genlist(MAX_NUM);
    //init 0
    for(std::size_t n=0;n<MAX_NUM;++n)
    {
        bucket[n]=0;
    }
    for(std::size_t n=0;n< len;++n)
    {
            bucket[p[n]]+=1;
    }
    std::cout<<"after simple_bucket_sort: "<<std::endl;
    for(std::size_t n=0;n< MAX_NUM;++n)
    {
        for(int m=1;m<=bucket[n];++m)
            std::cout<<n<<" ";
    }
    std::cout<<std::endl;
    delete [] bucket;

}
int bubble_sort(int *p,int len)
{
    std::cout<<"after bubble_sort: "<<std::endl;
    for(size_t i=0;i<len;++i)
        for(size_t j=i+1;j<len;++j)
        {
            if(p[i]>p[j])
            {
                int tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
}

int base_quick_sort(int *p, int left, int right)
{
    if (left>=right)
        return 0;
    int medi=p[left];
    int i=left+1;
    int j=right;
    while(i<j)
    {
        //find right first,
        while(p[j]>=medi && i<j)
            j--;
        //then find left
        while(p[i]<=medi && i<j)
            ++i;

        if(p[i]>p[j])
        {
            int tmp=p[i];
            p[i]=p[j];
            p[j]=tmp;
        }
    }
    //need change left and i
    p[left]=p[i];
    p[i]=medi;

    base_quick_sort(p, left, i-1);
    base_quick_sort(p, i+1, right);
    return 0;
}
int quick_sort(int *p,int len)
{
    std::cout<<"after quick_sort: "<<std::endl;
    base_quick_sort(p, 0, len-1);
    return 0;
}


int DoSort()
{
    int len;
    int *arr=0;
    try
    {

        std::cout << "please input len" << std::endl;
        std::cin >> len;
        arr = genlist(len);
        if (arr != 0) {
            printlist(arr, len);
            simple_bucket_sort(arr, len);
            clearlist(arr);
        }
        arr = genlist(len);
        if (arr != 0) {
            printlist(arr, len);
            bubble_sort(arr, len);
            printlist(arr, len);
            clearlist(arr);
        }
        arr = genlist(len);
        if (arr != 0) {
            printlist(arr, len);
            quick_sort(arr, len);
            printlist(arr, len);
            clearlist(arr);
        }
    }
    catch(...)
    {
        if(arr != 0)
            clearlist(arr);
        return -1;
    }

    return 0;

}