#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

namespace partition {
    void test_partition() {
        std::vector<int> vec;
        for (int i = 0; i < 10; i++) {
            vec.push_back(i);
        }

        std::vector<int>::iterator bound;

        bound = std::partition(vec.begin(), vec.end(), [](int i) {
            return i % 2 == 1;
        });

        // print out content
        std::cout << "odd elements:" << endl;
        for (auto it = vec.begin(); it != bound; it++) {
            std::cout << *it << " ";
        }
        cout << endl;

        std::cout << "even elements:" << endl;
        for (auto it = bound; it != vec.end(); it++) {
            std::cout << *it << " ";
        }
        cout << endl;
    }


    bool IsOdd(int i) {
        return i % 2 == 1;
    }
    void test_partition_copy() {
        vector<int> vec {1,2,3,4,5,6,7,8,9};
        vector<int> odds, evens;

        unsigned n = std::count_if(vec.begin(), vec.end(), IsOdd);

        odds.resize(n);
        evens.resize(vec.size()-n);

        std::partition_copy(vec.begin(), vec.end(), odds.begin(), evens.begin(), IsOdd);

        // print information
        std::cout << "odds contains: " << endl;
        for (auto& x : odds) {
            cout << x << " ";
        }

        cout << endl;


        std::cout << "evens contains:" << endl;
        for (auto& x : evens) {
            cout << x << " ";
        }

        cout << endl;
    }
}

namespace test {
    void test_find_first_of() {
        string str = "abcdef?!fdfj";
        int found = str.find_first_not_of("abcdef", 8);

        cout << found << endl;
        cout << str.npos << endl;

    }
}

#include <array>
#include <chrono>
#include <random>
namespace shuffle {
        void test_shuffle() {
            std::array<int,5> foo {1,2,3,4,5};

            // obtain a time-based seed:
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

            std::shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));

            std::cout << "shuffled elements:";
            for (int& x: foo) std::cout << ' ' << x;
            std::cout << '\n';
        }

        void test_random_shuffel() {
            vector<int> vec {1,2,3,4,5,6};
            std::random_shuffle(vec.begin(), vec.end());

            for (auto& x : vec) {
                cout << x << " ";
            }
            cout << endl;
        }
}

