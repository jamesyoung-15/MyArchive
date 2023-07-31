void cbr(int& x) { x += 10; }        // Fine

void cbcr(const int& x) { x += 10; } // Error!
