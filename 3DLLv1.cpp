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
    struct Node *t=new Node;
    struct Node *high=Origin;
    t->data=element;
        
    for (int i = 0; i < x; i++)
    {
        high=high->length;
    }
    for (int i = 0; i < y; i++)
    {
        high=high->breadth;
    }
    while (high->height!=NULL)
    {
        high=high->height;
    }
    high->height=t;
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

int main()
{   
    cout<<"3D Linked List MTE Project By"<<endl;
    cout<<"Guddu Kumar 2K20/MC/52"<<endl;
    cout<<"Hemaank Mahajan 2K20/MC/55"<<endl;
    cout << "Enter grid size as length breadth"<<endl;
    int max_len,max_breadth;
    cin >> max_len >> max_breadth;
    cout<<"Enter "<<(max_len+1)*(max_breadth+1)<<" Elements i.e "<<(max_len+1)<<" values in "<<(max_breadth+1)<<" Rows"<<endl;
    int array[(max_len+1)*(max_breadth+1)];
    for(int i=0;i<(max_len+1)*(max_breadth+1);i++){
        cin>>array[i];
    }
    int k=0;
    for (int i = 0; i <=max_breadth ; i++)
    {
        for (int j = 0; j <= max_len ; j++)
        {
            insert(array[k],j,i);
            k++;
        }   
    }
    cout << "Grid Created Successfully and Nodes are assigned Value"<<endl;
    display(14,14);
    highdata(28,3,0); highdata(110,3,0); highdata(26,9,0); highdata(21,11,0); 
    highdata(30,1,1); highdata(28,3,1); highdata(110,3,1); highdata(26,8,1); highdata(22,9,1); highdata(21,11,1); highdata(21,12,1);
    highdata(22,3,2);
    highdata(22,3,3); highdata(28,9,3); highdata(695,9,3); highdata(28,10,3); highdata(695,10,3);
    highdata(22,3,4); highdata(22,4,4); highdata(28,7,4);highdata(395,7,4); highdata(21,11,4); highdata(28,12,4); highdata(695,12,4);
    highdata(32,2,5); highdata(22,3,5); highdata(28,5,5); highdata(110,5,5); highdata(28,6,5); highdata(395,6,5); highdata(22,8,5); highdata(21,11,5); highdata(32,12,5);     
    highdata(32,2,6); highdata(28,4,6); highdata(110,4,6); highdata(24,5,6); highdata(22,8,6); highdata(28,13,6); highdata(295,13,6);
    highdata(28,4,7); highdata(395,4,7); highdata(28,5,7); highdata(395,5,7); highdata(22,8,7);
    highdata(28,3,8); highdata(395,3,8); highdata(31,4,8); highdata(27,6,8); highdata(28,11,8); highdata(295,11,8); highdata(21,13,8);
    highdata(23,1,9); highdata(28,3,9); highdata(395,3,9); highdata(27,6,9); highdata(27,7,9); highdata(28,11,9); highdata(295,11,9);
    highdata(29,4,10); highdata(27,6,10); highdata(27,7,10); 
    highdata(28,2,11); highdata(395,2,11); highdata(29,4,11); highdata(27,6,11);highdata(27,7,11); highdata(22,9,11); 
    highdata(21,2,12); highdata(21,3,12); highdata(27,6,12); highdata(27,7,12);
    highdata(25,0,13); highdata(28,1,13); highdata(395,1,13); highdata(21,2,13); highdata(21,3,13); highdata(27,6,13); highdata(27,7,13); highdata(29,11,13);
    highdata(28,0,14); highdata(395,0,14); highdata(21,2,14); highdata(21,3,14); highdata(28,10,14); highdata(295,10,14); highdata(22,14,14);            
    cout << "High Data Entered Succesfully"<<endl;
    display(14,14);
    char choice='y';
    while(choice=='y'){
    cout << "Enter Coordinate whose data is to be displayed:"<<endl;
    int x_coordinate=0,y_coordinate=0;
    cin >> x_coordinate >> y_coordinate;
    display(x_coordinate,y_coordinate);
    cout<<endl<<"Do you wish to Continue ? "<<endl;
    cin >> choice;    
    }
    return 0; 
}
    // char choice='y';
    // int option=0;
    // while(choice=='y'){
    // cout<<"3D Linked List MTE Project By"<<endl;
    // cout<<"Guddu Kumar 2K20/MC/52"<<endl;
    // cout<<"Hemaank Mahajan 2K20/MC/55"<<endl;
    // cout<<"Choose From Following Choices:\t"<<endl;
    // cout<<"1. Customize Base Grid."<<endl;
    // cout<<"2. Input Elevated Data."<<endl;
    // cout<<"3. Delete Elevated Data."<<endl;
    // cout<<"4. Display Particular Node."<<endl;
    // cout<<"5. Display Entire Grid With Elevated Data."<<endl;
    // cout<<"To Exit Enter 'n' Or 'N' In Choice."<<endl;
    // cin >> option; 
    // if(option==1){
    // int max_len=0,max_breadth=0;
    // cout << "Enter grid size as length breadth"<<endl;
    // cin >> max_len >> max_breadth;
    // cout<<"Enter "<<(max_len+1)*(max_breadth+1)<<" Elements i.e "<<(max_len+1)<<" values in "<<(max_breadth+1)<<" Rows"<<endl;
    // int array[(max_len+1)*(max_breadth+1)];
    // for(int i=0;i<(max_len+1)*(max_breadth+1);i++){
    //     cin>>array[i];
    // }
    // int k=0;
    // for (int i = 0; i <=max_breadth ; i++)
    // {
    //     for (int j = 0; j <= max_len ; j++)
    //     {
    //         insert(array[k],j,i);
    //         k++;
    //     }   
    // }
    // cout << "Grid Created Successfully and Nodes are assigned Value"<<endl;
    // }
    // else if(option==2){
    // cout << "Enter Coordinate whose high data is to be inserted:"<<endl;
    // int x_coordinate,y_coordinate=0,value;
    // cin >> x_coordinate >> y_coordinate;
    // cout <<"Enter data"<<endl;
    // cin>>value;
    // highdata(value,x_coordinate,y_coordinate);
    // cout<< "Element Inserted successfully "<<endl ;
    // }
    // else if(option==3){
    // cout << "Enter Coordinate whose high data is to be deleted:"<<endl;
    // int x_coordinate,y_coordinate=0;
    // cin >> x_coordinate >> y_coordinate;
    // deletehighdata(x_coordinate,y_coordinate);
    // cout<< "Element Deleted successfully "<<endl;        
    // }
    // else if(option==4){
    // cout << "Enter Coordinate whose data is to be displayed:"<<endl;
    // int x_coordinate,y_coordinate=0;
    // cin >> x_coordinate >> y_coordinate;
    // display(x_coordinate,y_coordinate);
    // }
    // else if(option==5){
    // int max_len=0,max_breadth=0;
    // cout << "Enter grid size as length breadth"<<endl;
    // cin >> max_len >> max_breadth;
    //  for (int i = 0; i <=max_breadth ; i++)
    // {
    //     for (int j = 0; j <= max_len ; j++)
    //     {
    //         display(j,i);
    //     }  
    //     cout<<" Next Row"<<endl; 
    // }
    // }
    // else cout<<"Enter Valid Choice."<<endl; 
    // cout<<"Do you wish to Continue ? "<<endl;
    // cin >> choice;
    // } 

    // 2 2 2 4 1 4 2 1 2 2 2 2 4 2 2 
    // 2 2 4 4 1 1 1 1 1 1 1 2 2 2 1
    // 2 4 2 1 4 3 1 3 2 2 4 2 2 2 2
    // 2 4 1 1 4 3 3 3 4 4 4 4 2 2 1
    // 2 4 1 1 1 3 3 4 3 2 1 2 4 2 3
    // 4 4 2 1 1 4 4 3 1 2 2 2 2 3 4
    // 2 2 2 1 4 2 4 3 1 3 2 3 3 4 2
    // 2 2 4 4 4 4 3 3 1 3 2 4 1 2 4
    // 2 2 1 4 2 4 2 3 3 3 3 4 4 2 2
    // 2 2 1 4 1 4 2 2 3 3 2 4 4 2 1
    // 2 2 1 4 2 4 2 2 3 3 2 2 5 4 4
    // 1 2 4 1 2 4 2 2 3 1 2 1 5 5 2
    // 3 2 2 2 1 1 2 2 3 2 2 1 5 5 2
    // 5 4 2 2 1 3 2 2 3 2 2 2 2 2 1
    // 4 4 2 2 3 5 3 3 3 2 4 2 2 1 1
    

    // insert(10,0,0);
    // insert(20,1,0);
    // insert(30,2,0);
    // insert(40,3,0);
    // insert(20,0,1);
    // insert(30,0,2);
    // insert(40,0,3);
    // insert(15,1,1);
    // highdata(25,0,0);
    // highdata(45,0,0); 
    // cout << Origin->data << endl;
    // cout<< Origin->length->data<<endl;
    // cout<< Origin->length->length->data<<endl;
    // cout<< Origin->length->length->length->data<<endl;
    // cout << Origin->data << endl;
    // cout<< Origin->breadth->data<<endl;
    // cout<< Origin->breadth->breadth->data<<endl;
    // cout<< Origin->breadth->breadth->breadth->data<<endl;
    // cout<< Origin->length->breadth->data<<endl;
    // cout<<Origin->breadth->length->data<<endl;
    // cout<<Origin->height->data<<endl;
    // cout<<Origin->height->height->data<<endl;
    // display(0,0);
    // display(1,1);
    // deletehighdata(0,0);
    // display(0,0);  