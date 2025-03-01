#include "string_util.h"
#include <cassert>
#include <iostream>

int main()
{

    vector<string> strings   = {"apple", "banana", "cherry"};
    char           delimiter = '-';
    string         joined    = StringUtil::join(strings, delimiter);
    string         expected1 = "apple-banana-cherry";
    cout << "Actual: " << joined << ", Expected: " << expected1 << endl;
    assert(joined == expected1);
    cout << "Join test passed!" << endl << endl;

    string         input     = "apple,banana,cherry";
    char           separator = ',';
    vector<string> splitted  = StringUtil::split(input, separator);
    vector<string> expected2 = {"apple", "banana", "cherry"};
    cout << "Splitted: " << endl;
    for (int i = 0; i < splitted.size(); i++) {
        cout << "Actual: " << splitted[i] << ", Expected: " << expected2[i] << endl;
        assert(splitted[i] == expected2[i]);
    }
    cout << "Split test passed!" << endl << endl;

    return 0;
}