class IntArray {
    public:
        static const int DEFAULT = 0;
        IntArray(int inputN); // (a)
        IntArray(const IntArray& other); // (b)
        ~IntArray(); // (c)
        int sumByLoop(int start, int end); // (d)
        int sumByRecursion(int start, int end); // (e)
    private:
        int n;
        int *data;
};

IntArray::IntArray(int inputN)
{
    n=inputN;
    data = new int[n];
    data={0};
}

template<typename T>
T* fun()
{return new T;}

