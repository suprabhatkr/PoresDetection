#include<stdio.h> 
#include<string.h> 

float max(float a,float b){
    if(a>b){
        return a;
    }
    return b;
}

void str(int x,char ret[]){
    int a=x%10,b=x/10;
    if(b==0){
        ret[0]=(char)(a+(int)('0'));
        ret[1]='\0';
    }
    else{
        ret[0]=(char)(b+(int)('0'));
        ret[1]=(char)(a+(int)('0'));
        ret[2]='\0';
    }
}

float accuracy(int img_arr1[][200],int img_arr2[][200]){
    int i,j,k,l,tot_acc1,tot_acc2,acc1,acc2;
    float mx_acc=0;
    for (i=0;i<50;i++){
        for (j=0;j<50;j++){
            tot_acc1=0;tot_acc2=0;acc1=0;acc2=0;
            for(k=0;k<200-i;k++){
                for(l=0;l<200-j;l++){
                    tot_acc1=img_arr1[k][l]+tot_acc1;
                    tot_acc2=img_arr2[k][l]+tot_acc2;
                    acc1=(img_arr1[k][l] & img_arr2[k+i][l+j])+acc1;
                    acc2=(img_arr2[k][l] & img_arr1[k+i][l+j])+acc2;
                }
            }
            mx_acc=max(mx_acc,(float)(acc1)/(float)(tot_acc1+tot_acc2));
            mx_acc=max(mx_acc,(float)(acc2)/(float)(tot_acc1+tot_acc2));
        }
    }
    // printf("%f",mx_acc);
    return mx_acc;
}

void binary_image_arr(int x,int y,int img_arr[][200]){
    FILE *fp;
    char ret[3];
    char path_name[35],buff[201];
    int i,j;
    strcpy(path_name,"bin_image/bin_image");
    str(x,ret);
    strcat(path_name,ret);
    str(y,ret);
    strcat(path_name,ret);
    strcat(path_name,".txt");
    // printf("%s",path_name);
    fp=fopen(path_name,"r+"); 
    for (i=0;i<200;i++){
        for (j=0;j<200;j++){
            fscanf(fp,"%s",buff);
            sscanf(buff,"%d",&img_arr[i][j]);
            // printf("%d",img_arr1[i][j]);
        }
    }
    fclose(fp);
}

int main(){
    int img_arr1[200][200],img_arr2[200][200];
    float mx_acc=0,temp_acc,tot_acc=0;
    int i,j,k,l,m,pos;
    for (m=1;m<=30;m++){
        binary_image_arr(m,5,img_arr1);
        mx_acc=0;
        for (k=m;k<=m;k++){
            for (l=1;l<=4;l++){
                binary_image_arr(k,l,img_arr2);
                temp_acc=accuracy(img_arr1,img_arr2);
                if(temp_acc>mx_acc){
                    mx_acc=temp_acc;
                    pos=k;
                }
            }
        }
        printf("%d = %d(%f)\n",m,pos,2*mx_acc);
        tot_acc=tot_acc+(2*mx_acc);
    }
    printf("%f\n",(float)tot_acc/(float)(30));
    return 0;
}