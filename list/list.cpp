
#include "list.h"
int palindrome()
{
    std::string word;
    std::cout<<"input word to test palindrome"<<std::endl;
    std::cin>>word;
    size_t len=word.size();

    //using stack
    std::cout<<"using stack:"<<std::endl;
    std::stack <char> mystack;
    for (std::string::iterator n=word.begin();n<word.begin()+len/2;n++)
        mystack.push(*n);
    std::string::iterator n=word.end()-len/2;
    for (;n<word.end();n++)
    {
        if(mystack.top()!=*n)
            break;
        //delete top
        mystack.pop();
    }
    if (word.end()==n)
    {
        std::cout<<"this is palindrome"<<std::endl;
    }
    else
    {
        std::cout<<"this is not palindrome"<<std::endl;
    }

    //using array
    std::cout<<"using array:"<<std::endl;
    const char * cword = word.c_str();
    //need len+1 to put /0
    char * array=new char[len+1];
    int top=0;
    for(size_t n=0;n<len/2;++n)
    {
        array[n]=cword[n];
        top=n;
    }
    bool flag=false;
    for(size_t n=len-(len/2);n<len;)
    {
        //std::cout<<array[top]<<cword[n]<<std::endl;
        if (array[top--]!=cword[n++])
            break;
        if (n==len)
            flag=true;
    }
    if (true==flag||len==1)
    {
        std::cout<<"this is palindrome"<<std::endl;
    }
    else
    {
        std::cout<<"this is not palindrome"<<std::endl;
    }
    delete [] array;

    return 0;
}
int create_list()
{
    //define head and before
    node *head=NULL;
    node *before=NULL;
    int len=0;
    std::cout<<"input len to create list"<<std::endl;
    std::cin>>len;
    if (len<=0)
        return -1;
    std::cout<<"create_list"<<std::endl;
    for(size_t n=0;n<len;++n)
    {
        int value=rand() % (MAX_NUM - MIN_NUM+1) + MIN_NUM;
        std::cout<<value<<" ";
        //give value to new node
        node * p=new node;
        p->data=value;
        //this node is the end one
        p->next=NULL;
        //before link this node,than change this node to before
        if (NULL==head)
        {
            head=p;
        }
        else
            before->next=p;


        //before is this one
        before=p;


    }//for
    std::cout<<std::endl;

    print_list(head);

}

int create_sorted_list()
{
    //define head and before
    node *head=NULL;

    int len=0;
    std::cout<<"input len to create list"<<std::endl;
    std::cin>>len;
    if (len<=0)
        return -1;
    std::cout<<"create_list"<<std::endl;
    for(size_t n=0;n<len;++n)
    {
        int value=rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        std::cout<<value<<" ";
        //give value to new node
        node * p=new node;
        p->data=value;
        //this node is the first one

        if (head==NULL)
        {
            head=p;
            p->next=NULL;
        }
        else
        {
            //iter the node to find the pos
            node * tmp = head;
            node * before = head;


            //using break jump out the while
            while(1)
            {


                //other node is already sorted
                if((tmp==NULL) || (tmp->data>=p->data))
                {
                    //if insert into first ,need change head;
                    if(tmp==head) {
                        head = p;
                        p->next=tmp;
                        break;
                    }
                    else {
                        //insert into before and tmp,if the node move to the last the same
                        p->next = tmp;
                        before->next = p;
                        break;
                    }
                }
                else{
                    before=tmp;
                    tmp=tmp->next;
                }
            }//while

        }
        print_list(head);

    }//for
    std::cout<<std::endl;

    print_list(head);

}

int print_list(node *head)
{
    std::cout<<"print list"<<std::endl;
    node *p=head;
    //the end node is null
    while(p!=NULL)
    {
        //head point to the first node
        std::cout << p->data << " " ;
        p=p->next;

    }
    std::cout<<std::endl;
}

int DoList()
{
    try
    {
        //palindrome();
        create_sorted_list();
    }
    catch(...)
    {
        return -1;
    }
    return 0;
}
