
#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
	long int n ,i;
	char a[30] ,temp;
	scanf("%ld %s ",&n ,a);
	long int b = 1;
	long int total =0 ,rec =0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='S')
			total += b;
		else if(a[i] =='C')
			b =b*2;
	}
	if(total <= n)
		printf("0");
	else
	{
		while(total > n)
		{
			int count =0;
			for(i=(strlen(a)-1);i>0;i--)
			{
				if(a[i] =='S' && a[i-1] =='C')
				{
					temp =a[i];
				    a[i] =a[i-1];
					a[i-1] = temp;
					count++;
					total -= 2;
		            rec += count;
		            break;
				}
			}
			if(count==0 )
				break;
		}
		if (rec ==0 && total > n)
			printf("Impossible");
		else if(rec > 0  && total <=n)
			printf("%d ",rec);
	}
	printf("\n");
    }
	return 0;
}
				    
					
	