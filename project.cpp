#include<stdio.h>
#include<conio.h>
struct process { 
	int processno,AT,BT,id,BTbackup,WT,TAT,CT; 
}p[3]; 
int totaltime = 0; 
int prefinaltotal = 0;  
int findlargest(int at) 
{ 
	int max = 0,i; 
	for (i = 0; i < 3; i++) {  
	                          if (p[i].AT <= at) { 
	                                               if(p[i].BT==p[max].BT)
				                                      {
				                                     	if(p[i].id<p[max].id)
					                                       max=i;
			                                          }
		                                            else if (p[i].BT > p[max].BT) 
				                                        max = i; 		
		                                          } 
	                        } 
	return max; 
} 
 int findCT() 
{ 
	int index; 
	int flag = 0; 
	int i = p[0].AT; 
	while (1) { 
		        if (i <= 3) { 
			                  index = findlargest(i); 
		                    } 
		        else
			      index = findlargest(3); 
		        printf("Process executing from %d to %d is: p%d\t ",totaltime,totaltime+1,index + 1); 
	         	p[index].BT -= 1; 
		        totaltime += 1; 
		        i++; 
		        if (p[index].BT == 0) { 
			                            p[index].CT = totaltime; 
			                            printf(" Process P%d is completed at %d",p[index].processno,totaltime); 
		                              } 
		        printf("\n");  
		        if (totaltime == prefinaltotal) 
		     	break; 
	          } 
} 
int main() 
{ 
	int i; 
    	p[0].id=2132;
    		p[1].id=2102;
    			p[2].id=2453;
	for (i = 0; i < 3; i++) { 
		p[i].processno = i + 1; 
	} 
	for (i = 0; i < 3; i++) 
	{ 
		p[i].AT = 0; 
	} 
	for (i = 0; i < 3; i++) { 
		p[0].BT = 2 ; 
		p[1].BT=4;
		p[2].BT=8;
		p[i].BTbackup = p[i].BT; 
		prefinaltotal += p[i].BT; 
	} 
