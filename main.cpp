#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <iterator>

template <typename Container>
Container Siev(Container v, size_t n)
{
    for(size_t i = 1; i < n; ++i)
    {
        if(i==1) v.push_back(0);
        v.push_back(1);
    }
    for(size_t i = 2; i < n; ++i)
    {
        if(v[i] == 1) 
        for(size_t j = i*2; j< n; j += i)
        {
            v[j] = 0;
        }
    }
    return v;
}
int main(int argc, char const *argv[])
{
    const size_t N {100000};
    int count {0};
    std::vector<int> a;
    auto b = Siev(a, N);
    auto dot_space ([](auto it_dot, int x) {
        *++it_dot = (x>0 ? '*' : ' ');
        return it_dot;
    });
    for(size_t M = 0; M < N; M += 100)
    {
        for(size_t i = M; i < M+100; i++)
        {
            if(b[i] == 1) count++;
        }
        std::cout << "M: " << M + 100 <<"\t" ;
        std::accumulate(std::begin(b) + M, std::begin(b) + M + 100, std::ostream_iterator<char> {std::cout}, dot_space);
        std::cout << "\t {" << count <<"}" << std::endl;
        count = 0;
    return 0;
}
