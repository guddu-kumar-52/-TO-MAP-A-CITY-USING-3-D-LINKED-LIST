#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* length;
    struct Node* breadth;
    struct Node* height; 
}*Origin=NULL;

void insert(int element,int x, int y){
    struct Node *temp=new Node;
    struct Node *Len=Origin;
    struct Node *Bth=Origin;
    temp->height=NULL;
    temp->data=element;
    if (Origin==NULL){
        temp->length=NULL;
        temp->breadth=NULL;
        Origin=temp;
        return;        
    }
    else if((x!=0 && y==0)||(x==0 && y!=0)){
        x--;
        y--;
        while (x>=1)
        {
            Len=Len->length;
            x--;
        }
        while (y>=1)
        {
            Len=Len->breadth;
            y--;
        }
        if(x==0)Len->length=temp;
        if(y==0)Len->breadth=temp;
        temp->length=NULL;
        temp->breadth=NULL;
        return;
    }
    else{
        for (int i = 0; i < x; i++)
        {
            Len=Len->length;
        }
        for (int i = 0; i < y-1; i++)
        {
            Len=Len->breadth;
        }
        for (int i = 0; i < y; i++)
        {
            Bth=Bth->breadth;
        }
        for (int i = 0; i < x-1; i++)
        {
            Bth=Bth->length;
        }
        Bth->length=temp;
        Len->breadth=temp;
        temp->length=NULL;
        temp->breadth=NULL;
    }
}
void highdata(int element,int x, int y){
    struct Node *temp=new Node;
    struct Node *high=Origin;
    temp->data=element;
    temp->length=temp->breadth=NULL;
    temp->height=NULL;    
    for (int i = 0; i < x; i++)
    {
        high=high->length;
    }
    for (int i = 0; i < y; i++)
    {
        high=high->breadth;
    }
    while (high->height)
    {
        high=high->height;
    }
    high->height=temp;
    return;
}
void display(int x,int y){
    struct Node *show=Origin;
     for (int i = 0; i < x; i++)
    {
        show=show->length;
    }
    for (int i = 0; i < y; i++)
    {
        show=show->breadth;
    }
    cout<<show->data<<"\t";
    while (show->height)
    {
        show=show->height;
        cout<<show->data<<"\t";
    }
    cout << "NULL" << endl; 
    return;
}
struct Node* give_node(int x,int y){
    struct Node *show=Origin;
     for (int i = 0; i < x; i++)
    {
        show=show->length;
    }
    for (int i = 0; i < y; i++)
    {
        show=show->breadth;
    }
    return show;
}
void deletehighdata(int x ,int y){
    struct Node *delhigh1=Origin;
    struct Node *delhigh2=Origin;
    for (int i = 0; i < x; i++)
    {
        delhigh1=delhigh1->length;
        delhigh2=delhigh2->length;
    }
    for (int i = 0; i < y; i++)
    {
        delhigh1=delhigh1->breadth;
        delhigh2=delhigh2->breadth;
    }
    while (delhigh1->height)
    {
        delhigh2=delhigh1;
        delhigh1=delhigh1->height;
    }
    delhigh2->height=NULL;
    free(delhigh1);    
}
int route(int x1,int y1,int x2, int y2){
    if(x1>x2 && y1 >y2){
        swap(x1,x2);
        swap(y1,y2);
    }
    else if(x1>x2&&y1==y2)swap(x1,x2);
    else if(x1==x2&&y1>y2)swap(y1,y2);
    else if(x1>x2 && y1<y2){
        swap(x1,x2);
        swap(y1,y2);
    }
    if(x1==x2){
        struct Node * temp1;
        int sum=0;
         temp1=give_node(x1,y1);
         printf("Path is \n%d\t",temp1->data);
         for (int i = 0; i < y2-y1; i++)
        {
        temp1=temp1->breadth;
        printf("%d\t",temp1->data);
        sum+=temp1->height->height->data;
        }
        printf("\n");
        return sum;
    }
    else if(y1==y2){
        struct Node * temp1;
        int sum=0;
        temp1=give_node(x1,y1);
        printf("Path is \n%d\t",temp1->data);
         for (int i = 0; i < x2-x1; i++)
        {
        temp1=temp1->length;
        printf("%d\t",temp1->data);
        sum+=temp1->height->data;
        }
        printf("\n");
        return sum;
    }
    else if((x1<x2)&&(y1<y2)){
        struct Node * temp1,*temp2;
        int sum1=0,sum2=0;
        temp1=give_node(x1,y1);
        temp2=temp1;
        for (int i = 0; i < y2-y1; i++)
        {
        temp1=temp1->breadth;
        sum1+=temp1->height->height->data;
        }
        for (int i = 0; i < x2-x1; i++)
        {
        temp1=temp1->length;
        sum1+=temp1->height->data;
        }
        for (int i = 0; i < x2-x1; i++)
        {
        temp2=temp2->length;
        sum2+=temp2->height->data;
        }
        for (int i = 0; i < y2-y1; i++)
        {
        temp2=temp2->breadth;
        sum2+=temp2->height->height->data;
        }
        //Comparing distances
        if(sum1>sum2){
        temp2=give_node(x1,y1);
        printf("Path is \n%d\t",temp2->data);
        for (int i = 0; i < x2-x1; i++)
        {
            temp2=temp2->length;
            printf("%d\t",temp2->data);
        }
        for (int i = 0; i < y2-y1; i++)
        {
            temp2=temp2->breadth;
            printf("%d\t",temp2->data);
        }
        printf("\n");    
        return sum2;}

        else{ 
            temp2=give_node(x1,y1);
            printf("Path is \n%d\t",temp2->data);
            for (int i = 0; i < y2-y1; i++)
            {
                temp2=temp2->breadth;
                printf("%d\t",temp2->data);
            }
            for (int i = 0; i < x2-x1; i++)
            {
                 temp2=temp2->length;
                printf("%d\t",temp2->data);
            }
            printf("\n");
            return sum1;}
    }
    else if((x1<x2)&&(y1>y2)){
        struct Node * temp1,*temp2;
        int sum1=0,sum2=0,arrl1[5],arrl2[5],arrb1[5],arrb2[5],l1=0,l2=0,b1=0,b2=0;
        temp1=give_node(x1,y2);
        temp2=temp1;
        arrb1[b1++]=temp1->data;
        for (int i = 0; i < y1-y2; i++)
        {
        temp1=temp1->breadth;
        arrb1[b1++]=temp1->data;
        sum1+=temp1->height->height->data;
        }
        for (int i = 0; i < x2-x1; i++)
        {
        temp2=temp2->length;
        arrl1[l1++]=temp2->data;
        sum1+=temp2->height->data;
        }
        temp1=give_node(x1,y1);
        arrl2[l2++]=temp1->data;
        temp2=give_node(x2,y2);
        arrb2[b2++]=temp2->data;
        int index_i=0,index_j=0;
        while(temp1!=temp2){
            if (temp1->length&&index_i<x2-x1){temp1=temp1->length;
            arrl2[l2++]=temp1->data;
            sum2+=temp1->height->data;
            index_i++;}
            if(temp2->breadth&&index_j<y1-y2){temp2=temp2->breadth;
            arrb2[b2++]=temp2->data;
            sum2+=temp2->height->height->data;
            index_j++;}
        }
        printf("%d   %d\n",sum1,sum2);
        if(sum1>sum2){
            cout<<"Path is "<<endl;
            for(int i=0;i<l2;i++){
                cout<< arrl2[i]<<"\t";
            }
            for(int i=b2-2;i>=0;i--){
                cout<< arrb2[i]<<"\t";
            }
            cout<<endl;
            return sum2;}
        else {
            cout<<"Path is "<<endl;
            for(int i=1;i<=b1;i++){
                cout<< arrb1[b1-i]<<"\t";
            }
            for(int i=0;i<l1;i++){
                cout<< arrl1[i]<<"\t";
            }
            cout<<endl;
            return sum1;}
    }
    return 0;
}

