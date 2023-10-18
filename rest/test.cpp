#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
using namespace nlohmann::literals;

// https://github.com/nlohmann/json
int main()
{
	// Using (raw) string literals and json::parse
	json ex1 = json::parse(R"(
	  {
		"pi": 3.141,
		"happy": true
	  }
	)");

	// Using user-defined (raw) string literals
	json ex2 = R"(
	  {
		"pi": 3.141,
		"happy": true
	  }
	)"_json;

	// Using initializer lists
	json ex3 = {
	  {"happy", true},
	  {"pi", 3.141},
	};	
}
