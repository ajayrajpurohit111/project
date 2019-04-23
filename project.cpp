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
 
