#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<stdio.h>
using namespace std;
class node
{
   private :
      int data;
      int column;
      node *next;
   public :
      node(int num , int col)
      {
          set_data(num);
          set_column(col);
          this->next=NULL;
      }
      //setter functions
      void set_data(int data){ this->data = data; }
      void set_column(int column){ this->column = column; }
      void set_next(node *next){ this->next = next; }
      //getter functions
      int get_data(){ return data;}
      int get_column(){ return column; }
      node *get_next(){ return next; }

};
class matrix
{
   private:
      node *head;
   public:
      matrix()
      {
         head=NULL;
      }
      void add(int data , int column){
         node *newNode = new node(data , column);
           if(head == NULL){
              head=newNode;
              return;
           }
         node *temp = head;
           while(temp->get_next()!=NULL){
              temp = temp->get_next();
            }
         temp->set_next(newNode);
      }
      void insert( int col, int value)
      {
         col=col-1;
         node *newNode = new node(value , col);
         node *per=head , *temp=head;
            if(head==NULL)
            {
              head=newNode;
              return;
            }
            if(temp->get_column()>col)
            {
                newNode->set_next(head);
                head=newNode;
                return;
            }
            while(temp->get_column()<col ){
                per=temp;
                temp=temp->get_next();
                if(temp==nullptr)
                    break;
            }

         newNode->set_next(temp);
         per->set_next(newNode);

      }
      bool check_insert(int col)
      {
         node *temp=head;
            while(temp!=nullptr)
            {
               if(temp->get_column()==col-1)
               {
                  cout<<"\n---This element isn't empty please choose another element---\n\n";
                  return true;
               }
               temp=temp->get_next();

            }
         return false;
      }
};
void menu(matrix RowList[] , int row , int column)
{
    bool flag=true , search;
    int choice , chosen_val , chosen_row , chosen_col , i , type;
         while(flag)
         {
         cout<<"------------------- MENU ------------------\n";
         cout<<"1.Insert\n";
         cout<<"2.Delete\n";
         cout<<"3.Search\n";
         cout<<"4.Update\n";
         cout<<"5.Print\n";
         cout<<"6.Exit\n";
         cout<<"Choice : ";
         cin>>choice;
            switch(choice){

               case 1:
                 cout<<"Value : ";
                 cin>>chosen_val;
                  do{
                    cout<<"Row : ";
                    cin>>chosen_row;
                    cout<<"Column : ";
                    cin>>chosen_col;
                  }while(RowList[chosen_row-1].check_insert(chosen_col));
                 RowList[chosen_row-1].insert(chosen_col , chosen_val);
                 break;

            }

       }

}
int main()
{

      matrix RowList[10000];
      string line , num;
      int row=0 , column=0 , number ;
      //file part
      ifstream matrix;
      matrix.open("M(300,200).csv");
         if(!matrix)
         {
            cout<<"error when opening file\n";
            exit(1);
         }

         while(getline(matrix, line))
         {
            column=0;
            stringstream str(line);
            //splitting part
            while (getline(str , num, ','))
            {
              if(num != "0")
              {
              //converting string to integer
                 stringstream ss;
                 ss << num;
                 ss >> number;
                 RowList[row].add(number , column);
              }
              column++;
            }
            row++;
         }
        matrix.close();
      //menu part
      menu(RowList , row , column);
}