namespace replace {
    void test_replace() {
        vector<int> vec {1,22,3,4,5,6,7};
        std::replace_if(vec.begin(), vec.end(), [](int i) {return i % 2 == 0;}, 2);
        for(auto& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    void test_replace_copy() {
        vector<int> vec {1,22,3,4,5,6,7};
        vector<int> res(7);
        std::replace_copy(vec.begin(), vec.end(), res.begin(), 22, 2);
        for(auto& x : res) {
            cout << x << " ";
        }
        cout << endl;

        std::replace_copy_if(vec.begin(), vec.end(), res.begin(), [](int i) {return i % 2 == 0;}, 2);
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
}

namespace rotate {
    void test_rotate() {
        vector<int> vec {1,2,3,4,5,6,7,8,9,10};
        std::rotate(vec.begin(), vec.begin()+5, vec.end());
        for (auto& x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    void  test_rotate_copy() {
        vector<int> vec {1,2,3,4,5,6,7,8,9,10};
        vector<int> res(10);

        std::rotate_copy(vec.begin(), vec.begin()+5, vec.end(), res.begin());
        for(auto& x : res) {
            cout << x << " ";
        }

        cout << endl;
    }
}

namespace search {
    void test_search() {
        vector<int> vec {1,2,3,4,5,6,7,8,9,10};
        vector<int> sec {3,4,5};

        auto it = std::search(vec.begin(), vec.end(), sec.begin(), sec.end());
        if (it != vec.end()) {
            cout << *it << endl;
            cout << "sec found at position:" << (it - vec.begin()) << endl;
        }
        else {
            cout << "sec not found in vec!" << endl;
        }
    }

    void test_search_n() {
        vector<int> vec {1,2,2,4,4,6,7,8,9,10};
        auto it = std::search_n(vec.begin(), vec.end(), 2, 4);
        if (it != vec.end()) {
            cout << "tow four appear at position:" << (it - vec.begin()) << endl;
        }

    }
}

namespace set {
    void test_set_difference() {
        vector<int> vec {1,2,3,4,5};
        vector<int> vv {2,3,4};
        vector<int> res(5);

        auto it = std::set_difference(vec.begin(), vec.end(), vv.begin(), vv.end(), res.begin());
        res.resize(it-res.begin());
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
    }

    void test_set_intersection() {
        vector<int> vec {1,2,3,4,5};
        vector<int> vv {2,3,4};
        vector<int> res(5);

        auto it = std::set_intersection(vec.begin(), vec.end(), vv.begin(), vv.end(), res.begin());
        res.resize(it-res.begin());
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
    }

    void test_set_symmetric_difference() {
        vector<int> vec {1,2,3,4,5};
        vector<int> vv {2,3,4,6,7,8};
        vector<int> res(5);
        auto it = std::set_symmetric_difference(vec.begin(), vec.end(), vv.begin(), vv.end(), res.begin());
        res.resize(it - res.begin());
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
    }

    void test_set_union() {
        vector<int> vec {1,2,3,4,5};
        vector<int> vv {2,3,4,6,7,8};
        vector<int> res(10);

        auto it = std::set_union(vec.begin(), vec.end(), vv.begin(), vv.end(), res.begin());
        res.resize(it - res.begin());
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
}

namespace partition {
    void test_stable_partition() {
        vector<int> vec {1,2,3,4,5,6,7};
        auto bound = std::stable_partition(vec.begin(), vec.end(), [](int i) {return i % 2 == 1;});

        cout << "odd elements: " << endl;
        for (auto it = vec.begin(); it != bound; it++) {
            cout << *it << " ";
        }
        cout << endl;

        cout << "even elements: " << endl;
        for (auto it = bound; it < vec.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

namespace unique {
    void test_unique() {
        vector<int> vec {10, 10, 20, 30, 20, 20, 10, 10, 50};
        auto it = std::unique(vec.begin(), vec.end());
        vec.resize(distance(vec.begin(), it));

        for (auto& x : vec) {
            cout << x << " ";
        }
        cout << endl;


    }

    void test_unique_copy() {
        vector<int> vec {10, 10, 20, 30, 20, 20, 10, 10, 50};
        vector<int> res(vec.size());

        auto it = std::unique_copy(vec.begin(), vec.end(), res.begin());
        res.resize(it - res.begin());
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
        std::stable_sort(res.begin(), res.end());
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
        std::unique_copy(res.begin(), res.end(), res.begin());
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
}

namespace upper_bound {
    void test_upper_bound() {
        vector<int> vec {1,2,3,4,5,6,7,8,9,10};
        auto it = std::upper_bound(vec.begin(), vec.end(), 6);

        cout << "the upper bound of vec compare with 6 is at position:" << (it - vec.begin()) << endl;
        cout << "the upper bound value is: " << *it << endl;
    }
}
int main() {
//    std::cout << "Hello, World!" << std::endl;
//    partition::test_partition();
//    partition::test_partition_copy();
//    test::test_find_first_of();
//    shuffle::test_random_shuffel();
//    shuffle::test_shuffle();
//    replace::test_replace();
//    replace::test_replace_copy();
//    rotate::test_rotate();
//    rotate::test_rotate_copy();
//    search::test_search();
//    search::test_search_n();
//    set::test_set_difference();
//    set::test_set_intersection();
//    set::test_set_symmetric_difference();
//    set::test_set_union();
//    partition::test_stable_partition();
//    unique::test_unique();
//    unique::test_unique_copy();
    upper_bound::test_upper_bound();
    return 0;
}