/*
 ============================================================================
 Program Name: polynomial long division calculator
 Author      : Ahmed Emad Hassan
 Version     : 1.0
 Date        : 2021
 Description : Calculates the long divition of two polynomials
 Input: The cofficients of the two polynomials
 output: The result and the reminder
 Notes : The values are printed in polynomial form 
 ============================================================================
 */


#include "stdio.h"
#include "math.h"
#include "conio.h"
int main(){
    int lim = 1000;
    int adeg,bdeg;
    float a[lim],b[lim],result[lim],temp[lim];
    for(int i=0;i<lim;i++){a[i]=0;b[i]=0;result[i]=0;temp[i]=0;}
    printf("Enter the degree of the nomerator: ");
    scanf("%d",&adeg);
    printf("\r\n");
    printf("Enter the degree of the demonator: ");
    scanf("%d",&bdeg);
    printf("\r\n");
    if(adeg>=bdeg){
        printf("Enter the coefficients of the numerator:\r\n");
        for(int i=adeg;i>=0;i--){printf("a%d= ",i);scanf("%f",&a[i]);}
        printf("Enter the coefficient of the denominator:\r\n");
        for(int i=bdeg;i>=0;i--){printf("b%d= ",i);scanf("%f",&b[i]);}
        printf("you entered for numerator:");
            int first_time_detector_nomenator=0;
        for(int i=lim-1;i>=0;i--){
            if(a[i] != 0.0f){
                if(first_time_detector_nomenator != 0){
                    if(a[i]>0){
                    if(i == 0) printf("+%.2f",fabs(a[i]));
                    else if(i==1)printf("+%.2fX",fabs(a[i]));
                    else printf("+%.2fX^%d",fabs(a[i]),i);
                    }
                    if(a[i]<0){
                    if(i == 0) printf("-%.2f",fabs(a[i]));
                    else if(i==1)printf("-%.2fX",fabs(a[i]));
                    else printf("-%.2fX^%d",fabs(a[i]),i);
                    }
                }
                            if(first_time_detector_nomenator == 0){
                    if(a[i]>0){
                    if(i == 0) printf("%.2f",fabs(a[i]));
                    else if(i==1)printf("%.2fX",fabs(a[i]));
                    else printf("%.2fX^%d",fabs(a[i]),i);
                    }
                    if(a[i]<0){
                    if(i == 0) printf("-%.2f",fabs(a[i]));
                    else if(i==1)printf("-%.2fX",fabs(a[i]));
                    else printf("-%.2fX^%d",fabs(a[i]),i);
                    }
                    first_time_detector_nomenator++;
                }
            }
        }
        printf("\r\n");
        printf("you entered for denominator:");
            int first_time_detector_demonator=0;
        for(int i=lim-1;i>=0;i--){
            if(b[i] != 0.0f){
                if(first_time_detector_demonator != 0){
                    if(b[i]>0){

                    if(i == 0) printf("+%.2f",fabs(b[i]));
                    else if(i==1)printf("+%.2fX",fabs(b[i]));
                    else printf("+%.2fX^%d",fabs(b[i]),i);

                    }
                    if(b[i]<0){
                    if(i == 0) printf("-%.2f",fabs(b[i]));
                    else if(i==1)printf("-%.2fX",fabs(b[i]));
                    else printf("-%.2fX^%d",fabs(b[i]),i);
                    }
                }
                    if(first_time_detector_demonator == 0){
                    if(b[i]>0){
                    if(i == 0) printf("%.2f",fabs(b[i]));
                    else if(i==1)printf("%.2fX",fabs(b[i]));
                    else printf("%.2fX^%d",fabs(b[i]),i);
                    }
                    if(b[i]<0){
                    if(i == 0) printf("-%.2f",fabs(b[i]));
                    else if(i==1)printf("-%.2fX",fabs(b[i]));
                    else printf("-%.2fX^%d",fabs(b[i]),i);
                    }
                    first_time_detector_demonator++;
                }
            }
        }

        for(;;){
            int a_max_deg_now=lim-1;
            int a_max_deg_now_2=lim-1;
            for(int i=lim-1;i>=0;i--){if(a[i] != 0){a_max_deg_now=i;break;}}
            result[(a_max_deg_now-bdeg)] = a[a_max_deg_now] / b[bdeg];
            for(int i=0;i<(lim-(adeg-bdeg));i++){temp[(a_max_deg_now-bdeg)+ i] = result[(a_max_deg_now-bdeg)] * b[i];}
            for(int i=0;i<lim;i++){a[i]=a[i]-temp[i];}
            printf("\r\n");
            for(int i=lim-1;i>=0;i--){if(a[i] != 0.0f){a_max_deg_now_2=i;break;}else if(i==0){a_max_deg_now_2=0;break;}}
            if(a_max_deg_now_2<bdeg){break;}
        }

        printf("\r\nthe result is: \r\n");
        int first_time_detector=0;
        for(int i=lim-1;i>=0;i--){
            if(result[i] != 0.0f){
                if(first_time_detector != 0){
                    if(result[i]>0){
                    if(i == 0) printf("+%.2f",fabs(result[i]));
                    else if(i==1)printf("+%.2fX",fabs(result[i]));
                    else printf("+%.2fX^%d",fabs(result[i]),i);
                    }
                    if(result[i]<0){
                    if(i == 0) printf("-%.2f",fabs(result[i]));
                    else if(i==1)printf("-%.2fX",fabs(result[i]));
                    else printf("-%.2fX^%d",fabs(result[i]),i);
                    }
                }
                            if(first_time_detector == 0){
                    if(result[i]>0){

                    if(i == 0) printf("%.2f",fabs(result[i]));
                    else if(i==1)printf("%.2fX",fabs(result[i]));
                    else printf("%.2fX^%d",fabs(result[i]),i);

                    }
                    if(result[i]<0){
                    if(i == 0) printf("-%.2f",fabs(result[i]));
                    else if(i==1)printf("-%.2fX",fabs(result[i]));
                    else printf("-%.2fX^%d",fabs(result[i]),i);
                    }
                    first_time_detector++;
                }
            }
        }

        int reminder_detector = 0;
        for(int i=lim-1;i>=0;i--){if(a[i] !=0) reminder_detector++;}
        if(reminder_detector != 0){
            printf("+(");
            int first_time_detector_reminder=0;
        for(int i=lim-1;i>=0;i--){
            if(a[i] != 0.0f){
                if(first_time_detector_reminder != 0){
                    if(a[i]>0){
                    if(i == 0) printf("+%.2f",fabs(a[i]));
                    else if(i==1)printf("+%.2fX",fabs(a[i]));
                    else printf("+%.2fX^%d",fabs(a[i]),i);
                    }
                    if(a[i]<0){
                    if(i == 0) printf("-%.2f",fabs(a[i]));
                    else if(i==1)printf("-%.2fX",fabs(a[i]));
                    else printf("-%.2fX^%d",fabs(a[i]),i);
                    }
                }
                            if(first_time_detector_reminder == 0){
                    if(a[i]>0){

                    if(i == 0) printf("%.2f",fabs(a[i]));
                    else if(i==1)printf("%.2fX",fabs(a[i]));
                    else printf("%.2fX^%d",fabs(a[i]),i);
                    }
                    if(a[i]<0){
                    if(i == 0) printf("-%.2f",fabs(a[i]));
                    else if(i==1)printf("-%.2fX",fabs(a[i]));
                    else printf("-%.2fX^%d",fabs(a[i]),i);
                    }
                    first_time_detector_reminder++;
                }
            }
        }
        printf(")/(");
            int first_time_detector_demonator2=0;
        for(int i=lim-1;i>=0;i--){
            if(b[i] != 0.0f){
                if(first_time_detector_demonator2 != 0){
                    if(b[i]>0){
                    if(i == 0) printf("+%.2f",fabs(b[i]));
                    else if(i==1)printf("+%.2fX",fabs(b[i]));
                    else printf("+%.2fX^%d",fabs(b[i]),i);
                    }
                    if(b[i]<0){
                    if(i == 0) printf("-%.2f",fabs(b[i]));
                    else if(i==1)printf("-%.2fX",fabs(b[i]));
                    else printf("-%.2fX^%d",fabs(b[i]),i);
                    }
                }
                    if(first_time_detector_demonator2 == 0){
                    if(b[i]>0){
                    if(i == 0) printf("%.2f",fabs(b[i]));
                    else if(i==1)printf("%.2fX",fabs(b[i]));
                    else printf("%.2fX^%d",fabs(b[i]),i);
                    }
                    if(b[i]<0){
                    if(i == 0) printf("-%.2f",fabs(b[i]));
                    else if(i==1)printf("-%.2fX",fabs(b[i]));
                    else printf("-%.2fX^%d",fabs(b[i]),i);
                    }
                    first_time_detector_demonator2++;
                }
            }
        }
        printf(")\r\n");
        }
        char x;
        x = getch();
        return 0;
    } else {printf("denominator coefficients can't be greater than numerator");}
}

