#include <iostream>  
  
auto List = [](auto ...xs) {   
    return [=](auto access) { return access(xs...); };   
};   
   
auto length = [](auto xs) {   
    return xs([](auto ...z) { return sizeof...(z); });   
};  
  
auto fmap = [](auto func) {  
    return [func] (auto alist) {  
        return alist([func](auto... xs) { return List(func(xs)...); });  
    };  
};  
  
int main()  
{  
    std::cout << length(List(1, '2', "3")); // 3  
    auto twice = [](auto i) { return 2*i; };  
    auto print = [](auto i) { std::cout << i << " "; return i; };  
    auto l1 = List(1, 2, 3, 4);  
    auto l2 = fmap(twice)(l1);  
    auto l3 = fmap(print)(l2); // 8 6 4 2  
}  