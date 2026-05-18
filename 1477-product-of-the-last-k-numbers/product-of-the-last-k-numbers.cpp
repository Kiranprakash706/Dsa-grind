class ProductOfNumbers {
public:
    vector<int> temp;

    ProductOfNumbers() {
        temp.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            temp.clear();
            temp.push_back(1);
        } else {
            temp.push_back(temp.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= temp.size()) return 0;
        return temp.back() / temp[temp.size() - 1 - k];
    }
};