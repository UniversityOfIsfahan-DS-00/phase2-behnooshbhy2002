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
      void Delete(int col)
      {
         node *temp=head;
         node *per;

         if(temp->get_column()==col-1){
            head=head->get_next();
            return;
         }

         while(temp->get_column()!= col-1)
         {
            per = temp;
            temp = temp->get_next();
         }
         per->set_next( temp->get_next());
         delete temp;

      }
      bool check_Delete(int col)
      {
         node *temp=head;
            while(temp!=nullptr)
            {
               if(temp->get_column()==col-1)
               {
                  return false;
               }
               temp=temp->get_next();
           }
          cout<<"\n---This element is empty please choose another element---\n\n";
          return true;
      }
      bool search(int value)
      {
         node *temp=head;
            while(temp!=nullptr)
            {
               if(temp->get_data()==value)
               {
                   return true;
               }

               temp=temp->get_next();
            }
         return false;
      }
      void update(int col , int value)
      {
         if(value==0)
            Delete(col);
         else{
          node *temp=head;
            while(temp!=nullptr)
            {
                if(temp->get_column()==col-1){
                    temp->set_data(value);
                    return;
                }
                temp=temp->get_next();
            }
         }
      }
      void print(matrix List[] , int row , int column , bool type)
      {

          int i , j;
          if(!type)
          {
              for(i=0; i<row; i++)
              {
                  node *temp=List[i].head;
                  for(j=0; j<column; j++)
                  {
                      if(temp!=nullptr){
                        while(temp!=nullptr)
                        {
                          if(temp->get_column()==j)
                          {
                             printf("%-5d" , temp->get_data());
                             temp=temp->get_next();
                          }
                          else
                             printf("%-5s" , "0");
                          break;
                        }
                      }
                      else
                        printf("%-5s" , "0");

                  }
                 cout<<endl;
             }
          }
          else
          {
             cout<<"Row\tColumn\tValue\n";
             for(i=0; i<row; i++)
              {
                node *temp=List[i].head;
                 while(temp!=nullptr)
                 {
                     cout<<i+1<<"\t"<<temp->get_column()+1<<"\t"<<temp->get_data()<<endl;
                     temp=temp->get_next();
                 }

              }
          }
      }
      void save_files(matrix List[] , int row , int column)
      {
          ofstream M("M(7000,9000).csv");
            if(M.is_open())
            {
                for(int i=0; i<row; i++){

                  node *temp=List[i].head;

                     for(int j=0; j<column; j++){

                        if(temp!=nullptr){
                          while(temp!=nullptr)
                          {
                            if(temp->get_column()==j)
                            {
                              M<<temp->get_data();
                              temp=temp->get_next();
                            }
                            else
                              M<<"0";
                            break;

                           }
                        }
                        else
                          M<<"0";
                        if(j!=column-1)
                          M<<",";
                     }
                 M<<endl;
              }
           }
      }
      void destroy()
      {
          node *temp=head;
          node *tmp;
            while(temp!=nullptr)
            {
                tmp=temp;
                delete tmp;
                temp=temp->get_next();
            }
          this->head=nullptr;
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

               case 2:
                 do{
                   cout<<"Row : ";
                   cin>>chosen_row;
                   cout<<"Column : ";
                   cin>>chosen_col;
                  }while(RowList[chosen_row-1].check_Delete(chosen_col));
                 RowList[chosen_row-1].Delete(chosen_col);
                 break;

               case 3:
                 cout<<"value : ";
                 cin>>chosen_val;
                  for(i=0; i<row; i++)
                  {
                     if(RowList[i].search(chosen_val)){
                        search=true;
                        break;
                     }
                     search=false;
                  }
                  if(search==true)
                     cout<<"\n--value "<<chosen_val<<" is found-- \n\n";
                  else
                     cout<<"\n--value "<<chosen_val<<" isn't found-- \n\n";
                 break;

              case 4:
                 cout<<"Value : ";
                 cin>>chosen_val;
                 cout<<"Row : ";
                 cin>>chosen_row;
                 cout<<"Column : ";
                 cin>>chosen_col;
                 RowList[chosen_row-1].update(chosen_col , chosen_val);
                 break;

              case 5:
                 cout<<"0.Display the matrix as a two-dimensional array\n";
                 cout<<"1.View the matrix compressed\n";
                 cin>>type;
                 RowList[1].print(RowList , row , column , type);
                 break;

              case 6:
                 RowList[1].save_files(RowList , row , column);
                   for(i=0; i<row; i++)
                     RowList[i].destroy();
                 flag=false;
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
