#include<stdio.h>
#include<string.h>

void add(char a[],char b[])
{
  int n1,n2,c=0,s,l1,l2;
  char an[350];
  l1=strlen(a)-1;
  l2=strlen(b)-1;

  if(l1>l2)
  {
    while(l2>=0)
    {
      n1=(int)a[l1];
      n2=(int)b[l2];
      s=n1+n2+c-96;

      if(s>=10)
      {
        c=1;
      }
      else
      {
        c=0;
      }

      s=s%10;
      an[l1]=s+'0';
      l1--;l2--;
    }

    n1=(int)a[l1];
    an[l1]=n1+c-48+'0';
    l1--;
    while(l1>=0)
    {
      n1=(int)a[l1];
      an[l1]=n1-48+'0';
      l1--;
    }
    printf("Answer = ");
    puts(an);
    printf("\n");
  }

  else if(l2>l1)
  {
    while(l1>=0)
    {
      n1=(int)a[l1];
      n2=(int)b[l2];
      s=n1+n2+c-96;

      if(s>=10)
      {
        c=1;
      }
      else
      {
        c=0;
      }

      s=s%10;
      an[l2]=s+'0';
      l1--;l2--;
    }

    n2=(int)b[l2];
    an[l2]=n2+c-48+'0';
    l2--;
    while(l2>=0)
    {
      n2=(int)b[l2];
      an[l2]=n2-48+'0';
      l2--;
    }
    printf("Answer = ");
    puts(an);
    printf("\n");
  }

  else
  {
    while((l1>=0)&&(l2>=0))
    {
      n1=(int)a[l1];
      n2=(int)b[l2];
      s=n1+n2+c-96;
      c=0;
      if(s>=10)
      {
        c=1;
      }
      else
      {
        c=0;
      }

      s=s%10;
      an[l2]=s+'0';
      l1--;l2--;
    }

    printf("Answer = %d",c);
    puts(an);
    printf("\n");
  }


}

void sub(char a[], char b[])
{
  int n1,n2,c,s,l1,l2;
  char an[350];
  l1=strlen(a)-1;
  l2=strlen(b)-1;
  c=strcmp(a, b);

  if(l1>l2)
  {
      while(l2>=0)
      {
        n1=(int)a[l1];
        n2=(int)b[l2];

        if(n2>n1)
        {
          s=10+n1-n2;
          a[l1-1]=a[l1-1]-1;
        }
        else
        {
          s=n1-n2;
        }

        an[l1]=s+'0';
        l1--;l2--;
      }

      while(l1>=0)
      {
        an[l1]=a[l1];
        l1--;
      }

      printf("Answer = ");
      puts(an);
      printf("\n");
  }

  else if(l2>l1)
  {
    while(l1>=0)
    {
      n1=(int)a[l1];
      n2=(int)b[l2];

      if(n1>n2)
      {
        s=10+n2-n1;
        b[l2-1]=b[l2-1]-1;
      }
      else
      {
        s=n2-n1;
      }

      an[l2]=s+'0';
      l1--;l2--;
    }

    while(l2>=0)
    {
      an[l2]=b[l2];
      l2--;
    }

    printf("Answer = -");
    puts(an);
    printf("\n");
  }

  else
  {
    if(c>=0)
    {
        while(l2>=0)
        {
          n1=(int)a[l1];
          n2=(int)b[l2];

          if(n2>n1)
          {
            s=10+n1-n2;
            a[l1-1]=a[l1-1]-1;
          }
          else
          {
            s=n1-n2;
          }

          an[l1]=s+'0';
          l1--;l2--;
        }

        while(l1>=0)
        {
          an[l1]=a[l1];
          l1--;
        }

        printf("Answer = ");
        puts(an);
        printf("\n");
    }
    else
    {
      while(l1>=0)
      {
        n1=(int)a[l1];
        n2=(int)b[l2];

        if(n1>n2)
        {
          s=10+n2-n1;
          b[l2-1]=b[l2-1]-1;
        }
        else
        {
          s=n2-n1;
        }

        an[l2]=s+'0';
        l1--;l2--;
      }

      while(l2>=0)
      {
        an[l2]=b[l2];
        l2--;
      }

      printf("Answer = -");
      puts(an);
      printf("\n");
    }
  }
}

void mult(char a[], char b[])
{
  char an[750],temp[350];
  int n1,n2,s,t,l1,l2,lt,i,j,tp,fp=0,lp=0,p=0,c=0;
  l1=strlen(a)-1;
  l2=strlen(b)-1;

    n2=(int)b[0]-48;
    for(j=l1;j>=0;j--)
    {
      n1=(int)a[j]-48;
      s=n1*n2;
      t=(s%10)+c;
      temp[p]=t+'0';
      p++;
      c=s/10;
    }
    lt=strlen(temp);
    t=lt-1;
    an[0]=c+'0';
    for(i=1;i<=lt;i++)
    {
      an[i]=temp[t];
      t--;
    }

  fp=2;
  c=0;
  for(i=1;i<=l2;i++)
  {

    lp=strlen(an);
    n2=(int)b[i]-48;
    n1=(int)a[l1]-48;
    s=(n1*n2);
    t=(s%10);
    an[lp]=t+'0';
    c=s/10;
   for(j=l1-1;j>=0;j--)
    {
      n1=(int)a[j]-48;
      s=(n1*n2)+c;
      t=(int)an[j+fp]-48;
      t=t+s;
      c=t/10;
      t=t%10;
      an[j+fp]=t+'0';
    }
    tp=j+fp;
    while(c!=0)
    {
      t=(int)an[tp]-48;
      t=t+c;
      c=t/10;
      t=t%10;
      an[tp]=t+'0';
      tp--;
    }

    fp++;
  }
  puts(an);

}


int main()
{
  int n=0;
  char in1[350],in2[350],a;

  printf("Enter the first no. ");
  gets(in1);
  printf("Enter the second no. ");
  gets(in2);
  printf("\n");


  while(n!=4)
  {

    printf("Make your choice\n");
    printf("1.Addition\n");
    printf("2.Subtraction (first no. - second no.)\n");
    printf("3.Multiplication\n");
    printf("4.Exit\n");
    scanf("%d",&n);

    switch(n)
    {
      case 1: add(in1,in2);
              break;
      case 2: sub(in1,in2);
              break;
      case 3: mult(in1,in2);
              break;
      case 4: break;

      default: printf("Wrong Choice!\n\n");
    }
  }
  return 0;


}
