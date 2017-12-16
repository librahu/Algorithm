#include "LinkedListMap.h"
#include "LinkedListMap.cpp"
#include <string>

using namespace std;

int main()
{
	LinkedListMap<string, int> linkedListMap;
	linkedListMap.put("a", 3);
	linkedListMap.put("b", 4);
	linkedListMap.put("c", 5);
	string a = "a";
	cout << linkedListMap.get("a") << endl;
	cout << linkedListMap.get("b") << endl;
	cout << linkedListMap.get("c") << endl;
    return 0;
}
