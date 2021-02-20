#include <stdio.h>
#include <stdlib.h>

float Recursion(float x,int y) {
    if (y > 0) {
        return x * Recursion(x,y - 1);
    } else {
        return 1;
    }
}


int main() {
    float x,z;
	int y;
   	printf("Ussunu almak istediginiz sayiyi giriniz : ");
    scanf("%f",&x);
    printf("Negatif olmayan bir us giriniz : ");
    scanf("%d",&y);
    while(y<0){
    	
    	
    	if(y>-1)
    	break;
    	else
    	printf("Negatif olmayan bir us giriniz : ");
        scanf("%d",&y);
    
	}
	
    z = Recursion(x,y);
    
    printf("%.1f sayisinin %d ussu %.1f'e esittir.",x,y,z);

    
}