// int autoroute(int x1,int y1,int x2, int y2){
//     if((x2>x1&&y1==y2)||(x1==x2&&y1>y2))return route(x1,y1,x2,y2);
//     return 0;
// }

int main()
{
    insert(1426,0,0);  insert(1427,1,0);  insert(1428,2,0);  insert(1429,3,0);  insert(1430,4,0);
    insert(1570,0,1);  insert(1571,1,1);  insert(1572,2,1);  insert(1573,3,1);  insert(1574,4,1); 
    insert(1664,0,2);  insert(1665,1,2);  insert(1666,2,2);  insert(1667,3,2);  insert(1668,4,2);
    insert(1711,0,3);  insert(1712,1,3);  insert(1713,2,3);  insert(1714,3,3);  insert(1715,4,3);
    insert(1844,0,4);  insert(1845,1,4);  insert(1846,2,4);  insert(1847,3,4);  insert(1848,4,4);

    highdata(0,0,0);   highdata(4,1,0);   highdata(5,2,0);   highdata(1,3,0);   highdata(3,4,0);
    highdata(0,0,1);   highdata(7,1,1);   highdata(6,2,1);   highdata(2,3,1);   highdata(6,4,1);
    highdata(0,0,2);   highdata(4,1,2);   highdata(5,2,2);   highdata(7,3,2);   highdata(2,4,2);
    highdata(0,0,3);   highdata(6,1,3);   highdata(1,2,3);   highdata(3,3,3);   highdata(1,4,3);
    highdata(0,0,4);   highdata(7,1,4);   highdata(4,2,4);   highdata(2,3,4);   highdata(5,4,4);

    highdata(0,0,0);   highdata(0,1,0);   highdata(0,2,0);   highdata(0,3,0);   highdata(0,4,0);
    highdata(2,0,1);   highdata(4,1,1);   highdata(2,2,1);   highdata(5,3,1);   highdata(7,4,1);
    highdata(5,0,2);   highdata(6,1,2);   highdata(2,2,2);   highdata(6,3,2);   highdata(7,4,2);
    highdata(3,0,3);   highdata(3,1,3);   highdata(1,2,3);   highdata(6,3,3);   highdata(1,4,3);
    highdata(1,0,4);   highdata(4,1,4);   highdata(7,2,4);   highdata(3,3,4);   highdata(5,4,4);
    
    cout<<"3D Linked List MTE Project By"<<endl;
    cout<<"Guddu Kumar 2K20/MC/52"<<endl;
    cout<<"Hemaank Mahajan 2K20/MC/55"<<endl;
    
    cout << endl;
    int ans=route(1,1,4,4);
    cout << "\t\tTime is "<< ans <<" minutes"<< endl;
    return 0;
}