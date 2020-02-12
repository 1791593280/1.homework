#include<stdio.h>
#include<string.h>
#include<math.h>
int first(char a[])
{
    if(strcmp("零",a)==0)
		return 0;
    if(strcmp("一",a)==0)
		return 1;
    if(strcmp("二",a)==0)
		return 2;
    if(strcmp("三",a)==0)
		return 3;
    if(strcmp("四",a)==0)
		return 4;
    if(strcmp("五",a)==0)
		return 5;
    if(strcmp("六",a)==0)
		return 6;
    if(strcmp("七",a)==0)
		return 7;
    if(strcmp("八",a)==0)
		return 8;
    if(strcmp("九",a)==0)
		return 9;
    if(strcmp("十",a)==0)
		return 10;
}
int second(char a[]){
    char b[10],c[10];
    if(strlen(a)==2)
	{
		return first(a); 
    }
    else if(strlen(a)==4)
	{
        b[0]=a[2];
        b[1]=a[3];
        b[2]='\0';      
        if(first(b)!=10) 
			return 10+first(b);
        else{
				b[0]=a[0];
				b[1]=a[1];
				b[2]='\0';
				return 10*first(b);
			}
    
	}
    else if(strlen(a)==6)
	{
        b[0]=a[4];
        b[1]=a[5];
        b[2]='\0';
        c[0]=a[0];
        c[1]=a[1];
        c[2]='\0';
        return first(b)+first(c)*10;
    }
}
int main(){
    char *chinese[11]={"零","一","二","三","四","五","六","七","八","九","十"};
    char name[200],verb[200],numb[200],oper[200],name1[200],toint[200],name3[200];
    char x[20],y[20],numb2[20],d[20],word[100],e[20],f[20],cold[100],name2[100];
    char age[200],money[200];
    int sum,sum2,sum3;
    scanf("%s",toint);
    scanf("%s %s %s",name,verb,numb);
    sum=second(numb);
    while(scanf("%s",name1)!=EOF)
    {   
        if(strcmp(name1,toint)==0)
        {
            scanf("%s %s %s",name3,verb,numb);
            sum2=first(numb);
        }
        if(strcmp(name1,name)==0){
            scanf("%s",oper);
            if(strcmp(oper,"增加")==0){
                scanf("%s",numb);
                sum3=second(numb);
                sum+=sum3;}
            if(strcmp(oper,"减少")==0){
                scanf("%s",numb);   
                if(strlen(numb)==2)
                {
                    sum3=second(numb);
                    sum-=sum3;
                }
            }
        }
        else if(strcmp(name1,"看看")==0)
        {
            int lasttmp;
            scanf("%s",name);
            scanf("%s %s %s %s %s %s %s %s %s %s",x,name,y,numb2,d,name2,word,e,f,cold);
            lasttmp=first(numb2);
            int len=strlen(word);
            int len1=strlen(cold);
            {
                if(sum>=lasttmp)
                {   if(sum>=0&&sum<=10){
                    printf("%s\n",chinese[sum]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}
                    }
                    else {
                    if(sum%10==0){
                        printf("%s十\n",chinese[sum/10]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}
                    }
                    else if(sum<=19){
                        printf("十%s\n",chinese[sum%10]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}
                    }
                    else {
                        printf("%s十%s\n",chinese[sum/10],chinese[sum%10]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}
                    }
                }
			}
                else if(sum<lasttmp){
                        if(sum<0)
                        {
                            int under=abs(sum); 
                            printf("%s%s\n","负",chinese[under]);
                            for(int j=1;j<len1-1;j+=2) {printf("%c%c",cold[j],cold[j+1]);}}
                        }
                else{   
                    printf("%s\n",chinese[sum]);for(int j=1;j<len1-1;j+=2) {printf("%c%c",cold[j],cold[j+1]);}}
            }
            }
        else if(strcmp(name1,"如果")==0)
        {   
            scanf("%s %s %s %s %s %s %s %s %s",age,y,numb2,d,money,word,e,f,cold);
            scanf("%s %s",x,age);
            if(strcmp(x,"看看")==0)
            {   
                if(sum>8)
                {
                    int x=sum2+1;
                    printf("%s",chinese[x]);

                }
            }
        }
    }
    return 0;
}