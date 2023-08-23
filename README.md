# C++ Prytyfy Debug Function

## Currently support:

primitive array

`vector`
`deque`
`priority_queue`
`array`
`valarray`

`set`
`multiset`
`unordered_set`
`unordered_multiset`

`pair`
`tuple`

`map`
`unordered_map`
`unordered_multimap`

`string`
`char`

## Not supported yet:
`stack`
`queue`

## Features:
* Print any number of anything with `print(...)`
* Print part of array with `print_arr(arr,dim0,dim1,...)`
* Different parentheses for different containers `[]`,`()`,`{}`,`<>`,`""`,`''`
* Support frequently used data types, ~~such as `vector<pair<map<long long,set<char>>,string>[100]`~~
* Highlight higher dimension parentheses
* Debug recursion code with `IDT()` with ease (inspired by https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html)
* Support custom data types with ostream overload
