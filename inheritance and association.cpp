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
      User(const char uName[], int uAge,const char uAddress[], string uContactNumber);
      void displayDetails();
};

class feedback {
  private: 
    char fNo[20];
    char description[50];
  public:
    feedback();
    feedback(const char f_NO[], const char fDescription[]);
    void displayFeedback();
};


class RegisterBuyer: public User  {
  private:
      int buyerID;
      char email[20];
      char password[20];
      feedback *fb_buyer;
  public:
  	  RegisterBuyer();
      RegisterBuyer(const char uName[], int uAge,const char uAddress[], string uContactNumber, int rb_BuyerID, const char rb_Email[],const char rb_Password[], feedback *fb_b);  
      void displayDetails();  
};

  

class RegisterSeller : public User {
  private: 
      int sellerID;
      char email[20];
      char password[20]; 
      feedback *fb_seller;
  public:
  	  RegisterSeller();
      RegisterSeller(const char uName[], int uAge,const char uAddress[], string uContactNumber, int rs_SellerID,const char rs_Email[],const char rs_Password[], feedback *fb_seller);
    void displayDetails();
};

  // --- user implementation ---------------

	  User::User(){
	  	
	  }
    User::User(const char uName[], int uAge,const char uAddress[], string uContactNumber) {
        //cout << "User called" << endl << endl;
        strcpy(name, uName);
        age = uAge;
        strcpy(address, uAddress);
        contactNumber = uContactNumber;
    }
    void User::displayDetails() {
        cout << "User Name : " << name << endl;
        cout << "Address : "<< address << endl;
        cout << "Contact Number : " << contactNumber << endl; 
    }

  // --- feedback imaplementation -----------

    feedback::feedback(){
      
    }
    feedback::feedback(const char f_No[], const char fDescription[]){
        strcpy(fNo, f_No);
        strcpy(description, fDescription);
    }
    void feedback::displayFeedback(){
        cout << "Feedback number : " << fNo << endl;
        cout << "Description : " << description << endl;
        cout << endl;
    }

    // --- RegisterBuyer implementation ----------
      
    RegisterBuyer::RegisterBuyer(){
      	
	  }
    RegisterBuyer::RegisterBuyer(const char uName[], int uAge,const char uAddress[], string uContactNumber, int rb_BuyerID, const char rb_Email[],const char rb_Password[], feedback *fb_b)
        :User(uName, uAge, uAddress, uContactNumber){
          cout << "RegisterBuyer called" << endl << endl;
          buyerID = rb_BuyerID;
          strcpy(email, rb_Email);
          strcpy(password, rb_Password);
          fb_buyer = fb_b;
    }
    void RegisterBuyer::displayDetails(){
        cout << endl;
        User::displayDetails();
        cout << "Register buyer ID : " << buyerID << endl;
        cout << "Register buyer email : " << email << endl;
        cout << "Register buyer password : " << password << endl;
        fb_buyer->displayFeedback();
        cout << endl;
    } 
      
  // --- RegisterSeller implementation ------------

    RegisterSeller::RegisterSeller(){
      	
	  }
    RegisterSeller::RegisterSeller(const char uName[], int uAge,const char uAddress[], string uContactNumber, int rs_SellerID,const char rs_Email[],const char rs_Password[], feedback *fb_s)
      :User(uName, uAge, uAddress, uContactNumber){
          cout << "RegisterSeller called" << endl << endl;
          sellerID = rs_SellerID;
          strcpy(email, rs_Email);
          strcpy(password, rs_Password);
          fb_seller = fb_s;
          
    }
    void RegisterSeller::displayDetails(){
      	User::displayDetails();
      	cout << "Register seller ID : " << sellerID << endl;
      	cout << "Register seller email : " << email << endl;
      	cout << "Register seller password : " << password << endl;
        fb_seller->displayFeedback();
        cout << endl;
    }
      
      
      

int main(){

  feedback *fb = new feedback("FB123", "Delivery Issues");
  fb->displayFeedback();
  feedback *fs = new feedback("FS123", "Payment issues");
  fs->displayFeedback();
  
  User *u1 = new User("jone", 40, "New york city", "0112132312");
  
  RegisterBuyer *rB1= new RegisterBuyer("David", 28, "London", "0101212123", 1234, "david11@gmail.com", "david123#", fb);
  
  RegisterSeller *rS1 = new RegisterSeller("Parker", 33, "Mexico", "0156221123", 5678, "parker23@gmail.com", "parker123#", fs);
  

  u1->displayDetails();
  rB1->displayDetails();
  rS1->displayDetails();

  delete fb;
  delete fs;
  delete u1;
  delete rB1;
  delete rS1;
  
  return 0;
}
