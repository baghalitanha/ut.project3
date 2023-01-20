#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct sm_node smNode;
struct sm_node {
    char username[20];
    char password[20];
    char post[50];
    int post_id;
    int likes;
    smNode *next; 
};
int scaner(smNode*head,char username[20]){
    /*chek mionad ke username tekrary vojod nadashte bashad*/
    smNode *prevNode = head;
    smNode *nextNode = prevNode->next;
    while((prevNode != NULL) ){
        int v= strcmp(username,prevNode->username);
        if(v==0){
            printf("user already exist!\n");
            return 1;
        }
        else{
            prevNode=prevNode->next;
        }
    } 

}
int scanerid(smNode*head,int post_id){
    /*chek mikonad ke post_id tekrari vojodnadashte bashad*/
    smNode *prevNode = head;
    smNode *nextNode = prevNode->next;
    while((prevNode != NULL) ){
        if(post_id==(prevNode->post_id)){
            printf("post_id already exist!\n");
            return 1;
        }
        else{
            prevNode=prevNode->next;
        }
    } 

}
smNode*end(smNode*head){
    /*yeki az abzar haye tabe addd va post ast ke akharim node ra barmigardanad*/
    smNode *prevNode = head;
    while((prevNode->next != NULL) ){
        prevNode=prevNode->next;
    } 
    return prevNode;
}
smNode *post(smNode*head,char username[20],char password[20]){
    /*tabe post data ha ra az karbar gerefte va dar yek node
    zakhire mikonad(chek minad ke post_id yeksan vojod nadashte bashad)*/
    smNode *newNode = (smNode*) malloc(sizeof(smNode));
    strcpy(newNode->password,password);
    strcpy(newNode->username,username);
    smNode *lastNode= end(head); 
    char buffer[20];
    char *b = buffer;
    size_t bufsize = 20;
    size_t characters;
    characters=getline(&b,&bufsize,stdin);
    printf("please enter post\n");
    strcpy(newNode->post,buffer);
    printf("please enter post_id\n");
    scanf("%d",&newNode->post_id);
    newNode->likes=0;
    int i = scanerid(head,newNode->post_id);
    if(i!=1){
        lastNode->next=newNode;
        newNode->next=NULL;
        printf("posted!\n");
        return newNode;
    }
    else{
        printf("please try again\n");
    }
}
void delete(smNode*head,char username[20],int post_id,char password[20]){
    smNode *prevNode = head->next;
    /*tabe delete data haye vared shode ra ba post mored nazar tatbigh midahad
    va agar yeksan bod node ghabli an ra be badi motasel mikonad va an node ra free mikonad */
    smNode *nextNode = prevNode->next;
    smNode *thNode = nextNode->next;
    while(prevNode != NULL ){
        int v= strcmp(username,prevNode->username);
        int aa=strcmp(password,prevNode->password);
        /*printf("deleted !\n");*/
        if(((v+aa)==0)&&(prevNode->post_id==post_id)){
            printf("deleted !\n");
            prevNode->post_id=0;
            prevNode->next=thNode;
            free(nextNode);
            break;
        }
        else{
            prevNode=prevNode->next;
        }
    } 
}
void info(smNode*head,char username[20],char password[20]){
    /*tabe info ba jost va jo adr node ha tama post haye account fard ra
    namayesh midahad*/
    smNode *prevNode = head;
    while(prevNode != NULL ){
        int v= strcmp(username,prevNode->username);
        int a =strcmp(password,prevNode->password);
        if(v==0&&(prevNode->likes!=-10)&&a==0){
            printf("post_id : %d\n",prevNode->post_id);
            printf("likes : %d\n",prevNode->likes);
            printf("post : %s\n",prevNode->post);
            prevNode=prevNode->next;
        }
        else{
            prevNode=prevNode->next;
        }
    } 
}
void searchuser(smNode*head,char username[20]){
    int count =0;
    smNode *prevNode = head;
    /*in tabe amalkardi moshabeh ba info dard va tafavot an inast 
    ke baraye namayesh dadan post ha niazi be passwprd nadarad*/
    while(prevNode != NULL ){
        int v= strcmp(username,prevNode->username);
        if(v==0&&(prevNode->likes!=-10)){
            printf("post_id : %d\n",prevNode->post_id);
            printf("likes : %d\n",prevNode->likes);
            printf("post : %s\n",prevNode->post);
            prevNode=prevNode->next;
            count++;
        }
        else{
            prevNode=prevNode->next;
        } 
    }
    if(prevNode==NULL&&count==0){
        printf("user not found!\n");
    }
    
}    
void like(smNode*head,char username[20],int post_id){
    /* tabe like dar node ha jos va jo mikonad ta post ra peida karde
    va yeki be like haye an ezafe mikonad*/
    smNode *prevNode = head;
    while(prevNode != NULL ){
        int v= strcmp(username,prevNode->username);
        if(v==0&&(prevNode->post_id==post_id)){
            prevNode->likes=(prevNode->likes)+1;
            printf("liked !\n");
            break;
        }
        else{
            prevNode=prevNode->next;
        }
    } 
}
smNode *addd(smNode *head,int*changer){
    /*tabe addd yek node ijad karde data haye karbar ra migirad 
    va agar username moshabehi nabod an ra be tah node ha ezafe mikonad*/
    smNode *newNode = (smNode*) malloc(sizeof(smNode));
    int b=3;
    while(b==3){
        printf("welcome to ut toti ! please enter your username\n");
        scanf("%s",newNode->username);
        printf("please enter your password\n");
        scanf("%s",newNode->password);
        newNode->likes=-10;
        smNode *lastNode= end(head); 
        smNode *prevNode = head;
        smNode *nextNode = prevNode->next;
        int i = scaner(head,newNode->username);
        if(i!=1){
            lastNode->next=newNode;
            newNode->next=NULL;
            return newNode;
        }
        else{
            *changer=125;
            b=625;
            break;
        }
    }
    
}
smNode*login(smNode *head,int*s){
    /*tabe login node jadidi ijad nemikonad faghat dar node
     ha jostojo mikonad ta be username va password mord nazar beresad
     va agar movafagh nabod be karbar ejaze talash dobare ya sign up midahad*/
    int i=2 ;
    while(i==2){
        char username[20],password[20];
        printf("please type your username.\n");
        scanf("%s",username);
        printf("please type your password.\n");
        scanf("%s",password);
        smNode *prevNode = head;
        smNode *nextNode = prevNode->next;
        while((prevNode != NULL) ){
            int v= strcmp(username,prevNode->username);
            int jim=strcmp(password,prevNode->password);
            if(v==0&&jim==0){
                printf("welcome %s\n",username);
                i=1;
                return prevNode;
                break;
            }
            else{
                prevNode=prevNode->next;
            }
        }
        if(i!=1){
            printf("incorrect username or password\n");
            *s=125;
            i=0;
            break;
        }
    }

}

