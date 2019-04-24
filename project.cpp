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
