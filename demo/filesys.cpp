// I took all the examples from
// https://www.studyplan.dev/pro-cpp/file-system
// and added here as functions. There are lot more than this
// and you may need to adapt , but the filesystem libray contains
// methods for copying, moving etc
// which are addressed by the above site

#include <filesystem>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>

bool directory_exists( const std::string& _directory );
bool is_directory( const std::string& _directory );
bool is_file( const std::string& _directory );
bool create_dir( const std::string& _directory );
uintmax_t getFileSize( const std::string& _file);
std::string getLastTime(const std::string& _file);

uintmax_t getFileSize( const std::string& _file)
{
	std::filesystem::directory_entry File{_file};
	return File.file_size();
}

// C++17 does not have an easy way to convert std::filesystem::file_time_type to a string
// https://stackoverflow.com/questions/56788745/how-to-convert-stdfilesystemfile-time-type-to-a-string-using-gcc-9
template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

// https://stackoverflow.com/questions/56788745/how-to-convert-stdfilesystemfile-time-type-to-a-string-using-gcc-9
std::string getLastTime(const std::string& _file)
{
	std::filesystem::file_time_type file_time = std::filesystem::last_write_time(  _file );
    std::time_t tt = to_time_t(file_time);
    std::tm *gmt = std::gmtime(&tt);
    std::stringstream buffer;
    buffer << std::put_time(gmt, "%A, %d %B %Y %H:%M");
	return buffer.str();
}

// you can add try catches to every call, this is only an example
bool directory_exists( const std::string& _directory )
{
	try
	{
		std::filesystem::directory_entry Directory{_directory};
		return Directory.exists();
	}
	catch (std::filesystem::filesystem_error e) 
	{
		return false;
	}
}

bool is_directory( const std::string& _directory )
{
	std::filesystem::directory_entry Directory{_directory};
	return Directory.is_directory();
}

bool is_file( const std::string& _directory )
{
	std::filesystem::directory_entry Directory{_directory};
	return Directory.is_regular_file();
}

bool create_dir( const std::string& _directory )
{
	return std::filesystem::create_directory(_directory);
}

int main() 
{
  std::string path = "C:\\Users\\Administrador\\Documents\\GitHub\\mycpp\\mycpp\\demo";
  
  if (directory_exists(path)) 
  {
    std::cout << "The location exists" << std::endl;;
  }

  if (is_directory(path))
  {
    std::cout << "It is a directory" << std::endl;;
  }

  if (!is_file(path)) 
  {
    std::cout << "It is not a file" << std::endl;;
  }
  
  if (create_dir(path+"\\out"))
  {
    std::cout << "Cannot create directory" << std::endl;;
  }  
  
  std::string filename = path + "\\" + "filesys.cpp";
  std::cout << filename << " has size " << getFileSize(filename) << std::endl;
  std::cout << filename << " last updated " << getLastTime(filename) << std::endl;
  
}