void main(){
    int v=6,m=5;
    int i=2;
    int *s;
    int var;
    s=&var;  
    /*scanf("%d",&v);/*/
    smNode *head = (smNode*) malloc(sizeof(smNode));
    head->next=NULL;
    smNode*prevnode=head;

    while(m==5){
        printf("welcome to uttooti !\n");
        printf("press 2 to login ,1 to sign up , 3to exit \n");
        scanf("%d",&i);
        *s=i;
        if (i==3){
            v=25;
            m=10;
            break;
        }
        if (i==1||i==2){
            v=6;
        }
        while(v==6){
            int b;
            if(b==4){
                b=-1;
                break;
            }
            if(i==1){
                smNode *nextnode1 = (smNode*) malloc(sizeof(smNode));
                nextnode1=addd(head,s);
                if(*s==125){
                    i=*s;
                    v=5556;
                }
                if (i==1){
                    while (i==1){                
                        printf("1 to post , 2 to delete , 3 to like , 4 to log out , 5 to show your info , 6 to search a user\n");
                        scanf("%d",&b);
                        if (b==4){
                            v==45;
                            i=0;
                        }
                        if (b==1){
                            smNode *postnode= (smNode*) malloc(sizeof(smNode));
                            postnode=post(head,nextnode1->username,nextnode1->password);
                        }

                        if (b==2){
                            int id;
                            printf("please enter the post_id\n");
                            scanf("%d",&id);
                            delete(head,nextnode1->username,id,nextnode1->password);
                        }
                        if (b==3){
                            int id;
                            printf("please enter the post_id\n");
                            scanf("%d",&id);
                            printf("please enter the username\n");
                            char un[20];
                            scanf("%s",un);
                            like(head,un,id);
                        }
                        if(b==5){
                            info(head,nextnode1->username,nextnode1->password);
                        }
                        if(b==6){
                            char user[20];
                            scanf("%s",user);
                            searchuser(head,user);
                        }
                    }

                }            
            }   
            if(i==2){
                smNode *nextnode2 = (smNode*) malloc(sizeof(smNode));
                nextnode2=login(head,s);
                if(*s==125){
                    i=*s;
                    v=5556;
                }
                if (i==2){
                    while (i==2){                
                        printf("1 to post , 2 to delete , 3 to like , 4 to log out , 5 to show your info , 6 to search a user\n"); 
                        scanf("%d",&b);
                        if (b==4){
                            v==45;
                            i=0;
                        }
                        if (b==1){
                            smNode *postnode= (smNode*) malloc(sizeof(smNode));
                            postnode=post(head,nextnode2->username,nextnode2->password);
                        }

                        if (b==2){
                            int id;
                            printf("please enter the post_id\n");
                            scanf("%d",id);
                            delete(head,nextnode2->username,id,nextnode2->password);
                        }
                        if (b==3){
                            int id;
                            printf("please enter the post_id\n");
                            scanf("%d",&id);
                            printf("please enter the username\n");
                            char un[20];
                            scanf("%s",un);
                            like(head,un,id);
                        }
                        if(b==5){
                            info(head,nextnode2->username,nextnode2->password);
                        }
                        if(b==6){
                            char user[20];
                            scanf("%s",user);
                            searchuser(head,user);
                        }
                    }
                }  
            }
        }
    }
    FILE *fp;
    fp = fopen ("student1.txt", "w");
    while(prevnode!=NULL){
        fwrite(prevnode->username,sizeof(prevnode->username),1,fp );
        fwrite(prevnode->password,sizeof(prevnode->password),1,fp );
        prevnode=prevnode->next;

    }
    return;
}