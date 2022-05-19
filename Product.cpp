# include <iostream>
# include <string>
using namespace std;

class product;
class discount;

class Product
{
private:
	string productName;
	string productID;
	string productDescription;
	float price;
public:
	Product() {}
	Product(string pID, string pname, float pprice)
	{
		productID = pID;
		productName = pname;
		price = pprice;
	}

	void setDescription(string descrip)
	{
		productDescription = descrip;
	}

	float getPrice() {
		return price;
	}

	void displayDetails()
	{
		cout << "Product ID =" << productID << endl;
		cout << "Product name =" << productName << endl;
		cout << "Product Description = " << productDescription << endl << endl;
	}
};

class Discount
{
private:
	double discount;
public:
	void setDiscount(double dcount) {
		discount = dcount;
	}

	void addProduct(int qty, Product* p) {

	}

	void getDiscount() {
		cout << "Discount = " << discount << endl;
	}

};

int main()
{
	char ch;
	Product* P1 = new Product("P001", "Mugs", 150.00);
	P1->setDescription("For camping");
	Discount* D1 = new Discount();
	P1->displayDetails();
	D1->setDiscount(12.5);
	D1->addProduct(5, P1);
	D1->getDiscount();
	
	cin >> ch;
}
