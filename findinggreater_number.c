#include<stdio.h>
void main()
{
    int i,j,k,num1,num2,a[50],b[50],size,ao[50],bo[50],count1=0,count2=0,rem,temp,pos,flag1,flag2,flag3,flag4,p,q,one_larger;
    printf("Enter first number: ");
    scanf("%d",&num1);
    i=0;
    //putting number1 into array
    while(num1>0)
    {
        rem=num1%10;
        ao[i]=rem;
        num1=num1/10;
        i++;
        count1++;
    }
    printf("Enter second number: ");
    scanf("%d",&num2);
    i=0;
    //putting number2 into array
    while(num2>0)
    {
        rem=num2%10;
        bo[i]=rem;
        num2=num2/10;
        i++;
        count2++;
    }
    //reversing arrays
    if(count1==count2)
    {
        for(i=0,j=count1-1;i<count1;i++,j--)
        {
            a[i]=ao[j];
            b[i]=bo[j];
        }
    }
    else
    {
            printf("no of digits not equal");
    }



    /*for(i=0;i<count1;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0;i<count1;i++)
    {
        printf("%d ",b[i]);
    }*/
    for(i=0;i<count1;i++)
    {
        flag1=0;
        flag2=0;
        for(j=i;j<count1;j++)
        {
            if(a[j]==b[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                flag1=1;
                //printf("If value equal,a[i]=%d",a[i]);
                break;
            }
        }
        //If number equal not found
        if(flag1!=1)
        {
            one_larger=9;
            flag3=0;
            //Checking just one greater number and assigning to one_larger
            for(j=i;j<count1;j++)
            {

                    if(a[j]>b[i] && a[j]<=one_larger)
                    {
                        one_larger=a[j];
                        pos=j;
                        flag3=1;
                    }

            }
            //If one number greater found
            if(flag3==1)
            {
                //swapping
                temp=a[i];
                a[i]=a[pos];
                a[pos]=temp;
                //arranging rest of the numbers in ascending order
                for (p = i+1; p < count1; ++p)
                {

                    for (q = p + 1; q < count1; ++q)
                    {

                        if (a[p] > a[q])
                        {

                            temp =  a[p];
                            a[p] = a[q];
                            a[q] = temp;

                        }

                    }

                }
                break;

            }
            //Checking if just one greater number not found
            if(flag3==0)
            {
               // printf("Number one greater not found:%d\n",b[i]);
                for(i=i-1;i>=0;i--)
                {
                    flag4=0;
                    for(j=i+1;j<count1;j++)
                    {
                        if(a[j]>b[i] && a[j]<=one_larger)
                        {
                            one_larger=a[j];
                            pos=j;
                            flag4=1;
                        }
                    }
                    //If one greater number found
                    if(flag4==1)
                    {
                        //swapping numbers
                        temp=a[i];
                        a[i]=a[pos];
                        a[pos]=temp;
                        //arranging rest in ascending order
                        for (p = i+1; p < count1; ++p)
                        {

                            for (q = p + 1; q < count1; ++q)
                            {

                                if (a[p] > a[q])
                                {

                                    temp =  a[p];
                                    a[p] = a[q];
                                    a[q] = temp;

                                }

                            }

                        }
                        break;

                    }
                    if(i<0)
                    {
                        printf("Not found");
                        break;
                    }

                }
                break;
            }



        }

    }
    if(i==count1&&flag1==1)
    {
        for(j=count1-2;j>=0;j--)
        {
            one_larger=9;
            flag3=0;
            for(k=j+1;k<count1;k++)
            {

                if(a[k]>a[j]&&a[k]<=one_larger)
                {
                    one_larger=a[k];
                    pos=k;
                    flag3=1;
                }

            }
            if(flag3==1)
            {
                temp=a[pos];
                a[pos]=a[j];
                a[j]=temp;
                for (p = j+1; p < count1; ++p)
                {

                    for (q = p + 1; q < count1; ++q)
                    {

                            if (a[p] > a[q])
                            {

                                temp =  a[p];
                                a[p] = a[q];
                                a[q] = temp;

                            }
                    }
                }
                break;
            }


        }
    }
    printf("Array a: ");
    for(i=0;i<count1;i++)
    {
        printf("%d",a[i]);
    }
}
