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
};
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

}
