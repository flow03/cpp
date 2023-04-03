// #include <cassert>
// #include <cstddef>
#include <iomanip>
#include <iostream>
//#include <unistd.h>
#include <getopt.h>

#define FILE

#ifdef FILE

#include <filesystem>
namespace fs = std::filesystem;

void path_test(const char* argv[]);
void space(const char * disk);


#endif



// int getopt(int argc, char *const argv[], const char *optstring);

// extern char *optarg;

// extern int optind, opterr, optopt;
void test_getopt(int argc, char* const argv[])
{
	using namespace std;
	
	int ch; /* символ опции */
	bool aflag = false, bflag = false;
	char * b_opt_arg = nullptr;

	//opterr = 0;
	while ((ch = getopt(argc, argv, "-:ab:")) != -1) {
		switch (ch) 
		{
		case 'a':
			/* обработка -а, установить соответствующий флаг */
			aflag = true;
			break;
		case 'b':
			/* обработка -b, получить значение аргумента из optarg */
			bflag = true;
			if (optarg[0] == '-') {
				cout << "Cannot use " << optarg << " as parameter for " << (char)ch << endl;
				--optind;
			}
			else b_opt_arg = optarg;
			//cout << "atoi " << atoi(optarg) << endl;
			break;
		case ':':
			cout << "Опция " << (char)optopt << " требует аргумент" << endl;
			cout << "optarg " << optarg << endl;
			break;
		case '?':
			cout << "Неверная опция " << (char)optopt << endl;
			break;
		case 1:
			cout << "Включен режим '-' в optstring. optarg = " << (char*)optarg << endl;
			break;
		default:
			/* обработка ошибок, см. текст */
			break;
		}
	}
	
	
	
	cout << boolalpha;
	cout << "aflag = " << aflag << endl;
	cout << "bflag = " << bflag << endl;
	if (b_opt_arg)
		cout <<	"b_opt_arg = " << b_opt_arg << endl;
}

int main(int argc, const char* argv[])
{
	//using namespace std;
	
	// if (argc > 1)
	// {
	// if (argv[1][0] == '\n') 
		// cout << "Пустой аргумент" << endl;
	// else cout << "Аргументы присутствуют" << endl;
	// }
	// else cout << "Аргументы отсутствуют" << endl;
	
	// if (argc > 1) test_getopt(argc, argv);
	
	// cout << endl << "opterr = " << opterr << endl;
	// cout << "optind = " << optind << endl;
	// cout << "optopt = " << (char)optopt << endl;
	// cout << "optarg = " << optarg << endl;
	
	path_test(argv);
	
	
	return 0;
}

#ifdef FILE

void space(const char * disk)
{
	using std::cout; using std::endl;
	
	auto root = fs::path(disk);
	auto space = fs::space(root);
	cout << "fs::path\t" << root << endl;
	cout << "space.capacity\t" << (double)space.capacity/1024/1024/1024 << " Gb" << endl;
	cout << "space.free\t" << (double)space.free/1024/1024/1024 << " Gb" << endl;
	cout << "space.available\t" << (double)space.available/1024/1024/1024 << " Gb" << endl;
}

void path_test(const char* argv[])
{
	using std::cout; using std::endl;
	
	// auto current = std::filesystem::current_path();
	// cout << "current_path\t\t" << current << endl;
	
	// std::filesystem::path path{ "C:\\TestingFolder" }; //creates TestingFolder object on C:
    // path /= "my new file.txt"; //put something into there
    // std::filesystem::create_directories(path.parent_path()); //add directories based on the object path (without this line it will not work)
	// cout << "Separator in my system " << (char)fs::path::preferred_separator << endl;
	
	fs::path file{argv[0], fs::path::native_format};
	
	cout << "operator<<\t\t" << file << endl;
	cout << "file.root_path\t\t" << file.root_path() << endl;
	cout << "file.root_name\t\t" << file.root_name() << endl;
	cout << "file.root_directory\t" << file.root_directory() << endl;
	cout << "file.relative_path\t" << file.relative_path() << endl;
	cout << "file.parent_path\t" << file.parent_path() << endl;
	cout << "file.parent_path.filename\t" << file.parent_path().filename().string() << endl; // with(out) string() method
	cout << "file.filename\t\t" << file.filename() << endl;
	cout << "file.stem\t\t" << file.stem() << endl;
	cout << "file.extension\t\t" << file.extension() << endl;
	
	cout << "fs:hash_value(file)\t" << std::uppercase << std::hex << fs::hash_value(file) << std::dec << '\t' << fs::hash_value(file) << endl;
	//cout << "std::hash<fs::path>{}(file)\t\t" << std::hash<fs::path>{}(file) << endl << endl;
	//std::cout << std::hex << std::uppercase << std::setw(16) << std::hash<fs::path>{}(file) << " : " << file << "\n\n";
	
	
	fs::directory_entry entry(file);
	std::cout << std::setw(25) << std::left << entry.path().filename() << std::right << entry.file_size()/1024 << "\tKb\n";
}

#endif