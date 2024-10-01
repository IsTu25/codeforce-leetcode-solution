#include<iostream>

using namespace std;

class Product{
    private:
    string product_name;
    string unique_id;
    int price; 
    int initial_quantity;
    int maximum_amount;

    public:
    Product(string name,string id,int pric,int initial,int max){
        product_name = name;
        unique_id = id;
        price = pric;
        maximum_amount = max;
        if(initial > max){
            initial_quantity = max;
        } else {
            initial_quantity = initial;
        }
    }

    void addToInventory(int addedQuanity){
        initial_quantity += addedQuanity;
    }

    int isAvailable(){
        if(initial_quantity > 0){
            return 1;
        } else {
            return 0;
        }
    }

    int purchase(int purchasedQuantity){
        if(initial_quantity >= purchasedQuantity){
            initial_quantity -= purchasedQuanity;
            return 1;
        } else {
            return 0;
        }
    }

    int updatePrice(int discountPercent){
        price = price - (price * discountPercent) / 100;
        return price;
    }

    int displayInventoryValue(){
        return initial_quantity * price;
    }

    void displayDetails(){
        cout<<"Product Name: "<<product_name<<endl;
        cout<<"Product ID: "<<unique_id<<endl;
        cout<<"Product Price: "<<price<<endl;
        cout<<"Product Quantity: "<<initial_quantity<<endl;
        cout<<"Availability: "<<(isAvailable() ? "Yes" : "No")<<endl;
    }

    int displayTotalInventoryValue(){
        return maximum_amount * price;
    }
};

int main(){
    Product product1("mojo", "220041213", 30, 2000, 1000);
    product1.addToInventory(45);
    product1.isAvailable();
    product1.purchase(30);
    product1.updatePrice(30);
    product1.displayInventoryValue();
    product1.displayDetails();

    Product product2("cocacola", "220041214", 10000, 2000, 1000);
    product2.addToInventory(55);
    product2.isAvailable();
    product2.purchase(115);
    product2.updatePrice(30);
    product2.displayInventoryValue();
    product2.displayDetails();

    Product product3("due", "220041215", 10000, 2000, 1000);
    product3.addToInventory(25);
    product3.isAvailable();
    product3.purchase(20);
    product3.updatePrice(10);
    product3.displayInventoryValue();
    product3.displayDetails();

    return 0;
}
