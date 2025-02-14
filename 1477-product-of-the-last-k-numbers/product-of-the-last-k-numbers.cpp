class ProductOfNumbers {
    vector<int> numbers;
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        numbers.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        int i = numbers.size()-1;
        while(k) {
            product *= numbers[i];
            i--;
            k--;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */