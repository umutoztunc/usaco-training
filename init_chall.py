#!/usr/bin/env python3
import os
import sys
import textwrap

def main():
    if len(sys.argv) < 2:
        print(f'{sys.argv[0]} <name>')
        return

    name = sys.argv[1].strip()
    os.makedirs(name, exist_ok=True)
    with open(f'{name}/{name}.cpp', 'w') as f:
        f.write(file_content(name))

def file_content(name):
    content = textwrap.dedent(f"""\
        /*
        ID: umutozt1
        TASK: {name}
        LANG: C++14
        */
        #include <iostream>
        #include <fstream>

        using namespace std;

        int main() {{
            ofstream fout("{name}.out");
            ifstream fin("{name}.in");
            return 0;
        }}""")
    return content

if __name__ == '__main__':
    main()
