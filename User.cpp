#include<iostream>
#include<cstring>
using namespace std;

class User {
  protected: 
      char name[20];
      int age;
      char address[40];
      string contactNumber;
  public:
      User();
      User(const char uName[], int uAge,const char uAddress[], string uContactNumber) {
        //cout << "User called" << endl << endl;
        strcpy(name, uName);
        age = uAge;
        strcpy(address, uAddress);
        contactNumber = uContactNumber;
      }
      virtual void displayDetails() {
        cout << "User Name : " << name << endl;
        cout << "Address : "<< address << endl;
        cout << "Contact Number : " << contactNumber << endl; 
      }
};

class RegsiterBuyer: public User  {
  private:
      int buyerID;
      char email[20];
      char password[20];
  public:
      RegsiterBuyer(const char uName[], int uAge,const char uAddress[], string uContactNumber, int rb_BuyerID, const char rb_Email[],const char rb_Password[])
        :User(uName, uAge, uAddress, uContactNumber){
          cout << "RegisterBuyer called" << endl << endl;
          buyerID = rb_BuyerID;
          strcpy(email, rb_Email);
          strcpy(password, rb_Password);
        }
      void displayDetails(){
        cout << endl;
        User::displayDetails();
        cout << "Register buyer ID : " << buyerID << endl;
        cout << "Register buyer email : " << email << endl;
        cout << "Register buyer password : " << password << endl << endl;
      }  
};

class RegisterSeller : public User {
  private: 
      int sellerID;
      char email[20];
      char password[20]; 
  public:
      RegisterSeller(const char uName[], int uAge,const char uAddress[], string uContactNumber, int rs_SellerID,const char rs_Email[],const char rs_Password[])
      :User(uName, uAge, uAddress, uContactNumber){
          cout << "RegisterSeller called" << endl << endl;
          sellerID = rs_SellerID;
          strcpy(email, rs_Email);
          strcpy(password, rs_Password);
      }
    void displayDetails(){
      User::displayDetails();
      cout << "Register seller ID : " << sellerID << endl;
      cout << "Register seller email : " << email << endl;
      cout << "Register seller password : " << password << endl << endl;
    }
};

int main(){

  User u1("jone", 40, "New york city", "0112132312");
  
  RegsiterBuyer rB1("David", 28, "London", "0101212123", 1234, "david11@gmail.com", "david123#");
  
  RegisterSeller rS1("Parker", 33, "Mexico", "0156221123", 5678, "parker23@gmail.com", "parker123#");
  

  u1.displayDetails();
  rB1.displayDetails();
  rS1.displayDetails();
  
  return 0;
}