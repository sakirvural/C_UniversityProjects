#include <stdio.h>
#include <stdlib.h>

int sifirarama(int a[10][10]){
	int b[10][10];
	int satir,sutun;
	int i,j;
	for( i=0;i<10;i++){
	for( j=0;j<10;j++){
			satir=i;
			sutun=j;
			
		 if(a[i][j]==0){
		 	
		    	if(a[i][j]==a[satir-1][sutun] || a[i][j]==a[satir+1][sutun] || a[i][j]==a[satir][sutun-1] || a[i][j]==a[satir][sutun+1] || a[i][j]==a[satir-1][sutun-1] || a[i][j]==a[satir+1][sutun+1] || a[i][j]==a[satir-1][sutun+1]  || a[i][j]==a[satir+1][sutun-1]){
	           
			    if((satir==0  && satir-1==-1) || (sutun==0  && sutun-1==-1) || (satir==9  && satir+1==10) || (sutun==9  && sutun+1==10)) {
				
				b[i][j]=' ';
					
				}
				
				else{	
			
			 	b[i][j]='0';
			 	
			 }
			 
 	    }               
                       }
		    	
			else{
			b[i][j]=' ';
			
			}
		
		}
		
	}
	for( i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("%c",b[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	printf("satir sutun         adres\n");
	for( i=0;i<10;i++){
	for( j=0;j<10;j++){
		
		if(b[i][j]=='0'){
				printf("  %d     %d      %p\n",i,j,&b[i][j]);
		}
	
		}
		
	}

	}

int matris(){
	
		int  a[10][10]={{0,15,15,15,15,15,7,15,15,15},{15,15,15,15,15,7,0,15,15,15},{15,15,15,15,15,0,7,15,15,15},{0,15,15,15,8,0,15,15,15,0},{15,15,15,15,7,0,15,15,15,7},{7,15,15,15,0,0,15,15,15,15},{15,15,15,0,7,0,8,15,15,15},{15,15,0,0,15,7,0,8,15,15},{15,0,0,15,15,15,7,0,7,15},{7,7,15,15,15,15,15,15,7,7}};
       
	    sifirarama(a);
}

int main(){
	
    matris();
	return 0;
}

