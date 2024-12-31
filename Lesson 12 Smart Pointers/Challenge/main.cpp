#include <iostream>
#include <memory>
#include <vector>

//! I DID THIS SHI FIRST TRY WITH NO PROBLEMS AND NO HELP I DIDNT THINK IT WOULD WORK IM SO HAPPY

class Test
{
private:
  int data;
public:
  Test(): data(0) { std::cout << "Test contructor (" << data << ")" << std::endl;}
  Test(int data): data(data) { std::cout << "Test contructor (" << data << ")" << std::endl;}
  int get_data() const { return data; }
  ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector <std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

int main()
{
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
  vec_ptr = make();
  std::cout << "Enter data points: ";
  int num;
  std::cin >> num;
  fill(*vec_ptr, num);
  display(*vec_ptr);

  return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
  return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector <std::shared_ptr<Test>> &vec, int num)
{
  int pushNum;
  std::shared_ptr<Test> ptr;
  for(int i = 1; i <= num; i++){
    std::cout << "Enter data point " << "[" << i << "]" << " : ";
    std::cin>>pushNum;
    ptr = std::make_unique<Test>(pushNum);
    vec.push_back(ptr);
  }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
  for(auto const &obj : vec)
    std::cout << obj->get_data() << std::endl;
}