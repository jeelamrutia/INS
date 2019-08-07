#include<stdio.h>
#include<string.h>



//playfair algorithm
	int main()
	{
		char key[10]="cryptogah";
		char pt[20];	
		char ct[20];
		char matrix[5][5];
		int length,lengthpt,frow,fcolumn,srow,scolumn,cti=0,l=0;
		char first,second,alpha='a';
	
		printf("%s \n",key);
		length=strlen(key);
	//	printf("%d \n ",length);

		//creation of matrix
		for(int i=0;i<5;i++)
		{
	
			for(int j=0;j<5;j++)
			{
		
				if(l<length)
				{	
					matrix[i][j]=key[  l++];
				
				}
				else
				{
					for(int k=0;k<length;k++)
					{
						if(alpha==key[k])
						{
							alpha=alpha+1;
							k=0;
						}
					
					}

					if(alpha=='j')
					{
						alpha++;
					}

					 matrix[i][j]=alpha++;	
				
				}	

			}
		}	

		//print matrix
	
		for(int l=0;l<5;l++)
		{
			for(int m=0;m<5;m++)
			{
				printf("%c \t",matrix[l][m]);
			}	
			printf("\n");
		}	

	printf("enter plain text for playfair");
	gets(pt);


	printf("%s \n",pt);
	lengthpt=strlen(pt);
//	printf("%d \n ",lengthpt);
	for(int i=0;i<lengthpt-1;i=i+2)
	{
		first=pt[i];
		second=pt[i+1];
		//for letter i th index and j th index
	
		for(int l=0;l<5;l++)
		{
					
			for(int m=0;m<5;m++)
			{
				if(first==matrix[l][m])                   
				{
					frow=l;
					fcolumn=m;
					printf("\n %d %d ",frow,fcolumn);
				}
				if(second==matrix[l][m])
				{
					
					srow=l;
					scolumn=m;
					printf("\n %d %d ",srow,scolumn);		
				}
			}
		}
			
		
		
		if(frow==srow)
		{
		ct[i]=matrix[frow][(fcolumn+1)%5];
		ct[i+1]=matrix[srow][(scolumn+1)%5];
		}
		
		else if(fcolumn==scolumn)
		{
		ct[i]=matrix[(frow+1)%5][fcolumn];
		ct[i+1]=matrix[(srow+1)%5][scolumn];
		}
		else
		{
		ct[i]=matrix[frow][scolumn];
		ct[i+1]=matrix[srow][fcolumn];
		}

	}
//for print the cipher text

for(int i=0;i<lengthpt;i++)
{
	printf("%c",ct[i]);
}
return 1;

} 