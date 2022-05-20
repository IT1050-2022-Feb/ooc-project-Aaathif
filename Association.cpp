//IT21154980 Asiff Y N A

#include <iostream>
using namespace std;

class Discount{
	private :
		double discount;
	
	public :
		Discount();
		Discount(double pdiscount){
			discount = pdiscount;
		}
		double getDiscount(){
			return discount;
		}
		void displayDisocunt(){
			cout << "Discount = " << discount << endl;
		}
};

class Payment{
	private : 
		double amount;
		Discount *dis;
		
	public :
		Payment (double pamount, Discount *d){
			amount = pamount;
			dis = d;
		} 

    void displayTotal(){
      cout << "Total : " << amount << endl;;
    }

		void displaySubTotal(){
			cout << "Sub Total : " << amount - dis->getDiscount();
		}
};

int main(){
	Discount *d = new Discount(250);
	d->displayDisocunt();
	
	Payment *p = new Payment(1000, d);
  p->displayTotal();
	p->displaySubTotal();
	delete d;
	delete p;
	return 0;
}





