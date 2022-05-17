//association relationship between payment class and order class.
//IT21155116 - M.A.D.A.DILSHAN

#include <iostream>
#include <string>
using namespace std;

class payment;
class Order;

class payment{
private:
int paymentId;
string paymentType;
double paymentAmount;
Order * order;
public:
payment();
payment(int pId, string pType, double pAmount);
void addOrder(Order * o);
void displayPayment();
};

class Order{
private:
int orderId;
payment * Payment;
public:
Order(int OId, payment * P);
void displayOrders();
};

Order::Order(int OId, payment * P)
{
  orderId = OId;
  Payment = P;
}
void Order :: displayOrders()
{
  cout<<"orderID : "<<orderId<<endl;
}

payment::payment(int pId, string pType, double pAmount)
{
  paymentId = pId;
  paymentType = pType;
  paymentAmount = pAmount;
}

void payment::displayPayment()
{
  cout<<"payment details  for the order "<<endl;
  cout<<"id number : "<<paymentId<<endl;
  cout<<"type : "<<paymentType<<endl;
  cout<<"amount : " << paymentAmount<<endl<<endl;
}

int main()
{
  char ch;
  payment * p1 = new payment(001, "cash", 1000.00);
  payment * p2 = new payment(002, "card", 2000.00);
  payment * p3 = new payment(003, "check", 5000.00);
  
  p1->displayPayment();
  p2->displayPayment();
  p3->displayPayment();

  cin >> ch;
  return 0;
};
