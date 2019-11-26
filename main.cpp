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

#include <algorithm>
#include <set>
using namespace std;
namespace leetcode {
    string reverseVowels(string s) {
        vector<char> vec {'a', 'e', 'i', 'o', 'u'};
        if (s.size() > 0) {
            auto first = s.begin();
            auto last = s.end() - 1;
            while (first < last) {
                while (first < last && find(vec.begin(), vec.end(), tolower(*first)) == vec.end()) {
                    first++;
                }

                while (first < last && find(vec.begin(), vec.end(), tolower(*last)) == vec.end()) {
                    last--;
                }
                swap(*first, *last);
                first++;
                last--;
            }
        }
        string str = "";
        for (auto& x : s) {
            str += x;
        }
        return str;
    }


    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> v(nums1.size());
        auto it = std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        v.resize(it - v.begin());
        it = std::unique(v.begin(), v.end());
        v.resize(it - v.begin());
        return v;
    }

    int findKthMaxNum(vector<int> vec, int K) {
        std::set<int> myset;
        for (auto& num : vec) {
            myset.insert(num);
            if (myset.size() > K) {
                myset.erase(*myset.begin());
            }
        }
        if (myset.size() < K) {
            return *myset.rbegin();
        } else return *myset.begin();
    }

    // leetcode 482 秘钥格式化
    string licenseKeyFormatting(string S, int K) {
        reverse(S.begin(), S.end());
        auto it = remove_if(S.begin(), S.end(), [](char ch) {return ch == '-';});
        S.resize(it - S.begin());
        for (auto s : S) {
            cout << s;
        }
        cout << endl;
        string res = "";
        int i = 0;
        for (; i < S.size()-1;) {
            for (int j = 0; j < K && i < S.size(); j++) {
                res += S.at(i);
                i++;
            }
            if (i+1 < S.size()) {
                res += '-';
            }
        }
        if (i <= S.size() - 1) {
            res += '-';
        }
        for (; i <= S.size()-1; i++) {
            res += S.at(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // leetcode 492 构造矩形

#include <climits>
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int min = INT_MAX;
        for (int i = 1, j = area; i <= j;) {
            if (i * j == area) {
                if (j - i < min) {
                    res.clear();
                    res.push_back(i);
                    res.push_back(j);
                    i++;
                    j--;
                }
            } else if (i * j < area) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }

    // LeetCode496 下一个更大元素
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (auto& num1 : nums1) {
            auto it = find(nums2.begin(), nums2.end(), num1);
            it++;
            while (it != nums2.end()) {
                if (*it > num1) {
                    res.push_back(*it);
                    break;
                } else {
                    it++;
                }
            }
            if (it == nums2.end()) {
                res.push_back(-1);
            }
        }
        return res;
    }
}




int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> res = leetcode::nextGreaterElement(nums1, nums2);
    for (auto& x : res) {
        cout << x << " ";
    }
    cout << endl;
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
//    upper_bound::test_upper_bound();
//    cout << leetcode::reverseVowels("hello") << endl;

//    vector<int> v1 {4,9,5}, v2 {9,4,9,8,4};
//    vector<int> res = leetcode::intersection(v1, v2);
//    for (auto& x : res) {
//        cout << x << " ";
//    }
//    cout << endl;

//    cout << leetcode::findKthMaxNum(vector<int> {1,2,3,4,5,6,7,8,9}, 5) << endl;
//    cout << leetcode::licenseKeyFormatting("2-4A0r7-4k", 3) << endl;
//    vector<int> res = leetcode::constructRectangle(4);
//    for (auto x : res) {
//        cout << x << " ";
//    }
//    cout << endl;
    return 0;

}