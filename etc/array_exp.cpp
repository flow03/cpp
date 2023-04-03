#include <iostream>
#include <cstring> //strlen

template<typename T, std::size_t N> 
class DoubleArrPtr
{
	public:
	
	DoubleArrPtr(T (*begin_arr)[N], T (*end_arr)[N]) : b_arr(begin_arr), e_arr(end_arr)
	{
		//cols = sizeof(*b_arr)/sizeof(*b_arr[0]);
		cols = N;
		for(auto i = b_arr; i != e_arr; ++i) {++rows;}
	}
	
	T (*b_arr)[N]; 
	T (*e_arr)[N]; 
	size_t rows = 0;
	size_t cols = 0;
};

void func(const char &arr){std::cout << sizeof(arr) << " arr" << std::endl;}

template<std::size_t N> 
void func2(char(*array)[N]) // 2x pointer array
{
// std::cout << sizeof(array[0]) << " sizeof" << std::endl; // возвращает размер первого подмассива в байтах
size_t columns = sizeof(*array)/ sizeof(*array[0]); // 8/1
// columns = sizeof(array[0])/ sizeof(array[0][0]); // равнозначно
std::cout << columns << std::endl;

char(*begin_a)[N] = std::begin(array);
char(*end_a)[N] = std::end(array);

for (auto i = begin_a; i != end_a; ++i)
{
	for (size_t j = 0; j != '\0'; ++j)
		std::cout << array[i][j] << ' ';
	std::cout << std::endl;
}

std::cout << std::endl;
}

template<std::size_t N, std::size_t M> 
void func22(char(*array)[N][M]) // 3x pointer array
{
// size_t col = sizeof(*array)/ sizeof(*array[0]); // 8/1
// std::cout << col << std::endl;

for (size_t m = 0; m < 2; ++m)
for (size_t i = 0; i < N; ++i)
{
	for (size_t j = 0; j < M; ++j)
		std::cout << array[m][i][j] << ' ';
	
	std::cout << std::endl;
}
}

// template<std::size_t N> 
void func3(char (&array)[][6], int rowsCount) // 2x reference array
{
size_t columns = sizeof(*array)/ sizeof(*array[0]); // 8/1
// size_t columns = sizeof(array[0])/ sizeof(array[0][0]); // равнозначно
// std::cout << sizeof(array) << std::endl;
std::cout << columns << std::endl;

// char (*begin)[N] = std::begin(array);      
// char (*end)[N] = std::end(array); 

for (size_t i = 0; i < rowsCount; ++i)
{
	for (size_t j = 0; j < columns; ++j)
	{
		std::cout << array[i][j] << ' ';
	}
	std::cout << std::endl;
}
}

void func4(char array[]) // 1x array
{
// size_t size = sizeof(array);
// std::cout << size << std::endl;

for (size_t i = 0; i != '\0'; ++i)
{
	std::cout <<array[i] <<' ';
	array[i] = '0';
}
std::cout << std::endl;
}

void func5(char *begin, char *end) // 1x iterators array
{
	size_t size = sizeof(begin); // размер массива, на который указывает указатель, в байтах
	std::cout << size << std::endl;
		
	for (char *ptr  = begin; ptr != end; ptr++)
	{
		std::cout << *ptr << ' ';
	}
	std::cout << std::endl;
}

template<std::size_t N> 
void func6(char (*begin)[N], char (*end)[N]) // 2x iterators array
{
	//size_t size = sizeof(begin); 
	std::cout << sizeof(*begin) << std::endl;
		
	for (char (*ptr)[N]  = begin; ptr != end; ptr++)
	{
		for (size_t i = 0; i < N; ++i)
			std::cout << (*ptr)[i] << ' ';
		
		std::cout << std::endl;
	}
}

int main()
{
// const unsigned char(*symbol)[16] = nullptr;
char arr[5][6] = {"arerw", "23re3","g4000", "122fd", "ggr01"};
char arr1[10][8] = {"some_text"};
char arr2[8] = {"sometext"};
char arr3[2][3][6] = {{{"sample"},{"text"},{"straw"}}};

// for (size_t i = 0; i < 3; ++i)
	// for (size_t j = 0; j < 6; ++j)
		// arr3[1][i][j] = arr[i][j];
	
// char *begin = std::begin(arr2);      
// char *end = std::end(arr2);  

char (*begin2)[6] = std::begin(arr);      
char (*end2)[6] = std::end(arr);
	
func2(arr);
// func6(begin2, end2);

// sizeof(*begin2)/sizeof(*begin2[0]);
// DoubleArrPtr<char, 6> d(std::begin(arr), std::end(arr));

// d.rows;
// d.cols;

// std::cout << "d.rows " << d.rows << " d.cols " << d.cols << std::endl;

//std::cin.get();
return 0;
}