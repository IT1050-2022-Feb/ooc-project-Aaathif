
//IT21156342 G.CPiyumal 

/ Dependency relationships

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
		cout << " Product ID =" << productID << endl;
		cout << " Product name =" << productName << endl;
		cout << " Product Description = " << productDescription << endl;
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
	D1->setDiscount(12.5);
	D1->addProduct(5, P1);
	D1->getDiscount();
	cin >> ch;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
