package products;

import java.util.ArrayList;

/**
 * Manage the stock in a business. The stock is described by zero or more
 * Products.
 * 
 * @author Safwane Benidir
 * @version 10/10/2019
 */
class StockManager {
    // A list of the products.
    final ArrayList<Product> stock;

    /**
     * Initialise the stock manager.
     */
    StockManager() {
        stock=new ArrayList<Product>();
    }

    /**
     * Add a product to the list.
     * 
     * @param item
     *            The item to be added.
     */
    void addProduct(Product item) {
        boolean bool = true;
        for (Product p: stock) {
            if (p.getID()==item.getID()) {
                bool = false;
        }
        if (bool) stock.add(item);
    }

    int numberOfProducts(){
        return stock.size();
    }

    /**
     * Receive a delivery of a particular product. Increase the quantity of the
     * product by the given amount.
     * 
     * @param id
     *            The ID of the product.
     * @param amount
     *            The amount to increase the quantity by.
     */
    void delivery(int id, int amount) {
        for (Product p: stock) {
            if (p.getID()==id){
                p.increaseQuantity(amount);
            }
        }
    }

    /**
     * Try to find a product in the stock with the given name.
     * 
     * @return The identified product, or null if there is none with a matching
     *         name.
     */
    Product findProduct(String name) {
        for (Product p: stock) {
            if (p.getName().equals(name)){
                return p;
            }
        }
            return null;
    }

    /**
     * Locate a product with the given ID, and return how many of this item are
     * in stock. If the ID does not match any product, return zero.
     * 
     * @param id
     *            The ID of the product.
     * @return The quantity of the given product in stock.
     */
    int numberInStock(int id) {
        for (Product p: stock) {
            if (p.getID()==id){
                return p.getQuantity();
            }
        }
        return 0;
    }

    /**
     * Print details of all the products.
     */
    void printProductDetails() {
        for (Product p: stock) {
            System.out.println(p.toString());
        }
    }

    void fewer(int numbers){
        for (Product p: stock) {
            if (p.getQuantity() < numbers){
                System.out.println(p.toString());
            }
        }
    }
}
